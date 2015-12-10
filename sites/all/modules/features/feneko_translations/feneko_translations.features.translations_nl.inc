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
  return $translations;
}
