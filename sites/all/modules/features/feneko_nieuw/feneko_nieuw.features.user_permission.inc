<?php
/**
 * @file
 * feneko_nieuw.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feneko_nieuw_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer addressfield staticmap'.
  $permissions['administer addressfield staticmap'] = array(
    'name' => 'administer addressfield staticmap',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'addressfield_staticmap',
  );

  return $permissions;
}
