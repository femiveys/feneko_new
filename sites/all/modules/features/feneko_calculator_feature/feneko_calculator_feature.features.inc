<?php
/**
 * @file
 * feneko_calculator_feature.features.inc
 */

/**
 * Implements hook_commerce_features_default_checkout_panes().
 */
function feneko_calculator_feature_commerce_features_default_checkout_panes() {
  $panes = array();

  $panes['account'] = array(
    'page' => 'disabled',
    'weight' => -17,
    'pane_id' => 'account',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['cart_contents'] = array(
    'page' => 'checkout',
    'weight' => -19,
    'pane_id' => 'cart_contents',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['checkout_completion_message'] = array(
    'page' => 'complete',
    'fieldset' => 0,
    'pane_id' => 'checkout_completion_message',
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -19,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['checkout_review'] = array(
    'page' => 'disabled',
    'fieldset' => 0,
    'pane_id' => 'checkout_review',
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -18,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['commerce_fieldgroup_pane__group_order_info'] = array(
    'enabled' => 1,
    'pane_id' => 'commerce_fieldgroup_pane__group_order_info',
    'page' => 'checkout',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -20,
    'review' => 1,
  );

  $panes['customer_profile_billing'] = array(
    'page' => 'disabled',
    'weight' => -16,
    'pane_id' => 'customer_profile_billing',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  return $panes;
}

/**
 * Implements hook_default_commerce_discount().
 */
function feneko_calculator_feature_default_commerce_discount() {
  $items = array();
  $items['discount_global_discount_0_200'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_0_200",
    "label" : "Global discount 0-200",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -30%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "30.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 0, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 20000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  $items['discount_global_discount_1200_16'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_1200_16",
    "label" : "Global discount 1200-1600",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -44%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "44.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 120000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 160000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  $items['discount_global_discount_1600_2000'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_1600_2000",
    "label" : "Global discount 1600-2000",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -47%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "47.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 160000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 200000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  $items['discount_global_discount_2000_2400'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_2000_2400",
    "label" : "Global discount 2000-2400",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -50%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "50.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 200000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 240000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  $items['discount_global_discount_200_400'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_200_400",
    "label" : "Global discount 0200-400",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -35%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "35.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 20000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 40000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  $items['discount_global_discount_2400_'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_2400_",
    "label" : "Global discount 2400-",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -53%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "53.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 240000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        }
      ]
    }
  }');
  $items['discount_global_discount_400_800'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_400_800",
    "label" : "Global discount 0400-800",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -38%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "38.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 40000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 80000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  $items['discount_global_discount_800_120'] = entity_import('commerce_discount', '{
    "name" : "discount_global_discount_800_120",
    "label" : "Global discount 0800-1200",
    "type" : "order_discount",
    "status" : "1",
    "component_title" : "Korting: -41%",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "41.00" } ] }
    },
    "inline_conditions" : { "und" : [
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 80000000, "currency_code" : "EUR" },
            "condition_logic_operator" : null
          },
          "condition_negate" : 0
        },
        {
          "condition_name" : "commerce_order_compare_order_amount",
          "condition_settings" : {
            "operator" : "\\u003E",
            "total" : { "amount" : 120000000, "currency_code" : "EUR" }
          },
          "condition_negate" : 1,
          "condition_logic_operator" : "1"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_commerce_line_item_default_types().
 */
function feneko_calculator_feature_commerce_line_item_default_types() {
  $items = array(
    'dorpel_stuk' => array(
      'name' => 'Dorpel Stuk',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'muurkap' => array(
      'name' => 'Muurkap',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'plaatbewerking' => array(
      'name' => 'Plaatbewerking',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'raamtablet' => array(
      'name' => 'Dorpel',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'raamtablet_eindstuk' => array(
      'name' => 'Dorpel Eindstuk',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'sandwichpaneel' => array(
      'name' => 'Sandwichpaneel',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'standaardprofiel' => array(
      'name' => 'Standaardprofiel',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function feneko_calculator_feature_commerce_product_default_types() {
  $items = array(
    'dorpel_anti_dreunstrook' => array(
      'type' => 'dorpel_anti_dreunstrook',
      'name' => 'Dorpel Anti-Dreunstrook',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'dorpel_eindstuk' => array(
      'type' => 'dorpel_eindstuk',
      'name' => 'Dorpel Eindstuk',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'dorpel_hoek' => array(
      'type' => 'dorpel_hoek',
      'name' => 'Dorpel Hoek',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'dorpel_koppelstuk' => array(
      'type' => 'dorpel_koppelstuk',
      'name' => 'Dorpel Koppelstuk',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'muurkap' => array(
      'type' => 'muurkap',
      'name' => 'Muurkap',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'muurkap_eindstuk' => array(
      'type' => 'muurkap_eindstuk',
      'name' => 'Muurkap Eindstuk',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'plaatbewerking' => array(
      'type' => 'plaatbewerking',
      'name' => 'Plaatbewerking',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'raamtablet' => array(
      'type' => 'raamtablet',
      'name' => 'Dorpel',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'raamtablet_eindstuk' => array(
      'type' => 'raamtablet_eindstuk',
      'name' => 'Dorpel Eindstuk Old',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'sandwichpaneel' => array(
      'type' => 'sandwichpaneel',
      'name' => 'Sandwichpaneel',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'sandwichpaneel_isolatie' => array(
      'type' => 'sandwichpaneel_isolatie',
      'name' => 'Sandwichpaneel Isolatie',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'standaardprofiel' => array(
      'type' => 'standaardprofiel',
      'name' => 'Standaardprofiel',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'unit' => array(
      'type' => 'unit',
      'name' => 'Unit',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function feneko_calculator_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feneko_calculator_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feneko_calculator_feature_node_info() {
  $items = array(
    'dorpel_anti_dreunstrook' => array(
      'name' => t('Dorpel Anti-Dreunstrook'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'dorpel_eindstuk' => array(
      'name' => t('Dorpel Eindstuk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'dorpel_hoek' => array(
      'name' => t('Dorpel Hoek'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'dorpel_koppelstuk' => array(
      'name' => t('Dorpel Koppelstuk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'muurkap' => array(
      'name' => t('Muurkap'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'plaatbewerking' => array(
      'name' => t('Plaatbewerking'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'raamtablet' => array(
      'name' => t('Dorpel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'sandwichpaneel' => array(
      'name' => t('Sandwichpaneel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'standaardprofiel' => array(
      'name' => t('Standaardprofiel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'stuk' => array(
      'name' => t('Stuk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'unit' => array(
      'name' => t('Unit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
