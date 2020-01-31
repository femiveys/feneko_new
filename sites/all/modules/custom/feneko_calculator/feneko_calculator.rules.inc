<?php
define('FC_PROFILE_LENGTH', 6000);

/**
 * Implementation of hook_rules_action_info().
 */
function feneko_calculator_rules_action_info() {
  return array(
    'fc_lengte_breedte_optimisation' => array(
      'label' => t('Lengte-Breedte optimalisatie'),
      'group' => t('Feneko'),
      'parameter' => array(
        'line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('The line item.'),
          'description' => t('The line item on which to apply the Lengte-Breedte optimalisatie.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
          'save' => true,    // And saved too!
        ),
      ),
      'module' => 'feneko_calculator',
    ),
    'fc_minimum_invoice_amount' => array( // This is the name of the callback function
      'label' => t('Set the minimum invoice amount difference'),
      'group' => t('Feneko'),
      'parameter' => array(
        'order' => array(
          'type' => 'commerce_order',
          'label' => t('Commerce order'),
          'description' => t('The order on which to apply the minimum invoice amount difference.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
          'save' => true,    // And saved too!
        ),
      ),
      'module' => 'feneko_calculator',
    ),
    'fc_niet_stock_standaardprofiel' => array(
      'label' => t('Calculate the price for niet-stock standaardprofiel'),
      'group' => t('Feneko'),
      'parameter' => array(
        'line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('The line item.'),
          'description' => t('Calculates the price for niet-stock standaardprofiel, including the optimisation.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
          'save' => true,    // And saved too!
        ),
      ),
      'module' => 'feneko_calculator',
    ),
    'fc_stock_standaardprofiel' => array(
      'label' => t('Calculate the price for stock standaardprofiel'),
      'group' => t('Feneko'),
      'parameter' => array(
        'line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('The line item.'),
          'description' => t('Calculates the price for stock standaardprofiel, including the optimisation.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
          'save' => true,    // And saved too!
        ),
      ),
      'module' => 'feneko_calculator',
    ),
    'fc_apply_korting' => array(
      'label' => t('Apply korting (klantenkorting or staffelkorting)'),
      'group' => t('Feneko'),
      'parameter' => array(
        'order' => array(
          'label' => t('Commerce Order'),
          'type' => 'commerce_order',
          'description' => t('Should point to this order.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
        ),
      ),
      'module' => 'feneko_calculator',
    ),
  );
}


function fc_lengte_breedte_optimisation($line_item_wrapper) {
  // Original
  $lengte  = $line_item_wrapper->field_lengte->value();
  $breedte = $line_item_wrapper->field_breedte->value();
  $original_price = $breedte
    * $line_item_wrapper->commerce_product->commerce_price->amount->value();

  // Get the price of the product with breedte and lengte switched
  $info = field_info_field('field_sandwichpaneel_lengte');
  $options = $info['settings']['allowed_values'];
  $new_lengte = $breedte;
  $new_breedte = $lengte;

  $chunks = explode('-', $line_item_wrapper->commerce_product->sku->value());
  $chunks[3] = fc_get_discrete_lengte($new_lengte, $options); // [3] holds the discrete lengte
  $new_sku = implode('-', $chunks);

  $new_product = commerce_product_load_by_sku($new_sku);
  $new_product_wrapper = entity_metadata_wrapper('commerce_product', $new_product);
  $new_price = $new_breedte * $new_product_wrapper->commerce_price->amount->value();

  // If the new price is cheaper than the old one, we change the line item
  if($new_price < $original_price) {
    $line_item_wrapper->line_item_label->set($new_sku);
    $line_item_wrapper->commerce_unit_price->set($new_product_wrapper->commerce_price->value());
    $line_item_wrapper->commerce_product->set($new_product);
    $line_item_wrapper->field_lengte->set($new_lengte);
    $line_item_wrapper->field_breedte->set($new_breedte);
    $line_item_wrapper->save();
  }
}

function fc_minimum_invoice_amount($order_wrapper) {
  $no_minimum_invoice_amount = $order_wrapper->field_client->field_no_minimum_invoice_amount->value();

  $minimum = variable_get('fc_minimum_order_amount') * 100000;
  $total = _fc_get_total($order_wrapper);

  // We set everything on the commerce discount line item
  foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
    if($line_item_wrapper->type->value() === 'commerce_discount') {
      _fc_reset_minimum_invoice_amount_components($line_item_wrapper);

      if($total < $minimum && !$no_minimum_invoice_amount) {
        _fc_add_minimum_invoice_amount_components($line_item_wrapper, $minimum - $total);
      }
    }
  }
}

function fc_niet_stock_standaardprofiel($line_item_wrapper) {
  // Data to work with
  $quantity = $line_item_wrapper->quantity->value();
  $order_length = $line_item_wrapper->field_lengte->value();
  $price_afwerking = $line_item_wrapper->commerce_product->commerce_price->amount->value();

  // Calculate number of full profiles needed
  $afwerking_length = $quantity * $order_length;
  $num_profiles = ceil($afwerking_length / FC_PROFILE_LENGTH);

  $total_price = $num_profiles * $price_afwerking * FC_PROFILE_LENGTH / 1000;

  // Calculate the price for the knippen
  $total_price_knippen = _fc_get_knippen_price($quantity, $order_length);

  // Calculate the total price per unit and set it
  // $total = ($total_price_afwerking + $total_price_brut + $total_price_knippen) / $quantity;
  $total = ($total_price + $total_price_knippen) / $quantity;
  set_total_price($line_item_wrapper, $total);
}

function fc_stock_standaardprofiel($line_item_wrapper) {
  // Data to work with
  $quantity = $line_item_wrapper->quantity->value();
  $order_length = $line_item_wrapper->field_lengte->value();
  $price_afwerking = $line_item_wrapper->commerce_product->commerce_price->amount->value();

  $afwerking_length = $quantity * $order_length;
  $total_price_knippen = _fc_get_knippen_price($quantity, $order_length, true);

  // Calculate the number of 3000 and 6000 profiles
  $num_profiles3 = 0;
  $num_profiles6 = 0;
  $rest_profile3 = FC_PROFILE_LENGTH/2;
  $rest_profile6 = FC_PROFILE_LENGTH;

  $rest = $afwerking_length;
  for($i = 0; $i < $quantity; $i++) {
    if($rest < FC_PROFILE_LENGTH/2 && $rest_profile6 < FC_PROFILE_LENGTH/2) {
      if($rest_profile3 === FC_PROFILE_LENGTH/2) $num_profiles3++;
      if($rest_profile3 < $order_length) {
        $rest_profile3 = FC_PROFILE_LENGTH/2;
        $num_profiles3++;
      }
      $rest_profile3 -= $order_length;
    } else {
      if($rest_profile6 === FC_PROFILE_LENGTH) $num_profiles6++;
      if($rest_profile6 < $order_length) {
        $rest_profile6 = FC_PROFILE_LENGTH;
        $num_profiles6++;
      }
      $rest_profile6 -= $order_length;
    }
    $rest -= $order_length;
  }

  $total_price = $num_profiles3 * $price_afwerking * FC_PROFILE_LENGTH / 2000
               + $num_profiles6 * $price_afwerking * FC_PROFILE_LENGTH / 1000;

  // Calculate the total price per unit and set it
  $total = ($total_price + $total_price_knippen) / $quantity;
  set_total_price($line_item_wrapper, $total);
}

function set_total_price($line_item_wrapper, $total) {
  $total_price = commerce_round(COMMERCE_ROUND_HALF_UP, $total);
  $line_item_wrapper->commerce_unit_price->amount->set($total_price);
  $data = $line_item_wrapper->commerce_unit_price->data->value();
  $data['components'][0]['price']['amount'] = $total_price;
  $line_item_wrapper->commerce_unit_price->data->set($data);
}

function _fc_get_knippen_price($quantity, $order_length) {
  $num_knippen = _fc_get_num_knippen($quantity, $order_length);
  $pruduct_knip = commerce_product_load_by_sku('EH-knip');
  $product_knip_wrapper = entity_metadata_wrapper('commerce_product', $pruduct_knip);
  $price_knip = $product_knip_wrapper->commerce_price->amount->value();
  return $num_knippen * $price_knip;
}

function _fc_get_num_knippen($quantity, $order_length, $is_stock = false) {
  // If the length is 6000, there should be no knippen
  if($order_length == FC_PROFILE_LENGTH) {
    return 0;
  }

  // If the length is 3000 for stock, there should also be no knippen
  if($is_stock && $order_length == FC_PROFILE_LENGTH/2) {
    return 0;
  }

  // The maximum number of knippen is the quantity
  $num_knippen = $quantity + 1;

  // For every full profile that holds an exact number of parts we substract 1 knip
  // Olivier wants this optimisation out
  // $afwerking_length = $quantity * $order_length;
  // $num_full_profiles = floor($afwerking_length / FC_PROFILE_LENGTH);
  // if(FC_PROFILE_LENGTH % $order_length === 0) {
  //   $num_knippen -= $num_full_profiles;
  // }

  return $num_knippen;
}

/**
 * Resets minimum invoice components on the unit price of a line item
 *
 * @param $line_item_wrapper
 *   The wrapper around the line item
 */
function _fc_reset_minimum_invoice_amount_components($line_item_wrapper) {
  $data = $line_item_wrapper->commerce_unit_price->data->value();

  // First remove all minimum_invoice_amount components
  foreach ($data['components'] as $key => $component) {
    if($component['name'] === 'minimum_invoice_amount') {
      unset($data['components'][$key]);
    }
  }

  // We reindex the array to win a beauty contest
  $data['components'] = array_values($data['components']);

  // We update the wrapper with the resetted data
  $line_item_wrapper->commerce_unit_price->data = $data;

  // Save the changes
  $line_item_wrapper->save();
}


/**
 * Adds minimum invoice amount components to the unit price of a line item
 *
 * There are 2 parts that need to be added
 * - The difference between the minimum invoice amount and the order total
 * - The Global discount part on this difference
 *
 * @param $line_item_wrapper
 *   The wrapper around the line item
 * @param $extra_price
 *   The difference between the minimum invoice amount and the order total
 */
function _fc_add_minimum_invoice_amount_components($line_item_wrapper, $extra_price) {
  // Add the extra price component
  $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add(
    $line_item_wrapper->commerce_unit_price->value(),
    'minimum_invoice_amount',
    array(
      'amount' => $extra_price,
      'currency_code' => 'EUR',
      'data' => array(),
    ),
    TRUE
  );

  $line_item = $line_item_wrapper->value();
  $discount_name = $line_item->data['discount_name'];
  $discount = entity_metadata_wrapper('commerce_discount', $discount_name);
  $pct = intval($discount->commerce_discount_offer->commerce_percentage->value());

  // Add the extra discount component
  $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add(
    $line_item_wrapper->commerce_unit_price->value(),
    // Comment 1st out to have the minimum invoice amount also include the discount part
    // Comment 2nd out to add the minimum invoice amount discount part to the global discount
    "discount|$discount_name",
    // 'minimum_invoice_amount',
    array(
      'amount' => $pct * $extra_price / -100,
      'currency_code' => 'EUR',
      // Comment 1st out to have the minimum invoice amount also include the discount part
      // Comment 2nd out to add the minimum invoice amount discount part to the global discount
      'data' => array(
        'discount_name' => $discount_name,
        'discount_component_title' => t('Korting: -!pct%', array('!pct' => $pct)),
      ),
      // 'data' => array(),
    ),
    TRUE
  );

  // Finally save the line item
  $line_item_wrapper->save();
}


/**
 * Gets the total of an order
 *
 * @param $order_wrapper
 *   The order in a wrapper
 */
function _fc_get_total($order_wrapper) {
  $total = 0;
  foreach ($order_wrapper->commerce_line_items as $line_item) {
    if($line_item->type->value() !== 'commerce_discount') {
      $total +=  $line_item->commerce_total->amount->value();
    }
  }

  return $total;
}

function _fc_update_discount($line_item_wrapper, $discount_amount) {
  $line_item = $line_item_wrapper->value();
  $line_item->commerce_unit_price['und'][0]['amount'] = $discount_amount;
  $line_item->commerce_unit_price['und'][0]['data']['components'][1]['price']['amount'] = $discount_amount;
  $line_item->commerce_total['und'][0]['amount'] = $discount_amount;
  $line_item->commerce_total['und'][0]['data']['components'][1]['price']['amount'] = $discount_amount;
}

function _fc_apply_staffelkorting($order_wrapper) {
  module_load_include('inc', 'commerce_discount', 'commerce_discount.rules');
  $default = 'discount_global_discount_0_200';
  $discounts = feneko_calculator_get_discounts();

  // Get the order-staffelkorting (pct) that should be applied normally based
  // on the sum of the amount for non-standaardprofiel
  $amount = 0;
  foreach ($order_wrapper->commerce_line_items->getIterator() as $line_item_wrapper) {
    $type = $line_item_wrapper->type->value();
    if($type !== 'standaardprofiel' and $type !== 'commerce_discount') {
      $amount = $amount + $line_item_wrapper->commerce_total->amount->value();
    }
  }
  $order_sk_pct = _feneko_calculator_get_normal_discount($amount, $discounts);

  // Get client-staffelkorting (pct)
  $client_sk_name = $order_wrapper->field_client->field_staffelkorting->value();
  $client_sk_name = empty($client_sk_name) ? $default : $client_sk_name;
  $client_sk_wrapper = entity_metadata_wrapper('commerce_discount', $client_sk_name);
  $client_sk_pct  = intval($client_sk_wrapper->commerce_discount_offer->commerce_percentage->value());

  foreach ($discounts as $discount_name => $discount) {
    // If the client-staffelkorting is more than the order-staffelkorting, the
    // client-staffelkorting has to be chosen. Otherwise the order-staffelkorting has to be chosen
    if($client_sk_pct >= $order_sk_pct) {
      // If the staffelkorting has to be chosen, only choose the one if the
      // current name equals that staffelkorting
      if($client_sk_name === $discount_name) {
        commerce_discount_percentage($order_wrapper, $discount_name);
        break;
      }
    } else {
      // Get the discount pct for this discount
      $discount_pct = intval($discount['wrapper']->commerce_discount_offer
                                                 ->commerce_percentage->value());

      // if normal discount === discount of this discount return
      if($order_sk_pct === $discount_pct) {
        commerce_discount_percentage($order_wrapper, $discount_name);
        break;
      }
    }
  }

  // Search the staffelkorting in the line items and update the amount with the
  // amount based on the non-standaardprofiel
  $discount_pct = $client_sk_pct >= $order_sk_pct ? $client_sk_pct : $order_sk_pct;
  $discount_amount = $amount * $discount_pct / -100;
  foreach ($order_wrapper->commerce_line_items->getIterator() as $line_item_wrapper) {
    if($line_item_wrapper->type->value() === 'commerce_discount'
    and $line_item_wrapper->value()->data['discount_name'] !== 'discount_klantenkorting') {
      _fc_update_discount($line_item_wrapper, $discount_amount);
    }
  }
}

function _fc_apply_klantenkorting($order_wrapper) {
  // TODO Take from DB
  $klantenkorting_pct = 20;

  // Get the sum of all standaardprofielen
  $amount = 0;
  foreach ($order_wrapper->commerce_line_items->getIterator() as $line_item_wrapper) {
    if($line_item_wrapper->type->value() === 'standaardprofiel') {
      $amount = $amount + $line_item_wrapper->commerce_total->amount->value();
    }
  }

  // Search the klantenkorting in the line items and update the amount with the
  // amount based on the standaardprofiel
  $discount_amount = $amount * $klantenkorting_pct / -100;
  foreach ($order_wrapper->commerce_line_items->getIterator() as $line_item_wrapper) {
    if($line_item_wrapper->type->value() === 'commerce_discount'
    and $line_item_wrapper->value()->data['discount_name'] === 'discount_klantenkorting') {
      _fc_update_discount($line_item_wrapper, $discount_amount);
    }
  }

}

function fc_apply_korting($order_wrapper) {
  _fc_apply_staffelkorting($order_wrapper);
  _fc_apply_klantenkorting($order_wrapper);
}


function _feneko_calculator_get_normal_discount($amount, $discounts) {
  foreach ($discounts as $discount_name => $discount) {
    if($amount > $discount['low']
     and ($amount <= $discount['high'] or !$discount['high'])) {
      return $discount['pct'];
    }
  }
}


function feneko_calculator_get_discounts() {
  $limits = array();

  // Get all order discounts
  $results = db_select('commerce_discount')->fields(NULL, array('name'))
           ->condition('name', 'discount_klantenkorting', '<>')
           ->condition('type', 'order_discount')
           ->orderBy('component_title')
           ->execute();

  foreach ($results as $discount) {
    $discount_wrapper = entity_metadata_wrapper('commerce_discount', $discount->name);
    preg_match("/([0-9]*)-([0-9]*)/", $discount_wrapper->label->value(), $matches);

    $pct = intval($discount_wrapper->commerce_discount_offer
                                                ->commerce_percentage->value());

    $limits[$discount->name] = array(
      'low'  => intval($matches[1])  * 100000,
      'high' => intval($matches[2]) * 100000,
      'pct'  => $pct,
      'wrapper' => $discount_wrapper,
    );
  }

  return $limits;
}
