<?php
class FenekoForm {
  private $fields;
  private $id;
  public $title;
  public $url;
  public $remark;

  const AFGEWERKTE_DIFF = 37;

  ////////////
  // PUBLIC //
  ////////////

  public function __construct($id, array $fields = NULL) {
    // Constants
    $basicFields = array(
      'klant'          => 10,
      'referentie'     => 20,
      'table1'         => 30,
      'kleur'          => 40,
      'type_gaas'      => 50,
      'gaas_kleur'     => 51,
      'kleur_pees'     => 500,
      'kies_een_optie' => 1100,
    );

    // Create the object fields
    $this->id = $id;
    $this->fields = empty($fields) ? $basicFields : $fields;
  }

  /**
   * Get the id of the form
   * @return string $id
   */
  public function getId() {
    return $this->id;
  }

  /**
   * Submits the values of a form to the DB
   * @param $values An array coming from the $form['form_state']['values']
   * @return boolean TRUE is the field exists, FALSE otherwise
   */
  public function submit($values) {
    $fields = $this->getSubmitFields($values);
    $id = $this->getId();

    $file = FALSE;
    if(isset($fields['file'])) {
      $file = file_load($fields['file']);
    }

    $articles = FALSE;
    if(isset($fields['soort_bevestiging'])) {
      list($val, $dep_val) = self::explodeDep($fields['soort_bevestiging']);
      if($val === 'op_maat')  {
        $articles = self::getArticles($fields, array('op_maat' => $dep_val));
      }
    }

    // Add client number to users with appropriate flag
    $user = entity_metadata_wrapper('user', $fields['uid']);
    if($user->field_add_client_number->value()) {
      $fields['referentie'] .= ' (' . $fields['klant'] . ')';
    }

    $dbID = db_insert("manyforms_$id")->fields($fields)->execute();

    $type = $values['kies_een_optie'];
    $ref = self::sanitize($values['referentie']);

    $client = feneko_code_get_client_by_number($fields['klant']);
    $this->message($dbID, $type);
    $this->mailing($dbID, $type, $ref, $file, $articles, $client);
  }

  /**
   * Validates the values of a form to the DB
   * @param $values An array coming from the $form['form_state']['values']
   * @return boolean TRUE is the field exists, FALSE otherwise
   */
  public function validate(&$values) {
    // Make sure all visible fields are mandatory and all invisible fields are reset
    $this->handleVisibilityState($values);
    foreach ($values as $name => $value) {
      // First make sure at least 1 line is filled in if there is a table
      if(substr($name, 0, 5) === 'table') {
        $table_is_empty = TRUE;
        foreach ($value as $i => $row) {
          if(!self::emptyRow($row)) {
            // Check for empty table
            $table_is_empty = FALSE;

            // Validate the measures
            $this->validate_measures($values, $name, $i);
          }
        }
        if($table_is_empty) {
          form_set_error($name, t('Er moet minstens 1 lijn ingevuld worden in de tabel.'));
        }
      }

      // Then do the other fields validation
      $id = $this->getId();
      switch ($name) {
        case 'plint':
          $plint_map = array(
            'f300mm' => 300,
            'geen' => 0,
            'tot_tssstijl' => 0,
            'andere' => $values['plint_dep'],
          );

          $plint_h = isset($plint_map[$value]) ? $plint_map[$value] : 0;

          // Check the minima of the dierendeur
          $ref = array(
            'hond_klein' => array(
              'min_h' => 500,
              'name' => t('kleine hond'),
            ),
            'kat' => array(
              'min_h' => 400,
              'name' => t('kat'),
            ),
          );

          if(isset($values['dierendeur'])) {
            switch ($values['dierendeur']) {
              case 'hond_groot':
                if($value !== 'tot_tssstijl') {
                  $msg = t("Bij een dierendeur voor een grote hond, bent u verplicht een plint tot tussenstijl te kiezen.");
                  form_set_error($name, $msg);
                }
                break;

              case 'hond_klein':
              case 'kat':
                if($plint_h < $ref[$values['dierendeur']]['min_h']) {
                  $msg = t("Bij een dierendeur voor een :name, moet de hoogte van de plint minstens :min_h zijn.",
                    array(
                      ':name'  => $ref[$values['dierendeur']]['name'],
                      ':min_h' => $ref[$values['dierendeur']]['min_h'],
                    ));
                  form_set_error($name, $msg);
                }
                break;
            }
          }
          break;

        case 'kies_een_optie':
          // To prevent fraude: set to offerte for blocked clients
          if($values['klant']) {
            $client = feneko_code_get_client_by_number($values['klant']);
            if($client->field_block_order_input->value()) {
              $values[$name] = 'offerte';
            }
          }
          break;

        case 'kleur_dep':
          // Make sure the RAL color has been chosen
          if($values['kleur'] === 'ral') {
            manyforms_ral_validate($this->getId(), $name, $value);
          }
          break;

        case 'opties':
          if($value === 'gebogen') {
            $validators = array(
              'file_validate_extensions' => array('pdf jpg jpeg png dwg dxf'),
              'file_validate_size' => array(3*1024*1024),
            );
            $file = file_save_upload('file', $validators);
            if($file) {
              $file = file_move($file, 'private://drawings/'. $file->filename, FILE_EXISTS_REPLACE);
              $file->status = FILE_STATUS_PERMANENT;
              $file = file_save($file);
              $values['file'] = $file->fid;
            } else {
              form_set_error('file', t('Een bestand dient opgeladen te worden.'));
            }
          }
          // Make sure the value of the file is numeric
          if(empty($values['file'])) {
            $values['file'] = 0;
          }
          break;

        case 'table1':
          foreach ($value as $i => $row) {
            $t_values = $row['t1'] . $row['t2'] . $row['t3'];
            $o_values = $row['aantal'] . $row['breedte'] . $row['hoogte'];
            if(!empty($o_values) && $row['standt'] === 0 && empty($t_values)) {
              $msg = t('T1, T2 en T3 kunnen niet oningevuld blijven als de stand T niet aangevinkt is.');
              $field_name = self::parseFormErrorFieldName($name, $i, 'standt');
              form_set_error(self::parseFormErrorFieldName($name, $i, 't1'));
              form_set_error(self::parseFormErrorFieldName($name, $i, 't2'));
              form_set_error(self::parseFormErrorFieldName($name, $i, 't3'));
              form_set_error($field_name, $msg);
            }
          }
          break;

        case 'table2':
          foreach ($value as $i => $row) {
            $t_values = $row['t1'] . $row['t2'];
            $o_values = $row['aantal'] . $row['breedte'] . $row['hoogte'] . $row['rails'];
            if(!empty($o_values) && $row['standt'] === 0 && empty($t_values)) {
              $msg = t('T1 en T2 kunnen niet oningevuld blijven als de stand T niet aangevinkt is.');
              $field_name = self::parseFormErrorFieldName($name, $i, 'standt');
              form_set_error(self::parseFormErrorFieldName($name, $i, 't1'));
              form_set_error(self::parseFormErrorFieldName($name, $i, 't2'));
              form_set_error($field_name, $msg);
            }
          }

        case 'table2':
        case 'table3':
          foreach ($value as $i => $row) {
            if(!self::emptyRow($row)) {
              $field_name = self::parseFormErrorFieldName($name, $i, 'rails');
              if($row['rails'] === '') {
                form_set_error(
                  $field_name,
                  t('Lengte rails moet ingevuld worden op rij :rij van de tabel. Vul desnoods 0 in.',
                    array(':rij' => $i + 1)
                  )
                );
              }
            }
          }
          break;

        case 'schuifdeur_pomp':
          // Only for schuifdeur classic, elegance or elegance+
          if($id == 8 || $id == 9 || $id == 13) {
            if($value === 'links' || $value === 'rechts') {
              $table = "table" . $this->getTableType();
              foreach ($values[$table] as $i => $row) {
                if(!self::emptyRow($row)) {
                  $field_name = self::parseFormErrorFieldName($table, $i, 'breedte');
                  if($row['breedte'] < 750) {
                    form_set_error(
                      $field_name,
                      t('Rij :rij: Een pomp is enkel mogelijk bij een breedte van :measure of meer.',
                        array(
                          ':rij' => $i + 1,
                          ':measure' => 750,
                        )
                      )
                    );
                  }
                }
              }
            }
          }
          break;
      }
    }
  }

  /**
   * Export all entries of this form to Excel
   */
  public function export($non_exported) {
    $table = "manyforms_" . $this->getId();
    $file_name = "$table.csv";

    $csv = $this->getCSV($non_exported);
    if(empty($csv)) {
      drupal_set_message(t('No results were found to be exported'), 'warning');
      return;
    }

    // Flag all items as exported
    db_update($table)->fields(array('exported' => 1))->execute();

    // Send the CSV to the browser
    header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
    header("Content-Length: " . strlen($csv));
    header("Content-type: text/x-csv");
    header("Content-Disposition: attachment; filename=$file_name");
    echo $csv;
    exit;
  }




  ///////////////
  // PROTECTED //
  ///////////////

  /**
   * Generate and return the Drupal form related to this form
   * @return array Drupal form
   */
  protected function getForm() {
    $form['remark'] = array(
      '#markup' => $this->remark,
      '#prefix' => '<div class="remark">',
      '#suffix' => '</div>',
    );

    foreach ($this->fields as $name => $weight) {
      $form[$name] = $this->getField($name, $weight);
    }
    $form['actions'] = array(
      '#type' => 'container',
      '#weight' => 1200,
      'submit_button' => $this->getField('submit_button', 10),
      'cancel_button' => $this->getField('cancel_button', 20),
    );

    return $form;
  }

  /**
   * Add a field to the field list of this form
   * @param $name   The name of the field to be added
   * @param $weight The weight of the field defining the sequence
   */
  protected function addField($name, $weight) {
    $this->fields[$name] = $weight;
  }

  /**
   * Remove a field from the field list of this form
   * @param $name The name of the field to be removed from the fields list
   */
  protected function removeField($name) {
    unset($this->fields[$name]);
  }

  /**
   * Checks if a form has $field_name in the field list
   * @param $field_name   The name of the field to be added be checked
   * @return boolean TRUE is the field exists, FALSE otherwise
   */
  protected function hasField($field_name) {
    foreach ($this->fields as $name => $weight) {
      if($field_name === $name) return TRUE;
    }
    return FALSE;
  }


  /**
   * Gets the schema needed to be able to store the fields of the form
   * @return array The schema to be used in hook_schema()
   */
  public function getSchema() {
    $schema['description'] = "Form " . $this->id;
    $schema['primary key'] = array('id');
    $fields = array_merge(
      array_flip(array('id', 'uid', 'datesubmit', 'exported')),
      $this->fields
    );

    foreach ($fields as $name => $weight) {
      self::addFieldToSchema($name, $schema);
    }

    return $schema;
  }

  /////////////
  // PRIVATE //
  /////////////

  /**
   * Get the fiche corresponding to a submission
   * @param $field Array of field-value pairs as returned from the DB or as
   *               input to the DB
   * @return string The fiche string
   */
  private function getFiche($fields) {
    $client = feneko_code_get_client_by_number($fields['klant']);
    // 8 = GK
    if($client->field_block_order_input->value() && $client->field_client_group->value() === 8) {
      return 'geblokkeerd';
    }

    $count = 9;

    $id = intval($this->getId());
    $table_type = $this->getTableType();
    $table_fields = self::getTableFields("table" . $table_type);
    $record = json_decode(json_encode($fields), FALSE);

    $header  = ':UOR:' . PHP_EOL . PHP_EOL;
    $header .= PHP_EOL . ":K1: " . $fields['klant'] . PHP_EOL . PHP_EOL . PHP_EOL; // klantnummer

    $header .= PHP_EOL . ":U1:" . PHP_EOL . PHP_EOL; // Begin orderblok
    $header .= PHP_EOL . ":O4: A>" . $fields['referentie']; // referentie

    // For every non empty line in the table we need to put the values
    // and recalculate the $product_fiche values
    $fiche = '';
    for($i = 1; $i <= $count; $i++) {
      $section_fields = $fields; // To be able to change the values by section
      // Skip empty rows
      if(self::emptyRow($record, $table_fields, $i)) continue;

      // Row is not empty from here on

      // For every non empty row, we print all fields in the row.
      // Then we add all product fiche data and then we sort the section
      // Finally we add the section to the fiche

      $fiche .= PHP_EOL . PHP_EOL . $this->getSetNr() . PHP_EOL . PHP_EOL . PHP_EOL; // Begin productblok

      $section = '';
      foreach ($table_fields as $table_field) {
        $value = $section_fields["$table_field$i"];
        if($table_field === 'stand') $this->handleStand($section_fields, $value, $section, $i);

        // Handle the schuifdeuren and deurplisse
        switch ($id) {
          case 8:
          case 9:
          case 13:
            $u = $section_fields['uitvoering'];
            $b = $section_fields["breedte$i"];
            if(($u === 'enkel' and $b <= 2000) or ($u === 'dubbel' and $b <= 4000)) {
              $strbr = 'val1';
            } elseif(($u === 'enkel' and $b > 2000) or ($u === 'dubbel' and $b < 4000)) {
              $strbr = 'val2';
            }
            $section .= $this->getCode('stootrubber', $strbr);
            break;

          case 10:
            $section .= $this->getCode('stootrubber', $section_fields['stootrubber']);
            break;

          case 11:
            switch ($section_fields['uitvoering']) {
              case 'enkel':
                $min_breedte = 1201;
                $max_breedte = 1600;
                break;

              case 'dubbel':
                $min_breedte = 2401;
                $max_breedte = 3200;
                break;
            }
            break;
        }
        $section .= $this->getCode($table_field, $value);

        // Elegance+ doesn't have a tussenstijl, so we need to force P7: 0
        if($id == 13) {
          $section .= $this->getCode('stand', '0');
        }
      }
      $section .= $this->getProductFiche($section_fields);


      $fiche .= self::lineSort($section) . PHP_EOL;
      $fiche .= ":O16: " . $section_fields["opmerking$i"] . PHP_EOL . PHP_EOL;
      $fiche .= ":UE" . PHP_EOL;  // End productblok
    }

    $footer = PHP_EOL . ":U2:"; // Eind orderblok

    return $header . $fiche . $footer;
  }


  /**
   * Handles all logic related to the P7 stand field of the table
   * @param $fields Array all fields of the submission
   * @param $value  mixed the value of the current field
   * @param $i      int the index of the current row
   * @return string The fiche string
   */
  private function handleStand(&$fields, &$value, &$section, $i) {
    $id = intval($this->getId());
    $hoogte = $fields["hoogte$i"];
    $breedte = $fields["breedte$i"];

    // Vliegenramen "basic", "Classic", inzetvliegenraam "VR033", "VR033-ultra"
    // Vliegendeur "Basic", "Classic", "Elegance"
    if($id <= 6) {
      if($value == 0) { // Stand T is not checked
        // Exact 1 of t1, t2, t3 is filled in
        if(self::ternary_xor(!empty($fields["t1$i"]), !empty($fields["t2$i"]), !empty($fields["t3$i"]))) {
          $value = 1;
          $fields["t1$i"] = $fields["t1$i"] + $fields["t2$i"] + $fields["t3$i"];
          $fields["t2$i"] = '0';
          $fields["t3$i"] = '0';
        }
        // Exact 2 of t1, t2, t3 are filled in
        elseif(self::ternary_xor(empty($fields["t1$i"]), empty($fields["t2$i"]), empty($fields["t3$i"]))) {
          // Remove empty t1, t2, or t3 and rebase the array of 2 elements
          $ts = array_values(array_filter(array($fields["t1$i"], $fields["t2$i"], $fields["t3$i"])));
          $value = 2;
          $fields["t1$i"] = $ts[0];
          $fields["t2$i"] = $ts[1];
          $fields["t3$i"] = '0';
        }
        // All of t1, t2, t3 are filled in
        else {
          $value = 3;
        }
      } else { // Stand T is checked
        // Vliegenramen "basic", "Classic", inzetvliegenraam "VR033", "VR033-ultra"
        if($id <= 3) {
          if($hoogte < 1600) {
            $value = 1; // TODO: Obsolete?
            $fields["t1$i"] = $hoogte/2;
            $fields["t2$i"] = '0';
            $fields["t3$i"] = '0';
          } else {
            $value = 2;
            $fields["t1$i"] = $hoogte/3;
            $fields["t2$i"] = 2*$hoogte/3;
            $fields["t3$i"] = '0';
          }
        }
        // Vliegendeur "Basic", "Classic", "Elegance"
        else {
          $value = 1; // TODO: Obsolete?
          $fields["t1$i"] = 917;
          $fields["t2$i"] = '0';
          $fields["t3$i"] = '0';
        }
      }
    }
    // SchuifVliegendeur "Basic", "Classic", "Elegance", "smal"
    elseif($id > 6 and $id <= 10) {
      // Set the right stootrubber value for the schuifdeuren
      $section .= $this->getCode('stootrubber', 'val2');

      if($value == 0) {
        // Exact 1 of t1 or t2 is filled in
        if(!empty($fields["t1$i"]) xor !empty($fields["t2$i"])) {
          $value = 1;
          $fields["t1$i"] = $fields["t1$i"] + $fields["t2$i"];
          $fields["t2$i"] = '0';
        }
        else {
          $value = 2;
        }
      } else {
        $value = 1;
        $fields["t1$i"] = 962;
        $fields["t2$i"] = '0';
      }
    }
  }


  /**
   * Get the fiche for all the product fields (P-fields)
   * @param $fields Array all fields of the submission
   * @return string The product fiche string
   */
  private function getProductFiche(&$fields) {
    $product_fiche = '';
    $id = intval($this->getId());

    // Switch on form id
    switch ($id) {
      case 1:
        $fields['uitvoering'] = 'enkel';
        $fields['pvc'] = 'nvt';
        if($fields['opties'] === 'gebogen') {
          $fields['opties'] = 'gebogen_raam';
        }
        if($fields['opties'] === 'nvt') {
          $fields['opties'] = 'nvt_raam';
        }
        break;

      case 2:
        $fields['uitvoering'] = 'enkel';
        break;

      case 3:
        $fields['bevestiging'] = 'nvt';
        $fields['uitvoering'] = 'enkel';
        break;

      case 4:
        $fields['opties'] = 'nvt';
        $fields['uitvoering'] = 'enkel';
        $fields['sluiting'] = 'magneet';
        $fields['afdekdoppen'] = 'nvt';
        break;

      case 5:
        $fields['opties'] = 'nvt';
        $fields['sluiting'] = 'magneet';
        if($fields['uitvoering'] !== 'enkel') {
          $fields['kader'] = 'nvt';
        }
        if($fields['uitvoering'] === 'zonder') {
          $fields['scharnierkant'] = 'nvt';
          $fields['pomp'] = 'nvt';
        }
        if($fields['kader'] === 'smal') {
          $fields['afdekdoppen'] = 'nvt';
        }
        break;

      case 6:
        $fields['opties'] = 'nvt';
        $fields['sluiting'] = 'magneet';
        $fields['pvc'] = 'nvt';
        if($fields['uitvoering'] === 'zonder') {
          $fields['kader'] = 'nvt';
          $fields['scharnierkant'] = 'nvt';
          $fields['pomp'] = 'nvt';
        }
        $fields['afdekdoppen'] = 'nvt';
        break;

      case 7:
        $fields['uitvoering'] = 'enkel';
        $fields['stootrubber'] = 'nvt';
        $fields['schuifdeur_pomp'] = 'nvt';
        $fields['borstel_kopse_kant'] = 'nvt';
        break;

      case 8:
        self::setSchuifdeurPomp($fields);
        break;

      case 9:
        self::setSchuifdeurPomp($fields);
        $fields['pvc'] = 'nvt';
        break;

      case 10:
        $fields['schuifdeur_pomp'] = 'nvt';
        $fields['pvc'] = 'nvt';
        break;

      case 12:
      case 16:
        $fields['borstel'] = 'geen';
        $fields['verbreding'] = 'geen';
        $fields['uitvoering'] = 'enkel';
        $fields['ondergeleider'] = 'geen';
        $fields['hoekverbinding'] = 'geen';
        $product_fiche .= $this->getCode("rails", '0');
        break;

      case 13:
        self::setSchuifdeurPomp($fields);
        if($fields['ondergeleider_anodise'] === 'ja') {
          $fields['ondergeleider'] .= 'a';
        }
        break;

      case 14:
        $fields['pvc'] = 'nvt';
        $fields['opties'] = 'nvt';
        $fields['sluiting'] = 'magneet';
        $fields['uitvoering'] = 'enkel';
        $fields['afdekdoppen'] = 'nvt';
        break;

      case 15:
        $fields['uitvoering'] = 'rv';
        break;
    }

    foreach ($fields as $name => $value) {
      // Switch on field names
      switch ($name) {
        case 'borstel_profiel':
          if($value === 'nee') {
            $product_fiche .= $this->getCode("borstel", 'nvt');
          }
          break;

        case 'borstel_links':
          $name = 'borstels';
          if(isset($fields['borstel_rechts'])) {
            $value .= "###" . $fields['borstel_rechts'];
          }
          if(isset($fields['uitvoering'])) {
            $value .= "###" . $fields['uitvoering'];
          }
          break;

        case 'kader_top':
          $bitmap = $fields['kader_top']    . $fields['kader_right']
                  . $fields['kader_bottom'] . $fields['kader_left'];
          if($bitmap === '0000') {
            $kader_plisse = 'nee';
          } else {
            $kader_plisse = 'ja';
          }
          $product_fiche .= $this->getCode("kader_plisse", $kader_plisse);
          $product_fiche .= $this->getCode("frame#kader", $bitmap);
          break;

        case 'kader':
          if(($id === 6 || $id === 14) and $value === 'vp1001') {
            $product_fiche .= $this->getCode("hoekverbinding", 'geperst');
          }
          if($id === 12) {
            $name = 'kader12';
          }
          break;

        case 'kleur':
          list($value, $ral_code) = self::explodeRal($value);
          if(($id >= 4 and $id <=10 or $id === 13 || $id === 14)
                             and ($value === 'f9001' or $value === 'anodise')) {
            $value .= '_s';
          }
          if(isset($ral_code)) {
            $product_fiche .= $this->getCode("kleur_dep", $ral_code);
          }
          if($value === 'ral') {
            $client = feneko_code_get_client_by_number($fields['klant']);
            $value = $this->handleRal($client, $ral_code);
          }
          break;

        case 'ondergeleider':
          if($id == 7 or $id == 8 or $id == 9 or $id == 13) {
            if($value === 'vp1016' or $value === 'vp1016a') {
              $product_fiche .= $this->getCode("montagediepte", '25 mm');
            } else {
              $product_fiche .= $this->getCode("montagediepte", '44 mm');
            }
          } elseif ($id == 10) {
            if($value === 'vp1016' or $value === 'vp1016a') {
              $product_fiche .= $this->getCode("montagediepte", '08 mm');
            } else {
              $product_fiche .= $this->getCode("montagediepte", '27 mm');
            }
          }
          break;

        case 'plint':
          list($value, $dep_val) = self::explodeDep($value);
          if(isset($dep_val)) {
            $product_fiche .= $this->getCode("plint_dep", $dep_val);
          }
          break;

        case 'profiel':
          if($value === 'vr060') {
            $product_fiche .= $this->getCode("scharnierkant", 'geen');
          }
          break;

        case 'scharnierkant':
          if($fields['uitvoering'] === 'dubbel') {
            $value .= '###' . $fields['uitvoering'];
          }
          break;

        case 'bevestiging':
          if(!empty($fields['soort_bevestiging'])) {
            if(strstr($fields['soort_bevestiging'], 'op_maat') !== FALSE) {
              $value = 'geen';

              // Add *** in front of every opmerking for non empty rows
              $count = 9;
              $table_type = $this->getTableType();
              $table_fields = self::getTableFields("table" . $table_type);
              $record = json_decode(json_encode($fields), FALSE);
              $pattern = "*** ";
              for($i = 1; $i <= $count; $i++) {
                if(!self::emptyRow($record, $table_fields, $i)) {
                  $fields["opmerking$i"] = "*** " . $fields["opmerking$i"];
                }
              }
            }
          }
          break;

        case 'type_gaas':
          if($id === 13 || $id === 14) {
            if($value === 'petscreen' or $value === 'clearview')
            $value .= "###volledig";
          }
          if(isset($fields['gaas_kleur'])) {
            $value .= "###" . $fields['gaas_kleur'];
          }
          if(isset($fields['type_gaas_dep'])) {
            $value .= "###" . $fields['type_gaas_dep'];
          }
          if($value === 'inox') {
            $value = $id > 3 ? 'inox2' : 'inox1';
          }
          if($value === 'soltisdoek') {
            $value = $id > 3 ? 'soltisdoek2' : 'soltisdoek1';
          }
          break;

        case 'uitvoering':
          $value .= $id;

          if($value === 'dubbel5')  {
            $product_fiche .= $this->getCode("kader", 'standaard');
          }
          break;
      }
      $product_fiche .= self::getCode($name, $value);
    }

    return $product_fiche;
  }


  /**
   * Get the table type used in the current form
   * @return int The number of the table (1, 2, 3, or 4)
   */
  private function getTableType() {
    for($i = 1; $i < 5; $i++) {
      if(isset($this->form["table$i"])) return $i;
    }
  }

  private function handleRal($client, $ralCode) {
    $id = intval($this->getId());
    $value = 'ral';
    $client_group = $client->field_client_group->value();

    // Find the client groups of the current RAL color
    $ral_record = fc_ral_search_by_kleur($ralCode);
    $ral_client_groups = explode(',', str_replace(' ', '', $ral_record['client_groups']));

    if(in_array($client_group, $ral_client_groups)) {
      switch ($client_group) {
        case 11: // BudgetLine
          $matches = array(2, 4, 10);
          if(in_array($id, $matches)) {
            $value = 'ral_bl';
          }
          break;

        case 13: // Groep A
          if($id <= 3) {
            $value = 'ral_a1';
          } else {
            $value = 'ral_a2';
          }
          break;
      }
    }

    return $value;
  }


  /**
   * Handle the visibility state of the form elements:
   * - Set an error message for visibile fields that are not filled in
   * - Set non visible values to NULL
   * @param $values Array all fields of the submission
   */
  private function handleVisibilityState(&$values) {
    $required = array();

    $ignore_list = array('file');

    foreach ($this->form as $name => $field) {
      $dep_name =  $name . "_dep"; // A helper variable

      //// We check on the #states property
      if(isset($field['#states'])) { // A normal field
        self::reactOnVisibility($field, $name, $required, $values);
      }
      if (isset($field[$name]['#states'])) { // A field with dependant fields
        self::reactOnVisibility($field[$name], $name, $required, $values);
      }
      if (isset($field['container'][$dep_name]['#states'])) { // A dependant field
        self::reactOnVisibility($field['container'][$dep_name], $dep_name, $required, $values);
      }
    }

    foreach ($required as $name) {
      if(!in_array($name, $ignore_list)) {
        if(empty($values[$name])) {
          form_set_error($name, t("Het veld @name is verplicht.",
            array('@name' => $this->getFieldTitle($name))));
        }
      }
    }
  }

  /**
   * Validate the breedte for this form on row $i
   * @param $values Array holding the fields of the submission
   * @param $name   The name of the field
   * @param $i      Row number
   */
  private function validate_measures(&$values, $name, $i) {
    $uitvoering = isset($values['uitvoering']) ? $values['uitvoering'] : 'enkel';
    $afgewerkte = isset($values['afgewerkte']) ? $values['afgewerkte'] : 0;
    $id = intval($this->getId());
    $key = $uitvoering . $id;
    unset($this->fields['afgewerkte']); // Always discard this field form the form
    unset($this->fields['afgewerkte_message']); // Always discard this field form the form

    switch ($key) {
      case 'enkel1':
      case 'enkel2':
      case 'enkel15':
        $max = array(
          'breedte' => 2000,
          'hoogte'  => 3000,
        );
        break;

      case 'enkel3':
        $max = array(
          'breedte' => 1500,
          'hoogte'  => 2500,
        );
        break;

      case 'enkel4':
      case 'enkel5':
      case 'enkel6':
      case 'zonder4':
      case 'zonder5':
      case 'zonder6':
        $max = array(
          'breedte' => 1600,
          'hoogte'  => 3250,
        );
        break;

      case 'dubbel4':
      case 'dubbel5':
      case 'dubbel6':
        $max = array(
          'breedte' => 3200,
          'hoogte'  => 3250,
        );
        break;

      case 'enkel7':
      case 'enkel8':
      case 'enkel9':
      case 'enkel10':
      case 'enkel13':
        $max = array(
          'breedte' => 3000,
          'hoogte'  => 3000,
        );
        break;

      case 'dubbel7':
      case 'dubbel8':
      case 'dubbel9':
      case 'dubbel10':
      case 'dubbel13':
        $max = array(
          'breedte' => 6000,
          'hoogte'  => 3000,
        );
        break;

      case 'enkel11':
        $max = array(
          'breedte' => 3050,
          'hoogte'  => 3320,
        );
        break;

      case 'dubbel11':
        $max = array(
          'breedte' => 4000,
          'hoogte'  => 3320,
        );
        break;

      case 'enkel12':
        $max = array(
          'breedte' => 2000,
          'hoogte'  => 2400,
        );
        break;

      case 'enkel14':
        $max = array(
          'breedte' => 1400,
          'hoogte'  => 3250,
        );
        break;

      case 'enkel16':
        $max = array(
          'breedte' => 1800,
          'hoogte'  => 2400,
        );
        break;

      default:
        $msg = t('The reference table for the measures is not complete. Was looking for :key', array(':key' => $key));
        form_set_error($name, $msg);
        return;
    }

    foreach (array('breedte', 'hoogte') as $measure) {
      // Add the diff if needed
      if($afgewerkte === 1 and !empty($values[$name][$i][$measure])) {
        if($values[$name][$i][$measure] > self::AFGEWERKTE_DIFF) {
          $values[$name][$i][$measure] -= self::AFGEWERKTE_DIFF;
        } else {
          $field_name = self::parseFormErrorFieldName($name, $i, $measure);
          form_set_error(
            $field_name,
            t("De $measure op rij :rij is te klein voor afgewerkte maten.",
              array(':rij' => $i + 1)
            )
          );
        }
      }

      // Make sure the measures don't exceed the maximum values
      $msg = t('De opgegeven :measure in rij :rij is te groot.
                Het maximum is :max. Gelieve met ons contact op te nemen.<br>
                Indien u de bestelling van andere lijnen dient door te geven, gelieve rij :rij te verwijderen.',
                array(
                  ':rij' => $i + 1,
                  ':measure' => $measure,
                  ':max' => $max[$measure],
                ));
      if($values[$name][$i][$measure] > $max[$measure]) {
        $field_name = self::parseFormErrorFieldName($name, $i, $measure);
        form_set_error($field_name, $msg);
      }
    }

    // Check the proportion of the breedte and hoogte for the deurplisse
    if($id === 11) {
      $breedte = $values[$name][$i]['breedte'];
      $hoogte  = $values[$name][$i]['hoogte'];
      $field_name = self::parseFormErrorFieldName($name, $i, 'breedte');

      switch ($uitvoering) {
        case 'enkel':
          if(abs($hoogte - $breedte) <= 200) {
            $msg = t('Breedte/Hoogte verhouding kan niet gemaakt worden. Hoogte - breedte moet groter zijn dan 200.');
            form_set_error($field_name, $msg);
          }
          break;

        case 'dubbel':
          if(abs($hoogte - $breedte/2) <= 200) {
            $msg = t('Breedte/Hoogte verhouding kan niet gemaakt worden. Hoogte - breedte/2 moet groter zijn dan 200.');
            form_set_error($field_name, $msg);
          }
          break;
      }
    }

    // For the deuren, make sure if plint other is filled in, that it is smaller
    // than T1 or standt (if checked)
    if(isset($values[$name][$i]['standt']) and isset($values[$name][$i]['t1'])) {
      $h = $values[$name][$i]['standt'] ? 917 : $values[$name][$i]['t1'];
      if(isset($values['plint_dep']) && $values['plint_dep'] > $h) {
        $msg = t('De plint mag niet hoger zijn dan :h.', array(':h' => $h));
        form_set_error('plint_dep', $msg);
      }
    }
  }

  /**
   * Handle the mailing of this form
   * @param $id The database id for which mailings have to be handled
   */
  private function mailing($id, $type, $ref, $file, $articles, $client){
    global $user;
    global $language;
    $feneko_attmnts = array();

    $user = user_load($user->uid);

    $feneko_mail = variable_get('manyforms_notification_email','offerte@feneko.be');

    $subject = "[Feneko Online] formulier ($id) verzonden door " . $user->name . " ($ref)";

    $feneko_msg = variable_get('manyforms_notification_email_text','');

    $type = $type === 'offerte' ? 'offer' : 'order';
    $user_msg =  variable_get("manyforms_" . $type . "_email_text",'');

    $user_msg   = str_replace('{name}', $user->name, $user_msg);
    $user_msg   = str_replace('{id}', $id, $user_msg);
    $feneko_msg = str_replace('{name}', $user->name, $feneko_msg);
    $feneko_msg = str_replace('{type}', $type, $feneko_msg);
    $feneko_msg = str_replace('{id}', $id, $feneko_msg);

    if($client->field_block_order_input->value()) {
      $feneko_msg .= "\n\nOPGEPAST KLANT DIENT EERST TE BETALEN, procedure EB volgen.";
    }

    // Generate the PDF for the user and FenekO in the current language
    $feneko_pdf = $user_pdf = array(
      'filecontent' => $this->generatePDF($id, true),
      'filename' => "$ref.pdf",
      'filemime' => 'application/pdf',
    );

    if($file) {
      $feneko_attmnts[] = array(
        'filecontent' => file_get_contents($file->uri),
        'filename' => $file->filename,
        'filemime' => $file->filemime,
      );
    }

    if($articles) {
      $feneko_attmnts[] = array(
        'filecontent' => $articles,
        'filename' => 'Artikelen.txt',
        'filemime' => 'text/plain',
      );
    }

    $feneko_pdf = $user_pdf = array(
      'filecontent' => $this->generatePDF($id, true),
      'filename' => "$ref.pdf",
      'filemime' => 'application/pdf',
    );

    // If the current language is another language than the FenekO language,
    // we need to change the FenekO PDF language to the FenekO language
    $languages = language_list();
    $feneko_language = $languages['nl'];
    if($language->language !== $feneko_language->language) {
      $current_language = $language; // Save the current language to restore it later.
      $language = $feneko_language;  // Change the language to the FenekO language to create the PDF
      $feneko_pdf['filecontent'] = $this->generatePDF($id, true); // Generate the FenekO PDF
      $language = $current_language; // Restore the current language
    }

    // Send a mail to the submitter with the form PDF in the attachment
    self::sendMail($user->mail , $subject, $user_msg, array($user_pdf));
    // Send a mail to FenekO with the form PDF //and 1-line CSV// in the attachment
    $feneko_attmnts[] = $feneko_pdf;
    self::sendMail($feneko_mail, $subject, $feneko_msg, $feneko_attmnts);
  }

  /**
   * Handle the message ff this form
   * @param $id The database id for which message has to be handled
   */
  private function message($id, $type) {
    global $user;

    $type = $type === 'offerte' ? t('offerte aanvraag') : t('bestelling');

    $message = variable_get('manyforms_submiting_text', '');
    $message = str_replace('{name}', $user->name, $message);
    $message = str_replace('{type}', $type, $message);
    drupal_set_message(nl2br($message));
  }

  /**
   * Get the fields array to be used in a db_insert statement
   * @param $values The array from $form['form_state']['values']
   * @param $count
   * @return array to be used in a db_insert statement
   */
  private function getSubmitFields($values, $count = 9) {
    global $user;

    $fields = array(
      'uid'        => $user->uid,
      'datesubmit' => REQUEST_TIME,
    );

    foreach ($this->fields as $name => $weight) {
      switch ($name) {
        case 'frame':
          $fields['kader_top'] = $values['kader']['top'];
          $fields['kader_left'] = $values['kader']['left'];
          $fields['kader_right'] = $values['kader']['right'];
          $fields['kader_bottom'] = $values['kader']['bottom'];
          break;

        case 'table1':
        case 'table2':
        case 'table3':
        case 'table4':
          for($i = 1; $i <= $count; $i++) {
            $fields["aantal$i"]    = (int)$values[$name][$i-1]['aantal'];
            $fields["breedte$i"]   = (int)$values[$name][$i-1]['breedte'];
            $fields["hoogte$i"]    = (int)$values[$name][$i-1]['hoogte'];
            $fields["opmerking$i"] = $values[$name][$i-1]['opmerking'];

            // Differentiate between the different table types
            if($name === 'table3' or $name === 'table2') {
              $fields["rails$i"] = (int)$values[$name][$i-1]['rails'];
            }

            if($name === 'table2' or $name === 'table1') {
              $fields["stand$i"] = (int)$values[$name][$i-1]['standt'];
              $fields["t1$i"]    = (int)$values[$name][$i-1]['t1'];
              $fields["t2$i"]    = (int)$values[$name][$i-1]['t2'];
            }

            if($name === 'table1') {
              $fields["t3$i"] = (int)$values[$name][$i-1]['t3'];
            }
          }
          break;

        default:
          $fields[$name] = $this->getSubmitField($name, $values);
          break;
      }
    }

    return $fields;
  }

  /**
   * Get an individual field value to be submitted
   * @param $field_name
   * @param $values The array from $form['form_state']['values']
   * @return The value to be stored in the DB for this field
   */
  private function getSubmitField($field_name, $values) {
    // If this is a field with dependant values concatenate the values with ### in between
    if(isset($this->form[$field_name]['container'][$field_name . "_dep"])) {
      $states_condition = end($this->form[$field_name]['container'][$field_name . "_dep"]['#states']['visible']);

      // Get all the conditional fields
      if(isset($states_condition['value'])) { // Only 1 condition
        $dependantValues[] = $states_condition['value'];
      } else { // Multiple conditions
        foreach ($states_condition as $condition) {
          $dependantValues[] = $condition['value'];
        }
      }

      // Return the value concatenated with the dependant value if the value
      // is in the list of the depending values
      if(in_array($values[$field_name], $dependantValues)) {
        return $values[$field_name] . '###' . $values[$field_name . "_dep"];
      }
    }
    // In all other cases just return the value submitted value for this field
    return $values[$field_name];
  }

  /**
   * Get a CSV export of the submissions of the current form
   * @param $non_exported   Set to TRUE if we want only the records that have
   *                        not been exported before. FALSE will return all matches
   * @param $id             The ID of the record we want (optional)
   * @return string The CSV string
   */
  private function getCSV($non_exported, $id = NULL) {
    $table = "manyforms_" . $this->getId();

    // Query the DB
    $query = db_select($table, 't')->fields('t');
    if($non_exported) {
      $query->condition('exported', 0);
    }
    if(isset($id)) {
      $query->condition('id', $id);
    }

    // Create the CSV
    $results = $query->execute()->fetchAllAssoc('id', PDO::FETCH_ASSOC);
    return self::array2csv($results);
  }

  /**
   * Get the Set Number of the current form
   * @return string The Set Number
   */
  private function getSetNr() {
    $id = intval($this->getId());
    switch ($id) {
      case 1:
      case 2:
      case 3:
      case 15:
        return ":UB46001:";
      case 4:
      case 5:
      case 6:
      case 14:
        return ":UB46002:";
      case 7:
      case 8:
      case 9:
      case 10:
      case 13:
        return ":UB46003:";
      case 11:
      case 12:
      case 16:
        return ":UB46000:";
      default:
        return 'NOT_SET';
    }
  }



  ///////////////////
  // PUBLIC STATIC //
  ///////////////////

  public static function doFiches($operation, $ids) {
    switch ($operation) {
      case 'export':
        self::handleExportFiches($ids);
        break;

      case 'undo_export':
        self::handleExportFiches($ids, TRUE);
        break;

      case 'remove':
        foreach ($ids as $id) {
          list($form_id, $pk) = explode("_", $id);
          db_delete("manyforms_$form_id")->condition('id', $pk)->execute();
        }
        break;

      case 'single':
        self::handleExportFiches($ids, FALSE, TRUE);
        break;
    }
  }

  ////////////////////
  // PRIVATE STATIC //
  ////////////////////

  private static function handleExportFiches($ids, $only_exported = FALSE, $single = FALSE) {
    $omdat = array(
      // 'op_maat' => t('de bevestiging op maat is'),
      'geblokkeerd' => t('de klant geblokkeerd is'),
    );

    if(!$only_exported or !$single) {
      libraries_load('zipstream');
      $zip = new ZipStream('fiches.zip');
    }

    // If $ids is not an array (we assume a string) we make it an array
    if(!is_array($ids)) {
      $ids = array($ids);
    }

    foreach ($ids as $id) {
      list($form_id, $pk) = explode("_", $id);

      // If we saw only exported submissions, we need to unset the exported flag
      if($only_exported) {
        db_update("manyforms_$form_id")->fields(array('exported' => 0))
                                       ->condition('id', $pk)
                                       ->execute();
      } else {
        $ff = new FenekoSpecificForm($form_id);
        $fields = (array) $ff->getRecord($pk);
        $fiche = $ff->getFiche($fields);

        switch ($fiche) {
          // case 'op_maat':
          case 'geblokkeerd':
            $msg = t(':title (pk=:pk) moet manueel ingevoerd worden omdat @omdat.',
              array(':title' => $ff->title, ':pk' => $pk, '@omdat' => $omdat[$fiche]));
            drupal_set_message($msg, 'status');
            if($single) {
              drupal_goto(drupal_get_destination());
            }
            break;

          default:
            if($single) {
              header("Content-type: application/octet-stream");
              header("Content-Disposition: attachment; filename=\"$id.txt\"");
              echo $fiche;
              exit;
            } else {
              // Flag this item as exported and then add it to the zip
              db_update("manyforms_$form_id")->fields(array('exported' => 1))
                                             ->condition('id', $pk)
                                             ->execute();
              $zip->add_file("$id.txt", $fiche);
            }
            break;
        }
      }
    }

    if(!$only_exported) {
      $zip->finish();
      exit;
    }
  }

  private static function parseFormErrorFieldName($tableName, $rowNum, $fieldName) {
    return implode('][', array($tableName, $rowNum, $fieldName));
  }

  private static function setSchuifdeurPomp(&$fields) {
    if($fields['uitvoering'] === 'dubbel') {
      $fields['schuifdeur_pomp'] = 'nvt';
    } else {
      if(!$fields['schuifdeur_pomp']) {
        $fields['schuifdeur_pomp'] = 'geen';
      }
    }
  }

  /**
   * Add a visible field to the $required array
   * and unset the value for an invisible field
   * @param $field  The field to react on
   * @param $name   The name of the field to react on
   * @param $required The array holding the required fields
   * @param $values The values filled in the form
   */
  private static function reactOnVisibility($field, $name, &$required, &$values) {
    if(self::stateIsVisible($field, $name, $values)) {
      $required[] = $name;
    } else {
      $values[$name] = NULL;
    }
  }

  /**
   * Check if the $field with name $name is visible with the current $values
   * taking into account the #states definition of the $field
   * @param $field  The field to check
   * @param $name   The name of the field
   * @param $values The values filled in the form
   * @return boolean TRUE
   */
  private static function stateIsVisible($field, $name, $values) {
    foreach ($field['#states'] as $state => $selectors) {
      switch ($state) {
        case 'visible':
          $ret_match = TRUE;
          break;

        case 'invisible':
          $ret_match = FALSE;
          break;
      }
      foreach ($selectors as $selector => $value_arrays) {
        preg_match("/\"(.*)\"/", $selector, $matches);
        $target_field = $matches[1];
        foreach ($value_arrays as $key => $value_array) {
          // Uniformize value_array to all be an array
          if(!is_array($value_array)) {
            $value_array = array($value_array);
          }
          foreach ($value_array as $key => $value) {
            if(isset($values[$target_field]) && $value === $values[$target_field]) {
              return $ret_match;
            }
          }
        }
      }
      return !$ret_match;
    }
  }





  /////////////////////
  // PROTECTED STATIC//
  /////////////////////

  /**
   * Gets all the fields of a table of a certain type
   * @param $type
   * @return array All the field names in the table
   */
  protected static function getTableFields($type) {
    $fields = array(
      'aantal',
      'breedte',
      'hoogte',
    );

    if($type === 'table3' or $type === 'table2') {
      $fields[] = 'rails';
    }

    if($type === 'table2' or $type === 'table1') {
      $fields[] = 'stand';
      $fields[] = 't1';
      $fields[] = 't2';
    }

    if($type === 'table1') {
      $fields[] = 't3';
    }

    $field[] = 'opmerking';

    return $fields;
  }

  /**
   * Checks if row $row_num in $record is empty
   * @param $record Object the record holding all the field data
   * @param $fields Array all field names of the table
   * @param $rown_num The number of the row (we start with 1)
   * @return boolean TRUE if the no fields in the row hold data
   *                 FALSE if at least 1 field is not empty
   */
  protected static function emptyRow($record, $fields = NULL, $row_num = NULL) {
    if(!isset($row_num)) {
      foreach ($record as $field) {
        if(!empty($field)) return FALSE;
      }
    } else {
      foreach ($fields as $field) {
        $db_field = $field . $row_num;
        if(!empty($record->$db_field)) return FALSE;
      }
    }
    return TRUE;
  }

  /**
   * Splits the value and the dependant value of a DB string
   * @param $string The string holding the DB value ###-delimited
   * @return array (value, dependant value)
   *               If the value doesn't have a dependant value, the second
   *               return value is NUIL
   */
  protected static function explodeDep($string) {
    $chunks = explode('###', $string);
    $val = $chunks[0];
    $dep_val = isset($chunks[1]) ? $chunks[1] : NULL;

    return array($val, $dep_val);
  }

  /**
   * Splits the color value into the name of the color (ral) and the RAL code
   * @param $string The string holding the DB value for the RAL color
   * @return array (value, RAL code)
   *               If it is not a RAL color the second return value is NUIL
   */
  protected static function explodeRal($string) {
    $ral_code = NULL;
    list($val, $dep_val) = self::explodeDep($string);
    if(isset($dep_val)) {
      $chunks = explode(" (", $dep_val);
      $ral_code = $chunks[0];
    }
    return array($val, $ral_code);
  }


  ///////////////////
  // PRIVATE STATIC//
  ///////////////////

  /**
   * Export an array to a CSV
   * @param $array
   * @return string The CSV string
   */
  private static function array2csv(array &$array) {
    if (count($array) == 0) {
     return null;
    }
    ob_start();
    $df = fopen("php://output", 'w');
    fputcsv($df, array_keys(reset($array))); // Set the header based on the keys
    foreach ($array as $row) {
      fputcsv($df, $row);
    }
    fclose($df);
    return ob_get_clean();
  }

  /**
   * Sort all ĺines by the P number
   * @param $unsorted String with all lines in an unsorted way
   * @return string The same lines in an ascended sorted order
   */
  private static function lineSort($unsorted) {
    $delim = PHP_EOL . PHP_EOL;
    $lines = explode($delim, $unsorted);
    $indexed_lines = array();
    foreach ($lines as $line) {
      if(!empty($line)) {
        preg_match('/^:P(.*?):/', $line, $matches);
        $indexed_lines[$matches[1]] = $line;
      }
    }
    ksort($indexed_lines);
    return implode($delim, $indexed_lines) . PHP_EOL;
  }


  protected function getRecord($pk) {
    $id = $this->getId();
    $record = db_query("SELECT * FROM {manyforms_$id} WHERE id = :pk", array(':pk' => $pk))->fetchAll();
    return $record[0];
  }

  /**
   * Convert a string to the file/URL safe "slug" form
   * See http://stackoverflow.com/questions/2668854/sanitizing-strings-to-make-them-url-and-filename-safe
   *
   * @param string $string the string to clean
   * @param bool $is_filename TRUE will allow additional filename characters
   * @return string
   */
  private static function sanitize($string = '', $is_filename = FALSE) {
    // Replace all weird characters with dashes
    $string = preg_replace('/[^\w\-'. ($is_filename ? '~_\.' : ''). ']+/u', '-', $string);

    // Only allow one dash separator at a time (and make string lowercase)
    return mb_strtolower(preg_replace('/--+/u', '-', $string), 'UTF-8');
  }

  /**
   * Helper function to add the infamous table to a Drupal schema
   * @param $schema The Drupal schema to be updated
   */
  private static function addTableToSchema(&$schema, $name) {
    $int = array(
      'type' => 'int',
      'size' => 'big',
    );

    $varchar = array(
      'type' => 'varchar',
      'length' => 100,
      'not null' => true,
    );

    $count = 9;

    // Differentiate between the different table types
    for($i = 1; $i <= $count; $i++) {
      $schema['fields']["aantal$i"]  = $int;
      $schema['fields']["breedte$i"] = $int;
      $schema['fields']["hoogte$i"]  = $int;

      if($name === 'table3' or $name === 'table2') {
        $schema['fields']["rails$i"] = $int;
      }
      if($name === 'table2' or $name === 'table1') {
        $schema['fields']["stand$i"] = $int;
        $schema['fields']["t1$i"]    = $varchar;
        $schema['fields']["t2$i"]    = $varchar;
      }
      if($name === 'table1') {
        $schema['fields']["t3$i"] = $varchar;
      }

      $schema['fields']["opmerking$i"]  = $varchar;
    }
  }

  /**
   * Helper function to add a field to a Drupal schema
   * @param $name   The name of the field to be added to the Drupal schema
   * @param $schema The Drupal schema to be updated
   */
  private static function addFieldToSchema($name, &$schema) {
    $varchar = array(
      'description' => $name,
      'type' => 'varchar',
      'length' => 100,
      'not null' => TRUE,
    );

    $checkbox = array(
      'description' => $name,
      'type' => 'int',
      'size' => 'tiny',
      'not null' => TRUE,
      'unsigned' => TRUE,
      'default' => 0,
    );

    switch ($name) {
      // case 'bijkomende':
      //   $schema['fields'][$name] = array(
      //     'description' => t('bijkomende'),
      //     'type' => 'text',
      //   );
      //   break;
      // Never add afgewerkte or afgewerkte_message to the schema
      case 'afgewerkte':
      case 'afgewerkte_message':
        break;

      case 'datesubmit':
        $schema['fields'][$name] = array(
          'description' => t('submission date'),
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'default' => 0,
        );
        break;

      case 'exported':
        $schema['fields'][$name] = $checkbox;
        $schema['fields'][$name]['description'] = t('Flag to store if the item has been exported before');
        break;

      case 'frame':
        $schema['fields']['kader_top'] = $checkbox;
        $schema['fields']['kader_left'] = $checkbox;
        $schema['fields']['kader_right'] = $checkbox;
        $schema['fields']['kader_bottom'] = $checkbox;
        $schema['fields']['kader_top']['description'] = 'Top checkbox of kader';
        $schema['fields']['kader_left']['description'] = 'Left checkbox of kader';
        $schema['fields']['kader_right']['description'] = 'Right checkbox of kader';
        $schema['fields']['kader_bottom']['description'] = 'Bottom checkbox of kader';
        break;

        case 'gaas_kleur':
          $schema['fields'][$name] = $varchar;
          $schema['fields'][$name]['not null'] = FALSE;
          break;

      case 'id':
        $schema['fields'][$name] = array(
          'description' => t('The primary identifier'),
          'type' => 'serial',
          'unsigned' => TRUE,
          'not null' => TRUE
        );
        break;

      case 'table1':
      case 'table2':
      case 'table3':
      case 'table4':
        self::addTableToSchema($schema, $name);
        break;

      case 'uid':
        $schema['fields'][$name] = array(
          'description' => t('user identifier'),
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'default' => 0,
        );
        break;

      case 'soort_bevestiging':
        $schema['fields'][$name] = $varchar;
        $schema['fields'][$name]['not null'] = FALSE;
        break;

      default:
        $schema['fields'][$name] = $varchar;
        break;
    }
  }

  /**
   * Helper function to send a mail
   * @param $to
   * @param $subject
   * @param $message
   * @return boolean TRUE if the mail could be sent, FALSE otherwise
   */
  public static function sendMail($to, $subject, $message, $attachments = NULL){
    $from = 'Feneko <offerte@feneko.be>';
    $params = array(
      'body'    => $message,
      'subject' => $subject,
      'attachments' => $attachments,
      'headers' => array(
        'Cc' => 'kurt@feneko.be,femi@itsimplyworks.be',
      ),
    );

    if(drupal_mail('manyforms', 'submit', $to, language_default(), $params, $from, TRUE)) {
        return TRUE;
    } else {
        return FALSE;
    }
  }

    /**
   * Get the #options array to be used in the field of a Drupal form, when this
   * field has dynamic options defined in the DB
   * @param $name The name of the field
   * @return array The #options array
   */
  private static function getDynamicFieldOptions($name) {
    global $user;
    global $language ;

    $lang = $language->language ;

    $options = array();
    $text = variable_get("manyforms_" . $name . "_options", '');
    $lines = explode("\n", $text);
    foreach ($lines as $line) {
      $cols = explode('|', $line);
      $key = trim($cols[0]);
      $nl = isset($cols[1]) ? trim($cols[1]) : $key;
      $fr = isset($cols[2]) ? trim($cols[2]) : $nl;
      $options[(string)$key] = $lang === 'nl' ? $nl : $fr;
    }
    return $options;
  }

  /**
  * Get the infamous table to be used as a field in a Drupal Forms API array
  * The technique with the references has been taken from:
  * http://passingcuriosity.com/2011/drupal-7-forms-tables/
  * @param $count  The number of rows in the table
  * @param $weight The weight of the field
  * @return array To be used as a field in a Drupal Forms API array
  */
  private static function getTable($weight, $type) {
    $count = 9;

    // BASIS OF THE TABLE
    $table = array(
      '#prefix' => '<div id="table" class="manyform_table">',
      '#suffix' => '</div>',
      '#tree'       => TRUE,
      '#theme'      => 'table',
      '#header'     => array(
        'aantal'    => t('aantal'),
        'breedte'   => t('breedte') . '<br/>(mm)',
        'hoogte'    => t('hoogte') . '<br/>(mm)',
      ),
      '#weight' => $weight,
      '#rows' => array(),
    );

    // HEADER
    // Differentiate between the different table types
    if($type === 3 or $type === 2) {
      $table['#header']['rails'] = t('lengte<br/>rails');
    }

    if($type === 2 or $type === 1) {
      $table['#header']['stand.t'] = t('standaard T');
      $table['#header']['t1']      = 'T1';
      $table['#header']['t2']      = 'T2';
    }

    if($type === 1) {
      $caption = t('Standaard T<br />
                    Hoogte <=1600 De tussenstijl (VR031) in het midden van het vliegenraam.<br />
                    Hoogte >=1600 Er worden 2 tussenstijlen (VR031) geplaatst gelijkmatig verdeeld over de hoogte.<br /><br />
                    Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                    Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.');
      $table['#header']['t3'] = 'T3';
      $table['#caption'] = $caption;
    }

    if($type === 2) {
      $caption = t('Standaard T<br />
                    Hoogte < 2300mm: Het midden van de tussenstijl in het midden van de schuifvliegendeur<br />
                    Hoogte > 2300mm: Het midden van de tussenstijl bevindt zich op 1000mm<br />
                    Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                    Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.');
      $table['#caption'] = $caption;
    }

    $table['#header']['opmerking'] = t('opmerking');

    // Some many used field definitions
    $int = array(
      '#type' => 'textfield',
      '#element_validate' => array('element_validate_integer_positive'),
    );
    $text = array(
      '#type' => 'textfield',
      '#maxlength' => 40,
    );

    // THE TABLE ROWS
    for ($i = 0; $i < $count; $i++) {
      $aantal = $breedte = $hoogte = $rails = $int;
      $opmerking = $text;

      $t1 = $t2 = $t3 = array(
        '#type' => 'textfield',
        '#states' => array(
          'disabled' => array(
            "input[name=\"table$type" . "[$i][standt]\"]" => array('checked' => TRUE),
          ),
        ),
      );
      $standt = array(
        '#type' => 'checkbox',
        '#default_value' => 0,
      );

      $table[$i] = array(
        'aantal' => &$aantal,
        'breedte' => &$breedte,
        'hoogte' => &$hoogte,
      );

      if($type === 3 or $type === 2) {
        $table[$i]['rails'] = &$rails;
      }

      if($type === 2 or $type === 1) {
        $table[$i]['standt'] = &$standt;
        $table[$i]['t1'] = &$t1;
        $table[$i]['t2'] = &$t2;
      }

      if($type === 1) {
        $table[$i]['t3'] = &$t3;
      }

      $table[$i]['opmerking'] = &$opmerking;

      foreach ($table[$i] as &$col) {
        $table['#rows'][$i][] = array('data' => &$col);
      }

      unset($aantal);
      unset($breedte);
      unset($hoogte);
      unset($standt);
      unset($rails);
      unset($t1);
      unset($t2);
      unset($t3);
      unset($opmerking);
    }

    return $table;
  }


    /**
   * Get the field definition of field with $name and $weight
   * @param $name   The name of the field
   * @param $weight The weight the field needs to have in the form
   * @return array The field definition for the Drupal Forms API
   */
  private function getCode($name, $value) {
    if(trim($value) === '') {
      return;
    }

    $ignore = array(
      'id',
      'uid',
      'exported',
      'datesubmit',
      'klant',
      'referentie',
      'aantal1',
      'breedte1',
      'hoogte1',
      'stand1',
      't11',
      't21',
      't31',
      'aantal2',
      'breedte2',
      'hoogte2',
      'stand2',
      't12',
      't22',
      't32',
      'aantal3',
      'breedte3',
      'hoogte3',
      'stand3',
      't13',
      't23',
      't33',
      'aantal4',
      'breedte4',
      'hoogte4',
      'stand4',
      't14',
      't24',
      't34',
      'aantal5',
      'breedte5',
      'hoogte5',
      'stand5',
      't15',
      't25',
      't35',
      'aantal6',
      'breedte6',
      'hoogte6',
      'stand6',
      't16',
      't26',
      't36',
      'aantal7',
      'breedte7',
      'hoogte7',
      'stand7',
      't17',
      't27',
      't37',
      'aantal8',
      'breedte8',
      'hoogte8',
      'stand8',
      't18',
      't28',
      't38',
      'aantal9',
      'breedte9',
      'hoogte9',
      'stand9',
      't19',
      't29',
      't39',
      'rails1',
      'rails2',
      'rails3',
      'rails4',
      'rails5',
      'rails6',
      'rails7',
      'rails8',
      'rails9',
      'opmerking1',
      'opmerking2',
      'opmerking3',
      'opmerking4',
      'opmerking5',
      'opmerking6',
      'opmerking7',
      'opmerking8',
      'opmerking9',
      'borstel_rechts',
      'gaas_kleur',
      'opties',
      'file',
      'kies_een_optie',
      'schuifdeur',
      'kader_top',
      'kader_left',
      'kader_right',
      'kader_bottom',
      'ondergeleider_anodise',
    );

    $mapping = array(
      'uitvoering' => array(
        '#code' => 4,
        'enkel1'   => 1,
        'enkel2'   => 7,
        'enkel3'   => 4,
        'enkel4'   => 30,
        'enkel5'   => 10,
        'dubbel5'  => 16,
        'zonder5'  => 5,
        'enkel6'   => 1,
        'dubbel6'  => 3,
        'zonder6'  => 2,
        'enkel7'   => 17,
        'enkel8'   => 5,
        'dubbel8'  => 6,
        'enkel9'   => 1,
        'dubbel9'  => 2,
        'enkel10'  => 3,
        'dubbel10' => 4,
        'enkel11'  => 1,
        'dubbel11' => 2,
        'enkel12'  => 3,
        'enkel13'  => 7,
        'dubbel13' => 8,
        'enkel14'  => 4,
        'rv15'     => 8,
        'basic'    => 17,
        'enkel16'  => 6,
      ),
      'scharnierkant' => array(
        '#code' => 5,
        'links'           => 1,
        'rechts'          => 2,
        'geen'            => 3,
        'nvt'             => 3,
        'links###dubbel'  => 4,
        'rechts###dubbel' => 5,
      ),
      'borstel_profiel' => array(
        '#code' => 5,
        'nee' => 3,
        'ja'  => 8,
      ),
      'borstels' => array(
        'geen###geen###enkel'  => array(5 => '', 18 => '', 43 => 1),
        '5mm###geen###enkel'   => array(5 => 1,  18 => 2,  43 => 2),
        '10mm###geen###enkel'  => array(5 => 1,  18 => 3,  43 => 2),
        '15mm###geen###enkel'  => array(5 => 1,  18 => 4,  43 => 2),
        '20mm###geen###enkel'  => array(5 => 1,  18 => 5,  43 => 2),
        'geen###5mm###enkel'   => array(5 => 2,  18 => 1,  43 => 2),
        '5mm###5mm###enkel'    => array(5 => '', 18 => 6,  43 => 3),
        '10mm###5mm###enkel'   => array(5 => 2,  18 => 3,  43 => 2),
        '15mm###5mm###enkel'   => array(5 => 2,  18 => 4,  43 => 2),
        '20mm###5mm###enkel'   => array(5 => 2,  18 => 4,  43 => 2),
        'geen###10mm###enkel'  => array(5 => 3,  18 => 1,  43 => 2),
        '5mm###10mm###enkel'   => array(5 => 3,  18 => 2,  43 => 2),
        '10mm###10mm###enkel'  => array(5 => '', 18 => 7,  43 => 3),
        '15mm###10mm###enkel'  => array(5 => 3,  18 => 4,  43 => 2),
        '20mm###10mm###enkel'  => array(5 => 3,  18 => 5,  43 => 2),
        'geen###15mm###enkel'  => array(5 => 4,  18 => 1,  43 => 2),
        '5mm###15mm###enkel'   => array(5 => 4,  18 => 2,  43 => 2),
        '10mm###15mm###enkel'  => array(5 => 4,  18 => 3,  43 => 2),
        '15mm###15mm###enkel'  => array(5 => '', 18 => 8,  43 => 3),
        '20mm###15mm###enkel'  => array(5 => 5,  18 => 5,  43 => 2),
        'geen###20mm###enkel'  => array(5 => 1,  18 => 1,  43 => 2),
        '5mm###20mm###enkel'   => array(5 => 5,  18 => 2,  43 => 2),
        '10mm###20mm###enkel'  => array(5 => 5,  18 => 3,  43 => 2),
        '15mm###20mm###enkel'  => array(5 => 5,  18 => 4,  43 => 2),
        '20mm###20mm###enkel'  => array(5 => '', 18 => 9,  43 => 3),
        'geen###geen###dubbel' => array(5 => '', 18 => '', 43 => 1),
        '5mm###geen###dubbel'  => array(5 => 1,  18 => 1,  43 => 2),
        '10mm###geen###dubbel' => array(5 => 1,  18 => 11, 43 => 2),
        '15mm###geen###dubbel' => array(5 => 1,  18 => 12, 43 => 2),
        '20mm###geen###dubbel' => array(5 => '', 18 => 13, 43 => 2),
        'geen###5mm###dubbel'  => array(5 => 2,  18 => 1,  43 => 2),
        '5mm###5mm###dubbel'   => array(5 => '', 18 => 6,  43 => 3),
        '10mm###5mm###dubbel'  => array(5 => 6,  18 => 11, 43 => 2),
        '15mm###5mm###dubbel'  => array(5 => 6,  18 => 12, 43 => 2),
        '20mm###5mm###dubbel'  => array(5 => 6,  18 => 12, 43 => 2),
        'geen###10mm###dubbel' => array(5 => 7,  18 => 1,  43 => 2),
        '5mm###10mm###dubbel'  => array(5 => 7,  18 => 11, 43 => 2),
        '10mm###10mm###dubbel' => array(5 => '', 18 => 7,  43 => 3),
        '15mm###10mm###dubbel' => array(5 => 7,  18 => 12, 43 => 2),
        '20mm###10mm###dubbel' => array(5 => 7,  18 => 13, 43 => 2),
        'geen###15mm###dubbel' => array(5 => 8,  18 => 1,  43 => 2),
        '5mm###15mm###dubbel'  => array(5 => 8,  18 => 1,  43 => 2),
        '10mm###15mm###dubbel' => array(5 => 8,  18 => 11, 43 => 2),
        '15mm###15mm###dubbel' => array(5 => '', 18 => 8,  43 => 3),
        '20mm###15mm###dubbel' => array(5 => 9,  18 => 12, 43 => 2),
        'geen###20mm###dubbel' => array(5 => 1,  18 => 1,  43 => 2),
        '5mm###20mm###dubbel'  => array(5 => 9,  18 => 1,  43 => 2),
        '10mm###20mm###dubbel' => array(5 => 9,  18 => 11, 43 => 2),
        '15mm###20mm###dubbel' => array(5 => 9,  18 => 12, 43 => 2),
        '20mm###20mm###dubbel' => array(5 => '', 18 => 9,  43 => 3),
      ),
      'kleur' => array(
        '#code' => 6,
        'wit'       => 1,
        'bruin'     => 2,
        'anodise'   => 3,
        'ral'       => 4,
        'ral_bl'    => 8,
        'ral_a1'    => 9,
        'ral_a2'    => 9,
        'f9001'     => 5,
        '7016'      => 6,
        '7039-70d'  => 7,
        'f9001_s'   => 3,
        'anodise_s' => 5,
      ),
      'type_gaas' => array(
        '#code' => 9,
        'standaard'                    => 1,
        'petscreen###grijs'            => 2,
        'petscreen###onderaan###grijs' => 2,
        'petscreen###volledig###grijs' => 3,
        'soltisdoek1'                  => 3,
        'soltisdoek2'                  => 4,
        'inox1'                        => 4,
        'inox2'                        => 5,
        'clearview'                    => 5,
        'clearview###volledig'         => 6,
        'clearview###onderaan'         => 8,
        'petscreen###zwart'            => 7,
        'petscreen###onderaan###zwart' => 8,
        'petscreen###volledig###zwart' => 9,
        'petscreen###volledig'         => '', // In case there is old data
        'petscreen###onderaan'         => '', // In case there is old data
      ),
      'pvc' => array(
        '#code' => 10,
        'zwart' => 1,
        'wit'   => 2,
        'bruin' => 3,
        'grijs' => 4,
        'nvt'   => 5,
      ),
      'diepte' => array(
        '#code' => 18,
        '20'  => 1,
        '30'  => 2,
        '40'  => 3,
        '50'  => 4,
        '60'  => 5,
        'nvt' => 6,
      ),
      'opties' => array(
        '#code' => 18,
        'nvt'          => 1,
        'gebogen'      => 2,
        'ondervulling' => 3,
        'rondom'       => 4,
        'nvt_raam'     => 6,
        'gebogen_raam' => 15,
      ),
      'speling' => array(
        '#code' => 18,
        'ja'  => 6,
        'nee' => 18,
      ),
      'dierendeur' => array(
        '#code' => 21,
        'geen'                => 1,
        'hond_groot###links'  => 7,
        'hond_groot###midden' => 9,
        'hond_groot###rechts' => 8,
        'hond_klein###links'  => 4,
        'hond_klein###midden' => 6,
        'hond_klein###rechts' => 5,
        'kat###links'         => 11,
        'kat###midden'        => 3,
        'kat###rechts'        => 2,
      ),
      'soort_bevestiging' => array(
        '#code' => 21,
        '4'  => 1,
        '5'  => 2,
        '7'  => 3,
        '10' => 4,
        '12' => 5,
        '15' => 6,
        '16' => 7,
        '17' => 8,
        '19' => 9,
        '32' => 10,
        '37' => 11,
        '6'  => 12,
        '22' => 13,
        '30' => 14,
        '5extr' => 15,
        '25' => 16,
        '26' => 17,
        '28' => 18,
        '7extr' => 19,
        '21'    => 20,
        '34'    => 21,
        'sl'    => 22,
        'sl38'  => 24,
        '18'    => 25,
        '20'    => 26,
        'hh'    => 30,
        'sch'   => 31,
        'spie_klemveer' => 54,
        'hoge_lage'     => 55,
        'op_maat'       => '',
      ),
      'verbreding' => array(
        '#code' => 27,
        'geen' => 9,
        'nee'  => 10,
        'ja'   => 11,
        'standaard' => 10,
      ),
      'kader' => array(
        '#code' => 27,
        'standaard' => 1,
        'smal'      => 2,
        'nvt'       => 3,
        'vp1000'    => 4,
        'vp1001'    => 5,
      ),
      'profiel' => array(
        '#code' => 27,
        'vr033'      => 1,
        'vr033ultra' => 2,
        'vr050'      => 3,
        'vr060'      => 4,
        'vr080'      => 5,
        'vr090'      => 6,
        'rv'         => 18,
      ),
      'borstel_kopse_kant' => array(
        '#code' => 27,
        'nvt'  => 1,
        'geen' => 2,
        '5mm'  => 3,
        '10mm' => 4,
        '15mm' => 5,
        '20mm' => 6,
      ),
      'sluiting' => array(
        '#code' => 30,
        'magneet'   => 1,
      ),
      'stootrubber' => array(
        '#code' => 30,
        'ja'   => 1,
        'nee'  => 2,
        'val1' => 3,
        'val2' => 5,
        'nvt'  => 3,
      ),
      'kader12' => array(
        '#code' => 31,
        '3/4'    => 14,
        'rondom' => 13,
      ),
      'frame#kader' => array(
        '#code' => 31,
        '0000' => '',
        '0001' => 2,
        '0010' => 1,
        '0011' => 4,
        '0100' => 2,
        '0101' => 11,
        '0110' => 6,
        '0111' => 7,
        '1000' => 1,
        '1001' => 3,
        '1010' => 10,
        '1011' => 12,
        '1100' => 5,
        '1101' => 7,
        '1110' => 12,
        '1111' => 8,
      ),
      'bevestiging' => array(
        '#code' => 31,
        'op'   => 1,
        'los'  => 2,
        'geen' => 3,
        'nvt'  => 4,
      ),
      'plint' => array(
        '#code' => 31,
        'geen'         => 1,
        'f300mm'       => 2,
        'tot_tssstijl' => 3,
        'andere'       => 4,
      ),
      'ondergeleider' => array(
        '#code' => 32,
        'vp1012'      => 1,
        'vr073'       => 2,
        'vr074'       => 3,
        'vp1016'      => 4,
        'vp1016a'     => 6,
        'vp1012a'     => 8,
        'vr073a'      => 9,
        'vr074a'      => 10,
        'u15x25x15x2' => 11,
        'geen'        => 8,
        'plat'        => 1,
        '6.5'         => 2,
      ),
      'bovengeleider' => array(
        '#code' => 33,
        'vp5087'      => 1,
        'vp1011'      => 2,
        'vp4961'      => 3,
        'vp5088'      => 4,
        'vp5514'      => 5,
        'vp1012'      => 6,
        'l20x20x2'    => 7,
        'vr073'       => 8,
        'vr074'       => 9,
        'u20x25x20x2' => 10,
      ),
      'borstel' => array(
        '#code' => 34,
        'nvt'  => 1,
        'geen'  => 1,
        'zij'   => 2,
        'kopse' => 3,
        '5mm'  => 5,
        '10mm' => 6,
        '15mm' => 7,
      ),
      'pomp' => array(
        '#code' => 34,
        'nvt'  => 3,
        'ja'   => 2,
        'nee'  => 1,
      ),
      'eindstoppen' => array(
        '#code' => 34,
        'ja'  => 2,
        'nee' => 1,
      ),
      'kader_plisse' => array(
        '#code' => 42,
        'ja'  => 1,
        'nee' => 2,
      ),
      'kleur_pees' => array(
        '#code' => 42,
        'zwart' => 1,
        'grijs' => 2,
      ),
      'hoekverbinding' => array(
        '#code' => 43,
        'geen'    => 1,
        'gevezen' => 2,
        'geperst' => 3,
      ),
      'diepte_borstel' => array(
        '#code' => 43,
        'geen' => '',
        '5'    => 2,
        '10'   => 3,
        '15'   => 4,
        '20'   => 5,
      ),
      'afdekdoppen' => array(
        '#code' => 44,
        'ja'  => 1,
        'nee' => 2,
        'nvt' => 3,
      ),
      'schuifdeur_pomp' => array(
        '#code' => 47,
        'links'  => 1,
        'rechts' => 2,
        'nvt'    => 3,
        'geen'   => 4,
      ),
      'aantal'     => 'P1',
      'breedte'    => 'P2',
      'hoogte'     => 'P3',
      'stand'      => 'P7',
      'plint_dep'  => 'P8',
      't1'         => 'P19',
      'rails'      => 'P35',
      't2'         => 'P36',
      't3'         => 'P37',
      'kleur_dep'  => 'P38',
      'montagediepte' => 'P40',
    );

    // When clipsen op maat is chosen, we ignore
    if($name === 'soort_bevestiging' and strstr($value, 'op_maat###') !== FALSE) {
      $value = 'op_maat';
      // return;
    }

    switch ($name) {
      case 'borstels':
        $ret = '';
        $chunks = explode('###', $value);

        $orig_name = array(
          5  => 'borstel_rechts',
          18 => 'borstel_links',
          43 => 'borstels',
        );

        $orig_val = array(
          5  => $chunks[1],
          18 => $chunks[0],
          43 => NULL,
        );

        foreach ($mapping[$name][$value] as $p => $val) {
          $ret .= $this->addCodeComment(":P$p: $p.$val", $orig_name[$p], $orig_val[$p]);
        }
        return $ret;

      default:
        if(isset($mapping[$name])) {
          if(is_array($mapping[$name])) { // A select field
            if(isset($mapping[$name]['#code'])) {
              $p = $mapping[$name]['#code'];
              if(isset($mapping[$name][$value])) {
                if($mapping[$name][$value] !== '') {
                  return $this->addCodeComment(":P$p: $p." . $mapping[$name][$value], $name, $value);
                }
              } else {
                drupal_set_message(t("The key :value could not be found for :name.",
                  array(":value" => $value, ":name" => $name)), 'warning');
              }
            } else {
              drupal_set_message(t("The code for :name could not be found.",
                array(":name" => $name)), 'warning');
            }
          } else { // A textfield
            if(!empty($value) or $value === '0') {
              $code = $mapping[$name];
              return $this->addCodeComment(":$code: $value", $name);
            }
          }
        } else {
          // TODO: For debug only
          if(!in_array($name, $ignore)) {
            drupal_set_message(t("$name not found"), 'warning');
          }
        }
    }
  }

  // Taken from http://stackoverflow.com/questions/6228252/xor-with-3-values
  private static function ternary_xor($a, $b, $c) {
    // return ($a and !$b and !$c) || (!$a and $b and !$c) || (!$a and !$b and $c);
    return (!$a && ($b xor $c)) || ($a && !($b || $c));
  }


  private function getFieldTitle($name) {
    // Find the field as field or dependant field
    $field = $this->getField($name); // Normal field
    if(!isset($field)) {
      $orig_name = str_replace('_dep', '', $name);
      $orig_field = $this->getField($orig_name);
      if(isset($orig_field['container'][$name])) {
        $field = $orig_field['container'][$name];
      }
    }

    if(isset($field[$name]['#title'])) {
      return $field[$name]['#title'];
    } elseif(isset($field['#title'])) {
      return $field['#title'];
    } else {
      // Translate the field name
      switch ($name) {
        case 't1': return t('Tussenstijl 1');
        case 't2': return t('Tussenstijl 2');
        case 't3': return t('Tussenstijl 3');
        case 'montagediepte': return t('Montagediepte onder');
        default:   return $name; // Fallback to the name
      }
    }
  }


  private function addCodeComment($string, $name, $value = NULL) {
    $colsize = 12;
    $format = '%-' . $colsize . 's %s';
    $comment = '$$ ' . $this->getFieldTitle($name);

    // Translate some values
    switch ($value) {
      case 'nvt':
        $value = t('Niet van toepassing');
        break;
    }

    // Add the human readible value if set
    if(isset($value)) {
      // Translate the special RAL values
      $rals = array(
        'ral' => 'Ral-' . t('color'),
        'ral_bl' => 'BudgetLine',
        'ral_a1' => t('Group') . ' A',
        'ral_a2' => t('Group') . ' A',
      );
      $value = isset($rals[$value]) ? $rals[$value] : $value;

      $comment .= ": $value";
    }

    $line = sprintf($format, $string, $comment);
    return $line . PHP_EOL . PHP_EOL;
  }



  /**
   * Gets the articles document for manual processing
   *
   * @param array $fields
   *   The submission fields
   * @param array $values
   *   Key value pairs determining the article and the corresponding value
   * @return string
   *   The content of the file
   */
  private static function getArticles($fields, $values) {
    $articles = "Klant     : " . $fields['klant'] . "\n"
              . "Gebruiker : " . user_load($fields['uid'])->name . "\n"
              . "Referentie: " . $fields['referentie'] . "\n\n"
              . "Artikelen :\n";
    foreach ($values as $key => $value) {
      switch ($key) {
        case 'op_maat':
          $articles .= " - Clipsen op maat: $value\n";
          break;
      }
    }

    return $articles;
  }

    /**
   * Get the field definition of field with $name and $weight
   * @param $name   The name of the field
   * @param $weight The weight the field needs to have in the form
   * @return array The field definition for the Drupal Forms API
   */
  private function getField($name, $weight = 0) {
    // Much used options
    $borstel_options = array(
      'geen' => t('geen'),
      '5mm'  => '5mm',
      '10mm' => '10mm',
      '15mm' => '15mm',
      '20mm' => '20mm',
    );
    $ja_nee_options = array(
      'ja'  => t('ja'),
      'nee' => t('nee'),
    );

    switch ($name) {
      case 'afdekdoppen':
        return array(
          '#title' => t('afdekdoppen op vleugel en kader'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#options' => $ja_nee_options,
          '#states' => array(
            'invisible' => array(
              'input[name="kader"]' => array('value' => 'smal'),
            ),
          ),
        );

      case 'afgewerkte':
        return array(
          '#title' => t('Afgewerkte maten'),
          '#type' => 'checkbox',
          '#weight' => $weight,
          '#description' => t('Indien u dit aanvinkt, zullen de maten bij bestelling automatisch aangepast worden naar de doorkijkmaten.'),
        );

      case 'afgewerkte_message':
        return array(
          '#type' => 'container',
          'wrapper' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('messages', 'warning')),
            'message' => array(
              '#markup' => t('U heeft afgewerkte maten aangevinkt. Dit betekent dat de maten bij bestelling automatisch aangepast zullen worden naar doorkijkmaten.'),
            ),
          ),
          '#weight' => $weight,
          '#states' => array(
            'visible' => array(
              'input[name="afgewerkte"]' => array('checked' => true),
            ),
          ),
        );

      case 'bevestiging':
        return array(
          '#title' => t('bevestiging'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => array(
            'geen' => t('geen bevestiging'),
            'los'  => t('los'),
            'op'   => t('op vliegenraam'),
          ),
        );

      case 'borstel':
        return array(
          '#title' => t('borstel'),
          '#type' => 'radios',
          '#required' => TRUE,
          '#weight' => $weight,
          '#options' => array(
            'kopse' => t('kopse kant'),
            'zij' => t('zijkant'),
          ),
        );

      case 'borstel_kopse_kant':
        return array(
          '#title' => t('borstel kopse kant'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $borstel_options,
        );

      case 'borstel_links':
        return array(
          '#title' => t('borstel links'),
          '#type' => 'radios',
          '#description' => t('Borstel van van buiten gezien'),
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $borstel_options,
        );

      case 'borstel_rechts':
        return array(
          '#title' => t('borstel rechts'),
          '#type' => 'radios',
          '#description' => t('Borstel van van buiten gezien'),
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $borstel_options,
        );

      case 'borstel_profiel':
        return array(
          '#title' => t('Borstelprofiel VP1200'),
          '#type' => 'radios',
          '#required' => FALSE,
          '#weight' => $weight,
          '#options' => array(
            'nee'  => t('nee'),
            'ja'  => t('ja'),
          ),
          '#states' => array(
            'visible' => array(
              'input[name="profiel"]' => array('value' => 'vr060'),
            ),
          ),
        );

      case 'bovengeleider':
        return array(
          '#title' => t('bovengeleider'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => array(
            'vp5087' => 'vp5087',
            'vp1011' => 'vp1011',
            'vp4961' => 'vp4961',
            'vp5088' => 'vp5088',
            'vp5514' => 'vp5514',
          ),
        );

      case 'cancel_button':
        return array(
          '#weight' => $weight,
          '#markup' => '<a href="javascript:history.back();">' . t('Back') . '</a>',
        );

      case 'diepte':
        return array(
          '#title' => t('diepte'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#options' => array(
            '20'      => 20,
            '30'      => 30,
            '40'      => 40,
            '50'      => 50,
            '60'      => 60,
          ),
          '#states' => array(
            'visible' => array(
              'input[name="profiel"]' => array('value' => 'vr033ultra'),
            ),
          ),
        );

      case 'diepte_borstel':
        return array(
          '#title' => t('diepte'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#options' => array(
            'geen' => t('geen'),
            '5'    => '5mm',
            '10'   => '10mm',
            '15'   => '15mm',
            '20'   => '20mm',
          ),
          '#states' => array(
            'visible' => array(
              'input[name="borstel"]' => array('value' => 'zij'),
            ),
          ),
        );

      case 'dierendeur':
        return array(
          '#type' => 'container',
          '#weight' => $weight,
          'dierendeur' => array(
            '#title' => t('dierendeur'),
            '#type' => 'radios',
            '#options' => array(
              'geen'       => t('geen'),
              'hond_groot' => t('hond groot'),
              'hond_klein' => t('hond klein'),
              'kat'        => t('kat'),
            ),
            '#states' => array(
              'invisible' => array(
                'input[name="plint"]' => array('value' => 'geen'),
              ),
            ),
          ),
          'container' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('dep-container')),
            'dierendeur_dep' => array(
              '#title' => t('Dierendeur plaats'),
              '#title_display' => 'invisible',
              '#type' => 'radios',
              '#options' => array(
                'links'  => t('links'),
                'midden' => t('midden'),
                'rechts' => t('rechts'),
              ),
              '#states' => array(
                'visible' => array(
                  'input[name="dierendeur"]' => array(
                    array('value' => 'hond_groot'),
                    array('value' => 'hond_klein'),
                    array('value' => 'kat'),
                  ),
                ),
              ),
            ),
          ),
        );

      case 'eindstoppen':
        return array(
          '#title' => t('eindstoppen'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $ja_nee_options,
        );

      case 'file':
        return array(
          '#title' => t('Tekening opladen'),
          '#type' => 'file',
          '#weight' => $weight,
          '#states' => array(
            'visible' => array('input[name="opties"]' => array('value' => 'gebogen')),
          ),
          '#description' => t('De toegelaten bestandstypes zijn: :types.<br />De maximum grootte is: :max.',
                              array(
                                ':types' => 'pdf jpg jpeg png dwg dxf',
                                ':max' => '3MB',
                            )),
        );

      case 'frame':
        return array(
          '#title' => t('kader'),
          '#type' => 'container',
          '#weight' => $weight,
          'title' => array(
            '#prefix' => '<label>',
            '#suffix' => '</label>',
            '#markup' => t('kader'),
          ),
          'kader' => array(
            '#type' => 'container',
            'kader' => array(
              '#type' => 'container',
              '#attributes' => array('class' => array('kader')),
              '#tree' => true,
              'markup' => array(
                '#markup' => t('Duid aan waar u een kader wenst'),
              ),
              'top' => array(
                '#type' => 'checkbox',
                '#default_value' => 0,
              ),
              'left' => array(
                '#type' => 'checkbox',
                '#default_value' => 0,
              ),
              'right' => array(
                '#type' => 'checkbox',
                '#default_value' => 0,
              ),
              'bottom' => array(
                '#type' => 'checkbox',
                '#default_value' => 0,
              ),
            ),
          ),
        );

      case 'hoekverbinding':
        return array(
          '#title' => t('hoekverbinding'),
          '#type' => 'radios',
          '#weight' => $weight,
          // '#required' => TRUE,
          '#options' => array(
            'gevezen' => t('gevezen'),
            'geperst' => t('geperst'),
          ),
          '#states' => array(
            'invisible' => array(
              'input[name="kader"]' => array('value' => 'vp1001'),
            ),
          ),
        );

      case 'kader':
        return array(
          '#title' => t('kader'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#options' => array(
            'standaard' => t('standaard'),
            'smal'      => t('smal'),
          ),
        );

      case 'kies_een_optie':
        return array(
          '#title' => t('kies een optie'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#prefix' => '<div id="kies-een-optie">',
          '#suffix' => '</div>',
          '#options' => array(
            'bestelling' => t('bestelling'),
            'offerte'    => t('offerte'),
          ),
          '#default_value' => 'offerte',
        );

      case 'klant':
        return array(
          '#title' => t('Klant'),
          '#type' => 'select',
          '#weight' => $weight,
          '#options' => feneko_code_get_clients_options(),
          '#required' => TRUE,
          // TODO: fix: table values are not posted anymore and on error this is
          //       not initialized
          // '#ajax' => array(
          //   'event' => 'change',
          //   'callback' => 'manyforms_kies_een_optie_callback',
          //   'wrapper' => 'kies-een-optie',
          //   'method' => 'replace',
          // ),
        );

      case 'kleur':
        return array(
          '#type' => 'container',
          '#weight' => $weight,
          'kleur' => array(
            '#title' => t('kleur'),
            '#type' => 'radios',
            '#required' => TRUE,
            '#options' => array(
              'wit'     => t('wit'),
              'f9001'   => '9001',
              'bruin'   => t('bruin'),
              '7016'    => '7016',
              'anodise' => t('anodise'),
              'ral'     => t('ral'),
            ),
          ),
          'container' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('dep-container', 'inline')),
            'kleur_dep' => array(
              '#title' => t('RAL code'),
              '#type' => 'textfield',
              '#description' => t('XXXX-30d** => Standaard voor matkleuren<br />XXXX-70d* => Standaard voor blinkende kleuren'),
              '#title_display' => 'invisible',
              '#autocomplete_path' => 'manyforms/autocomplete/'.$this->getId(),
              '#attributes' => array(
                'placeholder' => t('Zoek de RAL code'),
              ),
              '#states' => array(
                'visible' => array(
                  'input[name="kleur"]' => array('value' => 'ral'),
                ),
              ),
            ),
          ),
        );

      case 'kleur_pees':
        return array(
          '#title' => t('kleur pees'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => array(
            'zwart' => t('zwart'),
            'grijs' => t('grijs'),
          ),
        );

      case 'ondergeleider':
        return array(
          '#title' => t('ondergeleider'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => array(
            'vp1012'  => 'vp1012',
            'vr073'   => 'vr073',
            'vr074'   => 'vr074',
            'vp1016'  => 'vp1016',
            'vp1012a' => 'vp1012 (anodise)',
            'vp1016a' => 'vp1016 (anodise)',
            'vr073a'  => 'vr073 (anodise)',
            'vr074a'  => 'vr074 (anodise)',
          ),
        );

      case 'ondergeleider_anodise':
        return array(
          '#title' => t('ondergeleider anodisé'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $ja_nee_options,
        );

      case 'opties':
        return array(
          '#title' => t('opties'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#options' => array(
            'nvt' => t('Niet van toepassing'),
            'gebogen' => t('Gebogen/Schuin'),
          ),
          '#default_value' => 'nvt',
          '#prefix' => '<div id="opties-replace">',
          '#suffix' => '</div>',
        );

      case 'plint':
        return array(
          '#type' => 'container',
          '#weight' => $weight,
          'plint' => array(
            '#title' => t('plint'),
            '#type' => 'radios',
            '#required' => TRUE,
            '#options' => array(
              'geen'         => t('geen'),
              'f300mm'       => '300mm',
              'tot_tssstijl' => t('tot tussenstijl'),
              'andere'       => t('andere'),
            ),
          ),
          'container' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('dep-container', 'inline')),
            'plint_dep' => array(
              '#title' => t('Andere plint maat'),
              '#title_display' => 'invisible',
              '#type' => 'textfield',
              '#element_validate' => array('element_validate_integer'),
              '#attributes' => array(
                'placeholder' => t('Geef hier andere maten in...'),
              ),
              '#states' => array(
                'visible' => array(
                  'input[name="plint"]' => array('value' => 'andere'),
                ),
              ),
            ),
          ),
        );

      case 'pomp':
        return array(
          '#title' => t('pomp'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $ja_nee_options,
        );

      case 'profiel':
        return array(
          '#title' => t('profiel'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => array(
            'vr050' => 'vr050(16mm)',
            'vr060' => 'vr060(11mm)',
            'vr080' => 'vr080(24mm)',
            'vr090' => 'vr090(40mm)',
          ),
        );

      case 'pvc':
        return array(
          '#title' => t('kleur toebehoren PVC'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => array(
            'wit'   => t('wit'),
            'bruin' => t('bruin'),
            'zwart' => t('zwart'),
            'grijs' => t('grijs'),
          ),
        );

      case 'referentie':
        return array(
          '#title' => t('referentie'),
          '#type' => 'textfield',
          '#description' => t('De referentie dient om je stukken makkelijker terug te vinden'),
          '#weight' => $weight,
          '#size' => 60,
          '#maxlength' => 128,
          '#required' => TRUE,
        );

      case 'scharnierkant':
        return array(
          '#title' => t('scharnierkant'),
          '#type' => 'radios',
          '#description' => t('Kant scharnier van van buiten gezien<br />Scharnierkant is de eerst opendraaiende deur'),
          '#weight' => $weight,
          '#required' => FALSE,
          '#options' => array(
            'links' => t('links'),
            'rechts' => t('rechts'),
          ),
          '#states' => array(
            'invisible' => array(
              'input[name="uitvoering"]' => array(
                array('value' => 'zonder'),
              ),
            ),
          ),
        );

      case 'schuifdeur_pomp':
        return array(
          '#title' => t('pomp'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => FALSE,
          '#options' => array(
            'geen' => t('geen'),
            'links'  => t('rechts gemonteerd (deur opent naar links)'),
            'rechts' => t('links gemonteerd (deur opent naar rechts)'),
          ),
          '#description' => t('Van buiten gezien'),
          '#states' => array(
            'visible' => array(
              'input[name="uitvoering"]' => array(
                array('value' => 'enkel'),
              ),
            ),
          ),
        );

      case 'soort_bevestiging':
        return array(
          '#type' => 'container',
          '#weight' => $weight,
          '#states' => array(
            'invisible' => array(
              'input[name="bevestiging"]' => array(
                array('value' => 'geen'),
              ),
            ),
          ),
          'soort_bevestiging' => array(
            '#title' => t('soort bevestiging'),
            '#type' => 'radios',
            '#required' => FALSE,
            '#options' => self::getDynamicFieldOptions('soort_bevestiging') +
                          array('op_maat' => t('Op maat')),
          ),
          'container' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('dep-container')),
            'soort_bevestiging_dep' => array(
              '#title' => t('Andere soort bevestiging'),
              '#title_display' => 'invisible',
              '#type' => 'textfield',
              '#attributes' => array('placeholder' => t('Geef zelf de gewenste maat op')),
              '#states' => array(
                'visible' => array(
                  'input[name="soort_bevestiging"]' => array(
                    array('value' => 'op_maat'),
                  ),
                ),
              ),
            ),
          ),
        );

      case 'speling':
        return array(
          '#title' => t('speling voorzien'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#options' => $ja_nee_options,
          '#states' => array(
            'visible' => array(
              'input[name="profiel"]' => array(
                array('value' => 'vr033'),
              ),
            ),
          ),
        );

      case 'stootrubber':
        return array(
          '#title' => t('stootrubber'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => TRUE,
          '#options' => $ja_nee_options,
        );

      case 'submit_button':
        return array(
          '#type' => 'submit',
          '#weight' => $weight,
          '#value' => t('Submit'),
        );

      case 'table1':
        return self::getTable($weight, 1); // weight 30

      case 'table2':
        return self::getTable($weight, 2); // weight 30

      case 'table3':
        return self::getTable($weight, 3); // weight 30

      case 'table4':
        return self::getTable($weight, 4); // weight 30

      case 'type_gaas':
        return array(
          '#type' => 'container',
          '#weight' => $weight,
          'type_gaas' => array(
            '#title' => t('type gaas'),
            '#type' => 'radios',
            '#description' => t('Soltisdoek is door u aan te leveren.'),
            '#required' => TRUE,
            '#options' => array(
              'standaard'  => t('standaard'),
              'petscreen'  => t('petscreen'),
              'clearview'  => t('clearview'),
              'soltisdoek' => t('soltisdoek'),
              'inox'       => t('inox'),
            ),
          ),
          'container' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('dep-container')),
            'type_gaas_dep' => array(
              '#title' => t('Gaas plaats'),
              '#title_display' => 'invisible',
              '#type' => 'radios',
              '#options' => array(
                'onderaan' => t('onderaan'),
                'volledig'  => t('volledig'),
              ),
              '#states' => array(
                'visible' => array(
                  'input[name="type_gaas"]' => array(
                    array('value' => 'petscreen'),
                    array('value' => 'clearview'),
                  ),
                ),
              ),
            ),
          ),
        );

      case 'gaas_kleur':
        return array(
          '#title' => t('gaas kleur'),
          '#type' => 'radios',
          '#weight' => $weight,
          '#required' => FALSE,
          '#options' => array(
            'grijs'  => t('grijs'),
            'zwart' => t('zwart'),
          ),
          '#states' => array(
            'visible' => array(
              'input[name="type_gaas"]' => array('value' => 'petscreen'),
            ),
          ),
        );

      case 'uitvoering':
        return array(
          '#type' => 'container',
          '#weight' => $weight,
          'uitvoering' => array(
            '#title' => t('uitvoering'),
            '#type' => 'radios',
            '#required' => TRUE,
            '#options' => array(
              'enkel'  => t('enkel'),
              'dubbel' => t('dubbel'),
            ),
          ),
          'container' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('description')),
            'conditional_help' => array(
              '#markup' => t('De breedte is de maat van de 2 vleugels samen'),
            ),
            '#states' => array(
              'visible' => array(
                'input[name="uitvoering"]' => array('value' => 'dubbel'),
              ),
            ),
          ),
        );

      default:
        return NULL;
    }
  }
}
