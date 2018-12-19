<?php

/**
 * @file
 * feneko_account.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feneko_account_user_default_roles() {
  $roles = array();

  // Exported role: api.
  $roles['api'] = array(
    'name' => 'api',
    'weight' => 6,
  );

  // Exported role: content editor.
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => 3,
  );

  // Exported role: handelaar.
  $roles['handelaar'] = array(
    'name' => 'handelaar',
    'weight' => 2,
  );

  // Exported role: interne medewerker.
  $roles['interne medewerker'] = array(
    'name' => 'interne medewerker',
    'weight' => 3,
  );

  // Exported role: site_admin.
  $roles['site_admin'] = array(
    'name' => 'site_admin',
    'weight' => 7,
  );

  return $roles;
}
