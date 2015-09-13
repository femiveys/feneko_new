<?php
/**
 * @file
 * feneko_structure.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feneko_structure_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  return $permissions;
}
