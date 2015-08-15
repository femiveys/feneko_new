<?php
/**
 * @file
 * feneko_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feneko_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function feneko_structure_image_default_styles() {
  $styles = array();

  // Exported image style: force_square_medium.
  $styles['force_square_medium'] = array(
    'label' => 'force square medium',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 220,
          'upscale' => 1,
        ),
        'weight' => -9,
      ),
      7 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 220,
          'height' => 220,
        ),
        'weight' => -8,
      ),
      6 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'anchor' => 'center-center',
        ),
        'weight' => -7,
      ),
    ),
  );

  // Exported image style: front_image.
  $styles['front_image'] = array(
    'label' => 'front image',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 420,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: square_medium.
  $styles['square_medium'] = array(
    'label' => 'Square medium',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: square_thumbnail.
  $styles['square_thumbnail'] = array(
    'label' => 'square thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feneko_structure_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'info_pagina' => array(
      'name' => t('Info pagina'),
      'base' => 'node_content',
      'description' => t('Geef hier alle praktische informatie over FenekO in, zoals openingsuren, adres, telefoonnummer, ...'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'machine' => array(
      'name' => t('Machine'),
      'base' => 'node_content',
      'description' => t('Geef machines hier in'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Eenvoudige pagina'),
      'base' => 'node_content',
      'description' => t('Gebruik <em>basispagina\'s</em> voor vaste inhoud, zoals een \'Over ons\'-pagina.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Naam'),
      'help' => '',
    ),
    'vacature' => array(
      'name' => t('Vacature'),
      'base' => 'node_content',
      'description' => t('Geef vacatures in'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
