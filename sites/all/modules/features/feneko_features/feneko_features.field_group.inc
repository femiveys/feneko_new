<?php
/**
 * @file
 * feneko_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feneko_features_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bestellen|node|product|form';
  $field_group->group_name = 'group_bestellen';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prijzen en bestelformulieren',
    'weight' => '9',
    'children' => array(
      0 => 'field_bijlage_secured',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prijzen en bestelformulieren',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-bestellen field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_bestellen|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prijs_levering|node|product|default';
  $field_group->group_name = 'group_prijs_levering';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prijzen en levering',
    'weight' => '8',
    'children' => array(
      0 => 'field_levertermijn',
      1 => 'field_bijlage_secured',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prijzen en levering',
      'instance_settings' => array(
        'classes' => 'group-tech-info group-prijs-levering field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_prijs_levering|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tech_info|node|product|default';
  $field_group->group_name = 'group_tech_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technisch',
    'weight' => '7',
    'children' => array(
      0 => 'field_technische_informatie',
      1 => 'field_technische_tekening',
      2 => 'field_technische_documenten',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Technisch',
      'instance_settings' => array(
        'id' => 'node_product_full_group_tech_info',
        'classes' => ' group-tech-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_tech_info|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technische_info|node|product|form';
  $field_group->group_name = 'group_technische_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technische informatie',
    'weight' => '8',
    'children' => array(
      0 => 'field_technische_informatie',
      1 => 'field_technische_tekening',
      2 => 'field_technische_documenten',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => ' group-technische-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_technische_info|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_versies|node|product|form';
  $field_group->group_name = 'group_versies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Versies',
    'weight' => '7',
    'children' => array(
      0 => 'field_basic_product',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Versies',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-versies field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_versies|node|product|form'] = $field_group;

  return $export;
}
