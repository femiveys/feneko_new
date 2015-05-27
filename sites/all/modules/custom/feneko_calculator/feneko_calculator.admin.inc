<?php
/**
 * @file
 * For settings
 */

function feneko_calculator_settings_form($form, &$form_state) {
  $form['fc_minimum_order_amount'] = array(
    '#type' => 'textfield',
    '#title' => 'Minimum facturatie bedrag',
    '#size' => 2,
    '#maxlength' => 30,
    '#field_prefix' => '€',
    '#default_value' => variable_get('fc_minimum_order_amount'),
    '#element_validate' => array('element_validate_number'),
  );

  return system_settings_form($form);
}

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
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_color');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_comment');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_reference');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_maritime');

  $xml .= "<Owner>";
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'uid');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'name');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'mail');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'language');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_naam_bedrijf');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_btw_nummer');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_klantennummer');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_telefoon');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_geblokkeerd');
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
    return "<$tag>" . $wrapper->$name->value() . "</$tag>";
  }
}
