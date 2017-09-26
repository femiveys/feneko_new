<?php
/**
 * @file
 * feneko_account.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feneko_account_field_group_info() {
  $field_groups = array();

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
      1 => 'mimemail',
      2 => 'timezone',
      3 => 'overlay_control',
      4 => 'locale',
      5 => 'field_add_client_number',
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
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');

  return $field_groups;
}
