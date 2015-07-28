<?php
/**
 * @file
 * feneko_global.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feneko_global_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_default_export_path';
  $strongarm->value = 'sites/all/modules/features';
  $export['features_default_export_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'nl',
    'name' => 'Dutch',
    'native' => 'NL',
    'direction' => '0',
    'enabled' => 1,
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'nl',
    'weight' => '-10',
    'javascript' => 'Zr__OgYDyyoduQS1sQJbK4cQKgnUzD0B5yKfRx0kFB4',
  );
  $export['language_default'] = $strongarm;

  return $export;
}
