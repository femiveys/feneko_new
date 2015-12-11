<?php
/**
 * @file
 * feneko_translations.features.translations_nl.inc
 */

/**
 * Implements hook_translations_nl_defaults().
 */
function feneko_translations_translations_nl_defaults() {
  $translations = array();
  $translatables = array();
  $translations['nl:default']['33be3953588cc10edb3d6341919109b9'] = array(
    'source' => 'Order specific information',
    'context' => '',
    'location' => '/nl/admin/structure/features/feneko_calculator_feature/recreate?render=overlay',
    'translation' => 'Bestellingsspecifieke informatie',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Order specific information', array(), array('context' => ''));
  $translations['nl:default']['ad921d60486366258809553a3db49a4a'] = array(
    'source' => 'unknown',
    'context' => '',
    'location' => '/fr/user/1/feneko_orders?sort=desc&order=Fase%3Cspan%20class%3D%22help%22%3E%3C/span%3E',
    'translation' => 'onbekend',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('unknown', array(), array('context' => ''));
  return $translations;
}
