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
        'weight' => -8,
      ),
      'samurai' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'samurai',
        'weight' => -8,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
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
      'samurai' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'samurai',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
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
      'samurai' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'samurai',
        'weight' => -11,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
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
        'weight' => -14,
      ),
      'samurai' => array(
        'region' => 'main_menu',
        'status' => 1,
        'theme' => 'samurai',
        'weight' => -7,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
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
      'samurai' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'samurai',
        'weight' => 10,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
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
        'region' => 'user_menu',
        'status' => 1,
        'theme' => 'feneko',
        'weight' => -12,
      ),
      'samurai' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'samurai',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
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
      'samurai' => array(
        'region' => 'main_menu',
        'status' => 1,
        'theme' => 'samurai',
        'weight' => -11,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
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
      'samurai' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'samurai',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
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
      'samurai' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'samurai',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
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
      'samurai' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'samurai',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
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
      'samurai' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'samurai',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
