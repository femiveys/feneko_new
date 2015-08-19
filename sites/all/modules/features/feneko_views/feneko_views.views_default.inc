<?php
/**
 * @file
 * feneko_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feneko_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'about';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'About';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'About FenekO';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Afbeelding */
  $handler->display->display_options['fields']['field_afbeelding']['id'] = 'field_afbeelding';
  $handler->display->display_options['fields']['field_afbeelding']['table'] = 'field_data_field_afbeelding';
  $handler->display->display_options['fields']['field_afbeelding']['field'] = 'field_afbeelding';
  $handler->display->display_options['fields']['field_afbeelding']['label'] = '';
  $handler->display->display_options['fields']['field_afbeelding']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_afbeelding']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_afbeelding']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_afbeelding']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_afbeelding']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Field: Content: About */
  $handler->display->display_options['fields']['field_about']['id'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['table'] = 'field_data_field_about';
  $handler->display->display_options['fields']['field_about']['field'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['label'] = '';
  $handler->display->display_options['fields']['field_about']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'info_pagina' => 'info_pagina',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page about */
  $handler = $view->new_display('page', 'Page about', 'page');
  $handler->display->display_options['path'] = 'about';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Over FenekO';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page lever */
  $handler = $view->new_display('page', 'Page lever', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Levertijden';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: levertijden */
  $handler->display->display_options['fields']['field_levertijden']['id'] = 'field_levertijden';
  $handler->display->display_options['fields']['field_levertijden']['table'] = 'field_data_field_levertijden';
  $handler->display->display_options['fields']['field_levertijden']['field'] = 'field_levertijden';
  $handler->display->display_options['fields']['field_levertijden']['label'] = '';
  $handler->display->display_options['fields']['field_levertijden']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_levertijden']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_levertijden']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'levertijden';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Levertijden';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-footer-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page klant */
  $handler = $view->new_display('page', 'Page klant', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Klant worden';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: klant worden */
  $handler->display->display_options['fields']['field_klant_worden']['id'] = 'field_klant_worden';
  $handler->display->display_options['fields']['field_klant_worden']['table'] = 'field_data_field_klant_worden';
  $handler->display->display_options['fields']['field_klant_worden']['field'] = 'field_klant_worden';
  $handler->display->display_options['fields']['field_klant_worden']['label'] = '';
  $handler->display->display_options['fields']['field_klant_worden']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_klant_worden']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_klant_worden']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'klant-worden';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Klant worden';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-footer-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page verkoop */
  $handler = $view->new_display('page', 'Page verkoop', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Verkoopsvoorwaarden';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Verkoopsvoorwaarden */
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['id'] = 'field_verkoopsvoorwaarden';
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['table'] = 'field_data_field_verkoopsvoorwaarden';
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['field'] = 'field_verkoopsvoorwaarden';
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['label'] = '';
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_verkoopsvoorwaarden']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'verkoopsvoorwaarden';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Verkoopsvoorwaarden';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-footer-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page disclaimer */
  $handler = $view->new_display('page', 'Page disclaimer', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Disclaimer';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Disclaimer */
  $handler->display->display_options['fields']['field_disclaimer']['id'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['table'] = 'field_data_field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['field'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['label'] = '';
  $handler->display->display_options['fields']['field_disclaimer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_disclaimer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_disclaimer']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'disclaimer';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Disclaimer';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-footer-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['about'] = $view;

  $view = new view();
  $view->name = 'contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'contact';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Adres */
  $handler->display->display_options['fields']['field_adres_1']['id'] = 'field_adres_1';
  $handler->display->display_options['fields']['field_adres_1']['table'] = 'field_data_field_adres';
  $handler->display->display_options['fields']['field_adres_1']['field'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres_1']['label'] = '';
  $handler->display->display_options['fields']['field_adres_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adres_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_adres_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_adres_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_adres_1']['type'] = 'addressfield_staticmap';
  $handler->display->display_options['fields']['field_adres_1']['settings'] = array(
    'zoom_level' => '14',
    'map_size' => '400x400',
    'map_style' => 'roadmap',
    'advanced_settings_index' => '0',
  );
  /* Field: Content: Adres */
  $handler->display->display_options['fields']['field_adres']['id'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres']['table'] = 'field_data_field_adres';
  $handler->display->display_options['fields']['field_adres']['field'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres']['label'] = '';
  $handler->display->display_options['fields']['field_adres']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_adres']['alter']['text'] = '<i class="fa fa-home"></i>[field_adres]';
  $handler->display->display_options['fields']['field_adres']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_adres']['element_class'] = 'adres';
  $handler->display->display_options['fields']['field_adres']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adres']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_adres']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_adres']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_adres']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_e_mail']['id'] = 'field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['table'] = 'field_data_field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['field'] = 'field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['label'] = '';
  $handler->display->display_options['fields']['field_e_mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_e_mail']['alter']['text'] = '<i class="fa fa-envelope"></i> [field_e_mail]';
  $handler->display->display_options['fields']['field_e_mail']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_e_mail']['element_class'] = 'mail';
  $handler->display->display_options['fields']['field_e_mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_e_mail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_e_mail']['hide_empty'] = TRUE;
  /* Field: Content: Tel */
  $handler->display->display_options['fields']['field_tel']['id'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['table'] = 'field_data_field_tel';
  $handler->display->display_options['fields']['field_tel']['field'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['label'] = '';
  $handler->display->display_options['fields']['field_tel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_tel']['element_wrapper_class'] = 'tel';
  $handler->display->display_options['fields']['field_tel']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tel']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_tel']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tel']['multi_type'] = 'ul';
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = '<i class="fa fa-fax"></i> [field_fax]';
  $handler->display->display_options['fields']['field_fax']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_fax']['element_wrapper_class'] = 'fax';
  $handler->display->display_options['fields']['field_fax']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'info_pagina' => 'info_pagina',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Adres */
  $handler->display->display_options['fields']['field_adres_1']['id'] = 'field_adres_1';
  $handler->display->display_options['fields']['field_adres_1']['table'] = 'field_data_field_adres';
  $handler->display->display_options['fields']['field_adres_1']['field'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres_1']['label'] = '';
  $handler->display->display_options['fields']['field_adres_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_adres_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adres_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_adres_1']['element_wrapper_class'] = 'map';
  $handler->display->display_options['fields']['field_adres_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_adres_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_adres_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_adres_1']['type'] = 'addressfield_staticmap';
  $handler->display->display_options['fields']['field_adres_1']['settings'] = array(
    'zoom_level' => '14',
    'map_size' => '400x400',
    'map_style' => 'roadmap',
    'advanced_settings_index' => '0',
  );
  /* Field: Content: Adres */
  $handler->display->display_options['fields']['field_adres']['id'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres']['table'] = 'field_data_field_adres';
  $handler->display->display_options['fields']['field_adres']['field'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres']['label'] = '';
  $handler->display->display_options['fields']['field_adres']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_adres']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_adres']['alter']['text'] = '<i class="fa fa-home"></i>[field_adres]';
  $handler->display->display_options['fields']['field_adres']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adres']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_adres']['element_wrapper_class'] = 'adres';
  $handler->display->display_options['fields']['field_adres']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_adres']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_adres']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_adres']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Route */
  $handler->display->display_options['fields']['field_route']['id'] = 'field_route';
  $handler->display->display_options['fields']['field_route']['table'] = 'field_data_field_route';
  $handler->display->display_options['fields']['field_route']['field'] = 'field_route';
  $handler->display->display_options['fields']['field_route']['label'] = 'Routebeschrijving';
  $handler->display->display_options['fields']['field_route']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_route']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_route']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_route']['element_wrapper_class'] = 'route';
  $handler->display->display_options['fields']['field_route']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_route']['hide_empty'] = TRUE;
  /* Field: Content: Tel */
  $handler->display->display_options['fields']['field_tel']['id'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['table'] = 'field_data_field_tel';
  $handler->display->display_options['fields']['field_tel']['field'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['label'] = 'Telefoon';
  $handler->display->display_options['fields']['field_tel']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tel']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_tel']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tel']['multi_type'] = 'ul';
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_e_mail']['id'] = 'field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['table'] = 'field_data_field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['field'] = 'field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['label'] = '';
  $handler->display->display_options['fields']['field_e_mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_e_mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_e_mail']['alter']['text'] = '<i class="fa fa-envelope"></i> [field_e_mail]';
  $handler->display->display_options['fields']['field_e_mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_e_mail']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_e_mail']['element_wrapper_class'] = 'mail';
  $handler->display->display_options['fields']['field_e_mail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_e_mail']['hide_empty'] = TRUE;
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['label'] = '';
  $handler->display->display_options['fields']['field_fax']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = '<div class="c-l">
[field_adres_1]
<span>Route</span>
[field_route]
</div>

<div class="c-r">
<div class="adres">
[field_adres]
</div>
<div class="tel">
[field_tel]
</div>
<div class="cl">
[field_e_mail] 
</div>
<div class="cl">
<i class="fa fa-fax"></i> [field_fax]
</div>
</div>';
  $handler->display->display_options['fields']['field_fax']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'contact';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Contact';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $export['contact'] = $view;

  $view = new view();
  $view->name = 'footer_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Footer info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'footer-block';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Openingsuren */
  $handler->display->display_options['fields']['field_openingsuren']['id'] = 'field_openingsuren';
  $handler->display->display_options['fields']['field_openingsuren']['table'] = 'field_data_field_openingsuren';
  $handler->display->display_options['fields']['field_openingsuren']['field'] = 'field_openingsuren';
  $handler->display->display_options['fields']['field_openingsuren']['label'] = '';
  $handler->display->display_options['fields']['field_openingsuren']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_openingsuren']['element_class'] = 'opening';
  $handler->display->display_options['fields']['field_openingsuren']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openingsuren']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_openingsuren']['hide_empty'] = TRUE;
  /* Field: Content: Social follow */
  $handler->display->display_options['fields']['field_social_follow']['id'] = 'field_social_follow';
  $handler->display->display_options['fields']['field_social_follow']['table'] = 'field_data_field_social_follow';
  $handler->display->display_options['fields']['field_social_follow']['field'] = 'field_social_follow';
  $handler->display->display_options['fields']['field_social_follow']['label'] = '';
  $handler->display->display_options['fields']['field_social_follow']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_social_follow']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_social_follow']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  /* Field: Content: Adres */
  $handler->display->display_options['fields']['field_adres']['id'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres']['table'] = 'field_data_field_adres';
  $handler->display->display_options['fields']['field_adres']['field'] = 'field_adres';
  $handler->display->display_options['fields']['field_adres']['label'] = '';
  $handler->display->display_options['fields']['field_adres']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adres']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_adres']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_adres']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_adres']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
      'address-hide-country' => 'address-hide-country',
    ),
  );
  /* Field: Content: Tel */
  $handler->display->display_options['fields']['field_tel']['id'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['table'] = 'field_data_field_tel';
  $handler->display->display_options['fields']['field_tel']['field'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['label'] = '';
  $handler->display->display_options['fields']['field_tel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_tel']['element_wrapper_class'] = 'tel';
  $handler->display->display_options['fields']['field_tel']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tel']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tel']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_tel']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_tel']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'info_pagina' => 'info_pagina',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['footer_info'] = $view;

  $view = new view();
  $view->name = 'front_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front image';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Big image */
  $handler->display->display_options['fields']['field_big_image']['id'] = 'field_big_image';
  $handler->display->display_options['fields']['field_big_image']['table'] = 'field_data_field_big_image';
  $handler->display->display_options['fields']['field_big_image']['field'] = 'field_big_image';
  $handler->display->display_options['fields']['field_big_image']['label'] = '';
  $handler->display->display_options['fields']['field_big_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_big_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_big_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_big_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_big_image']['settings'] = array(
    'image_style' => 'front_image',
    'image_link' => '',
  );
  /* Field: Content: Tekst big image */
  $handler->display->display_options['fields']['field_tekst_big_image']['id'] = 'field_tekst_big_image';
  $handler->display->display_options['fields']['field_tekst_big_image']['table'] = 'field_data_field_tekst_big_image';
  $handler->display->display_options['fields']['field_tekst_big_image']['field'] = 'field_tekst_big_image';
  $handler->display->display_options['fields']['field_tekst_big_image']['label'] = '';
  $handler->display->display_options['fields']['field_tekst_big_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tekst_big_image']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_tekst_big_image']['element_class'] = 'big-image-caption';
  $handler->display->display_options['fields']['field_tekst_big_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tekst_big_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tekst_big_image']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<p class="big-image-caption">[field_tekst_big_image]</p><p class="node-readmore"><a href="/onze-producten">Ontdek ons aanbod&nbsp;&raquo;</a></p>';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'inner-wrapper';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'info_pagina' => 'info_pagina',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['front_image'] = $view;

  $view = new view();
  $view->name = 'jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'teaser-rij job-rij';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Er zijn op dit ogenblik gaan openstaande vacatures.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['preserve_tags'] = 'h2';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Solliciteren tot */
  $handler->display->display_options['fields']['field_ultimate_date']['id'] = 'field_ultimate_date';
  $handler->display->display_options['fields']['field_ultimate_date']['table'] = 'field_data_field_ultimate_date';
  $handler->display->display_options['fields']['field_ultimate_date']['field'] = 'field_ultimate_date';
  $handler->display->display_options['fields']['field_ultimate_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_ultimate_date']['alter']['preserve_tags'] = 'div label';
  $handler->display->display_options['fields']['field_ultimate_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_ultimate_date']['element_wrapper_class'] = 'datum';
  $handler->display->display_options['fields']['field_ultimate_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ultimate_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_ultimate_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = 'p';
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['preserve_tags'] = 'p';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'p';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'node-readmore';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Lees verder';
  /* Sort criterion: Content: Solliciteren tot (field_ultimate_date) */
  $handler->display->display_options['sorts']['field_ultimate_date_value']['id'] = 'field_ultimate_date_value';
  $handler->display->display_options['sorts']['field_ultimate_date_value']['table'] = 'field_data_field_ultimate_date';
  $handler->display->display_options['sorts']['field_ultimate_date_value']['field'] = 'field_ultimate_date_value';
  $handler->display->display_options['sorts']['field_ultimate_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vacature' => 'vacature',
  );
  /* Filter criterion: Content: Solliciteren tot (field_ultimate_date) */
  $handler->display->display_options['filters']['field_ultimate_date_value']['id'] = 'field_ultimate_date_value';
  $handler->display->display_options['filters']['field_ultimate_date_value']['table'] = 'field_data_field_ultimate_date';
  $handler->display->display_options['filters']['field_ultimate_date_value']['field'] = 'field_ultimate_date_value';
  $handler->display->display_options['filters']['field_ultimate_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_ultimate_date_value']['default_date'] = 'today';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'jobs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Jobs';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'All jobs';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['preserve_tags'] = 'h2';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $export['jobs'] = $view;

  $view = new view();
  $view->name = 'machines';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Machines';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Machines';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'teaser-rij machine-rij blocklink';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Afbeelding */
  $handler->display->display_options['fields']['field_afbeelding']['id'] = 'field_afbeelding';
  $handler->display->display_options['fields']['field_afbeelding']['table'] = 'field_data_field_afbeelding';
  $handler->display->display_options['fields']['field_afbeelding']['field'] = 'field_afbeelding';
  $handler->display->display_options['fields']['field_afbeelding']['label'] = '';
  $handler->display->display_options['fields']['field_afbeelding']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_afbeelding']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_afbeelding']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_afbeelding']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_afbeelding']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['preserve_tags'] = 'h2';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = 'p';
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'machine' => 'machine',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'machines';

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['preserve_tags'] = 'h2';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $export['machines'] = $view;

  $view = new view();
  $view->name = 'main_categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Main Categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Onze producten';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_product_category_image',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    2 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'text--uppercase';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Bovenliggend';
  /* Relationship: Taxonomy term: Content using product categorie */
  $handler->display->display_options['relationships']['reverse_field_productcategorie_node']['id'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['relationships']['reverse_field_productcategorie_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_productcategorie_node']['field'] = 'reverse_field_productcategorie_node';
  /* Field: Taxonomy term: product category Image */
  $handler->display->display_options['fields']['field_product_category_image']['id'] = 'field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['table'] = 'field_data_field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['field'] = 'field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_category_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_category_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_category_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_product_category_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_product_category_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_category_image']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]  &raquo;';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'parent';
  $handler->display->display_options['sorts']['name']['order'] = 'DESC';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'product_category' => 'product_category',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['relationship'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '0';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page: onze producten */
  $handler = $view->new_display('page', 'Page: onze producten', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: product category Image */
  $handler->display->display_options['fields']['field_product_category_image']['id'] = 'field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['table'] = 'field_data_field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['field'] = 'field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_category_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_category_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_category_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_product_category_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_product_category_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_category_image']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]  &raquo;';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['path'] = '[name_1]';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'onze-producten';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Producten';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page colors */
  $handler = $view->new_display('page', 'Page colors', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'product_category' => 'product_category',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'colors';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'colors';
  $handler->display->display_options['menu']['title'] = 'colors';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page screens */
  $handler = $view->new_display('page', 'Page screens', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'product_category' => 'product_category',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'screens';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'screens';
  $handler->display->display_options['menu']['title'] = 'screens';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Blok colors en screens */
  $handler = $view->new_display('block', 'Blok colors en screens', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_product_category_image',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    2 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: product category Image */
  $handler->display->display_options['fields']['field_product_category_image']['id'] = 'field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['table'] = 'field_data_field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['field'] = 'field_product_category_image';
  $handler->display->display_options['fields']['field_product_category_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_category_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_category_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_category_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_product_category_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_product_category_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_category_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = 'h3';
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'product_category' => 'product_category',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['relationship'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '0';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_productcategorie_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $export['main_categories'] = $view;

  $view = new view();
  $view->name = 'nieuws';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'nieuws';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'nieuws';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Alle nieuwsberichten';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'teaser-rij nieuws-rij';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Er zijn op dit ogenblik gaan nieuwsberichten.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['preserve_tags'] = 'h2';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<div class="submitted">
<i class="fa fa-calendar"></i> [created] 
</div>';
  $handler->display->display_options['fields']['created']['alter']['preserve_tags'] = 'div';
  $handler->display->display_options['fields']['created']['element_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_class'] = 'datum';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd F Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'nieuws-body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'p';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'node-readmore';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nieuws';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Nieuws';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Alle nieuwsberichten';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $export['nieuws'] = $view;

  $view = new view();
  $view->name = 'related';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'related';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'gerelateerde producten';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Afbeeldingen */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'square_medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'product_category' => 'product_category',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['related'] = $view;

  return $export;
}
