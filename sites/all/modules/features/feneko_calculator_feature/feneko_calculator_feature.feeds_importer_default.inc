<?php

/**
 * @file
 * feneko_calculator_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feneko_calculator_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dorpel_anti_dreunstroken';
  $feeds_importer->config = array(
    'name' => 'Dorpel Anti-Dreunstroken',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'dorpel_anti_dreunstrook',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Type',
            'target' => 'field_anti_dreunstrook',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dorpel_anti_dreunstrook',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['dorpel_anti_dreunstroken'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dorpel_eindstukken';
  $feeds_importer->config = array(
    'name' => 'Dorpel Eindstukken',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'dorpel_eindstuk',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Type',
            'target' => 'field_raamtablet_afwerking',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Id',
            'target' => 'field_raamtablet_eindstuk_type',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dorpel_eindstuk',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['dorpel_eindstukken'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dorpel_hoeken';
  $feeds_importer->config = array(
    'name' => 'Dorpel Hoeken',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'dorpel_hoek',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Type',
            'target' => 'field_raamtablet_afwerking',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Id',
            'target' => 'field_hoek_type',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dorpel_hoek',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['dorpel_hoeken'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dorpel_koppelstukken';
  $feeds_importer->config = array(
    'name' => 'Dorpel Koppelstukken',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'dorpel_koppelstuk',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Type',
            'target' => 'field_raamtablet_afwerking',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dorpel_koppelstuk',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['dorpel_koppelstukken'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dorpel_montagebeugels';
  $feeds_importer->config = array(
    'name' => 'Dorpel Montagebeugels',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
        'encoding' => 'UTF-8',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'dorpel_montagebeugel',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Maat',
            'target' => 'field_montagebeugel_maat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Type',
            'target' => 'field_standaardprofiel_afwerking',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dorpel_montagebeugel',
        'insert_new' => '1',
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['dorpel_montagebeugels'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'muurkap_eindstukken';
  $feeds_importer->config = array(
    'name' => 'Muurkap Eindstukken',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'muurkap_eindstuk',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'Type',
            'target' => 'field_muurkap_type',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Breedte',
            'target' => 'field_muurkap_diepte',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Afwerking',
            'target' => 'field_standaardprofiel_afwerking',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'MKE type',
            'target' => 'field_mke_type',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'muurkap_eindstuk',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['muurkap_eindstukken'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'muurkappen';
  $feeds_importer->config = array(
    'name' => 'Muurkappen',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://calculator',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'muurkap',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'Type',
            'target' => 'field_muurkap_type',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Breedte',
            'target' => 'field_muurkap_diepte',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Afwerking',
            'target' => 'field_standaardprofiel_afwerking',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'lengte',
            'target' => 'field_raamtablet_lengte',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'muurkap',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['muurkappen'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'plaatbewerkingen';
  $feeds_importer->config = array(
    'name' => 'Plaatbewerkingen',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'plaatbewerking',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'Type',
            'target' => 'field_plaatbewerking_afwerking',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'lengte',
            'target' => 'field_sandwichpaneel_lengte',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'dikte',
            'target' => 'field_plaatbewerking_dikte',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'plaatbewerking',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['plaatbewerkingen'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'raamtablet_eindstukken';
  $feeds_importer->config = array(
    'name' => 'Raamtablet Eindstukken',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'raamtablet_eindstuk',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Type',
            'target' => 'field_raamtablet_afwerking',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Product',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'raamtablet_eindstuk',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['raamtablet_eindstukken'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'raamtabletten';
  $feeds_importer->config = array(
    'name' => 'Raamtabletten',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://calculator',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'raamtablet',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'Id',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Diepte',
            'target' => 'field_raamtablet_diepte',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'type',
            'target' => 'field_raamtablet_afwerking',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'lengte',
            'target' => 'field_raamtablet_lengte',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'raamtablet',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['raamtabletten'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'sandwichpanelen';
  $feeds_importer->config = array(
    'name' => 'Sandwichpanelen',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'sandwichpaneel',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'lengte',
            'target' => 'field_sandwichpaneel_lengte',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Plaat 1',
            'target' => 'field_sandwichpaneel_afwerking',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Plaat 2',
            'target' => 'field_sandwichpaneel_afwerking_2',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'sandwichpaneel',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['sandwichpanelen'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'sandwichpanelen_isolatie';
  $feeds_importer->config = array(
    'name' => 'Sandwichpanelen Isolatie',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'sandwichpaneel_isolatie',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'type',
            'target' => 'field_isolatie_dikte',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'lengte',
            'target' => 'field_sandwichpaneel_lengte',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'titel',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'sandwichpaneel_isolatie',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['sandwichpanelen_isolatie'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'standaardprofielen';
  $feeds_importer->config = array(
    'name' => 'Standaardprofielen',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
        'delete_uploaded_file' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
        'encoding' => 'UTF-8',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'standaardprofiel',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'Referentie',
            'target' => 'sku',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Referentie',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'afwerking',
            'target' => 'field_standaardprofiel_afwerking',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'type',
            'target' => 'field_standaardprofiel_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'maat',
            'target' => 'field_maat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Stock',
            'target' => 'field_stockprofiel',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'standaardprofiel',
        'insert_new' => 1,
        'update_non_existent' => 'skip',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['standaardprofielen'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'units';
  $feeds_importer->config = array(
    'name' => 'Units',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => '',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'unit',
        'author' => 0,
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'referentie',
            'target' => 'sku',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'omschrijving',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'unit',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['units'] = $feeds_importer;

  return $export;
}
