<?php
/**
 * @file
 * feneko_calculator_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feneko_calculator_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer product display types'.
  $permissions['administer product display types'] = array(
    'name' => 'administer product display types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_backoffice_product',
  );

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce',
  );

  return $permissions;
}
