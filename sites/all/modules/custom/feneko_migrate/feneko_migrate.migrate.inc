<?php
/**
 * @file
 * Declares our migrations.
 */


/**
 * Implements hook_migrate_api().
 */
function feneko_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'profiles' => array(
        'title' => t('User profiles related Migrations'),
      ),
    ),
    'migrations' => array(
      'clients' => array(
        'class_name' => 'ClientsMigration',
        'group_name' => 'profiles',
      ),
      // 'users' => array(
      //   'class_name' => 'UsersMigration',
      //   'group_name' => 'profiles',
      // ),
    ),
  );
  return $api;
}

