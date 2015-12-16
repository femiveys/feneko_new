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

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'administrator' => 'administrator',
      'handelaar' => 'handelaar',
    ),
    'module' => 'commerce_checkout',
  );

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

  // Exported permission: 'feneko admin'.
  $permissions['feneko admin'] = array(
    'name' => 'feneko admin',
    'roles' => array(
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'feneko_code',
  );

  // Exported permission: 'feneko order'.
  $permissions['feneko order'] = array(
    'name' => 'feneko order',
    'roles' => array(
      'handelaar' => 'handelaar',
    ),
    'module' => 'feneko_code',
  );

  // Exported permission: 'post api'.
  $permissions['post api'] = array(
    'name' => 'post api',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'feneko_code',
  );

  // Exported permission: 'see the catalog'.
  $permissions['see the catalog'] = array(
    'name' => 'see the catalog',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'handelaar' => 'handelaar',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'feneko_code',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      'administrator' => 'administrator',
      'handelaar' => 'handelaar',
    ),
    'module' => 'commerce_product',
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
