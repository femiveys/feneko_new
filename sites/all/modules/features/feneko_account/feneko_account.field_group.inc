<?php
/**
 * @file
 * feneko_account.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feneko_account_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|user|user|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '6',
    'children' => array(
      0 => 'ckeditor',
      1 => 'timezone',
      2 => 'overlay_control',
      3 => 'locale',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_advanced|user|user|form'] = $field_group;

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
    'label' => 'Old fields',
    'weight' => '7',
    'children' => array(
      0 => 'field_btw_nummer',
      1 => 'field_klantennummer',
      2 => 'field_naam_bedrijf',
      3 => 'field_telefoon',
      4 => 'field_geblokkeerd',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Old fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contact|user|user|form'] = $field_group;

  return $export;
}
