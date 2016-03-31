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

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'administrator' => 'administrator',
      'handelaar' => 'handelaar',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'handelaar' => 'handelaar',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'handelaar' => 'handelaar',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'overlay',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer optimizedb settings'.
  $permissions['administer optimizedb settings'] = array(
    'name' => 'administer optimizedb settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'optimizedb',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'archive_manyforms'.
  $permissions['archive_manyforms'] = array(
    'name' => 'archive_manyforms',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'manyforms',
  );

  // Exported permission: 'assign roles'.
  $permissions['assign roles'] = array(
    'name' => 'assign roles',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'roleassign',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'handelaar' => 'handelaar',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'handelaar' => 'handelaar',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'configure order settings'.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create banner content'.
  $permissions['create banner content'] = array(
    'name' => 'create banner content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create client content'.
  $permissions['create client content'] = array(
    'name' => 'create client content',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle commerce_order'.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create dorpel_anti_dreunstrook content'.
  $permissions['create dorpel_anti_dreunstrook content'] = array(
    'name' => 'create dorpel_anti_dreunstrook content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create dorpel_eindstuk content'.
  $permissions['create dorpel_eindstuk content'] = array(
    'name' => 'create dorpel_eindstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create dorpel_hoek content'.
  $permissions['create dorpel_hoek content'] = array(
    'name' => 'create dorpel_hoek content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create dorpel_koppelstuk content'.
  $permissions['create dorpel_koppelstuk content'] = array(
    'name' => 'create dorpel_koppelstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create field_attach_secured'.
  $permissions['create field_attach_secured'] = array(
    'name' => 'create field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_block_order_input'.
  $permissions['create field_block_order_input'] = array(
    'name' => 'create field_block_order_input',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_btw_nummer'.
  $permissions['create field_btw_nummer'] = array(
    'name' => 'create field_btw_nummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_clients'.
  $permissions['create field_clients'] = array(
    'name' => 'create field_clients',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_geblokkeerd'.
  $permissions['create field_geblokkeerd'] = array(
    'name' => 'create field_geblokkeerd',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_klantennummer'.
  $permissions['create field_klantennummer'] = array(
    'name' => 'create field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_naam_bedrijf'.
  $permissions['create field_naam_bedrijf'] = array(
    'name' => 'create field_naam_bedrijf',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'create field_staffelkorting'.
  $permissions['create field_staffelkorting'] = array(
    'name' => 'create field_staffelkorting',
    'roles' => array(
      'site_admin' => 'site_admin',
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

  // Exported permission: 'create field_telefoon'.
  $permissions['create field_telefoon'] = array(
    'name' => 'create field_telefoon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create info_pagina content'.
  $permissions['create info_pagina content'] = array(
    'name' => 'create info_pagina content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create machine content'.
  $permissions['create machine content'] = array(
    'name' => 'create machine content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create muurkap content'.
  $permissions['create muurkap content'] = array(
    'name' => 'create muurkap content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create plaatbewerking content'.
  $permissions['create plaatbewerking content'] = array(
    'name' => 'create plaatbewerking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create product content'.
  $permissions['create product content'] = array(
    'name' => 'create product content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create raamtablet content'.
  $permissions['create raamtablet content'] = array(
    'name' => 'create raamtablet content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create sandwichpaneel content'.
  $permissions['create sandwichpaneel content'] = array(
    'name' => 'create sandwichpaneel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create standaardprofiel content'.
  $permissions['create standaardprofiel content'] = array(
    'name' => 'create standaardprofiel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create unit content'.
  $permissions['create unit content'] = array(
    'name' => 'create unit content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create vacature content'.
  $permissions['create vacature content'] = array(
    'name' => 'create vacature content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any banner content'.
  $permissions['delete any banner content'] = array(
    'name' => 'delete any banner content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any client content'.
  $permissions['delete any client content'] = array(
    'name' => 'delete any client content',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any dorpel_anti_dreunstrook content'.
  $permissions['delete any dorpel_anti_dreunstrook content'] = array(
    'name' => 'delete any dorpel_anti_dreunstrook content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any dorpel_eindstuk content'.
  $permissions['delete any dorpel_eindstuk content'] = array(
    'name' => 'delete any dorpel_eindstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any dorpel_hoek content'.
  $permissions['delete any dorpel_hoek content'] = array(
    'name' => 'delete any dorpel_hoek content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any dorpel_koppelstuk content'.
  $permissions['delete any dorpel_koppelstuk content'] = array(
    'name' => 'delete any dorpel_koppelstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any entityform'.
  $permissions['delete any entityform'] = array(
    'name' => 'delete any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any info_pagina content'.
  $permissions['delete any info_pagina content'] = array(
    'name' => 'delete any info_pagina content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any machine content'.
  $permissions['delete any machine content'] = array(
    'name' => 'delete any machine content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any muurkap content'.
  $permissions['delete any muurkap content'] = array(
    'name' => 'delete any muurkap content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any plaatbewerking content'.
  $permissions['delete any plaatbewerking content'] = array(
    'name' => 'delete any plaatbewerking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any product content'.
  $permissions['delete any product content'] = array(
    'name' => 'delete any product content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any raamtablet content'.
  $permissions['delete any raamtablet content'] = array(
    'name' => 'delete any raamtablet content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any sandwichpaneel content'.
  $permissions['delete any sandwichpaneel content'] = array(
    'name' => 'delete any sandwichpaneel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any standaardprofiel content'.
  $permissions['delete any standaardprofiel content'] = array(
    'name' => 'delete any standaardprofiel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any unit content'.
  $permissions['delete any unit content'] = array(
    'name' => 'delete any unit content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any vacature content'.
  $permissions['delete any vacature content'] = array(
    'name' => 'delete any vacature content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own banner content'.
  $permissions['delete own banner content'] = array(
    'name' => 'delete own banner content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own client content'.
  $permissions['delete own client content'] = array(
    'name' => 'delete own client content',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own dorpel_anti_dreunstrook content'.
  $permissions['delete own dorpel_anti_dreunstrook content'] = array(
    'name' => 'delete own dorpel_anti_dreunstrook content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own dorpel_eindstuk content'.
  $permissions['delete own dorpel_eindstuk content'] = array(
    'name' => 'delete own dorpel_eindstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own dorpel_hoek content'.
  $permissions['delete own dorpel_hoek content'] = array(
    'name' => 'delete own dorpel_hoek content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own dorpel_koppelstuk content'.
  $permissions['delete own dorpel_koppelstuk content'] = array(
    'name' => 'delete own dorpel_koppelstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own info_pagina content'.
  $permissions['delete own info_pagina content'] = array(
    'name' => 'delete own info_pagina content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own machine content'.
  $permissions['delete own machine content'] = array(
    'name' => 'delete own machine content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own muurkap content'.
  $permissions['delete own muurkap content'] = array(
    'name' => 'delete own muurkap content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own plaatbewerking content'.
  $permissions['delete own plaatbewerking content'] = array(
    'name' => 'delete own plaatbewerking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own product content'.
  $permissions['delete own product content'] = array(
    'name' => 'delete own product content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own raamtablet content'.
  $permissions['delete own raamtablet content'] = array(
    'name' => 'delete own raamtablet content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own sandwichpaneel content'.
  $permissions['delete own sandwichpaneel content'] = array(
    'name' => 'delete own sandwichpaneel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own standaardprofiel content'.
  $permissions['delete own standaardprofiel content'] = array(
    'name' => 'delete own standaardprofiel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own unit content'.
  $permissions['delete own unit content'] = array(
    'name' => 'delete own unit content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own vacature content'.
  $permissions['delete own vacature content'] = array(
    'name' => 'delete own vacature content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in product_category'.
  $permissions['delete terms in product_category'] = array(
    'name' => 'delete terms in product_category',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any banner content'.
  $permissions['edit any banner content'] = array(
    'name' => 'edit any banner content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any client content'.
  $permissions['edit any client content'] = array(
    'name' => 'edit any client content',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle commerce_order'.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any dorpel_anti_dreunstrook content'.
  $permissions['edit any dorpel_anti_dreunstrook content'] = array(
    'name' => 'edit any dorpel_anti_dreunstrook content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any dorpel_eindstuk content'.
  $permissions['edit any dorpel_eindstuk content'] = array(
    'name' => 'edit any dorpel_eindstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any dorpel_hoek content'.
  $permissions['edit any dorpel_hoek content'] = array(
    'name' => 'edit any dorpel_hoek content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any dorpel_koppelstuk content'.
  $permissions['edit any dorpel_koppelstuk content'] = array(
    'name' => 'edit any dorpel_koppelstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any entityform'.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any info_pagina content'.
  $permissions['edit any info_pagina content'] = array(
    'name' => 'edit any info_pagina content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any machine content'.
  $permissions['edit any machine content'] = array(
    'name' => 'edit any machine content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any muurkap content'.
  $permissions['edit any muurkap content'] = array(
    'name' => 'edit any muurkap content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any plaatbewerking content'.
  $permissions['edit any plaatbewerking content'] = array(
    'name' => 'edit any plaatbewerking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any product content'.
  $permissions['edit any product content'] = array(
    'name' => 'edit any product content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any raamtablet content'.
  $permissions['edit any raamtablet content'] = array(
    'name' => 'edit any raamtablet content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any sandwichpaneel content'.
  $permissions['edit any sandwichpaneel content'] = array(
    'name' => 'edit any sandwichpaneel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any standaardprofiel content'.
  $permissions['edit any standaardprofiel content'] = array(
    'name' => 'edit any standaardprofiel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any unit content'.
  $permissions['edit any unit content'] = array(
    'name' => 'edit any unit content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any vacature content'.
  $permissions['edit any vacature content'] = array(
    'name' => 'edit any vacature content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit field_attach_secured'.
  $permissions['edit field_attach_secured'] = array(
    'name' => 'edit field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_block_order_input'.
  $permissions['edit field_block_order_input'] = array(
    'name' => 'edit field_block_order_input',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_btw_nummer'.
  $permissions['edit field_btw_nummer'] = array(
    'name' => 'edit field_btw_nummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_clients'.
  $permissions['edit field_clients'] = array(
    'name' => 'edit field_clients',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_geblokkeerd'.
  $permissions['edit field_geblokkeerd'] = array(
    'name' => 'edit field_geblokkeerd',
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

  // Exported permission: 'edit field_naam_bedrijf'.
  $permissions['edit field_naam_bedrijf'] = array(
    'name' => 'edit field_naam_bedrijf',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'edit field_staffelkorting'.
  $permissions['edit field_staffelkorting'] = array(
    'name' => 'edit field_staffelkorting',
    'roles' => array(
      'site_admin' => 'site_admin',
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

  // Exported permission: 'edit field_telefoon'.
  $permissions['edit field_telefoon'] = array(
    'name' => 'edit field_telefoon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own banner content'.
  $permissions['edit own banner content'] = array(
    'name' => 'edit own banner content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own client content'.
  $permissions['edit own client content'] = array(
    'name' => 'edit own client content',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle commerce_order'.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own dorpel_anti_dreunstrook content'.
  $permissions['edit own dorpel_anti_dreunstrook content'] = array(
    'name' => 'edit own dorpel_anti_dreunstrook content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own dorpel_eindstuk content'.
  $permissions['edit own dorpel_eindstuk content'] = array(
    'name' => 'edit own dorpel_eindstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own dorpel_hoek content'.
  $permissions['edit own dorpel_hoek content'] = array(
    'name' => 'edit own dorpel_hoek content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own dorpel_koppelstuk content'.
  $permissions['edit own dorpel_koppelstuk content'] = array(
    'name' => 'edit own dorpel_koppelstuk content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_attach_secured'.
  $permissions['edit own field_attach_secured'] = array(
    'name' => 'edit own field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_block_order_input'.
  $permissions['edit own field_block_order_input'] = array(
    'name' => 'edit own field_block_order_input',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_btw_nummer'.
  $permissions['edit own field_btw_nummer'] = array(
    'name' => 'edit own field_btw_nummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_clients'.
  $permissions['edit own field_clients'] = array(
    'name' => 'edit own field_clients',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_geblokkeerd'.
  $permissions['edit own field_geblokkeerd'] = array(
    'name' => 'edit own field_geblokkeerd',
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

  // Exported permission: 'edit own field_naam_bedrijf'.
  $permissions['edit own field_naam_bedrijf'] = array(
    'name' => 'edit own field_naam_bedrijf',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'edit own field_staffelkorting'.
  $permissions['edit own field_staffelkorting'] = array(
    'name' => 'edit own field_staffelkorting',
    'roles' => array(
      'site_admin' => 'site_admin',
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

  // Exported permission: 'edit own field_telefoon'.
  $permissions['edit own field_telefoon'] = array(
    'name' => 'edit own field_telefoon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own info_pagina content'.
  $permissions['edit own info_pagina content'] = array(
    'name' => 'edit own info_pagina content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own machine content'.
  $permissions['edit own machine content'] = array(
    'name' => 'edit own machine content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own muurkap content'.
  $permissions['edit own muurkap content'] = array(
    'name' => 'edit own muurkap content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own plaatbewerking content'.
  $permissions['edit own plaatbewerking content'] = array(
    'name' => 'edit own plaatbewerking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own product content'.
  $permissions['edit own product content'] = array(
    'name' => 'edit own product content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own raamtablet content'.
  $permissions['edit own raamtablet content'] = array(
    'name' => 'edit own raamtablet content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own sandwichpaneel content'.
  $permissions['edit own sandwichpaneel content'] = array(
    'name' => 'edit own sandwichpaneel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own standaardprofiel content'.
  $permissions['edit own standaardprofiel content'] = array(
    'name' => 'edit own standaardprofiel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own unit content'.
  $permissions['edit own unit content'] = array(
    'name' => 'edit own unit content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own vacature content'.
  $permissions['edit own vacature content'] = array(
    'name' => 'edit own vacature content',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in product_category'.
  $permissions['edit terms in product_category'] = array(
    'name' => 'edit terms in product_category',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as any user'.
  $permissions['masquerade as any user'] = array(
    'name' => 'masquerade as any user',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'post api'.
  $permissions['post api'] = array(
    'name' => 'post api',
    'roles' => array(
      'api' => 'api',
    ),
    'module' => 'feneko_code',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
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

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
      'site_admin' => 'site_admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle commerce_order'.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'commerce_order',
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

  // Exported permission: 'view any commerce_product entity of bundle product'.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any entityform'.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'interne medewerker' => 'interne medewerker',
    ),
    'module' => 'entityform',
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

  // Exported permission: 'view field_block_order_input'.
  $permissions['view field_block_order_input'] = array(
    'name' => 'view field_block_order_input',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_btw_nummer'.
  $permissions['view field_btw_nummer'] = array(
    'name' => 'view field_btw_nummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_clients'.
  $permissions['view field_clients'] = array(
    'name' => 'view field_clients',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_geblokkeerd'.
  $permissions['view field_geblokkeerd'] = array(
    'name' => 'view field_geblokkeerd',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_klantennummer'.
  $permissions['view field_klantennummer'] = array(
    'name' => 'view field_klantennummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_naam_bedrijf'.
  $permissions['view field_naam_bedrijf'] = array(
    'name' => 'view field_naam_bedrijf',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'view field_staffelkorting'.
  $permissions['view field_staffelkorting'] = array(
    'name' => 'view field_staffelkorting',
    'roles' => array(
      'site_admin' => 'site_admin',
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

  // Exported permission: 'view field_telefoon'.
  $permissions['view field_telefoon'] = array(
    'name' => 'view field_telefoon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own field_attach_secured'.
  $permissions['view own field_attach_secured'] = array(
    'name' => 'view own field_attach_secured',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_block_order_input'.
  $permissions['view own field_block_order_input'] = array(
    'name' => 'view own field_block_order_input',
    'roles' => array(
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_btw_nummer'.
  $permissions['view own field_btw_nummer'] = array(
    'name' => 'view own field_btw_nummer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_clients'.
  $permissions['view own field_clients'] = array(
    'name' => 'view own field_clients',
    'roles' => array(
      'handelaar' => 'handelaar',
      'site_admin' => 'site_admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_geblokkeerd'.
  $permissions['view own field_geblokkeerd'] = array(
    'name' => 'view own field_geblokkeerd',
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

  // Exported permission: 'view own field_naam_bedrijf'.
  $permissions['view own field_naam_bedrijf'] = array(
    'name' => 'view own field_naam_bedrijf',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'view own field_staffelkorting'.
  $permissions['view own field_staffelkorting'] = array(
    'name' => 'view own field_staffelkorting',
    'roles' => array(
      'site_admin' => 'site_admin',
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

  // Exported permission: 'view own field_telefoon'.
  $permissions['view own field_telefoon'] = array(
    'name' => 'view own field_telefoon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'interne medewerker' => 'interne medewerker',
      'site_admin' => 'site_admin',
    ),
    'module' => 'system',
  );

  return $permissions;
}
