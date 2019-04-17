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

  // Exported permission: 'create field_attach_secured'.
  $permissions['create field_attach_secured'] = array(
    'name' => 'create field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_orderable_products'.
  $permissions['create field_orderable_products'] = array(
    'name' => 'create field_orderable_products',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_tech_docs'.
  $permissions['create field_tech_docs'] = array(
    'name' => 'create field_tech_docs',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_attach_secured'.
  $permissions['edit field_attach_secured'] = array(
    'name' => 'edit field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_orderable_products'.
  $permissions['edit field_orderable_products'] = array(
    'name' => 'edit field_orderable_products',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_tech_docs'.
  $permissions['edit field_tech_docs'] = array(
    'name' => 'edit field_tech_docs',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_attach_secured'.
  $permissions['edit own field_attach_secured'] = array(
    'name' => 'edit own field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_orderable_products'.
  $permissions['edit own field_orderable_products'] = array(
    'name' => 'edit own field_orderable_products',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_tech_docs'.
  $permissions['edit own field_tech_docs'] = array(
    'name' => 'edit own field_tech_docs',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_attach_secured'.
  $permissions['view field_attach_secured'] = array(
    'name' => 'view field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
      'handelaar' => 'handelaar',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_orderable_products'.
  $permissions['view field_orderable_products'] = array(
    'name' => 'view field_orderable_products',
    'roles' => array(
      'administrator' => 'administrator',
      'handelaar' => 'handelaar',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_tech_docs'.
  $permissions['view field_tech_docs'] = array(
    'name' => 'view field_tech_docs',
    'roles' => array(
      'content editor' => 'content editor',
      'handelaar' => 'handelaar',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_attach_secured'.
  $permissions['view own field_attach_secured'] = array(
    'name' => 'view own field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_orderable_products'.
  $permissions['view own field_orderable_products'] = array(
    'name' => 'view own field_orderable_products',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_tech_docs'.
  $permissions['view own field_tech_docs'] = array(
    'name' => 'view own field_tech_docs',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
