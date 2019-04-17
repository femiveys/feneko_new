<?php

/**
 * @file
 * feneko_structure.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feneko_structure_taxonomy_default_vocabularies() {
  return array(
    'product_category' => array(
      'name' => 'Product category',
      'machine_name' => 'product_category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 32768,
      'base_i18n_mode' => 32768,
      'base_language' => 'und',
      'base_type' => 'taxonomy_vocabulary',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
      'base_type' => 'taxonomy_vocabulary',
    ),
  );
}
