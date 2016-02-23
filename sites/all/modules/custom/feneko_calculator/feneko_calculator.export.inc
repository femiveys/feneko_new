<?php

/**
 * Sends the XML export to the browser for immediate download
 *
 * @param stdClass $order
 */
function feneko_calculator_xml(stdClass $order) {
    header("Content-type: application/octet-stream");
    header("Content-Disposition: attachment; filename=\"order_" . $order->order_id . ".xml\"");
    echo feneko_calculator_order_to_xml($order);
    exit;
}

/**
 * Transforms an order into an XML string
 *
 * @param stdClass $order
 *
 * @return string The formatted XML
 */
function feneko_calculator_order_to_xml(stdClass $order) {
  module_load_include('inc', 'feneko_calculator', 'extra_fields');
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  $xml = "<Order>";

  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'order_id');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'status');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'created');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'changed');

  $xml .= "<Client>";
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->field_client, 'title', 'Name');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->field_client, 'field_client_number');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->field_client, 'field_tva_number');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->field_client, 'field_phone');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->field_client, 'field_block_order_input');
  $xml .= "</Client>";

  // $xml .= _feneko_calculator_add_xml_field($order_wrapper->field_client, 'field_client_number', 'Klantennummer');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_color');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_comment');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_reference');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_maritime');

  $xml .= "<Owner>";
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'uid');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'name');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'mail');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'language');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_phone');
  $xml .= "</Owner>";

  foreach ($order_wrapper->commerce_line_items as $delta => $line) {
    if($line->type->value() !== 'commerce_discount') {
      $xml .= "<Item>";
      $xml .= _feneko_calculator_add_xml_field($line, 'line_item_id');
      $xml .= _feneko_calculator_add_xml_field($line, 'quantity');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'type', 'ProductType');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'sku');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'product_id');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'title');
      $xml .= fc_line_item_details($line->value(), 'xml');
      $xml .= "</Item>";
    }
  }

  $totals = _fc_totals_order($order_wrapper);
  $xml .= "<SubTotal><Raw>" . $totals['raw']['subtotal'] . "</Raw>";
  $xml .= "<Formatted>" . $totals['formatted']['subtotal'] . "</Formatted></SubTotal>";
  $xml .= "<Total><Raw>" . $totals['raw']['total'] . "</Raw>";
  $xml .= "<Formatted>" . $totals['formatted']['total'] . "</Formatted></Total>";
  $xml .= "</Order>";

  // Pretty print the XML
  $dom = new DOMDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);
  $dom->formatOutput = TRUE;

  return $dom->saveXml();
}

/**
 * Helper function to add a field to an XML string
 *
 * If it is a multivaluefield, the first value is taken.
 *
 * @param EntityMetadataWrapper $wrapper The wrapper holding the field to
 *                                       transform into a tag
 * @param string $name The name of the field. Field names starting with
 *                     "field_" will get a tag name without the field_ prefix
 * @param string $tag_override Name of the tag if it needs to be overridden
 *
 * @return string The XML tag
 */
function _feneko_calculator_add_xml_field(EntityMetadataWrapper $wrapper, $name,
                                                         $tag_override = NULL) {
  $tag = isset($tag_override) ? $tag_override : camelCase(str_replace('field_', '', $name));
  if(!empty($wrapper->$name->value())) {
    $value = $wrapper->$name->value();
    if(is_array($value)) {
      $value = $value[0];
    }
    return "<$tag>" . htmlspecialchars($value) . "</$tag>";
  }
}

/**
 * Sends the TXT export to the browser for immediate download
 *
 * @param stdClass $order
 */
function feneko_calculator_txt(stdClass $order) {
    header("Content-type: text/plain");
    header("Content-Disposition: attachment; filename=\"order_" . $order->order_id . ".txt\"");
    echo feneko_calculator_order_to_txt($order);
    exit;
}

/**
 * Transforms an order into an TXT string
 *
 * @param stdClass $order
 *
 * @return string The formatted TXT
 */
function feneko_calculator_order_to_txt(stdClass $order) {
  module_load_include('inc', 'feneko_calculator', 'extra_fields');
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $totals = _fc_totals_order($order_wrapper);
  $discounts = '';

  $arr = array(
    _feneko_calculator_add_txt_field($order_wrapper, 'order_id'),
    _feneko_calculator_add_txt_field($order_wrapper->field_client, 'field_client_number'),
    _feneko_calculator_add_txt_field($order_wrapper, 'field_reference'),
    _feneko_calculator_add_txt_field($order_wrapper, 'changed'),
    fc_price($totals['raw']['subtotal']),
    fc_price($totals['raw']['subtotal'] - $totals['raw']['total']),
    _feneko_calculator_add_txt_field($order_wrapper->owner, 'name'),
    _feneko_calculator_add_txt_field($order_wrapper->owner, 'mail'),
    _feneko_calculator_add_txt_field($order_wrapper, 'field_maritime'),
  );

  $txt = arrayToCsv($arr) . "\n";

  foreach ($order_wrapper->commerce_line_items as $delta => $line) {
    $linePrice = _feneko_calculator_add_txt_field($line, 'commerce_total');
    if($line->type->value() === 'commerce_discount') {
      // $sections = _fc_get_discount_sections($line->commerce_unit_price->data->value());

      // foreach ($sections as $section) {
      //   dpm($section);
      //   $discounts .= '<tr class="' . $section['key'] . '">';
      //   $discounts .= '<td colspan="4">' . $section['label'] . '</td>';
      //   $discounts .= '<td>' . $section['price'] . '</td>';
      //   $discounts .= '</tr>';
      // }
    } else {
      $arr = array(
        _feneko_calculator_add_txt_field($line, 'line_item_id'),
        _feneko_calculator_add_txt_field($line->commerce_product, 'type'),
        _feneko_calculator_add_txt_field($order_wrapper, 'field_color'),
        fc_price($linePrice['amount']),
        // LakOpp
        round(_feneko_calculator_add_txt_field($line, 'quantity')),
      );

      switch ($line->commerce_product->type->value()) {
        case 'plaatbewerking':
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_type_bewerking');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_lakzijde');
          $arr = array_merge(
            $arr,
            _feneko_calculator_add_txt_field($line, 'field_multi_breedte'),
            _feneko_calculator_add_txt_field($line, 'field_multi_hoek')
          );

          $arr[] = _feneko_calculator_add_txt_field($line, 'field_lengte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_breedte')
                    * _feneko_calculator_add_txt_field($line, 'field_lengte');
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_plaatbewerking_dikte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_plooien');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_ophanging');
          break;

        case 'standaardprofiel':
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_standaardprofiel_type');
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_maat');
          // ProfielID
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_lengte');
          // Ophanging
          break;

        case 'sandwichpaneel':
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_lengte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_breedte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_isolatie_dikte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_bicolor_kleur');
          break;

        case 'raamtablet':
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_rug');
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_raamtablet_diepte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_lengte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_gaatjes_rug');
          $arr = array_merge(
            $arr,
            _feneko_calculator_add_txt_field($line, 'field_eindstukken'),
            _feneko_calculator_add_txt_field($line, 'field_hoeken')
          );
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_koppelstukken');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_anti_dreunstrook');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_aantal_adsn');
          break;

        case 'muurkap':
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_muurkap_type');
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_muurkap_diepte');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_lengte');
          $arr = array_merge(
            $arr,
            _feneko_calculator_add_txt_field($line, 'field_eindstukken'),
            _feneko_calculator_add_txt_field($line, 'field_hoeken')
          );
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_koppelstukken');
          $arr[] = _feneko_calculator_add_txt_field($line, 'field_beugels');
          break;

        case 'muurkap_eindstuk':
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_muurkap_type');
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_muurkap_diepte');
          $arr[] = _feneko_calculator_add_txt_field($line->commerce_product, 'field_mke_type');
          break;
      }

      $txt .= arrayToCsv($arr) . "\n";
    }
  }

  return $txt;
}

function _feneko_calculator_add_txt_field(EntityMetadataWrapper $wrapper, $name) {
    $jaNeeFields = array('field_gaatjes_rug');
    $value = $wrapper->$name->value();

    // Make sure booleans or other fields are returned as ja or nee
    if(is_bool($value) || in_array($name, $jaNeeFields)) {
        $value = $value ? 'ja' : 'nee';
    }
    return $value;
}

/**
  * Formats a line (passed as a fields  array) as CSV and returns the CSV as a string.
  * Adapted from http://us3.php.net/manual/en/function.fputcsv.php#87120
  */
function arrayToCsv( array &$fields, $delimiter = ';', $enclosure = '"', $encloseAll = false, $nullToMysqlNull = false ) {
  $delimiter_esc = preg_quote($delimiter, '/');
  $enclosure_esc = preg_quote($enclosure, '/');

  $output = array();
  foreach ( $fields as $field ) {
    if ($field === null && $nullToMysqlNull) {
      $output[] = 'NULL';
      continue;
    }

    // Enclose fields containing $delimiter, $enclosure or whitespace
    if ( $encloseAll || preg_match( "/(?:${delimiter_esc}|${enclosure_esc}|\s)/", $field ) ) {
      $output[] = $enclosure . str_replace($enclosure, $enclosure . $enclosure, $field) . $enclosure;
    }
    else {
      $output[] = $field;
    }
  }

  return implode( $delimiter, $output );
}

function fc_price($price) {
  if(empty($price)) {
    return 0;
  } else {
    $multiplyer = pow(10, 5);
    return round($price/$multiplyer, 2);
  }
}

function _fc_get_discount_sections($data) {
  $sections = array();
  $mapping = commerce_price_component_titles();

  foreach ($data['components'] as $component) {
    $key = $component['name'];
    $sections[$key] = array();
    if($key === 'minimum_invoice_amount') {
      $sections[$key]['weight'] = 0;
      $sections[$key]['key'] = $key;
      $sections[$key]['label'] = $mapping[$key];
      _fc_set_price($sections[$key], $component['price']['amount']);
    } elseif (substr($key, 0, 9) === 'discount|') {
      $sections[$key]['weight'] = 10;
      $sections[$key]['key'] = drupal_clean_css_identifier($component['price']['data']['discount_name']);
      $sections[$key]['label'] = $component['price']['data']['discount_component_title'];
      _fc_set_price($sections[$key], $component['price']['amount']);
    }
  }

  // Set the price in a readible way
  foreach ($sections as &$section) {
    $section['price'] = _fc_format_amount($section['price']);
  }

  // Sort the array
  uasort($sections, 'drupal_sort_weight');

  return $sections;
}

function _fc_set_price(&$section, $price) {
  if(isset($section['price'])) {
    $section['price'] += $price;
  } else {
    $section['price'] = $price;
  }
}

