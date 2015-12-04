<?php
/**
 * @file
 * feneko_calculator_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feneko_calculator_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-98643495f0710babea3fc27079ddaf6f'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '98643495f0710babea3fc27079ddaf6f',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'shopping_cart',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -18,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
