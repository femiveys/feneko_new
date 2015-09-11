<?php
/**
 * @file
 * feneko_account.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feneko_account_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_klantennummer'.
  $permissions['create field_klantennummer'] = array(
    'name' => 'create field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_klantennummer'.
  $permissions['edit field_klantennummer'] = array(
    'name' => 'edit field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_klantennummer'.
  $permissions['edit own field_klantennummer'] = array(
    'name' => 'edit own field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'post api'.
  $permissions['post api'] = array(
    'name' => 'post api',
    'roles' => array(
      'api' => 'api',
    ),
    'module' => 'feneko_code',
  );

  // Exported permission: 'view field_klantennummer'.
  $permissions['view field_klantennummer'] = array(
    'name' => 'view field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_klantennummer'.
  $permissions['view own field_klantennummer'] = array(
    'name' => 'view own field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
