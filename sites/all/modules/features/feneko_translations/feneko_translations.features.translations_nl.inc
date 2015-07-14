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
  $translations['nl:default']['10b9486648b56ba44ab65c59df05dde5'] = array(
    'source' => 'Borstelprofiel VP1200',
    'context' => '',
    'location' => '/nl/vliegenraam-basic/bestel',
    'translation' => 'Borstelprofiel VP1200',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Borstelprofiel VP1200', array(), array('context' => ''));
  return $translations;
}
