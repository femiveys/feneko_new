<?php
/**
 * @file
 * feature_content_types.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_content_types_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

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
