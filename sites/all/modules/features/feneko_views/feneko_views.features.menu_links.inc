<?php
/**
 * @file
 * feneko_views.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feneko_views_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_jobs:jobs
  $menu_links['main-menu_jobs:jobs'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'jobs',
    'router_path' => 'jobs',
    'link_title' => 'Jobs',
    'options' => array(
      'identifier' => 'main-menu_jobs:jobs',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_nieuws:nieuws
  $menu_links['main-menu_nieuws:nieuws'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nieuws',
    'router_path' => 'nieuws',
    'link_title' => 'Nieuws',
    'options' => array(
      'identifier' => 'main-menu_nieuws:nieuws',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_producten:onze-producten
  $menu_links['main-menu_producten:onze-producten'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'onze-producten',
    'router_path' => 'onze-producten',
    'link_title' => 'producten',
    'options' => array(
      'identifier' => 'main-menu_producten:onze-producten',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Jobs');
  t('Nieuws');
  t('producten');

  return $menu_links;
}
