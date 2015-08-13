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
    'module' => 'views',
    'node_types' => array(
      0 => 'dorpel_anti_dreunstrook',
      1 => 'dorpel_eindstuk',
      2 => 'dorpel_hoek',
      3 => 'dorpel_koppelstuk',
      4 => 'muurkap',
      5 => 'plaatbewerking',
      6 => 'raamtablet',
      7 => 'sandwichpaneel',
      8 => 'standaardprofiel',
      9 => 'stuk',
      10 => 'unit',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'shopping_cart',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -15,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
