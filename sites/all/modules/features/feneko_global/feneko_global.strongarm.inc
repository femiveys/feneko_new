<?php
/**
 * @file
 * feneko_global.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feneko_global_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 'Europe/Brussels';
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_first_day';
  $strongarm->value = '1';
  $export['date_first_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_default_export_path';
  $strongarm->value = 'sites/all/modules/features';
  $export['features_default_export_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_sql_norevisions_enabled_entities';
  $strongarm->value = array(
    'field_sql_norevisions_node_banner_enabled' => 1,
    'field_sql_norevisions_node_raamtablet_enabled' => 1,
    'field_sql_norevisions_node_dorpel_anti_dreunstrook_enabled' => 1,
    'field_sql_norevisions_node_dorpel_eindstuk_enabled' => 1,
    'field_sql_norevisions_node_dorpel_hoek_enabled' => 1,
    'field_sql_norevisions_node_dorpel_koppelstuk_enabled' => 1,
    'field_sql_norevisions_node_dorpel_montagebeugel_enabled' => 1,
    'field_sql_norevisions_node_page_enabled' => 1,
    'field_sql_norevisions_node_info_pagina_enabled' => 1,
    'field_sql_norevisions_node_client_enabled' => 1,
    'field_sql_norevisions_node_machine_enabled' => 1,
    'field_sql_norevisions_node_muurkap_enabled' => 1,
    'field_sql_norevisions_node_muurkap_stuk_enabled' => 1,
    'field_sql_norevisions_node_article_enabled' => 1,
    'field_sql_norevisions_node_plaatbewerking_enabled' => 1,
    'field_sql_norevisions_node_product_enabled' => 1,
    'field_sql_norevisions_node_sandwichpaneel_enabled' => 1,
    'field_sql_norevisions_node_standaardprofiel_enabled' => 1,
    'field_sql_norevisions_node_stuk_enabled' => 1,
    'field_sql_norevisions_node_unit_enabled' => 1,
    'field_sql_norevisions_node_vacature_enabled' => 1,
    'field_sql_norevisions_taxonomy_term_tags_enabled' => 1,
    'field_sql_norevisions_taxonomy_term_product_category_enabled' => 1,
    'field_sql_norevisions_commerce_customer_profile_billing_enabled' => 1,
    'field_sql_norevisions_commerce_discount_order_discount_enabled' => 1,
    'field_sql_norevisions_commerce_discount_product_discount_enabled' => 1,
    'field_sql_norevisions_commerce_discount_offer_fixed_amount_enabled' => 1,
    'field_sql_norevisions_commerce_discount_offer_percentage_enabled' => 1,
    'field_sql_norevisions_commerce_discount_offer_free_products_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_dorpel_stuk_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_muurkap_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_muurkap_stuk_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_plaatbewerking_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_raamtablet_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_raamtablet_eindstuk_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_sandwichpaneel_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_standaardprofiel_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_commerce_discount_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_product_discount_enabled' => 1,
    'field_sql_norevisions_commerce_line_item_product_enabled' => 1,
    'field_sql_norevisions_commerce_order_commerce_order_enabled' => 1,
    'field_sql_norevisions_commerce_product_dorpel_anti_dreunstrook_enabled' => 1,
    'field_sql_norevisions_commerce_product_dorpel_eindstuk_enabled' => 1,
    'field_sql_norevisions_commerce_product_dorpel_hoek_enabled' => 1,
    'field_sql_norevisions_commerce_product_dorpel_koppelstuk_enabled' => 1,
    'field_sql_norevisions_commerce_product_dorpel_montagebeugel_enabled' => 1,
    'field_sql_norevisions_commerce_product_muurkap_enabled' => 1,
    'field_sql_norevisions_commerce_product_muurkap_eindstuk_enabled' => 1,
    'field_sql_norevisions_commerce_product_plaatbewerking_enabled' => 1,
    'field_sql_norevisions_commerce_product_product_enabled' => 1,
    'field_sql_norevisions_commerce_product_raamtablet_enabled' => 1,
    'field_sql_norevisions_commerce_product_sandwichpaneel_enabled' => 1,
    'field_sql_norevisions_commerce_product_sandwichpaneel_isolatie_enabled' => 1,
    'field_sql_norevisions_commerce_product_standaardprofiel_enabled' => 1,
    'field_sql_norevisions_commerce_product_unit_enabled' => 1,
    'field_sql_norevisions_entityform_contact_enabled' => 1,
    'field_sql_norevisions_entityform_solliciteer_enabled' => 1,
    'field_sql_norevisions_field_collection_item_field_tel_enabled' => 1,
    'field_sql_norevisions_field_collection_item_field_social_follow_enabled' => 1,
    'field_sql_norevisions_file_image_enabled' => 1,
    'field_sql_norevisions_file_video_enabled' => 1,
    'field_sql_norevisions_file_audio_enabled' => 1,
    'field_sql_norevisions_file_document_enabled' => 1,
    'field_sql_norevisions_user_user_enabled' => 1,
    'field_sql_norevisions_rules_config_rules_config_enabled' => 1,
  );
  $export['field_sql_norevisions_enabled_entities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_string_allowed_formats';
  $strongarm->value = array(
    'filtered_html' => 'filtered_html',
    'full_html' => 'full_html',
    'plain_text' => 'plain_text',
    'php_code' => 0,
  );
  $export['i18n_string_allowed_formats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'nl',
    'name' => 'Dutch',
    'native' => 'NL',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'nl',
    'weight' => '-10',
    'javascript' => 'aj-JSA4vwU12SpenKIK5wU0eMmBOaztKk1doTHAMito',
  );
  $export['language_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'language-default' => array(
      'callbacks' => array(
        'language' => 'language_from_default',
      ),
    ),
  );
  $export['language_negotiation_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_url';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-url-fallback' => array(
      'callbacks' => array(
        'language' => 'locale_language_url_fallback',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_language_providers_weight_language';
  $strongarm->value = array(
    'locale-url' => '-8',
    'locale-session' => '-6',
    'locale-user' => '-4',
    'locale-browser' => '-2',
    'language-default' => '10',
  );
  $export['locale_language_providers_weight_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'feneko';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_feneko_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_comment_user_verification' => 0,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 0,
    'toggle_secondary_menu' => 0,
    'default_logo' => 0,
    'logo_path' => 'public://logo.png',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => 'public://favicon.ico',
    'favicon_upload' => '',
    'jquery_update_jquery_version' => '',
  );
  $export['theme_feneko_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'variable_realm_list_language';
  $strongarm->value = array(
    0 => 'fc_order_email_text',
    1 => 'fc_offer_email_text',
    2 => 'fc_submiting_text',
    3 => 'manyforms_order_email_text',
    4 => 'manyforms_offer_email_text',
    5 => 'manyforms_submiting_text',
    6 => 'site_name',
    7 => 'site_slogan',
    8 => 'maintenance_mode_message',
    9 => 'eu_cookie_compliance',
  );
  $export['variable_realm_list_language'] = $strongarm;

  return $export;
}
