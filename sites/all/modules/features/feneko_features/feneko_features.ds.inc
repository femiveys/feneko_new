<?php
/**
 * @file
 * feneko_features.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function feneko_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_afbeeldingen',
        1 => 'field_order_link',
        2 => 'field_orderable_products',
        3 => 'field_catalogus_link',
        4 => 'field_basic_product',
      ),
      'right' => array(
        0 => 'field_afbeeldingen_multiple',
        1 => 'body',
        2 => 'group_tech_info',
        3 => 'field_levertermijn',
        4 => 'group_prijs_levering',
        5 => 'field_bijlage_secured',
        6 => 'field_technische_informatie',
        7 => 'field_technische_tekening',
        8 => 'field_technische_documenten',
      ),
    ),
    'fields' => array(
      'field_afbeeldingen' => 'left',
      'field_order_link' => 'left',
      'field_orderable_products' => 'left',
      'field_catalogus_link' => 'left',
      'field_basic_product' => 'left',
      'field_afbeeldingen_multiple' => 'right',
      'body' => 'right',
      'group_tech_info' => 'right',
      'field_levertermijn' => 'right',
      'group_prijs_levering' => 'right',
      'field_bijlage_secured' => 'right',
      'field_technische_informatie' => 'right',
      'field_technische_tekening' => 'right',
      'field_technische_documenten' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|product|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_afbeeldingen',
      ),
      'middle' => array(
        0 => 'field_afbeeldingen_multiple',
        1 => 'body',
        2 => 'group_tech_info',
        3 => 'group_prijs_levering',
        4 => 'field_technische_informatie',
        5 => 'field_technische_tekening',
        6 => 'field_technische_documenten',
        7 => 'field_levertermijn',
        8 => 'field_bijlage',
      ),
      'right' => array(
        0 => 'group_versies',
        1 => 'field_basic_product',
      ),
    ),
    'fields' => array(
      'field_afbeeldingen' => 'left',
      'field_afbeeldingen_multiple' => 'middle',
      'body' => 'middle',
      'group_tech_info' => 'middle',
      'group_prijs_levering' => 'middle',
      'group_versies' => 'right',
      'field_technische_informatie' => 'middle',
      'field_technische_tekening' => 'middle',
      'field_technische_documenten' => 'middle',
      'field_basic_product' => 'right',
      'field_levertermijn' => 'middle',
      'field_bijlage' => 'middle',
    ),
    'classes' => array(),
  );
  $export['node|product|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|icon';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'icon';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_afbeeldingen',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_afbeeldingen' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|product|icon'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_afbeeldingen',
      ),
      'right' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_order_link',
        3 => 'field_orderable_products',
      ),
    ),
    'fields' => array(
      'field_afbeeldingen' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_order_link' => 'right',
      'field_orderable_products' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|product|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|teaser_left';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'teaser_left';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_afbeeldingen',
      ),
      'right' => array(
        0 => 'title',
        1 => 'body',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_afbeeldingen' => 'left',
      'title' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'limit' => array(
      'field_afbeeldingen' => '1',
    ),
    'classes' => array(),
  );
  $export['node|product|teaser_left'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|teaser_right';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'teaser_right';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
        2 => 'node_link',
      ),
      'right' => array(
        0 => 'field_afbeeldingen',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'node_link' => 'left',
      'field_afbeeldingen' => 'right',
    ),
    'limit' => array(
      'field_afbeeldingen' => '1',
    ),
    'classes' => array(),
  );
  $export['node|product|teaser_right'] = $ds_layout;

  return $export;
}
