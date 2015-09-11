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

  // Exported role: interne medewerker.
  $roles['interne medewerker'] = array(
    'name' => 'interne medewerker',
    'weight' => 3,
  );

  return $roles;
}
