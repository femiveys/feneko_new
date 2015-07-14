<?php
/**
 * @file
 * feneko_calculator_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feneko_calculator_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|user|user|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '11',
    'children' => array(
      0 => 'field_btw_nummer',
      1 => 'field_telefoon',
      2 => 'field_naam_bedrijf',
      3 => 'field_klantennummer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_order_info|commerce_order|commerce_order|default';
  $field_group->group_name = 'group_order_info';
  $field_group->entity_type = 'commerce_order';
  $field_group->bundle = 'commerce_order';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Order Info',
    'weight' => '9',
    'children' => array(
      0 => 'field_color',
      1 => 'field_comment',
      2 => 'field_reference',
      3 => 'field_maritime',
      4 => 'field_order_type',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Order Info',
      'instance_settings' => array(
        'classes' => 'order-info',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_order_info|commerce_order|commerce_order|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_order_info|commerce_order|commerce_order|form';
  $field_group->group_name = 'group_order_info';
  $field_group->entity_type = 'commerce_order';
  $field_group->bundle = 'commerce_order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Order specific information',
    'weight' => '0',
    'children' => array(
      0 => 'field_comment',
      1 => 'field_reference',
      2 => 'field_order_type',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Order specific information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-order-info field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_order_info|commerce_order|commerce_order|form'] = $field_group;

  return $export;
}
