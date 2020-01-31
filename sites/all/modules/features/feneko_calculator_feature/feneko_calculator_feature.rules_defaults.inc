<?php

/**
 * @file
 * feneko_calculator_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feneko_calculator_feature_default_rules_configuration() {
  $items = array();
  $items['commerce_checkout_send_e_mail_client'] = entity_import('rules_config', '{ "commerce_checkout_send_e_mail_client" : {
      "LABEL" : "Send an order notification e-mail to Client",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "[commerce-order:owner:name],\\r\\n\\r\\nBedankt voor je [commerce-order:field-order-type].\\r\\nIn de bijlage vind je een overzicht van je aanvraag.\\r\\n\\r\\nmvg,\\r\\n\\r\\nFenekO",
            "from" : "Feneko \\u003Cofferte@feneko.be\\u003E",
            "language" : [ "commerce-order:owner:language" ]
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_send_e_mail_feneko'] = entity_import('rules_config', '{ "commerce_checkout_send_e_mail_feneko" : {
      "LABEL" : "Send an order notification e-mail to FenekO",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_order_type" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "Feneko \\u003Colivier@feneko.be\\u003E",
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "[commerce-order:owner:name] van [commerce-order:owner:field-naam-bedrijf] ([commerce-order:field_order4])  heeft net een bestellling geplaatst.\\r\\n\\r\\nIn de bijlage vind je een overzicht van de bestelling.\\r\\n\\r\\nmvg,\\r\\n\\r\\nFenekO",
            "from" : "Feneko \\u003Cofferte@feneko.be\\u003E",
            "language" : "nl"
          }
        }
      ]
    }
  }');
  $items['feneko_calculator_feature_plaatbewerking_add_lasbtn_price'] = entity_import('rules_config', '{ "feneko_calculator_feature_plaatbewerking_add_lasbtn_price" : {
      "LABEL" : "Plaatbewerking Add Lasbouten price",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "plaatbewerking" : "plaatbewerking" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_ophanging" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:field-ophanging" ],
            "value" : "lasbouten"
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "EH-lasbout" },
            "PROVIDE" : { "variable_added" : { "lasbout_sku" : "Lasbout SKU" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "lasbout-sku" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "lasbout" : "Lasbout" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-lengte" ],
              "op" : "\\/",
              "input_2" : "700"
            },
            "PROVIDE" : { "result" : { "roundup_float" : "Roundup (floating)" } }
          }
        },
        { "data_convert" : {
            "USING" : {
              "type" : "integer",
              "value" : [ "roundup-float" ],
              "rounding_behavior" : "up"
            },
            "PROVIDE" : { "conversion_result" : { "roundup" : "Roundup" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "roundup" ],
              "op" : "*",
              "input_2" : [ "lasbout:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "lasbouten_price" : "Lasbouten price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "lasbouten-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['feneko_calculator_feature_standaarprofiel_niet_stock'] = entity_import('rules_config', '{ "feneko_calculator_feature_standaarprofiel_niet_stock" : {
      "LABEL" : "Standaarprofiel (niet-stock)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "feneko_calculator", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "standaardprofiel" : "standaardprofiel" } }
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "standaardprofiel"
          }
        },
        { "NOT data_is" : {
            "data" : [ "commerce-line-item:commerce-product:field-stockprofiel" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "fc_niet_stock_standaardprofiel" : { "line_item" : [ "commerce-line-item" ] } }
      ]
    }
  }');
  $items['rules_add_knippen_price'] = entity_import('rules_config', '{ "rules_add_knippen_price" : {
      "LABEL" : "Standaardprofiel (stock) Add Knippen Price",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_knippen" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "standaardprofiel" : "standaardprofiel" } }
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "standaardprofiel"
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:field-stockprofiel" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "EH-knip" },
            "PROVIDE" : { "variable_added" : { "knip_sku" : "Knip SKU" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "knip-sku" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "knip" : "Knip" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "knip:0:commerce-price:amount" ],
              "op" : "*",
              "input_2" : [ "commerce-line-item:field-knippen" ]
            },
            "PROVIDE" : { "result" : { "knippen_price" : "Knippen Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "knippen-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calc_knippen'] = entity_import('rules_config', '{ "rules_calc_knippen" : {
      "LABEL" : "Standaardprofiel (stock) Calculate #Knippen Price",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-5",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "standaardprofiel" : "standaardprofiel" } }
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "standaardprofiel"
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_knippen" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:field-stockprofiel" ],
            "value" : "1"
          }
        },
        { "NOT data_is" : {
            "data" : [ "commerce-line-item:field-standaardprofiel-lengte" ],
            "value" : "6000"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-line-item:field-knippen" ], "value" : "2" } }
      ]
    }
  }');
  $items['rules_handle_minimum_invoice_amount'] = entity_import('rules_config', '{ "rules_handle_minimum_invoice_amount" : {
      "LABEL" : "Handle minimum invoice amount",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "feneko_calculator", "commerce_discount" ],
      "ON" : { "commerce_discount_order" : [] },
      "DO" : [ { "fc_minimum_invoice_amount" : { "order" : [ "commerce-order" ] } } ]
    }
  }');
  $items['rules_muurkap_add_stukken'] = entity_import('rules_config', '{ "rules_muurkap_add_stukken" : {
      "LABEL" : "Muurkap Add Stukken",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "6",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "muurkap" : "muurkap" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_standaardprofiel_afwerking"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_raamtablet_lengte"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_muurkap_type"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_muurkap_diepte"
          }
        }
      ],
      "DO" : [
        { "data_convert" : {
            "USING" : {
              "type" : "token",
              "value" : [ "commerce-line-item:commerce-product:field-standaardprofiel-afwerking" ]
            },
            "PROVIDE" : { "conversion_result" : { "afwerking_token" : "Afwerking Token" } }
          }
        },
        { "data_convert" : {
            "USING" : {
              "type" : "integer",
              "value" : [ "commerce-line-item:commerce-product:field-muurkap-type" ]
            },
            "PROVIDE" : { "conversion_result" : { "muurkap_type" : "Muurkap Type" } }
          }
        },
        { "data_convert" : {
            "USING" : {
              "type" : "integer",
              "value" : [ "commerce-line-item:commerce-product:field-muurkap-diepte" ]
            },
            "PROVIDE" : { "conversion_result" : { "diepte" : "Diepte" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "afwerking-token" ] },
            "PROVIDE" : { "variable_added" : { "afwerking" : "Afwerking" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-eindstukken:0" ],
              "op" : "+",
              "input_2" : [ "commerce-line-item:field-eindstukken:1" ]
            },
            "PROVIDE" : { "result" : { "num_eindstukken_1" : "Number of Eindstukken 1" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-eindstukken:2" ],
              "op" : "+",
              "input_2" : [ "commerce-line-item:field-eindstukken:3" ]
            },
            "PROVIDE" : { "result" : { "num_eindstukken_2" : "Number of Eindstukken 2" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "MKE-[muurkap-type:value]-[diepte:value]-[afwerking:value]-Eindstuk"
            },
            "PROVIDE" : { "variable_added" : { "sku_eindstuk_1" : "SKU Eindstuk 1" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "MKE-[muurkap-type:value]-[diepte:value]-[afwerking:value]-Eindstuk"
            },
            "PROVIDE" : { "variable_added" : { "sku_eindstuk_2" : "SKU Eindstuk 2" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "MKE-[muurkap-type:value]-[diepte:value]-[afwerking:value]-Koppelstuk"
            },
            "PROVIDE" : { "variable_added" : { "sku_koppelstuk" : "SKU Koppelstuk" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "MKE-[muurkap-type:value]-[diepte:value]-[afwerking:value]-Hoek"
            },
            "PROVIDE" : { "variable_added" : { "sku_buitenhoek" : "SKU Buitenhoek" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "MKE-[muurkap-type:value]-[diepte:value]-[afwerking:value]-Hoek"
            },
            "PROVIDE" : { "variable_added" : { "sku_binnenhoek" : "SKU Binnenhoek" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "MKE-[muurkap-type:value]-[diepte:value]-[afwerking:value]-Beugel"
            },
            "PROVIDE" : { "variable_added" : { "sku_beugel" : "SKU Beugel" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-eindstuk-1" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "eindstuk_1" : "Eindstuk 1" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-eindstuk-2" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "eindstuk_2" : "Eindstuk 2" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-koppelstuk" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "koppelstuk" : "Koppelstuk" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-buitenhoek" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "buitenhoek" : "Buitenhoek" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-binnenhoek" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "binnenhoek" : "Binnenhoek" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-beugel" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "beugel" : "Beugel" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "num-eindstukken-1" ],
              "op" : "*",
              "input_2" : [ "eindstuk-1:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "eindstukken_1_price" : "Eindstukken 1 Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "num-eindstukken-2" ],
              "op" : "*",
              "input_2" : [ "eindstuk-2:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "eindstukken_2_price" : "Eindstukken 2 Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-koppelstukken" ],
              "op" : "*",
              "input_2" : [ "koppelstuk:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "koppelstukken_price" : "Koppelstukken Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-hoeken:0" ],
              "op" : "*",
              "input_2" : [ "binnenhoek:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "binnenhoek_price" : "Binnenhoek Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-hoeken:1" ],
              "op" : "*",
              "input_2" : [ "buitenhoek:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "buitenhoek_price" : "Buitenhoek Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-beugels" ],
              "op" : "*",
              "input_2" : [ "beugel:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "beugel_price" : "Beugel Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "eindstukken-1-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "eindstukken-2-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "koppelstukken-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "binnenhoek-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "buitenhoek-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "beugel-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_plaatbewerking'] = entity_import('rules_config', '{ "rules_plaatbewerking" : {
      "LABEL" : "Plaatbewerking",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "plaatbewerking" : "plaatbewerking" } }
          }
        }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_multiply" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:field-breedte" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "EH-Vastekostperstuk" },
            "PROVIDE" : { "variable_added" : { "sku_vaste_kost" : "SKU Vaste kost" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-vaste-kost" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "vaste_kost" : "Vaste Kost" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "vaste-kost:0:commerce-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_plaatbewerking_add_plooien_price'] = entity_import('rules_config', '{ "rules_plaatbewerking_add_plooien_price" : {
      "LABEL" : "Plaatbewerking Add Plooien Price",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "plaatbewerking" : "plaatbewerking" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_plooien" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "EH-plooi" },
            "PROVIDE" : { "variable_added" : { "plooi_sku" : "Plooi SKU" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "plooi-sku" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "plooi" : "Plooi" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "plooi:0:commerce-price:amount" ],
              "op" : "*",
              "input_2" : [ "commerce-line-item:field-plooien" ]
            },
            "PROVIDE" : { "result" : { "plooien_price" : "Plooien Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "plooien-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_raamtablet_add_anti_dreunstrook'] = entity_import('rules_config', '{ "rules_raamtablet_add_anti_dreunstrook" : {
      "LABEL" : "Raamtablet Add Anti-Dreunstrook",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "6",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "raamtablet" : "raamtablet" } }
          }
        },
        { "NOT data_is_empty" : { "data" : [ "commerce-line-item:field-aantal-adsn" ] } }
      ],
      "DO" : [
        { "data_convert" : {
            "USING" : {
              "type" : "token",
              "value" : [ "commerce-line-item:field-anti-dreunstrook" ]
            },
            "PROVIDE" : { "conversion_result" : { "sku_anti_dreunstrook" : "SKU Anti-Dreunstrook" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-anti-dreunstrook" ]
            },
            "PROVIDE" : { "entity_fetched" : { "anti_dreunstrook" : "Anti-Dreunstrook" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-aantal-adsn" ],
              "op" : "*",
              "input_2" : [ "anti-dreunstrook:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "anti_dreunstrook_price" : "Anti-Dreunstrook Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "anti-dreunstrook-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_raamtablet_add_stukken'] = entity_import('rules_config', '{ "rules_raamtablet_add_stukken" : {
      "LABEL" : "Raamtablet Add Stukken",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "6",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "raamtablet" : "raamtablet" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_raamtablet_afwerking"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_raamtablet_lengte"
          }
        }
      ],
      "DO" : [
        { "data_convert" : {
            "USING" : {
              "type" : "token",
              "value" : [ "commerce-line-item:commerce-product:field-raamtablet-afwerking" ]
            },
            "PROVIDE" : { "conversion_result" : { "afwerking_token" : "Afwerking Token" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "afwerking-token" ] },
            "PROVIDE" : { "variable_added" : { "afwerking" : "Afwerking" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-eindstukken:0" ],
              "op" : "+",
              "input_2" : [ "commerce-line-item:field-eindstukken:1" ]
            },
            "PROVIDE" : { "result" : { "num_eindstukken_1" : "Number of Eindstukken 1" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-eindstukken:2" ],
              "op" : "+",
              "input_2" : [ "commerce-line-item:field-eindstukken:3" ]
            },
            "PROVIDE" : { "result" : { "num_eindstukken_2" : "Number of Eindstukken 2" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "RT-ET1-[afwerking:value]" },
            "PROVIDE" : { "variable_added" : { "sku_eindstuk_1" : "SKU Eindstuk 1" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "RT-ET2-[afwerking:value]" },
            "PROVIDE" : { "variable_added" : { "sku_eindstuk_2" : "SKU Eindstuk 2" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "RT-K-[afwerking:value]" },
            "PROVIDE" : { "variable_added" : { "sku_koppelstuk" : "SKU Koppelstuk" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "RT-BUH-[afwerking:value]" },
            "PROVIDE" : { "variable_added" : { "sku_buitenhoek" : "SKU Buitenhoek" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "RT-BIH-[afwerking:value]" },
            "PROVIDE" : { "variable_added" : { "sku_binnenhoek" : "SKU Binnenhoek" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-eindstuk-1" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "eindstuk_1" : "Eindstuk 1" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-eindstuk-2" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "eindstuk_2" : "Eindstuk 2" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-koppelstuk" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "koppelstuk" : "Koppelstuk" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-buitenhoek" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "buitenhoek" : "Buitenhoek" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-binnenhoek" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "binnenhoek" : "Binnenhoek" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "num-eindstukken-1" ],
              "op" : "*",
              "input_2" : [ "eindstuk-1:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "eindstukken_1_price" : "Eindstukken 1 Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "num-eindstukken-2" ],
              "op" : "*",
              "input_2" : [ "eindstuk-2:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "eindstukken_2_price" : "Eindstukken 2 Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-koppelstukken" ],
              "op" : "*",
              "input_2" : [ "koppelstuk:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "koppelstukken_price" : "Koppelstukken Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-hoeken:0" ],
              "op" : "*",
              "input_2" : [ "binnenhoek:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "binnenhoek_price" : "Binnenhoek Price" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-hoeken:1" ],
              "op" : "*",
              "input_2" : [ "buitenhoek:0:commerce-price:amount" ]
            },
            "PROVIDE" : { "result" : { "buitenhoek_price" : "Buitenhoek Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "eindstukken-1-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "eindstukken-2-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "koppelstukken-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "binnenhoek-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "buitenhoek-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_raamtablet_muurkap'] = entity_import('rules_config', '{ "rules_raamtablet_muurkap" : {
      "LABEL" : "Raamtablet\\/Muurkap",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "muurkap" : "muurkap", "raamtablet" : "raamtablet" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_raamtablet_lengte"
          }
        }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_multiply" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:commerce-product:field-raamtablet-lengte" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        },
        { "commerce_line_item_unit_price_divide" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : "1000",
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_raamtablet_muurkap_add_knip'] = entity_import('rules_config', '{ "rules_raamtablet_muurkap_add_knip" : {
      "LABEL" : "Raamtablet\\/Muurkap Add Knip",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "muurkap" : "muurkap", "raamtablet" : "raamtablet" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_lengte" } },
        { "NOT data_is" : {
            "data" : [ "commerce-line-item:field-lengte" ],
            "op" : "IN",
            "value" : { "value" : [ "1000", "2000", "3000", "4000" ] }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "EH-knip" },
            "PROVIDE" : { "variable_added" : { "sku_knip" : "SKU Knip" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-knip" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "knip" : "Knip" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "knip:0:commerce-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_round_price'] = entity_import('rules_config', '{ "rules_round_price" : {
      "LABEL" : "Round Price",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "DO" : [
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : "0",
            "component_name" : "base_price",
            "round_mode" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_sandwichpaneel'] = entity_import('rules_config', '{ "rules_sandwichpaneel" : {
      "LABEL" : "Sandwichpaneel",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "sandwichpaneel" : "sandwichpaneel" } }
          }
        }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_multiply" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:field-breedte" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_sandwichpaneel_add_isolatie'] = entity_import('rules_config', '{ "rules_sandwichpaneel_add_isolatie" : {
      "LABEL" : "Sandwichpaneel add Isolatie",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "sandwichpaneel" : "sandwichpaneel" } }
          }
        },
        { "NOT data_is" : { "data" : [ "commerce-line-item:field-isolatie-dikte" ], "value" : "20" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_sandwichpaneel_lengte"
          }
        }
      ],
      "DO" : [
        { "data_convert" : {
            "USING" : {
              "type" : "integer",
              "value" : [ "commerce-line-item:field-isolatie-dikte" ]
            },
            "PROVIDE" : { "conversion_result" : { "iso_dikte" : "Isolatie Dikte (integer)" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "SW-ISO-[iso-dikte:value]-[commerce-line-item:commerce-product:field-sandwichpaneel-lengte]"
            },
            "PROVIDE" : { "variable_added" : { "sku_isolatie" : "SKU Isolatie" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "sku-isolatie" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "isolatie" : "Isolatie" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "isolatie:0:commerce-price:amount" ],
              "op" : "*",
              "input_2" : [ "commerce-line-item:field-breedte" ]
            },
            "PROVIDE" : { "result" : { "isolatie_price" : "Isolatie Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "isolatie-price" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_sandwichpaneel_lengte_breedte_optimalisatie'] = entity_import('rules_config', '{ "rules_sandwichpaneel_lengte_breedte_optimalisatie" : {
      "LABEL" : "Sandwichpaneel Lengte-Breedte optimalisatie",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-6",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "feneko_calculator", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "sandwichpaneel" : "sandwichpaneel" } }
          }
        }
      ],
      "DO" : [
        { "fc_lengte_breedte_optimisation" : { "line_item" : [ "commerce-line-item" ] } }
      ]
    }
  }');
  $items['rules_set_base_price'] = entity_import('rules_config', '{ "rules_set_base_price" : {
      "LABEL" : "Set Base Price",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-5",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_base_price" } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "commerce-line-item:field-base-price:amount" ],
            "value" : [ "commerce-line-item:commerce-unit-price:amount" ]
          }
        }
      ]
    }
  }');
  $items['rules_skip_checkout_pages'] = entity_import('rules_config', '{ "rules_skip_checkout_pages" : {
      "LABEL" : "Skip checkout pages",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_page" : [] },
      "DO" : [
        { "commerce_rules_extra_change_page" : { "page_id" : "checkout", "submit_value" : "Plaats bestelling" } }
      ]
    }
  }');
  $items['rules_standaarprofiel'] = entity_import('rules_config', '{ "rules_standaarprofiel" : {
      "LABEL" : "Standaarprofiel (stock)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "feneko_calculator", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "standaardprofiel" : "standaardprofiel" } }
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "standaardprofiel"
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:field-stockprofiel" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "fc_stock_standaardprofiel" : { "line_item" : [ "commerce-line-item" ] } }
      ]
    }
  }');
  $items['rules_standaarprofiel_lengte'] = entity_import('rules_config', '{ "rules_standaarprofiel_lengte" : {
      "LABEL" : "Standaarprofiel Lengte",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "calculator" ],
      "REQUIRES" : [ "rules", "php", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "standaardprofiel" : "standaardprofiel" } }
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "standaardprofiel"
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_lengte" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item" ],
            "field" : "field_standaardprofiel_lengte"
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "\\/\\/ Set the field_standaardprofiel_lengte based on the field_lengte\\r\\n$field = field_info_field(\\u0027field_standaardprofiel_lengte\\u0027);\\r\\n$options = $field[\\u0027settings\\u0027][\\u0027allowed_values\\u0027];\\r\\n$lengte = $commerce_line_item-\\u003Efield_lengte[\\u0027und\\u0027][0][\\u0027value\\u0027];\\r\\n$commerce_line_item-\\u003Efield_standaardprofiel_lengte[LANGUAGE_NONE][0][\\u0027value\\u0027] = fc_get_discrete_lengte($lengte, $options);\\r\\n" } }
      ]
    }
  }');
  return $items;
}
