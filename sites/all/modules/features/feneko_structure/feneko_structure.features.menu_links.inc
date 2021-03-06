<?php

/**
 * @file
 * feneko_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feneko_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_jobs:jobs.
  $menu_links['main-menu_jobs:jobs'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'jobs',
    'router_path' => 'jobs',
    'link_title' => 'Jobs',
    'options' => array(
      'identifier' => 'main-menu_jobs:jobs',
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
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
  // Exported menu link: main-menu_nieuws:nieuws.
  $menu_links['main-menu_nieuws:nieuws'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nieuws',
    'router_path' => 'nieuws',
    'link_title' => 'Nieuws',
    'options' => array(
      'identifier' => 'main-menu_nieuws:nieuws',
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_producten:onze-producten.
  $menu_links['main-menu_producten:onze-producten'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'onze-producten',
    'router_path' => 'onze-producten',
    'link_title' => 'Producten',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_producten:onze-producten',
      'alter' => TRUE,
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
  // Exported menu link: menu-waarom-feneko_onze-machines:machines.
  $menu_links['menu-waarom-feneko_onze-machines:machines'] = array(
    'menu_name' => 'menu-waarom-feneko',
    'link_path' => 'machines',
    'router_path' => 'machines',
    'link_title' => 'Onze machines',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-waarom-feneko_onze-machines:machines',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-waarom-feneko_onze-producten-colors--screens:onze-producten.
  $menu_links['menu-waarom-feneko_onze-producten-colors--screens:onze-producten'] = array(
    'menu_name' => 'menu-waarom-feneko',
    'link_path' => 'onze-producten',
    'router_path' => 'onze-producten',
    'link_title' => 'Onze producten: Colors & Screens',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-waarom-feneko_onze-producten-colors--screens:onze-producten',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'nl',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_klantenzone:user/login.
  $menu_links['user-menu_klantenzone:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Klantenzone',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_klantenzone:user/login',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Jobs');
  t('Klantenzone');
  t('Log out');
  t('Nieuws');
  t('Onze machines');
  t('Onze producten: Colors & Screens');
  t('Producten');

  return $menu_links;
}
