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
    'fc_apply_staffel_korting' => array(
      'label' => t('Apply staffel korting'),
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
  $minimum = variable_get('fc_minimum_order_amount') * 100000;
  $total = _fc_get_total($order_wrapper);

  // We set everything on the commerce discount line item
  foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
    if($line_item_wrapper->type->value() === 'commerce_discount') {
      _fc_reset_minimum_invoice_amount_components($line_item_wrapper);

      if($total < $minimum) {
        _fc_add_minimum_invoice_amount_components($line_item_wrapper, $minimum - $total);
      }
    }
  }
}

function fc_niet_stock_standaardprofiel($line_item_wrapper) {
  // Data to work with
  $quantity = $line_item_wrapper->quantity->value();
  $order_length = $line_item_wrapper->field_lengte->value();
  $discrete_length = $line_item_wrapper->field_standaardprofiel_lengte->value();
  $price_afwerking = $line_item_wrapper->commerce_product->commerce_price->amount->value();

  // Calculate number of full profiles needed
  $afwerking_length = $quantity * $order_length;
  $num_profiles = ceil($afwerking_length / FC_PROFILE_LENGTH);

  // Calculate the afwerking price
  $total_price_afwerking = $price_afwerking * $afwerking_length / 1000;

  // Calculate the brut price
  $sku_brut = preg_replace("/-ral$|-str$/", "-brut", $line_item_wrapper->commerce_product->sku->value());
  $product_brut = commerce_product_load_by_sku($sku_brut);
  $product_brut_wrapper = entity_metadata_wrapper('commerce_product', $product_brut);
  $price_brut = $product_brut_wrapper->commerce_price->amount->value();
  $brut_length = $num_profiles * FC_PROFILE_LENGTH - $afwerking_length;
  $total_price_brut = $price_brut * $brut_length / 1000;

  // Calculate the price for the knippen
  $num_knippen = _fc_get_num_knippen($quantity, $order_length);
  $pruduct_knip = commerce_product_load_by_sku('EH-knip');
  $product_knip_wrapper = entity_metadata_wrapper('commerce_product', $pruduct_knip);
  $price_knip = $product_knip_wrapper->commerce_price->amount->value();
  $total_price_knippen = $num_knippen * $price_knip;

  // Calculate the total price per unit and set it
  $total = ($total_price_afwerking + $total_price_brut + $total_price_knippen) / $quantity;
  $total = commerce_round(COMMERCE_ROUND_HALF_UP, $total);
  $line_item_wrapper->commerce_unit_price->amount->set($total);
  $data = $line_item_wrapper->commerce_unit_price->data->value();
  $data['components'][0]['price']['amount'] = $total;
  $line_item_wrapper->commerce_unit_price->data->set($data);
}

function _fc_get_num_knippen($quantity, $order_length) {
  // If the length is 6000, there should be no knippen
  if($order_length === FC_PROFILE_LENGTH) {
    return 0;
  }

  // The maximum number of knippen is the quantity
  $num_knippen = $quantity;

  // For every full profile that holds an exact number of parts we substract 1 knip
  $afwerking_length = $quantity * $order_length;
  $num_full_profiles = floor($afwerking_length / FC_PROFILE_LENGTH);
  if(FC_PROFILE_LENGTH % $order_length === 0) {
    $num_knippen -= $num_full_profiles;
  }

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
    if($component['name'] === 'minimum_invoice_amount'
      // || substr($component['name'], 0, 8) === 'discount'
    ) {
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


function fc_apply_staffel_korting($order_wrapper) {
  module_load_include('inc', 'commerce_discount', 'commerce_discount.rules');
  $default = 'discount_global_discount_0_200';
  $discounts = feneko_calculator_get_discounts();

  // Get the amount in the order
  $amount = $order_wrapper->commerce_order_total->amount->value();

  // Retrieve the discount (pct) that should be applied normally based on the amount
  $normal_discount_pct = _feneko_calculator_get_normal_discount($amount, $discounts);

  // Get the staffelkorting (pct) for this user (owner of order)
  $sk_name = $order_wrapper->field_client->field_staffelkorting->value();
  $sk_name = empty($sk_name) ? $default : $sk_name;
  $sk_wrapper = entity_metadata_wrapper('commerce_discount', $sk_name);
  $sk_pct  = intval($sk_wrapper->commerce_discount_offer->commerce_percentage->value());

  foreach ($discounts as $discount_name => $discount) {
    // Get the discount pct for this discount
    $discount_pct = intval($discount['wrapper']->commerce_discount_offer
                                               ->commerce_percentage->value());

    // If the staffelkorting is more than the discount applied normally, the
    // staffelkorting has to be chosen. Otherwise a normal discount has to be chosen
    if($sk_pct >= $normal_discount_pct) {
      // If the staffelkorting has to be chosen, only choose the one if the
      // current name equals that staffelkorting
      if($sk_name === $discount_name) {
        commerce_discount_percentage($order_wrapper, $discount_name);
        return;
      }
    } else {
      // if normal discount === discount of this discount return true
      if($normal_discount_pct === $discount_pct) {
        commerce_discount_percentage($order_wrapper, $discount_name);
        return;
      }
    }
  }
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
           ->condition('type', 'order_discount')
           ->orderBy('component_title')
           ->execute();

  foreach ($results as $discount) {
    $discount_wrapper = entity_metadata_wrapper('commerce_discount', $discount->name);
    preg_match("/([0-9]*)-([0-9]*)/", $discount_wrapper->label->value(), $matches);

    $pct = intval($discount_wrapper->commerce_discount_offer
                                                ->commerce_percentage->value());

    $limits[$discount->name] = array(
      'low'  => $matches[1]  * 100000,
      'high' => $matches[2] * 100000,
      'pct'  => $pct,
      'wrapper' => $discount_wrapper,
    );
  }

  return $limits;
}
