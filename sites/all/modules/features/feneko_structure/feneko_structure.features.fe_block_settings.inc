<?php
/**
 * @file
 * feneko_structure.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feneko_structure_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['entityform_block-contact'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'contact',
    'module' => 'entityform_block',
    'node_types' => array(),
    'pages' => 'contact',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'module' => 'locale',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -15,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -17,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-waarom-feneko'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-waarom-feneko',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'bottom_block',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'main_menu',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'feneko',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'feneko',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'main_menu',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -16,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'feneko',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-contact-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'contact-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'about',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-footer_info-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'footer_info-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-front_image-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'front_image-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'cover',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-jobs-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'jobs-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'jobs/*',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -14,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-main_categories-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main_categories-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'front_block',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -13,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-nieuws-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'nieuws-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'nieuws/',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -13,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-related-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'related-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'feneko' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
