<?php
/**
 * @file
 * feneko_structure.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feneko_structure_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_algemeen|node|info_pagina|form';
  $field_group->group_name = 'group_algemeen';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_pagina';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_informatie';
  $field_group->data = array(
    'label' => 'algemeen',
    'weight' => '3',
    'children' => array(
      0 => 'field_adres',
      1 => 'field_fax',
      2 => 'field_e_mail',
      3 => 'field_tel',
      4 => 'field_about',
      5 => 'field_afbeelding',
      6 => 'field_route',
      7 => 'field_social_follow',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_algemeen|node|info_pagina|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doc_tab|node|product|default';
  $field_group->group_name = 'group_doc_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Technical documents',
    'weight' => '6',
    'children' => array(
      0 => 'field_tech_docs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Technical documents',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_doc_tab|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_draw_tab|node|product|default';
  $field_group->group_name = 'group_draw_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Technical drawing',
    'weight' => '4',
    'children' => array(
      0 => 'field_tech_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Technical drawing',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_draw_tab|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_front|node|info_pagina|form';
  $field_group->group_name = 'group_front';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_pagina';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_informatie';
  $field_group->data = array(
    'label' => 'big image front',
    'weight' => '4',
    'children' => array(
      0 => 'field_big_image',
      1 => 'field_tekst_big_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_front|node|info_pagina|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_tab|node|product|default';
  $field_group->group_name = 'group_info_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Technical information',
    'weight' => '5',
    'children' => array(
      0 => 'field_tech_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Technical information',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_info_tab|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_informatie|node|info_pagina|form';
  $field_group->group_name = 'group_informatie';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_pagina';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'informatie',
    'weight' => '2',
    'children' => array(
      0 => 'group_algemeen',
      1 => 'group_front',
      2 => 'group_sales',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-informatie field-group-htabs',
      ),
    ),
  );
  $export['group_informatie|node|info_pagina|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sales|node|info_pagina|form';
  $field_group->group_name = 'group_sales';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_pagina';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_informatie';
  $field_group->data = array(
    'label' => 'Sales info',
    'weight' => '5',
    'children' => array(
      0 => 'field_openingsuren',
      1 => 'field_klant_worden',
      2 => 'field_disclaimer',
      3 => 'field_verkoopsvoorwaarden',
      4 => 'field_levertijden',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sales field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_sales|node|info_pagina|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper|node|product|default';
  $field_group->group_name = 'group_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'group_doc_tab',
      1 => 'group_info_tab',
      2 => 'group_draw_tab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-wrapper field-group-htabs',
      ),
    ),
  );
  $export['group_wrapper|node|product|default'] = $field_group;

  return $export;
}
