<?php
/**
 * @file
 * feneko_account.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feneko_account_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feneko_account_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feneko_account_node_info() {
  $items = array(
    'client' => array(
      'name' => t('Klant'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Naam'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
