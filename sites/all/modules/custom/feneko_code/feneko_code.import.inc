<?php
// SQL om client duplicates te vinden
// SELECT node.title, entity_id, nid, COUNT(field_client_number_value)
// FROM field_data_field_client_number, node
// WHERE field_data_field_client_number.entity_id = node.nid
// GROUP BY field_client_number_value
// HAVING COUNT(field_client_number_value) > 1
//
// SELECT node.title, entity_id, field_client_number_value
// FROM field_data_field_client_number, node
// WHERE field_data_field_client_number.entity_id = node.nid and field_client_number_value in (11,16,283,481,505,533,752,755,1912,1992,2227,2388,2656,2700,2702,2704,2806,2841,3044,3125,3375,3869,3870)
// ORDER BY field_client_number_value


function feneko_code_import_form($form, &$form_state) {
  $formaat = "formaat (gescheiden door <strong>punt-comma's</strong>).</li>";
  // $csv = "<li>Upload een bestand in <strong>CSV</strong> $formaat";
  $csvzip = "<li>Upload een bestand in <strong>.csv</strong> of <strong>.zip</strong> $formaat";
  $ral      = "<ul>$csvzip<li>Velden: kleurcode;poedercode;typeKleur;typesKlant(comma-separated)</li></ul>";
  $renolit  = "<ul>$csvzip<li>Velden: id;kleurcode;omschrijving</li></ul>";
  $utilo    = "<ul>$csvzip<li>Velden: ?;referentie;omschrijving</li></ul>";
  $blocked  = "<ul>$csvzip<li>Velden: klantennummer;geblokkeerd_J/N</li></ul>";
  $statuses = "<ul>$csvzip<li>Velden: klant;orderbon;orderdatum;omschrijving;"
            . "referentie;fase;leverdatum;aantal;bedrag;leverconditie;kleur</li></ul>";
  $pdf      = "PDF bestand";

  $mapping = array(
    'ral'                            => $ral,
    'renolit'                        => $renolit,
    'utilo'                          => $utilo,
    'blocked'                        => $blocked,
    FENEKO_CODE_ORDER_STATUSES_TABLE => $statuses,
    'screens'                        => $pdf,
    'doors'                          => $pdf,
    'alu_systems'                    => $pdf,
  );

  $manual = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('manual')),
    'title' => array(
      '#markup' => '<h2>Aanwijzingen voor formaat</h2>',
    ),
    'empty' => array(
      '#type' => 'container',
      'markup' => array('#markup' => 'Selecteer een Type upload'),
      '#states' => array(
        'visible' => array('input[name="type"]' => array('value' => FALSE)),
      ),
    ),
  );
  foreach ($mapping as $table => $markup) {
    $manual[$table] = array(
      '#type' => 'container',
      'markup' => array('#markup' => $markup),
      '#states' => array(
        'visible' => array('input[name="type"]' => array('value' => $table)),
      ),
    );
  }

  return array(
    'manual' => $manual,
    'type' => array(
      '#type' => "radios",
      '#title' => 'Type upload',
      '#options' => array(
        'ral'                            => 'RAL codes',
        'renolit'                        => 'Renolit codes',
        'utilo'                          => 'Utilo profielen',
        'blocked'                        => 'Geblokkeerd/EB',
        FENEKO_CODE_ORDER_STATUSES_TABLE => 'Statussen Orders',
        'screens'                        => 'Screens catalogus',
        'doors'                          => 'Doors catalogus',
        'alu_systems'                    => 'Alu Systems catalogus',
      ),
      '#required' => true,
    ),
    'file_upload' => array(
      '#title' => 'Bestand',
      '#type' => 'file',
      '#states' => array(
        'invisible' => array('input[name="type"]' => array('value' => FALSE)),
      ),
    ),
    'header' => array(
      '#type' => "checkbox",
      '#title' => 'De eerste lijn overslaan',
      '#description' => 'Het kan dat de eerste lijn de kolom namen bevat. Vink '
                      . 'deze optie aan indien de eerste lijn overgeslaan moet worden.',
      '#states' => array(
        'invisible' => array(
          'input[name="type"]' => array(
            array('value' => FENEKO_CODE_ORDER_STATUSES_TABLE),
            array('value' => 'screens'),
            array('value' => 'doors'),
            array('value' => 'alu_systems'),
            array('value' => FALSE),
          )
        ),
      ),
    ),
    'full' => array(
      '#type' => "checkbox",
      '#title' => 'Full load',
      '#description' => 'Vink dit aan als je wil dat alle gegevens in deze tabel eerst verwijderd worden.',
      '#states' => array(
        'visible' => array(
          'input[name="type"]' => array(
            array('value' => FENEKO_CODE_ORDER_STATUSES_TABLE),
          )
        ),
      ),
    ),
    'submit' => array(
      '#type' => "submit",
      "#value" => "Importeer",
    ),
  );
}

function feneko_code_import_form_submit($form, &$form_state) {
  ini_set('post_max_size', '10M');
  ini_set('upload_max_filesize', '10M');

  $folder = 'private://catalogs';
  $values = $form_state['values'];

  if($values['type'] === 'screens'
  || $values['type'] === 'doors'
  || $values['type'] === 'alu_systems') {
    $file = file_save_upload(
      'file_upload',
      array('file_validate_extensions' => array('pdf')),
      $folder,
      FILE_EXISTS_REPLACE
    );

    if($file) {
      // Make the file permanent
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);

      // If the file doesn't have the correct name, move it
      $target_filename = $values['type'] . ".pdf";
      if($file->filename !== $target_filename) {
        file_move($file, "$folder/$target_filename", FILE_EXISTS_REPLACE);
      }
      drupal_set_message(t('De :t catalogus werd vervangen.', array(':t' => $values['type'])));
    } else {
      drupal_set_message(t('Er werd geen bestand meegegeven.'));
    }
  } else {
    $file = file_save_upload('file_upload', array(
      'file_validate_extensions' => array('csv','zip'),
    ));

    if($file) {
      if($file->filemime === 'application/zip') {
        _feneko_code_zip_import($file->uri, $values);
      } else {
        _feneko_code_csv_import($file->uri, $values);
      }
    } else {
      drupal_set_message(t('Er werd geen bestand meegegeven.'));
    }
  }
}

function _feneko_oderline_is_valid($fields) {
  if(!ctype_digit($fields['klant'])) return false;
  return true;
}

function _feneko_code_zip_import($zipname, $values) {
  $folder = drupal_tempnam('private://');
  drupal_unlink($folder);
  if(drupal_mkdir($folder)) {
    // Extract to a temporary folder
    $path = str_replace('temporary:/', file_directory_temp(), $zipname);
    $zip = new ArchiverZip($path);
    $zip->extract($folder);

    // Sort and loop
    $files = file_scan_directory($folder, '/.*\.csv/');
    ksort($files);
    foreach ($files as $filename => $file) {
      // Import, then remove
      _feneko_code_csv_import($filename, $values);
      drupal_unlink($filename);
    }

    // Remove the folder
    drupal_rmdir($folder);
  } else {
    drupal_set_message(t('Unable to create temporary folder for extract'), 'error');
  }
}

function _fc_import_insert($table, $fields, &$num_updated) {
  try {
    db_insert($table)->fields($fields)->execute();
    $num_updated++;
  } catch(Exception $e) {
    $msg = t('Er was een probleem bij het importeren van :ref', array(':ref'   => $fields['ref']));
    drupal_set_message($msg, 'warning');
  }
}

function _feneko_code_pdf_import($filename, $values) {
  $file = file_save_upload($filename, array(), 'private://');
}

function _feneko_code_csv_import($filename, $values) {
  $skipHeader = $values['header'];
  $table = $values['type'];

  // Reuse the OrderStatusSchema
  $orderStatusesSchema = drupal_get_schema(FENEKO_CODE_ORDER_STATUSES_TABLE);

  // Open the file.
  $handle = fopen($filename, "r");

  // Skip the header if needed
  if($skipHeader) {
    fgetcsv($handle, 0, FENEKO_CODE_IMPORT_DELIMITER);
  }

  $full = isset($values['full']) ? $values['full'] : false;

  if(!($table === 'blocked' or ($table === FENEKO_CODE_ORDER_STATUSES_TABLE and !$full))) {
    // First clear the table.
    if (db_table_exists($table)) {
      db_truncate($table)->execute();
    }

    // For ral table
    $mapping = array(
      'laken std' => 'ral',
      'laken str' => 'str',
      'Laken std' => 'ral',
      'Laken str' => 'str',
    );
  } else {
    // For blocked table
    $mapping = array('N' => 0, 'J' => 1);
  }

  $num_updated  = 0;
  $num_inserted = 0;

  // Loop through the csv file and insert into database.
  while ($data = fgetcsv($handle, 0, FENEKO_CODE_IMPORT_DELIMITER)) {
    switch ($table) {
      case 'ral':
        if(isset($mapping[$data[2]])) {
          $type = $mapping[$data[2]];
        } else {
          $msg = t("Type Mapping not found for :mapping. Ignored record.", array(':mapping' => $data[2]));
          drupal_set_message($msg, 'warning');
          continue 2;
        }

        $field = field_info_field('field_client_group');
        $client_group_keys = array_keys(list_allowed_values($field));

        $typesKlantArray = explode(',', str_replace(' ', '', $data[3]));

        if(count(array_diff($typesKlantArray, $client_group_keys)) === 0) {
          $client_groups = implode(',', $typesKlantArray);
        } else {
          if(!empty($data[3])) {
            $msg = t("Client mapping not found for :mapping. Cleared field.", array(':mapping' => $data[3]));
            drupal_set_message($msg, 'warning');
          }
          $client_groups = '';
        }

        $fields = array(
          'kleur'         => drupal_convert_to_utf8($data[0], 'Windows-1252'),
          'ref'           => drupal_convert_to_utf8($data[1], 'Windows-1252'),
          'type'          => $type,
          'client_groups' => $client_groups,
        );

        _fc_import_insert($table, $fields, $num_updated);
        break;

      case 'renolit':
        $fields = array(
          'kleur' => drupal_convert_to_utf8($data[2], 'Windows-1252'),
          'ref'   => drupal_convert_to_utf8($data[1], 'Windows-1252'),
        );
        _fc_import_insert($table, $fields, $num_updated);
        break;

      case 'utilo':
        $fields = array(
          'ref'   => drupal_convert_to_utf8($data[1], 'Windows-1252'),
          'descr' => drupal_convert_to_utf8($data[2], 'Windows-1252'),
          'lang'  => 'nl',
        );
        _fc_import_insert($table, $fields, $num_updated);
        break;

      case 'blocked':
        if($client = feneko_code_get_client_by_number($data[0])) {
          $client->field_block_order_input->set(strtr(strtoupper($data[1]), $mapping));
          $client->save();
          $num_updated++;
        }

        break;

      case FENEKO_CODE_ORDER_STATUSES_TABLE:
        if(!isset($data[1])) {
          continue;
        }

        $fields = array(
          'klant'         => trim(drupal_convert_to_utf8($data[0], 'Windows-1252')),
          'orderbon'      => trim(drupal_convert_to_utf8($data[1], 'Windows-1252')),
          'ref'           => trim(drupal_convert_to_utf8($data[4], 'Windows-1252')),
          'omschrijving'  => trim(drupal_convert_to_utf8($data[3], 'Windows-1252')),
          'kleur'         => trim(drupal_convert_to_utf8($data[10],'Windows-1252')),
          'order_datum'   => trim(drupal_convert_to_utf8($data[2], 'Windows-1252')),
          'lever_datum'   => trim(drupal_convert_to_utf8($data[6], 'Windows-1252')),
          'fase'          => trim(drupal_convert_to_utf8($data[5], 'Windows-1252')),
          'aantal'        => trim(drupal_convert_to_utf8($data[7], 'Windows-1252')),
          'bedrag'        => str_replace(',', '.', trim(drupal_convert_to_utf8($data[8], 'Windows-1252'))) ,
          'leverconditie' => trim(drupal_convert_to_utf8($data[9], 'Windows-1252')),
        );

        // Skip invalid lines
        if(!_feneko_oderline_is_valid($fields)) {
          continue;
        }

        // Set the dates
        $format = 'd-m-y';
        if($dt = DateTime::createFromFormat($format . " H:i", $fields['order_datum'] . " 00:00")) {
          $fields['order_datum'] = $dt->getTimestamp();
        } else {
          $msg = t("Orderbon: :orderbon: Orderdatum :date is een ongeldige datum. Het verwachte formaat is: :format", array(
            ':date' => $fields['order_datum'],
            ':format' => $format,
            ':orderbon' => $fields['orderbon'],
          ));
          drupal_set_message($msg, 'warning');
          $fields['order_datum'] = 0;
        }

        if($dt = DateTime::createFromFormat($format . " H:i", $fields['lever_datum'] . " 00:00")) {
          $fields['lever_datum'] = $dt->getTimestamp();
        } else {
          $msg = t("Orderbon: :orderbon: Leverdatum :date is een ongeldige datum. Het verwachte formaat is: :format", array(
            ':date' => $fields['lever_datum'],
            ':format' => $format,
            ':orderbon' => $fields['orderbon'],
          ));
          drupal_set_message($msg, 'warning');
          $fields['lever_datum'] = 0;
        }

        // Do some checks
        if($fields['bedrag'] != (string)(float)$fields['bedrag']) {
          $msg = t("Orderbon: :orderbon: Het bedrag: :bedrag is niet geldig", array(
            ':orderbon' => $fields['orderbon'],
            ':bedrag' => $fields['bedrag'],
          ));
          drupal_set_message($msg, 'warning');
        }

        _feneko_code_check_length($fields, $orderStatusesSchema);

        $op_type = db_merge($table)->key(array('orderbon' => $fields['orderbon']))
                                   ->fields($fields)->execute();

        // Increment the counters
        switch ($op_type) {
          case MergeQuery::STATUS_INSERT: $num_inserted++; break;
          case MergeQuery::STATUS_UPDATE: $num_updated++;  break;
        }

        break;
    }
  }
  fclose($handle);

  if($table !== FENEKO_CODE_ORDER_STATUSES_TABLE) {
    if($table === 'blocked') {
      if($num_updated > 0) {
        $msg = t('Er werden :num klanten aangepast.', array(':num' => $num_updated));
      }
    } else {
      $msg = t(':num records werden succesvol geïmporteerd.', array(':num' => $num_updated));
    }

    drupal_set_message($msg);
  } else {
    _fc_clean_order_statuses();
    $filename = basename($filename);
    $msg_ins = t(':file: Er werden :num statussen toegevoegd.', array(':file' => $filename, ':num' => $num_inserted));
    $msg_upd = t(':file: Er werden :num statussen aangepast.' , array(':file' => $filename, ':num' => $num_updated));

    drupal_set_message($msg_ins);
    drupal_set_message($msg_upd);
  }

}

function _feneko_code_check_length(&$fields, $schema) {
  foreach ($schema['fields'] as $fieldname => $field) {
    if($field['type'] === 'varchar' && strlen($fields[$fieldname]) > $field['length']) {
      $fields[$fieldname] = substr($fields[$fieldname], 0, $field['length']);
      $msg = t("Orderbon: :orderbon: :fieldname werd afgekapt op het maximum van :length tekens", array(
        ':orderbon' => $fields['orderbon'],
        ':fieldname' => $fieldname,
        ':length' => $field['length'],
      ));
      drupal_set_message($msg, 'warning');
    }
  }
}

/**
 * Callback function for order statuses
 */
function _feneko_order_statuses_service($file) {
  $data = base64_decode($file);
  $filename = drupal_tempnam("private://", "order_statuses");
  if(file_put_contents($filename, $data)) {
    watchdog("feneko_api", ":filename created", array(':filename' => $filename), WATCHDOG_INFO);
  } else {
    watchdog("feneko_api", "Could not write :filename", array(':filename' => $filename), WATCHDOG_ERROR);
  }

  $arg = array(
    'type' => FENEKO_CODE_ORDER_STATUSES_TABLE,
    'header' => false,
  );
  _feneko_code_csv_import($filename, $arg);

  if(unlink($filename)) {
    watchdog("feneko_api", ":filename deleted", array(':filename' => $filename), WATCHDOG_INFO);
  } else {
    watchdog("feneko_api", "Could not delete :filename", array(':filename' => $filename), WATCHDOG_ERROR);
  }
}
