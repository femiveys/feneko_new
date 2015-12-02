<?php
/**
 * Makes the content of a line item beautiful
 *
 * @param $line_item
 *   The line item
 * @param $format
 *   output needs to be 'text', 'xml' or 'ra'
 * @return array/string
 *   Renderable array of string
 */
function fc_line_item_details($line_item, $format = 'ra') {
  $fields = array(
    'commerce_product' => array(
      'field_mke_type',
      'field_muurkap_type',
      'field_standaardprofiel_type',
      'field_muurkap_diepte',
      'field_raamtablet_eindstuk_typeiepte',
      'field_plaatbewerking_dikte',
      'field_raamtablet_eindstuk_type',
      'field_anti_dreunstrook',
      'field_hoek_type',
      'field_maat',
      'field_raamtablet_diepte',
    ),
    'commerce_line_item' => array(
      'field_type_bewerking',
      'field_tekening',
      'field_lakzijde',
      'field_lengte',
      'field_breedte',
      'field_multi_breedte',
      'field_multi_hoek',
      'field_knippen',
      'field_plooien',
      'field_ophanging',
      'field_isolatie_dikte',
      'field_bicolor_kleur',
      'field_eindstukken',
      'field_hoeken',
      'field_koppelstukken',
      'field_anti_dreunstrook',
      'field_aantal_adsn',
      'field_beugels',
      'field_rug',
      'field_gaatjes_rug',
      'field_kant',
      'field_raamtablet_diepte',
      'field_comment',
    ),
  );

  $product = commerce_product_load($line_item->commerce_product[LANGUAGE_NONE][0]['product_id']);
  $output = array();
  $text = '';
  $weight = 0;

  // if($product->type === 'raamtablet_eindstuk' or $product === 'muurkap_eindstuk') {
  //   $fields['commerce_product'][] = 'title';
  // }
// dpm($line_item);

  foreach ($fields as $entity_type => $field_names) {
    $e = $entity_type === 'commerce_product' ? $product : $line_item;

    foreach ($field_names as $field_name) {
      if (isset($e->$field_name)) {
        if($field_ra = _fc_field_output($field_name, $e, $entity_type, $format)) {
          $output[$field_name] = $field_ra;
          $output[$field_name]['#weight'] = $weight++;
        }
      }
    }
  }

  switch ($format) {
    case 'ra':
      // If not empty, add wrapper
      if (!empty($output)) {
        $output = array(
          '#type' => 'container',
          '#attributes' => array('class' => array('line-item-details')),
          'data' => $output,
          '#attached' => array('css' => array(
            drupal_get_path('module', 'feneko_calculator') . '/css/extra_fields.css'
          )),
        );
      }
      break;

    case 'text':
    case 'xml':
      $text = '';
      foreach ($output as $field_name => $value) {
        $text .= $value[$format];
      }
      $output = $text;
      break;

    default:
      drupal_set_message(t('Illegal format: :f', array(':f' => $format)), 'error');
      break;
  }

  return $output;
}


/**
 * Helper function to render a specific field.
 *
 * @param array $field_name
 *   The name of the field
 * @param array $field
 *   The entity instance field value
 * @param array $entity_type
 *   The entity type
 * @param string $format
 *   ra, xml or text
 * @return array / string
 *   Renderable array representing the field or an array with a text or xml key.
 *   NULL otherwise
 */
function _fc_field_output($field_name, $entity, $entity_type, $format) {
  $ra = array();

  $lang = $format === 'xml' ? 'nl' : NULL;

  if ($info = field_info_field($field_name)) {
    $raw_values = field_get_items($entity_type, $entity, $field_name, $lang);

    // Multifields have to be rendered differently
    if ($info['cardinality'] == 1) {
      // These fields should be shown even if empty or 0
      $force_empty = array('field_tekening', 'field_rug');

      // We don't render fields having an empty value
      if (!empty($raw_values[0]['value']) or in_array($field_name, $force_empty)) {
        $display = array(
          'label' => 'inline',
          'settings' => array(
            'decimal_separator' => ',',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
        );
        $ra = field_view_field($entity_type, $entity, $field_name, $display, $lang);

        // For products, we need to take the label from the ATTRIBUTE FIELD SETTINGS
        if($entity_type === 'commerce_product') {
          $instance_info = field_info_instance($entity_type, $field_name, $entity->type);
          $ra['#title'] =  commerce_cart_attribute_widget_title($instance_info);
        }

        // Convert this to just the text for text-only output
        switch ($format) {
          case 'text':
            if($field_name === 'field_tekening') {
              if(isset($ra[0]['#file'])) {
                $file = $ra[0]['#file'];
                $ra = array(
                  'text' => $ra['#title'] . ": " . $file->filename . "\n",
                );
              }
            } else {
              $ra = array(
                'text' => $ra['#title'] . ": " . $ra[0]['#markup'] . "\n",
              );
            }
            break;

          case 'xml':
            if($field_name === 'field_tekening') {
              if(isset($ra[0]['#file'])) {
                $file = $ra[0]['#file'];
                $ra = array(
                  'xml' => $ra['#title'] . ": " . $file->filename . "\n",
                );
              }
            } else {
              $replacements = array(
                '_' => '-',
                ' ' => '-',
              );
              $tag = camelCase($ra['#title']);
              $ra = array(
                'xml' => "<$tag>" . $ra[0]['#markup'] . "</$tag>",
              );
            }
            break;
        }
      }
    } else {
      $ra = _fc_multi_field_ra($entity, $field_name, $format);
    }
  } else {
    $msg = t('Field info for :field was not found', array(':field' => $field_name));
    drupal_set_message($msg, 'error');
  }

  return $ra;
}

function camelCase($str, array $noStrip = array()) {
  // non-alpha and non-numeric characters become spaces
  $str = preg_replace('/[^a-z0-9' . implode("", $noStrip) . ']+/i', ' ', $str);
  $str = trim($str);
  // uppercase the first character of each word
  $str = ucwords($str);
  $str = str_replace(" ", "", $str);
  $str = ucfirst($str);

  return $str;
}

/**
 * Get the renderable array for multivalue fields
 *
 * @param stdClass $entity
 *   The entity holding the field
 * @param string $field_name
 *   The name of the field
 * @param string $format
 *   ra, xml or text
 * @return array
 *   The renderable array
 */
function _fc_multi_field_ra($entity, $field_name, $format) {
  $muurkap_type = NULL;

  if ($entity->type === 'muurkap') {
    $product = commerce_product_load($entity->commerce_product[LANGUAGE_NONE][0]['product_id']);
    $mapping = fc_get_multi_field_mapping($product->field_muurkap_type['und'][0]['value']);
  } else {
    $mapping = fc_get_multi_field_mapping();
  }

  $ra = array();
  foreach ($entity->{$field_name}[LANGUAGE_NONE] as $index => $value) {
    if (!empty($value['value'])) {
      $label = $mapping[$field_name][$index];
      switch ($format) {
        case 'ra':
          $ra[] = array(
            '#prefix' => '<li>',
            '#suffix' => '</li>',
            'data' => array(
              '#prefix' => '<dl>',
              '#suffix' => '</dl>',
              'label' => array(
                '#prefix' => '<dt>',
                '#suffix' => '</dt>',
                '#markup' => $label,
              ),
              'value' => array(
                '#prefix' => '<dd>',
                '#suffix' => '</dd>',
                '#markup' => $value['value'],
              ),
            ),
          );
          break;

        case 'text':
          // $utf_mapping = array(
          //   'α' => 'alpha',
          //   'β' => 'beta ',
          //   'γ' => 'gamma',
          //   'δ' => 'delta',
          // );
          // $label = strtr($label, $utf_mapping);
          $text = '';
          $text .= $field_name === 'field_eindstukken' ? "&nbsp;&nbsp;- " : '';
          $text .= "$label: " . $value['value'];
          $text .= $field_name === 'field_eindstukken' ? "\n" : '';
          $ra[] = $text;
          break;

        case 'xml':
          $tag = camelCase($label);
          $ra[] = "<$tag>" . $value['value'] . "</$tag>";
          break;
      }
    }
  }

  // If not empty, we need to add some wrappers and the label
  if (!empty($ra)) {
    if ($label = commerce_cart_attribute_widget_title(
                  field_info_instance('commerce_line_item', $field_name, $entity->type))) {

      switch ($format) {
        case 'ra':
          $ra = array(
            '#type' => 'container',
            '#attributes' => array('class' => array(
              "field",
              "field-name-field-" . drupal_clean_css_identifier($field_name),
              "field-type-number-integer",
              "field-cardinality-multi",
              "field-label-above",
              "clearfix",
            )),
            'label' => array(
              '#type' => 'container',
              '#attributes' => array('class' => array('field-label')),
              'data' => array('#markup' => $label . ":&nbsp;")
            ),
            'value' => array(
              '#prefix' => '<ul>',
              '#suffix' => '</ul>',
              'data' => $ra,
            ),
          );
          break;

        case 'text':
          $delim = $field_name === 'field_eindstukken' ? "" : ', ';
          $text  = $label . ": ";
          $text .= $field_name === 'field_eindstukken' ? "\n" : '';
          $text .= implode($delim, $ra);
          $text .= $field_name === 'field_eindstukken' ? "" : "\n";
          $ra = array('text' => $text);
          break;

        case 'xml':
          $tag = camelCase($label);
          $ra = array('xml' => "<$tag>" . implode('', $ra) . "</$tag>");
          break;
      }
    } else {
      $msg = t('Instance info for :field on :type Line Item was not found',
                      array(':field' => $field_name, ':type' => $entity->type));
      drupal_set_message($msg, 'error');
    }
  }

  return $ra;
}

function fc_order_overview_mail_text($order) {
  $text = '';

  foreach ($order->commerce_line_items[LANGUAGE_NONE] as $key => $value) {
    $line_item = commerce_line_item_load($value['line_item_id']);
    $text .= strtoupper($line_item->type) . "\n";
    $text .= fc_line_item_details($line_item, 'text');
    $text .= "\n";
  }

  return $text;
}
