<?php
/**
 * @file
 * feneko_calculator_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feneko_calculator_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_display_path'
  $field_bases['commerce_display_path'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_display_path',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'commerce_line_items'
  $field_bases['commerce_line_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_line_items',
    'indexes' => array(
      'line_item_id' => array(
        0 => 'line_item_id',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_line_item',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_line_item_reference',
  );

  // Exported field_base: 'commerce_order_total'
  $field_bases['commerce_order_total'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_order_total',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'commerce_price'
  $field_bases['commerce_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_product',
    ),
    'field_name' => 'commerce_price',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'commerce_product'
  $field_bases['commerce_product'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_product',
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => NULL,
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  // Exported field_base: 'commerce_total'
  $field_bases['commerce_total'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_total',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'commerce_unit_price'
  $field_bases['commerce_unit_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_unit_price',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_aantal_adsn'
  $field_bases['field_aantal_adsn'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aantal_adsn',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_anti_dreunstrook'
  $field_bases['field_anti_dreunstrook'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_anti_dreunstrook',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'VA9051' => '50mm',
        'VA9052' => '80mm',
        'VA9053' => '100mm',
        'VA9054' => '120mm',
        'VA9055' => '160mm',
        'VA9056' => '200mm',
        'VA9057' => '500mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_base_price'
  $field_bases['field_base_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_base_price',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_beugels'
  $field_bases['field_beugels'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_beugels',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_bicolor_kleur'
  $field_bases['field_bicolor_kleur'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_bicolor_kleur',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_breedte'
  $field_bases['field_breedte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_breedte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_btw_nummer'
  $field_bases['field_btw_nummer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_btw_nummer',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_color'
  $field_bases['field_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_color',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_comment'
  $field_bases['field_comment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_comment',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_eindstukken'
  $field_bases['field_eindstukken'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_eindstukken',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_gaatjes_rug'
  $field_bases['field_gaatjes_rug'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_gaatjes_rug',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Nee',
        1 => 'Ja',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_hoek_type'
  $field_bases['field_hoek_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hoek_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'binnen' => 'Binnenhoek',
        'buiten' => 'Buitenhoek',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_hoeken'
  $field_bases['field_hoeken'] = array(
    'active' => 1,
    'cardinality' => 2,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hoeken',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_isolatie_dikte'
  $field_bases['field_isolatie_dikte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_isolatie_dikte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        20 => '20mm',
        25 => '25mm',
        30 => '30mm',
        35 => '35mm',
        40 => '40mm',
        42 => '42mm',
        50 => '50mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_kant'
  $field_bases['field_kant'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_kant',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'left' => 'Links',
        'right' => 'Rechts',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_klantennummer'
  $field_bases['field_klantennummer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_klantennummer',
    'field_permissions' => array(
      'type' => 1,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_knippen'
  $field_bases['field_knippen'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_knippen',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_koppelstukken'
  $field_bases['field_koppelstukken'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_koppelstukken',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_lakzijde'
  $field_bases['field_lakzijde'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lakzijde',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'e' => 'Buitenkant',
        'i' => 'Binnenkant',
        'r' => 'Beide kanten',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_lengte'
  $field_bases['field_lengte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lengte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_maat'
  $field_bases['field_maat'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_maat',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        '100x5' => '100x5',
        '12x1' => '12x1',
        '14x1' => '14x1',
        '150x5' => '150x5',
        '15x1.5' => '15x1.5',
        '160x5' => '160x5',
        '16x1.5' => '16x1.5',
        '18x1.5' => '18x1.5',
        '19x1.5' => '19x1.5',
        '200x5' => '200x5',
        '20x1.5' => '20x1.5',
        '20x2' => '20x2',
        '20x5' => '20x5',
        '22x1.5' => '22x1.5',
        '22x2' => '22x2',
        '25x1.5' => '25x1.5',
        '25x2' => '25x2',
        '25x2.5' => '25x2.5',
        '25x3' => '25x3',
        '25x5' => '25x5',
        '28x1.5' => '28x1.5',
        '30x1.5' => '30x1.5',
        '30x2' => '30x2',
        '30x2.5' => '30x2.5',
        '30x3' => '30x3',
        '30x5' => '30x5',
        '32x1.5' => '32x1.5',
        '35x2' => '35x2',
        '35x2.5' => '35x2.5',
        '35x5' => '35x5',
        '36x1.5' => '36x1.5',
        '38x4' => '38x4',
        '40x1.5' => '40x1.5',
        '40x2' => '40x2',
        '40x2.5' => '40x2.5',
        '40x5' => '40x5',
        '4x1' => '4x1',
        '40x25x2' => '40x25x2',
        '100x18x2' => '100x18x2',
        '100x40x4' => '100x40x4',
        '100x50x3' => '100x50x3',
        '100x50x4' => '100x50x4',
        '100x50x5' => '100x50x5',
        '100x60x4' => '100x60x4',
        '120x30x3' => '120x30x3',
        '120x40x4' => '120x40x4',
        '120x60x3' => '120x60x3',
        '130x50x4' => '130x50x4',
        '140x40x3' => '140x40x3',
        '150x40x4' => '150x40x4',
        '150x50x3' => '150x50x3',
        '150x50x4' => '150x50x4',
        '200x50x4' => '200x50x4',
        '20x10x1.5' => '20x10x1.5',
        '25x15x2' => '25x15x2',
        '25x20x2' => '25x20x2',
        '30x15x1.5' => '30x15x1.5',
        '30x20x2' => '30x20x2',
        '30x25x2' => '30x25x2',
        '35x20x2' => '35x20x2',
        '35x25x2' => '35x25x2',
        '40x20x1.5' => '40x20x1.5',
        '40x20x2' => '40x20x2',
        '40x20x3' => '40x20x3',
        '40x30x3' => '40x30x3',
        '45x25x2' => '45x25x2',
        '50x15x2' => '50x15x2',
        '50x20x2' => '50x20x2',
        '50x25x1.5' => '50x25x1.5',
        '50x25x2' => '50x25x2',
        '50x25x3' => '50x25x3',
        '50x30x2' => '50x30x2',
        '50x30x2.5' => '50x30x2.5',
        '50x30x3' => '50x30x3',
        '50x40x2' => '50x40x2',
        '50x40x4' => '50x40x4',
        '60x20x2' => '60x20x2',
        '60x25x2' => '60x25x2',
        '60x25x3' => '60x25x3',
        '60x30x2' => '60x30x2',
        '60x40x4' => '60x40x4',
        '60x40x2' => '60x40x2',
        '60x40x2.5' => '60x40x2.5',
        '80x30x2' => '80x30x2',
        '80x40x2' => '80x40x2',
        '80x40x2.5' => '80x40x2.5',
        '80x40x3' => '80x40x3',
        '80x40x4' => '80x40x4',
        '80x50x4' => '80x50x4',
        '100x100x2' => '100x100x2',
        '100x100x4' => '100x100x4',
        '100x100x5' => '100x100x5',
        '120x120x5' => '120x120x5',
        '15x15x1' => '15x15x1',
        '15x15x1.5' => '15x15x1.5',
        '15x15x2' => '15x15x2',
        '20x20x1' => '20x20x1',
        '20x20x1.5' => '20x20x1.5',
        '20x20x2' => '20x20x2',
        '25x25x1.5' => '25x25x1.5',
        '25x25x2' => '25x25x2',
        '25x25x3' => '25x25x3',
        '30x30x2' => '30x30x2',
        '30x30x2.5' => '30x30x2.5',
        '30x30x3' => '30x30x3',
        '35x35x2' => '35x35x2',
        '35x35x3' => '35x35x3',
        '40x40x2' => '40x40x2',
        '40x40x3' => '40x40x3',
        '40x40x4' => '40x40x4',
        '45x45x2' => '45x45x2',
        '50x50x2' => '50x50x2',
        '50x50x3' => '50x50x3',
        '50x50x4' => '50x50x4',
        '60x60x2' => '60x60x2',
        '60x60x3' => '60x60x3',
        '60x60x4' => '60x60x4',
        '65x65x2.5' => '65x65x2.5',
        '70x70x4' => '70x70x4',
        '80x80x3' => '80x80x3',
        '80x80x4' => '80x80x4',
        '100x100x10' => '100x100x10',
        '100x25x2' => '100x25x2',
        '100x64x8' => '100x64x8',
        '100x75x8' => '100x75x8',
        '10x10x2' => '10x10x2',
        '120x80x10' => '120x80x10',
        '130x30x3' => '130x30x3',
        '130x30x5' => '130x30x5',
        '150x75x8' => '150x75x8',
        '15x10x2' => '15x10x2',
        '15x15x3' => '15x15x3',
        '20x10x2' => '20x10x2',
        '20x15x2' => '20x15x2',
        '20x20x3' => '20x20x3',
        '20x20x4' => '20x20x4',
        '25x10x2' => '25x10x2',
        '25x25x4' => '25x25x4',
        '30x10x2' => '30x10x2',
        '30x15x2' => '30x15x2',
        '30x20x3' => '30x20x3',
        '30x20x4' => '30x20x4',
        '30x25x3' => '30x25x3',
        '30x30x4' => '30x30x4',
        '30x30x5' => '30x30x5',
        '35x35x5' => '35x35x5',
        '40x10x2' => '40x10x2',
        '40x15x2' => '40x15x2',
        '40x20x4' => '40x20x4',
        '40x25x3' => '40x25x3',
        '40x30x2' => '40x30x2',
        '40x40x5' => '40x40x5',
        '45x30x3' => '45x30x3',
        '45x45x3' => '45x45x3',
        '50x20x3' => '50x20x3',
        '50x25x4' => '50x25x4',
        '50x30x4' => '50x30x4',
        '50x30x5' => '50x30x5',
        '50x50x5' => '50x50x5',
        '50x50x6' => '50x50x6',
        '60x15x2' => '60x15x2',
        '60x30x3' => '60x30x3',
        '60x30x4' => '60x30x4',
        '60x40x3' => '60x40x3',
        '60x40x5' => '60x40x5',
        '60x60x5' => '60x60x5',
        '60x60x6' => '60x60x6',
        '70x30x2' => '70x30x2',
        '70x20x2' => '70x20x2',
        '70x40x2' => '70x40x2',
        '70x70x7' => '70x70x7',
        '75x40x3' => '75x40x3',
        '75x50x5' => '75x50x5',
        '75x50x6' => '75x50x6',
        '80x20x2' => '80x20x2',
        '80x25x2' => '80x25x2',
        '80x50x6' => '80x50x6',
        '80x80x8' => '80x80x8',
        '90x40x2' => '90x40x2',
        '30x20' => '30x20',
        '100x10' => '100x10',
        '100x12' => '100x12',
        '100x15' => '100x15',
        '100x20' => '100x20',
        '100x3' => '100x3',
        '100x4' => '100x4',
        '100x6' => '100x6',
        '100x8' => '100x8',
        '10x2' => '10x2',
        '10x3' => '10x3',
        '10x4' => '10x4',
        '10x5' => '10x5',
        '120x10' => '120x10',
        '120x15' => '120x15',
        '120x20' => '120x20',
        '120x5' => '120x5',
        '120x8' => '120x8',
        '125x15' => '125x15',
        '150x10' => '150x10',
        '150x15' => '150x15',
        '150x8' => '150x8',
        '15x10' => '15x10',
        '15x2' => '15x2',
        '15x3' => '15x3',
        '15x4' => '15x4',
        '15x5' => '15x5',
        '15x6' => '15x6',
        '15x8' => '15x8',
        '200x10' => '200x10',
        '200x20' => '200x20',
        '20x10' => '20x10',
        '20x12' => '20x12',
        '20x15' => '20x15',
        '20x3' => '20x3',
        '20x4' => '20x4',
        '20x6' => '20x6',
        '20x8' => '20x8',
        '25x10' => '25x10',
        '25x12' => '25x12',
        '25x15' => '25x15',
        '25x20' => '25x20',
        '25x4' => '25x4',
        '25x6' => '25x6',
        '25x8' => '25x8',
        '30x10' => '30x10',
        '30x12' => '30x12',
        '30x15' => '30x15',
        '30x25' => '30x25',
        '30x4' => '30x4',
        '30x6' => '30x6',
        '30x8' => '30x8',
        '35x10' => '35x10',
        '35x15' => '35x15',
        '35x3' => '35x3',
        '35x4' => '35x4',
        '35x6' => '35x6',
        '35x8' => '35x8',
        '40x10' => '40x10',
        '40x12' => '40x12',
        '40x20' => '40x20',
        '40x25' => '40x25',
        '40x3' => '40x3',
        '40x30' => '40x30',
        '40x4' => '40x4',
        '40x6' => '40x6',
        '40x8' => '40x8',
        '45x5' => '45x5',
        '50x10' => '50x10',
        '50x12' => '50x12',
        '50x15' => '50x15',
        '50x2' => '50x2',
        '50x20' => '50x20',
        '50x25' => '50x25',
        '50x3' => '50x3',
        '50x30' => '50x30',
        '50x4' => '50x4',
        '50x5' => '50x5',
        '50x6' => '50x6',
        '50x8' => '50x8',
        '60x10' => '60x10',
        '60x12' => '60x12',
        '60x15' => '60x15',
        '60x2' => '60x2',
        '60x20' => '60x20',
        '60x25' => '60x25',
        '60x3' => '60x3',
        '60x30' => '60x30',
        '60x4' => '60x4',
        '60x40' => '60x40',
        '60x5' => '60x5',
        '60x6' => '60x6',
        '60x8' => '60x8',
        '70x10' => '70x10',
        '70x15' => '70x15',
        '70x3' => '70x3',
        '70x40' => '70x40',
        '70x5' => '70x5',
        '70x6' => '70x6',
        '70x8' => '70x8',
        '80x10' => '80x10',
        '80x15' => '80x15',
        '80x20' => '80x20',
        '80x3' => '80x3',
        '80x30' => '80x30',
        '80x4' => '80x4',
        '80x40' => '80x40',
        '80x5' => '80x5',
        '80x6' => '80x6',
        '80x8' => '80x8',
        '90x10' => '90x10',
        '10mm' => '10mm',
        '12mm' => '12mm',
        '15mm' => '15mm',
        '16mm' => '16mm',
        '20mm' => '20mm',
        '25mm' => '25mm',
        '28mm' => '28mm',
        '30mm' => '30mm',
        '35mm' => '35mm',
        '40mm' => '40mm',
        '45mm' => '45mm',
        '50mm' => '50mm',
        '6mm' => '6mm',
        '7mm' => '7mm',
        '8mm' => '8mm',
        '10x10' => '10x10',
        '12x12' => '12x12',
        '15x15' => '15x15',
        '20x20' => '20x20',
        '25x25' => '25x25',
        '30x30' => '30x30',
        '35x35' => '35x35',
        '40x40' => '40x40',
        '50x50' => '50x50',
        '60x60' => '60x60',
        '8x8' => '8x8',
        '25x50x25x3' => '25x50x25x3',
        '100x200x100x12' => '100x200x100x12',
        '10x10x10x1.5' => '10x10x10x1.5',
        '10x20x10x2' => '10x20x10x2',
        '12x25x12x2' => '12x25x12x2',
        '13x13x13x1.5' => '13x13x13x1.5',
        '15x10x15x1.5' => '15x10x15x1.5',
        '15x15x15x1.5' => '15x15x15x1.5',
        '15x15x15x2' => '15x15x15x2',
        '15x20x15x2' => '15x20x15x2',
        '15x25x15x2' => '15x25x15x2',
        '15x30x15x2' => '15x30x15x2',
        '15x30x15x3' => '15x30x15x3',
        '18x18x18x2' => '18x18x18x2',
        '20x12x20x2' => '20x12x20x2',
        '20x20x20x1.5' => '20x20x20x1.5',
        '20x20x20x2' => '20x20x20x2',
        '20x25x20x3' => '20x25x20x3',
        '20x30x20x2' => '20x30x20x2',
        '20x30x20x3' => '20x30x20x3',
        '20x40x20x2' => '20x40x20x2',
        '20x40x20x3' => '20x40x20x3',
        '22x22x22x2' => '22x22x22x2',
        '25x25x25x2' => '25x25x25x2',
        '25x25x25x3' => '25x25x25x3',
        '25x40x25x3' => '25x40x25x3',
        '25x45x25x3' => '25x45x25x3',
        '30x20x30x2' => '30x20x30x2',
        '30x30x30x2' => '30x30x30x2',
        '30x30x30x3' => '30x30x30x3',
        '30x40x30x3' => '30x40x30x3',
        '30x40x30x4' => '30x40x30x4',
        '30x50x30x3' => '30x50x30x3',
        '30x50x30x4' => '30x50x30x4',
        '30x60x30x4' => '30x60x30x4',
        '35x25x35x2' => '35x25x35x2',
        '40x100x40x3' => '40x100x40x3',
        '40x40x40x2' => '40x40x40x2',
        '40x40x40x3' => '40x40x40x3',
        '40x40x40x4' => '40x40x40x4',
        '40x50x40x4' => '40x50x40x4',
        '40x60x40x3' => '40x60x40x3',
        '40x60x40x4' => '40x60x40x4',
        '40x60x40x5' => '40x60x40x5',
        '40x80x40x4' => '40x80x40x4',
        '50x100x50x5' => '50x100x50x5',
        '50x50x50x3' => '50x50x50x3',
        '50x50x50x5' => '50x50x50x5',
        '50x80x50x5' => '50x80x50x5',
        '60x140x60x7' => '60x140x60x7',
        '64x100x64x6.4' => '64x100x64x6.4',
        '80x125x80x8' => '80x125x80x8',
        '80x160x80x10' => '80x160x80x10',
        '15x10x15x2' => '15x10x15x2',
        '15x6x15x1.5' => '15x6x15x1.5',
        '100x20x2' => '100x20x2',
        '100x30x2' => '100x30x2',
        '90x3' => '90x3',
        '6x1' => '6x1',
        '80x80x2' => '80x80x2',
        '12x8' => '12x8',
        '80x2' => '80x2',
        '25x20x25x2' => '25x20x25x2',
        '80x80x5' => '80x80x5',
        '60x80x2' => '60x80x2',
        '120x30' => '120x30',
        '35x15x2' => '35x15x2',
        '80x40x5' => '80x40x5',
        '100x2' => '100x2',
        '60x50x3' => '60x50x3',
        '120x120x4' => '120x120x4',
        '150x40x2.5' => '150x40x2.5',
        '40x20x1' => '40x20x1',
        '20x25x20x2' => '20x25x20x2',
        '120x40x2.5' => '120x40x2.5',
        '30x15x30x3' => '30x15x30x3',
        '200x100x4' => '200x100x4',
        '100x15x2' => '100x15x2',
        '100x40x2' => '100x40x2',
        '100x100x3' => '100x100x3',
        '100x100x6' => '100x100x6',
        '100x60x6' => '100x60x6',
        '80x50x2' => '80x50x2',
        '180x50x4' => '180x50x4',
        '120x20x2.5' => '120x20x2.5',
        '70x70x2' => '70x70x2',
        '120x20x2' => '120x20x2',
        '10x1' => '10x1',
        '50x50x10' => '50x50x10',
        '45x45x45x2' => '45x45x45x2',
        '10x10x1.5' => '10x10x1.5',
        '110x5' => '110x5',
        '70x4' => '70x4',
        '80x60x4' => '80x60x4',
        '45x2' => '45x2',
        '150x80x4' => '150x80x4',
        '100x40x3' => '100x40x3',
        '80x30x3' => '80x30x3',
        '120x80x3' => '120x80x3',
        '75x2' => '75x2',
        '120x50x4' => '120x50x4',
        '20x15x20x2' => '20x15x20x2',
        '120x120x2.5' => '120x120x2.5',
        '75x20x2' => '75x20x2',
        '35x21x35x2' => '35x21x35x2',
        '100x45x2' => '100x45x2',
        '30x30x1.5' => '30x30x1.5',
        '25x20x25x1.5' => '25x20x25x1.5',
        '30x20x30x1.5' => '30x20x30x1.5',
        '90x50x4' => '90x50x4',
        '80x60x3' => '80x60x3',
        '80x50x3' => '80x50x3',
        '35x35x35x2' => '35x35x35x2',
        '50x50x50x4' => '50x50x50x4',
        '40x40x2.5' => '40x40x2.5',
        '40x40x1.5' => '40x40x1.5',
        '65x2' => '65x2',
        '120x120x10' => '120x120x10',
        '100x30x3' => '100x30x3',
        '20x35x20x2' => '20x35x20x2',
        '100x60x3' => '100x60x3',
        '40x30x1.5' => '40x30x1.5',
        '30x60x30x3' => '30x60x30x3',
        '200x100x10' => '200x100x10',
        '90x90x4' => '90x90x4',
        '100x50x2' => '100x50x2',
        '16x2' => '16x2',
        '22x22' => '22x22',
        '45x10' => '45x10',
        '25x35x25x2' => '25x35x25x2',
        '30x25x30x2' => '30x25x30x2',
        '18x3' => '18x3',
        '30x80x30x3' => '30x80x30x3',
        '140x80x4' => '140x80x4',
        '40x15' => '40x15',
        '120x60x4' => '120x60x4',
        '70x25' => '70x25',
        '120x4' => '120x4',
        '200x65x3' => '200x65x3',
        '35x20' => '35x20',
        '' => '',
        0 => 4000,
        '26x8(a310181)' => '26x8(a310181)',
        '150x50x5' => '150x50x5',
        '25x15x1.5' => '25x15x1.5',
        '40x100x40x4' => '40x100x40x4',
        '60x45x3' => '60x45x3',
        '40x20x40x2' => '40x20x40x2',
        '30x15x3' => '30x15x3',
        '40x30x4' => '40x30x4',
        '60x60x2.5' => '60x60x2.5',
        '12.5x12.5x12.5x1.5' => '12.5x12.5x12.5x1.5',
        '100x50x6' => '100x50x6',
        '45x8' => '45x8',
        '40x70x40x4' => '40x70x40x4',
        '12x6' => '12x6',
        '15x15x15x3' => '15x15x15x3',
        '100x50x8' => '100x50x8',
        '150x30x2.5' => '150x30x2.5',
        '45x3' => '45x3',
        '180x10' => '180x10',
        '250x10' => '250x10',
        '140x18x2' => '140x18x2',
        '120x50x5' => '120x50x5',
        '50x90x50x3' => '50x90x50x3',
        '150x150x4' => '150x150x4',
        '150x100x3' => '150x100x3',
        '65x65x2' => '65x65x2',
        '30x20x30x3' => '30x20x30x3',
        '62x17x2' => '62x17x2',
        1 => 4000,
        2 => 4000,
        3 => 4000,
        4 => 4000,
        5 => 4000,
        6 => 4000,
        7 => 4000,
        8 => 4000,
        9 => 4000,
        10 => 4000,
        11 => 4000,
        12 => 4000,
        13 => 4000,
        14 => 4000,
        15 => 4000,
        16 => 4000,
        17 => 4000,
        18 => 4000,
        19 => 4000,
        20 => 4000,
        21 => 4000,
        22 => 4000,
        23 => 4000,
        24 => 4000,
        25 => 4000,
        26 => 4000,
        27 => 4000,
        28 => 4000,
        29 => 4000,
        30 => 4000,
        31 => 4000,
        32 => 4000,
        33 => 4000,
        34 => 4000,
        35 => 4000,
        36 => 4000,
        37 => 4000,
        38 => 4000,
        39 => 4000,
        40 => 4000,
        41 => 4000,
        42 => 4000,
        43 => 4000,
        44 => 4000,
        45 => 4000,
        46 => 4000,
        47 => 4000,
        48 => 4000,
        49 => 4000,
        50 => 4000,
        51 => 4000,
        52 => 4000,
        53 => 4000,
        54 => 4000,
        55 => 4000,
        56 => 4000,
        57 => 4000,
        58 => 4000,
        59 => 4000,
        60 => 4000,
        61 => 4000,
        62 => 4000,
        63 => 4000,
        64 => 4000,
        65 => 4000,
        66 => 4000,
        67 => 4000,
        68 => 4000,
        69 => 4000,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_maritime'
  $field_bases['field_maritime'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_maritime',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_mke_type'
  $field_bases['field_mke_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_mke_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Eindstuk' => 'Eindstuk',
        'Koppelstuk' => 'Koppelstuk',
        'Hoek' => 'Hoek',
        'Beugel' => 'Beugel',
        'eindstuk' => 'Eindstuk',
        'koppelstuk' => 'Koppelstuk',
        'hoek' => 'Hoek',
        'beugel' => 'Beugel',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_multi_breedte'
  $field_bases['field_multi_breedte'] = array(
    'active' => 1,
    'cardinality' => 5,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_multi_breedte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_multi_hoek'
  $field_bases['field_multi_hoek'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_multi_hoek',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_muurkap_diepte'
  $field_bases['field_muurkap_diepte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_muurkap_diepte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        250 => '250mm',
        300 => '300mm',
        350 => '350mm',
        400 => '400mm',
        450 => '450mm',
        500 => '500mm',
        550 => '550mm',
        600 => '600mm',
        650 => '650mm',
        700 => '700mm',
        750 => '750mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_muurkap_type'
  $field_bases['field_muurkap_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_muurkap_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Type 1',
        2 => 'Type 2',
        3 => 'Type 3',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_naam_bedrijf'
  $field_bases['field_naam_bedrijf'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_naam_bedrijf',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_ophanging'
  $field_bases['field_ophanging'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ophanging',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'haakjes' => 'Haakjes',
        'gaatjes' => 'Gaatjes',
        'lasbouten' => 'Lasbouten',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_order_type'
  $field_bases['field_order_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_order_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'order' => 'Bestelling',
        'offer' => 'Offerte',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_plaatbewerking_afwerking'
  $field_bases['field_plaatbewerking_afwerking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_plaatbewerking_afwerking',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'brut' => 'Brut',
        'ral' => 'Ral',
        'ral2' => 'Ral (2-zijden)',
        'str' => 'Stuctuur, Coatex an Anodisé',
        'str2' => 'Stuctuur, Coatex an Anodisé (2-zijden)',
        'reno' => 'Renolit',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_plaatbewerking_dikte'
  $field_bases['field_plaatbewerking_dikte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_plaatbewerking_dikte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        '1.5mm' => '1.5mm',
        '2mm' => '2mm',
        '3mm' => '3mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_plooien'
  $field_bases['field_plooien'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_plooien',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_product'
  $field_bases['field_product'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => '',
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  // Exported field_base: 'field_product_image'
  $field_bases['field_product_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_raamtablet_afwerking'
  $field_bases['field_raamtablet_afwerking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_raamtablet_afwerking',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'brut' => 'Brut',
        'ral' => 'Kleuren Ral, blinkend of mat',
        'str' => 'Structuur, Coatex en Anodisé',
        'reno' => 'Renolith',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_raamtablet_diepte'
  $field_bases['field_raamtablet_diepte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_raamtablet_diepte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        50 => '50mm',
        70 => '70mm',
        90 => '90mm',
        110 => '110mm',
        130 => '130mm',
        150 => '150mm',
        170 => '170mm',
        190 => '190mm',
        210 => '210mm',
        230 => '230mm',
        250 => '250mm',
        270 => '270mm',
        290 => '290mm',
        310 => '310mm',
        330 => '330mm',
        350 => '350mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_raamtablet_eindstuk_type'
  $field_bases['field_raamtablet_eindstuk_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_raamtablet_eindstuk_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Type 1',
        2 => 'Type 2',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_raamtablet_lengte'
  $field_bases['field_raamtablet_lengte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_raamtablet_lengte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1000 => '1000mm',
        2000 => '2000mm',
        3000 => '3000mm',
        4000 => '4000mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_reference'
  $field_bases['field_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_reference',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_rug'
  $field_bases['field_rug'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rug',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Geen',
        17 => '17mm',
        25 => '25mm',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_sandwichpaneel_afwerking'
  $field_bases['field_sandwichpaneel_afwerking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sandwichpaneel_afwerking',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'brut' => 'Brut',
        'ral' => 'Ral',
        'str' => 'Structuur, Coatex en Anondisé',
        'bicolor' => 'Bicolor',
        'reno' => 'Renolith',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_sandwichpaneel_afwerking_2'
  $field_bases['field_sandwichpaneel_afwerking_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sandwichpaneel_afwerking_2',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'brut' => 'Brut',
        'ral' => 'Ral',
        'str' => 'Structuur, Coatex en Anondisé',
        'reno' => 'Renolith',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_sandwichpaneel_lengte'
  $field_bases['field_sandwichpaneel_lengte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sandwichpaneel_lengte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        500 => 500,
        1000 => 1000,
        1250 => 1250,
        1500 => 1500,
        1750 => 1750,
        2000 => 2000,
        2500 => 2500,
        3000 => 3000,
        3500 => 3500,
        4000 => 4000,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_standaardprofiel_afwerking'
  $field_bases['field_standaardprofiel_afwerking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_standaardprofiel_afwerking',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'brut' => 'Brut',
        'ral' => 'Ral',
        'str' => 'Structuur, Métalique, Anodisé',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_standaardprofiel_lengte'
  $field_bases['field_standaardprofiel_lengte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_standaardprofiel_lengte',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1000 => 1000,
        2000 => 2000,
        3000 => 3000,
        6000 => 6000,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_standaardprofiel_type'
  $field_bases['field_standaardprofiel_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_standaardprofiel_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'BR' => 'Ronde buis',
        'BRH' => 'Rechthoekige buis',
        'BVK' => 'Vierkante buis',
        'L' => 'L-profiel',
        'SPL' => 'Platte staaf',
        'SR' => 'Ronde staaf',
        'SVK' => 'Vierkante staaf',
        'T' => 'T-profiel',
        'U' => 'U-profiel',
        'Z' => 'Z-profiel',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_stockprofiel'
  $field_bases['field_stockprofiel'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_stockprofiel',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_tekening'
  $field_bases['field_tekening'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tekening',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_telefoon'
  $field_bases['field_telefoon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_telefoon',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_type_bewerking'
  $field_bases['field_type_bewerking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_type_bewerking',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'L' => 'L',
        'U' => 'U',
        'C' => 'C',
        'J' => 'J',
        'Z' => 'Z',
        'I' => 'I',
        'special' => 'Speciaal',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
