<?php
class FenekoSpecificForm extends FenekoForm {
  public $form;

  public function __construct($id, array $fields = NULL) {
    parent::__construct($id, $fields);
    $this->setFields();
    $this->form = $this->getForm();
    $this->setValueExceptions();
  }

  public function generatePDF($dbId, $outputAsString = FALSE) {
    libraries_load('mpdf');

    $record = $this->getRecord($dbId);

    $type = $this->form['kies_een_optie']['#options'][$record->kies_een_optie];

    $border = "1px solid black";

    $html="
    <html>
    <head>
    <style>
    body {
      font-size: 12px;
    }

    h1 {
      font-size: 30px;
      letter-spacing: 3px;
      margin: 0;
    }

    h3 {
      margin: 0;
      font-weight: normal;
      font-size: 13px;
      text-transform: uppercase;
    }
    .left {
      width: 40%;
    }
    .right {
      width: 60%;
    }

    .inline {
      float: left;
    }

    .inline-field {
      clear: both;
    }

    .inline-field div {
      border-top: $border;
      border-left: $border;
      padding: 2px 5px;
      float: left;
    }

    .inline-field div.value {
      border-right: $border;
    }

    .last div {
      border-bottom: $border;
    }

    .inline-field .label {
      width: 20%;
      text-transform: uppercase;
    }

    .inline-field .value {
      width: 74%;
    }
    .maintable {
      width:100%;
      border-collapse: collapse;
      border: $border;
      margin-top: 5px;
    }
    .maintable td {
      border: $border;
      height: 20px;
      text-align: center;
      font-size: 20px;
    }
    .maintable th {
      background: gray;
      border: $border;
    }
    .choices div {
      border: $border;
      width: 140px;
      float: left;
      padding: 5px 0px 4px 4px;
      margin: 0 0 5px 5px;
    }
    .choices .has-dep {
      margin-bottom: 0px;
    }
    .choices div.dep {
      border: 0;
      clear: both;
      padding: 0;
      width: auto;
    }
    .choices .dep div {
      margin-left: 0;
      margin-bottom: 0;
      border-top: none;
      border-right: none;
    }
    .choices .dep div.last {
      border-right: $border;
    }
    .left .choices div {
      width: 128px;
    }
    .kader {
      width: 278px;
      height: 100px;
      border: 10px solid gray;
      margin-left: 5px;
      margin-right: 20px;
    }
    .kader div {
      position: absolute;
    }
    .measures {
      margin-left: 10px;
    }
    .measures .inline-field {
      padding-right-top: 5px;
    }
    .measures .label {
      border: none;
      width: 60px;
    }
    .measures .value {
      border: $border;
      height: 16px;
    }


    .top-line {
      border-top: $border;
      font-size: 20px;
      width: 650px;
      margin-left: 170px;
      text-align: center;
    }
    .feneko_logo {
      text-align: right;
      font-family: Georgia, 'Times New Roman', serif;
    }
    .feneko_logo span {
      font-size: 56px;
    }
    .feneko_logo span.feneko_o {
      color: #295D8F;
    }
    .slogan {
      text-transform: uppercase;
      color: gray;
      font-family: Arial,Helvetica,clean,sans-serif;
      font-size: 10px;
      letter-spacing: 1px;
      line-height: 10px;
    }
    .client-logo {
      float:left;
      max-height: 70px;
      max-width: 170px;
    }

    </style>
    </head>
    <body>";
    $html .= '<h1>' . $this->title . ': ' . strtoupper($type) . ' ' . t('via website') . '</h1>';
    $html .= '<div class="inline left">';
    $html .= $this->remark . '<br/><br />';
    $html .= $this->parsePDFfield('uid', $record);
    $html .= $this->parsePDFfield('datesubmit', $record);
    $html .= $this->parsePDFfield('klant', $record);
    $html .= $this->parsePDFfield('referentie', $record);
    $html .= $this->parsePDFfullWidthField('table1', $record);
    $html .= $this->parsePDFfullWidthField('table2', $record);
    $html .= $this->parsePDFfullWidthField('table3', $record);
    $html .= $this->parsePDFfullWidthField('table4', $record);
    $html .= $this->parsePDFfullWidthField('uitvoering', $record);
    $html .= $this->parsePDFfullWidthField('ondergeleider', $record);
    $html .= $this->parsePDFfullWidthField('ondergeleider_anodise', $record);
    $html .= $this->parsePDFfullWidthField('bovengeleider', $record);
    $html .= $this->parsePDFfullWidthField('borstel_kopse_kant', $record);
    $html .= '</div>';
    $html .= '<div class="inline right" style="margin-left: 10px">';
    $html .= $this->parsePDFfullWidthField('profiel', $record);
    $html .= $this->parsePDFfullWidthField('diepte', $record);
    $html .= $this->parsePDFfullWidthField('kader', $record);
    $html .= $this->parsePDFfullWidthField('kleur', $record);
    $html .= $this->parsePDFfullWidthField('type_gaas', $record);
    $html .= $this->parsePDFfullWidthField('gaas_kleur', $record);
    $html .= $this->parsePDFfullWidthField('scharnierkant', $record);
    $html .= $this->parsePDFfullWidthField('stootrubber', $record);
    $html .= $this->parsePDFfullWidthField('pomp', $record);
    $html .= $this->parsePDFfullWidthField('plint', $record);
    $html .= $this->parsePDFfullWidthField('borstel_links', $record);
    $html .= $this->parsePDFfullWidthField('borstel_rechts', $record);
    $html .= $this->parsePDFfullWidthField('eindstoppen', $record);
    $html .= $this->parsePDFfullWidthField('schuifdeur_pomp', $record);
    $html .= $this->parsePDFfullWidthField('dierendeur', $record);
    $html .= $this->parsePDFfullWidthField('bevestiging', $record);
    $html .= $this->parsePDFfullWidthField('soort_bevestiging', $record);
    $html .= $this->parsePDFfullWidthField('speling', $record);
    $html .= $this->parsePDFfullWidthField('kleur_pees', $record);
    $html .= $this->parsePDFfullWidthField('hoekverbinding', $record);
    $html .= $this->parsePDFfullWidthField('frame', $record);
    $html .= $this->parsePDFfullWidthField('borstel_profiel', $record);
    $html .= $this->parsePDFfullWidthField('borstel', $record);
    $html .= $this->parsePDFfullWidthField('diepte_borstel', $record);
    $html .= $this->parsePDFfullWidthField('pvc', $record);
    $html .= $this->parsePDFfullWidthField('afdekdoppen', $record);
    $html .= $this->parsePDFfullWidthField('opties', $record);
    $html .= '</div>';
    $html .= "</body></html>";

    $user = user_load($record->uid);
    $uri = isset($user->picture->uri) ? $user->picture->uri : false;

    $footer = '';
    if(file_exists($uri)) {
      $footer .= "<img class=\"client-logo\" src=\"$uri\">";
    }
    $footer.= '<div class="feneko_logo">';
    // $footer.= '<div class="feneko_logo" style="line-height: 20px">';
    // $footer.= '<span class="feneko_fenek">Fenek</span><span class="feneko_o">O</span>';
    $footer.= '<img src="/sites/all/themes/feneko/img/logo.png" style="height: 60px; margin-right: -10px">';
    $footer.= '<div class="slogan">' . t('vliegenramen & plaatbewerking') . '</div>';
    $footer.= '</div>';
    $footer.= '<div class="top-line" style="margin-top: -5px">' . t('Bestelbonnen') . ' 2018</div>';

  // echo $html;
  // exit;

    $mpdf = new mPDF('UTF-8-s', 'A4-L', 0, 'Arial', 10, 10, 5, 5, 4, 6, 'L');
    $mpdf->SetAutoFont(AUTOFONT_ALL);
    $mpdf->WriteHTML($html);
    $mpdf->SetHTMLFooter($footer);

    if($outputAsString) {
      return $mpdf->Output('', 'S');
    } else {
      $mpdf->Output();
      exit;
    }
  }


  private function setFields() {
    switch ($this->getId()) {
      case '01':
        $this->title = t('Vliegenramen Classic');
        $this->remark = t('Opgegeven maten zijn de doorkijkmaten');
        $this->addField('afgewerkte', 25);
        $this->addField('afgewerkte_message', 1200);
        $this->addField('profiel', 35);
        $this->addField('bevestiging', 60);
        $this->addField('soort_bevestiging', 70);
        $this->addField('borstel_profiel', 80);
        $this->addField('borstel', 90);
        $this->addField('opties', 510);
        $this->addField('file', 520);
        $this->url = array(
          'nl' => 'vliegenraam-classic',
          'fr' => 'moustiquaire-classic',
        );
        break;

      case '02':
        $this->title = t('Vliegenramen Basic');
        $this->remark = t('Opgegeven maten zijn de doorkijkmaten');
        $this->addField('afgewerkte', 25);
        $this->addField('afgewerkte_message', 1200);
        $this->addField('bevestiging', 60);
        $this->addField('soort_bevestiging', 70);
        $this->addField('borstel_profiel', 80);
        $this->addField('borstel', 90);
        $this->addField('pvc', 550);
        $this->url = array(
          'nl' => 'vliegenraam-basic',
          'fr' => 'moustiquaire-basic',
        );
        break;

      case '03':
        $this->title = t('Inzetvliegenramen');
        $this->remark = t('Opgegeven maten zijn de doorkijkmaten');
        $this->addField('profiel', 35);
        $this->addField('diepte', 36);
        $this->addField('soort_bevestiging', 70);
        $this->addField('speling', 80);
        $this->addField('pvc', 500);
        $this->url = array(
          'nl' => 'inzetvliegenraam',
          'fr' => 'moustiquaires-encastree',
        );
        break;

      case '04':
        $this->title = t('Vliegendeuren Basic');
        $this->remark = t('Opgegeven maten zijn de maten van de buitenkader');
        $this->addField('scharnierkant', 60);
        $this->addField('pomp', 70);
        $this->addField('plint', 80);
        $this->addField('dierendeur', 90);
        $this->addField('pvc', 510);
        $this->url = array(
          'nl' => 'vliegendeur-basic',
          'fr' => 'porte-moustiquaire-basic',
        );
        break;

      case '05':
        $this->title = t('Vliegendeuren Classic');
        $this->remark = t('<b>Deur met kader</b><br />
                           Opgegeven maten zijn de maten van de buitenkader.<br />
                           Doorgegeven maat is de volledige maat van de afgewerkte kader.<br /><br />
                           <b>Deur zonder kader</b><br />
                           Opgegeven maten zijn de maten van het deurblad, zonder scharnieren en zonder magneten.');
        $this->addField('uitvoering', 33);
        $this->addField('kader', 36);
        $this->addField('scharnierkant', 60);
        $this->addField('pomp', 70);
        $this->addField('plint', 80);
        $this->addField('dierendeur', 90);
        $this->addField('opties', 510);
        $this->addField('file', 520);
        $this->addField('pvc', 530);
        $this->addField('afdekdoppen', 540);
        $this->url = array(
          'nl' => 'vliegendeur-classic',
          'fr' => 'porte-moustiquaire-classic',
        );
        break;

      case '06':
        $this->title = t('Vliegendeuren Elegance');
        $this->remark = t('<b>Deur met kader</b><br />
                           Opgegeven maten zijn de maten van de buitenkader.<br />
                           Doorgegeven maat is de volledige maat van de afgewerkte kader.<br />
                           Opgelet : VP1001 : Opgegeven maten zijn de maten zonder flens.<br /><br />
                           <b>Deur zonder kader</b><br />
                           Opgegeven maten zijn de maten van het deurblad, zonder scharnieren en zonder magneten.');
        $this->addField('uitvoering', 33);
        $this->addField('kader', 36);
        $this->addField('scharnierkant', 60);
        $this->addField('pomp', 70);
        $this->addField('plint', 80);
        $this->addField('dierendeur', 90);
        $this->addField('hoekverbinding', 510);
        // $this->addField('opties', 510);
        $this->url = array(
          'nl' => 'vliegendeur-elegance',
          'fr' => 'porte-moustiquaire-elegance',
        );
        break;

      case '07':
        $this->title = t('Schuifvliegendeuren Basic');
        $this->remark = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.');
        $this->removeField('table1');
        $this->addField('table2', 30);
        $this->addField('ondergeleider', 33);
        $this->addField('bovengeleider', 36);
        $this->addField('plint', 60);
        $this->addField('dierendeur', 70);
        $this->addField('borstel_links', 80);
        $this->addField('borstel_rechts', 90);
        $this->addField('eindstoppen', 100);
        $this->addField('pvc', 500);
        $this->url = array(
          'nl' => 'schuifvliegendeur-basic',
          'fr' => 'porte-coulissante-basic',
        );
        break;

      case '08':
        $this->title = t('Schuifvliegendeuren Classic');
        $this->remark = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.');
        $this->removeField('table1');
        $this->addField('table2', 30);
        $this->addField('uitvoering', 33);
        $this->addField('ondergeleider', 34);
        $this->addField('bovengeleider', 35);
        $this->addField('plint', 60);
        $this->addField('dierendeur', 70);
        $this->addField('borstel_links', 80);
        $this->addField('borstel_rechts', 90);
        $this->addField('eindstoppen', 100);
        $this->addField('schuifdeur_pomp', 110);
        $this->addField('pvc', 500);
        $this->url = array(
          'nl' => 'schuifvliegendeur-classic',
          'fr' => 'porte-coulissante-classic',
        );
        break;

      case '09':
        $this->title = t('Schuifvliegendeuren Elegance');
        $this->remark = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.');
        $this->removeField('table1');
        $this->addField('table2', 30);
        $this->addField('uitvoering', 33);
        $this->addField('ondergeleider', 34);
        $this->addField('bovengeleider', 35);
        $this->addField('borstel_kopse_kant', 45);
        $this->addField('plint', 60);
        $this->addField('dierendeur', 70);
        $this->addField('borstel_links', 80);
        $this->addField('borstel_rechts', 90);
        $this->addField('eindstoppen', 100);
        $this->addField('schuifdeur_pomp', 110);
        $this->url = array(
          'nl' => 'schuifvliegendeur-elegance',
          'fr' => 'porte-coulissante-elegance',
        );
        break;

      case '10':
        $this->title = t('Schuifvliegendeuren smal');
        $this->remark = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.');
        $this->removeField('table1');
        $this->addField('table2', 30);
        $this->addField('uitvoering', 33);
        $this->addField('ondergeleider', 34);
        $this->addField('bovengeleider', 35);
        $this->addField('stootrubber', 55);
        $this->addField('plint', 60);
        $this->addField('dierendeur', 70);
        $this->addField('borstel_links', 80);
        $this->addField('borstel_rechts', 90);
        $this->url = array(
          'nl' => 'schuifvliegendeur-smal',
          'fr' => 'porte-coulissante-etroite',
        );
        break;

      case '11':
        $this->title = t('Deurplisse');
        $this->remark = t('Afgewerkte maten');
        $this->removeField('table1');
        $this->removeField('type_gaas');
        $this->removeField('gaas_kleur');
        $this->removeField('kleur_pees');
        $this->addField('table3', 30);
        $this->addField('uitvoering', 35);
        $this->addField('ondergeleider', 50);
        $this->addField('frame', 70);
        $this->addField('borstel', 80);
        $this->addField('diepte_borstel', 90);
        $this->url = array(
          'nl' => 'deur-plisse',
          'fr' => 'porte-moustiquaire-pliante',
        );
        break;

      case '12':
        $this->title = t('Raamplisse');
        $this->remark = t('Afgewerkte maten');
        $this->removeField('type_gaas');
        $this->removeField('gaas_kleur');
        $this->removeField('kleur_pees');
        $this->removeField('table1');
        $this->addField('table4', 30);
        $this->addField('kader', 50);
        $this->url = array(
          'nl' => 'raam-plisse',
          'fr' => 'moustiquaire-pliante',
        );
        break;

      case '13':
        $this->title = t('Schuifvliegendeuren Elegance+');
        $this->remark = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.');
        $this->removeField('table1');
        $this->addField('table3', 30);
        $this->addField('uitvoering', 33);
        $this->addField('ondergeleider', 34);
        $this->addField('ondergeleider_anodise', 35);
        $this->addField('bovengeleider', 36);
        $this->addField('borstel_kopse_kant', 45);
        // $this->addField('plint', 60);
        // $this->addField('dierendeur', 70);
        $this->addField('borstel_links', 80);
        $this->addField('borstel_rechts', 90);
        $this->addField('eindstoppen', 100);
        $this->addField('schuifdeur_pomp', 110);
        $this->url = array(
          'nl' => 'schuifvliegendeur-elegance-plus',
          'fr' => 'porte-coulissante-elegance-plus',
        );
        break;

      case '14':
        $this->title = t('Vliegendeuren Elegance+');
        $this->remark = t('<b>Deur met kader</b><br />
                           Opgegeven maten zijn de maten van de buitenkader.<br />
                           Doorgegeven maat is de volledige maat van de afgewerkte kader.<br />
                           Opgelet : VP1001 : Opgegeven maten zijn de maten zonder flens.<br /><br />
                           <b>Deur zonder kader</b><br />
                           Opgegeven maten zijn de maten van het deurblad, zonder scharnieren en zonder magneten.');
        $this->removeField('table1');
        $this->addField('table4', 30);
        $this->addField('kader', 36);
        $this->addField('scharnierkant', 60);
        $this->addField('pomp', 70);
        $this->addField('hoekverbinding', 510);
        $this->url = array(
          'nl' => 'vliegendeur-elegance-plus',
          'fr' => 'porte-moustiquaire-elegance-plus',
        );
        break;

      case '15':
        $this->title = t('Vliegenramen RV');

        $this->remark = t('Opgegeven maten zijn de doorkijkmaten');
        $this->addField('afgewerkte', 25);
        $this->addField('afgewerkte_message', 1200);
        $this->addField('bevestiging', 60);
        $this->addField('soort_bevestiging', 70);
        $this->url = array(
          'nl' => 'vliegenraam-rv',
          'fr' => 'moustiquaire-rv',
        );
        break;

      case '16':
        $this->title = t('Rolhorplissé');
        $this->remark = t('Afgewerkte maten');
        $this->removeField('type_gaas');
        $this->removeField('gaas_kleur');
        $this->removeField('kleur_pees');
        $this->removeField('table1');
        $this->addField('table3', 30);
        $this->url = array(
          'nl' => 'rolhor-plisse',
          'fr' => 'moustiquaire-pliante-enroulable',
        );
        break;

    }
  }


  public function setValueExceptions() {
    $uitvoering_options = array(
      'enkel'  => t('met kader (enkel)'),
      'dubbel' => t('met kader (dubbel)'),
      'zonder' => t('zonder kader'),
    );

    $ajax = array(
      'event' => 'change',
      'callback' => 'manyforms_opties_callback',
      'wrapper' => 'opties-replace',
    );

    $caption2 = t('Het midden van de tussenstijl (VP1005) komt op 917mm.<br />
                   Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                   Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.');


    $vliegenraam_borstels = array(
      '#required' => FALSE,
      '#options' => array(
        '5mm'  => t('5mm'),
        '10mm' => t('10mm'),
        '15mm' => t('15mm'),
      ),
      '#states' => array(
        'visible' => array(
          'input[name="borstel_profiel"]' => array('value' => 'ja'),
        ),
      ),
    );

    switch ($this->getId()) {
      case '01':
        unset($this->form['type_gaas']['container']);

        $ral = $this->form['kleur']['kleur']['#options']['ral'];
        unset($this->form['kleur']['kleur']['#options']['ral']);
        $this->form['kleur']['kleur']['#options']['7039-70d'] = '7039-70d';
        $this->form['kleur']['kleur']['#options']['ral'] = $ral;
        $this->form['kleur']['kleur']['#description'] = t('7039-70D en anodise zijn kleuren met een supplement Ralkleur');
        $this->form['kleur']['container']['kleur_dep']['#autocomplete_path'] .= '2';
        $this->form['borstel'] = array_merge($this->form['borstel'], $vliegenraam_borstels);
        break;

      case '02':
        unset($this->form['type_gaas']['container']);
        unset($this->form['kleur']['kleur']['#options']['anodise']);
        unset($this->form['pvc']['#options']['grijs']);
        unset($this->form['borstel_profiel']['#states']);
        $this->form['borstel'] = array_merge($this->form['borstel'], $vliegenraam_borstels);
        break;

      case '03':
        unset($this->form['kleur']['kleur']['#options']['anodise']);
        unset($this->form['type_gaas']['container']);
        unset($this->form['pvc']['#options']['grijs']);
        $this->form['profiel']['#options'] = array(
          'vr033'      => 'vr033',
          'vr033ultra' => 'vr033-ultra',
        );

        $weight = $this->form['soort_bevestiging']['#weight'];
        $this->form['soort_bevestiging'] = $this->form['soort_bevestiging']['soort_bevestiging'];
        $this->form['soort_bevestiging']['#weight'] = $weight;
        $this->form['soort_bevestiging']['#options'] = array(
          'spie_klemveer' => t('spie & klemveer'),
          'hoge_lage'     => t('hoge & lage nok'),
        );

        $this->form['soort_bevestiging']['#states'] = array(
          'invisible' => array(
            'input[name="profiel"]' => array('value' => 'vr033ultra'),
          ),
        );
        $this->form['soort_bevestiging']['#required'] = FALSE;
        break;

      case '04':
        $this->form['table1']['#caption'] = $caption2;
        unset($this->form['kleur']['kleur']['#options']['anodise']);
        unset($this->form['pvc']['#options']['grijs']);
        break;

      case '05':
        $this->form['table1']['#caption'] = $caption2;
        $this->form['uitvoering']['uitvoering']['#options'] = $uitvoering_options;
        unset($this->form['opties']['#options']['gebogen']);
        unset($this->form['pvc']['#options']['grijs']);

        $this->form['kader']['#states'] = array(
          'visible' => array(
            'input[name="uitvoering"]' => array('value' => 'enkel'),
          ),
        );

        break;

      case '06':
        $this->form['table1']['#caption'] = $caption2;
        unset($this->form['kleur']['kleur']['#options']['anodise']);

        $this->form['uitvoering']['uitvoering']['#options'] = $uitvoering_options;
        // $this->form['uitvoering']['uitvoering']['#ajax'] = $ajax;
        unset($this->form['opties']['#options']['gebogen']);

        $kader = $this->form['kader'];
        unset($this->form['kader']['#options']);

        $this->form['kader']['#type'] = 'container';
        $this->form['kader']['kader'] = $kader;

        $this->form['kader']['kader']['#options'] = array(
          'vp1000' => 'vp1000',
          'vp1001' => 'vp1001',
        );

        $this->form['kader']['container'] = array(
          '#type' => 'container',
          '#attributes' => array('class' => array('description')),
          'conditional_help' => array(
            '#markup' => t('Opgelet : Bij kader “VP1001” is de opgegeven maat de maat van de afgewerkte kader zonder flens.'),
          ),
          '#states' => array(
            'visible' => array(
              'input[name="kader"]' => array('value' => 'vp1001'),
            ),
          ),
        );
        $this->form['kader']['#states'] = array(
          'invisible' => array(
            'input[name="uitvoering"]' => array('value' => 'zonder'),
          ),
        );
        unset($this->form['kader']['kader']['#weight']);
        break;

      case '07':
        // unset($this->form['kleur']['kleur']['#options']['anodise']);
        unset($this->form['pvc']['#options']['grijs']);
        break;

      case '08':
        // unset($this->form['kleur']['kleur']['#options']['anodise']);
        unset($this->form['pvc']['#options']['grijs']);
        unset($this->form['plint']['plint']['#options']['f300mm']);
        $descr = t('Voor het bestellen van 300mm, gebruik de optie "Andere".');
        $this->form['plint']['plint']['#description'] = $descr;
        break;

      case '09':
        unset($this->form['kleur']['kleur']['#options']['anodise']);
        break;

      case '10':
        $this->form['bovengeleider']['#options'] = array(
          'vp1012'      => 'vp1012',
          'vr073'       => 'vr073',
          'vr074'       => 'vr074',
          'l20x20x2'    => 'l20x20x2',
          'u20x25x20x2' => 'u20x25x20x2',
        );

        $this->form['ondergeleider']['#options']['u15x25x15x2'] = 'u15x25x15x2';

        unset($this->form['borstel_links']['#options']['geen']);
        unset($this->form['borstel_rechts']['#options']['geen']);
        unset($this->form['plint']['plint']['#options']['f300mm']);
        break;

      case '11':
        $this->form['ondergeleider']['#options'] = array(
          'plat'   => t('plat'),
          '6.5'    => '6.5',
        );
        break;

      case '12':
        $this->form['kader']['#options'] = array(
          '3/4'   => '3/4',
          'rondom'    => t('rondom'),
        );
        break;

      case '13':
        $this->form['ondergeleider']['#options'] = array(
          'vp1012' => 'vp1012',
          'vr073'  => 'vr073',
          'vr074'  => 'vr074',
          'vp1016' => 'vp1016',
        );
        unset($this->form['kleur']['kleur']['#options']['anodise']);
        unset($this->form['type_gaas']['container']);
        unset($this->form['type_gaas']['type_gaas']['#options']['soltisdoek']);
        unset($this->form['type_gaas']['type_gaas']['#options']['inox']);
        break;

      case '14':
        unset($this->form['kleur']['kleur']['#options']['anodise']);

        $this->form['uitvoering']['uitvoering']['#options'] = $uitvoering_options;
        // $this->form['uitvoering']['uitvoering']['#ajax'] = $ajax;
        unset($this->form['opties']['#options']['gebogen']);

        $kader = $this->form['kader'];
        unset($this->form['kader']['#options']);

        $this->form['kader']['#type'] = 'container';
        $this->form['kader']['kader'] = $kader;

        $this->form['kader']['kader']['#options'] = array(
          'vp1000' => 'vp1000',
          'vp1001' => 'vp1001',
        );

        $this->form['kader']['container'] = array(
          '#type' => 'container',
          '#attributes' => array('class' => array('description')),
          'conditional_help' => array(
            '#markup' => t('Opgelet : Bij kader “VP1001” is de opgegeven maat de maat van de afgewerkte kader zonder flens.'),
          ),
          '#states' => array(
            'visible' => array(
              'input[name="kader"]' => array('value' => 'vp1001'),
            ),
          ),
        );
        $this->form['kader']['#states'] = array(
          'invisible' => array(
            'input[name="uitvoering"]' => array('value' => 'zonder'),
          ),
        );
        unset($this->form['kader']['kader']['#weight']);

        unset($this->form['type_gaas']['container']);

        break;

      case '15':
        unset($this->form['type_gaas']['container']);
        $this->form['soort_bevestiging']['soort_bevestiging']['#options'] = array(
          '15' => '15',
          '16' => '16',
          '17' => '17',
          '18' => '18',
          '19' => '19',
          '20' => '20',
          '21' => '21',
        );
        break;

    }
  }

  public function getOpties($uitvoering) {
    $options = array(
      'nvt'     => t('Niet van toepassing'),
      'gebogen' => t('Gebogen/Schuin'),
    );

    $ondervulling = t('Ondervulling B100');

    $id = intval($this->getId());
    switch ($uitvoering . $id) {
      case 'enkel5':
      case 'dubbel5':
        $options['rondom'] = t('Kader Rondom');
        break;

      case 'zonder5':
        $options['ondervulling'] = $ondervulling;
        break;

      case 'enkel6':
      case 'dubbel6':
        unset($options['gebogen']);
        $options['rondom'] = t('Kader Rondom');
        break;

      case 'zonder6':
        unset($options['gebogen']);
        $options['ondervulling'] = $ondervulling;
        break;
    }
    return $options;
  }

  private function parsePDFfullWidthField($name, $record) {
    if($this->hasField($name)) {
      $style = 'style="clear:both;width:100%;margin-top:10px"';
      return "<div $style>" . $this->parsePDFfield($name, $record) . '</div>';
    }
  }


  private function parsePDFfield($name, $record) {
    $border = "1px solid black";

    // Most of the times this is the value we need to parse
    if(isset($record->$name)) {
      $val = $record->$name;
    }

    switch ($name) {
      case 'datesubmit':
        $val = date('d-m-Y', $record->$name);

      case 'datesubmit':
        return "<div class=\"inline-field\">"
             . "<div class=\"label\">" . t('datum') . "</div><div class=\"value\">$val</div>"
             . "</div>";

      case 'klant':
        $client = feneko_code_get_client_by_number($val);
        $val = $client->title->value() . " (" . $client->field_client_number->value() . ")";
        return "<div class=\"inline-field\">"
             . "<div class=\"label\">" . t('klant') . "</div><div class=\"value\">$val</div>"
             . "</div>";

      case 'uid':
        $user = entity_metadata_wrapper('user', $val);
        $val = $user->name->value();
        return "<div class=\"inline-field\">"
             . "<div class=\"label\">" . t('user') . "</div><div class=\"value\">$val</div>"
             . "</div>";

      case 'referentie':
        $title = $this->form[$name]['#title'];
        return "<div class=\"inline-field last\">"
             . "<div class=\"label\">$title</div><div class=\"value\">$val</div>"
             . "</div>";

      case 'frame':
        return $this->parsePDFframe($record);

      // case 'bijkomende':
      //   if(empty($val)) {
      //     return;
      //   } else {
      //     $val = nl2br($val);
      //     $title = $this->form[$name]['#title'];
      //     return "<h3 style=\"margin-top: 10px\">$title</h3>"
      //          . "<div style=\"border:$border; padding:2px 5px;\">$val</div>";
      //   }

      case 'table1':
      case 'table2':
      case 'table3':
      case 'table4':
        return self::parsePDFtable($record, $name);

      case 'soort_bevestiging':
        return $this->parsePDFckeckboxes($name, $val, 'width:65px');

      default:
        return $this->parsePDFckeckboxes($name, $val);
    }
  }

  private function parsePDFckeckboxes($name, $val, $style = '') {
    // We don't do anything for NULL values
    if(!isset($val)) return;

    $check = '<img style="width:12px;height:12px;vertical-align:middle" src="'
           . drupal_get_path('module', 'manyforms')
           . '/images/check-box_{num}.png" />';
    $check0 = str_replace('{num}', 0, $check);
    $check1 = str_replace('{num}', 1, $check);

    // Get the title for normal fields, but for depending fields, we need to go 1 level deeper
    $title = empty($this->form[$name]['#title']) ?
             $this->form[$name][$name]['#title'] : $this->form[$name]['#title'];

    $style = empty($style) ? '' : " style=\"$style\"";

    if(isset($this->form[$name][$name]['#options'])) {
      $options = $this->form[$name][$name]['#options']; // for container fields
    } else {
      $options = $this->form[$name]['#options']; // for normal fields
    }

    list($val, $dep_val) = self::explodeDep($val);
    // $chunks = explode('###', $val);
    // $val = $chunks[0];
    // $dep_val = isset($chunks[1]) ? $chunks[1] : NULL;

    $html = "<h3>$title</h3>";
    $html.= '<div class="choices">';
    $i = 0;
    foreach ($options as $key => $value) {
      $class = '';
      if((string)$key === (string)$val) {
        $checked_idx = $i;
        $checkbox = $check1;
      } else {
        $checkbox = $check0;
      }
      $class = isset($dep_val) && $this->form[$name]['container'][$name . "_dep"]['#type'] === 'radios' ? ' class="has-dep"' : '';
      $html .= "<div$style $class>$checkbox <span>$value</span></div>";
      $i++;
    }

    if(isset($dep_val)) {
      $dep_field = $this->form[$name]['container'][$name . "_dep"];
      switch ($dep_field['#type']) {
        case 'textfield':
          $html .= "<div$style><span>$dep_val</span></div>";
          break;

        case 'radios':
          $classes = "dep $name $val";
          $num_options = count($dep_field['#options']);
          $width = (145 / $num_options - 5) . "px";
          $margin = ($checked_idx * 151 + 5) . 'px';
          $html.="<div class=\"$classes\" style=\"margin-left:$margin;font-size:8px\">";
          $i = 0;
          foreach ($dep_field['#options'] as $key => $value) {
            $i++;
            $checkbox = $key == $dep_val ? $check1 :$check0;
            $class = $i === $num_options ? ' class="last"' : '';
            $html .= "<div style=\"width: $width\"$class>$checkbox <span>$value</span></div>";
          }
          $html.='</div>';
          break;
      }
    }
    $html.= '</div>';
    return $html;
  }

  private function parsePDFframe($record) {
    $check = '<img style="width:12px;height:12px;vertical-align:middle" src="'
           . drupal_get_path('module', 'manyforms')
           . '/images/check-box_{num}.png" />';
    $check0 = str_replace('{num}', 0, $check);
    $check1 = str_replace('{num}', 1, $check);

    $title = $this->form['frame']['#title'];

    $html = "<h3>$title</h3>";
    $html.= '<div class="inline kader">';
    $style['top'] = "margin-top: -11px; margin-left: 133px; z-index:10";
    $style['left'] = "margin-top: 34px; margin-left: -11px; z-index:10";
    $style['right'] = "width: 100px; margin-top: -12px; margin-left: auto; margin-right: -99px; z-index:10";
    $style['bottom'] = "margin-top: 34px; margin-bottom: -11px; margin-left: 133px; z-index:10";
    foreach (array('top', 'left', 'right', 'bottom') as $type) {
      $field = "kader_$type";
      $stl = $style[$type];
      $html .= "<div class=\"$type\" style=\"$stl\">";
      $html .= empty($record->$field) ? $check0 : $check1;
      $html .= "</div>";
    }
    $html.= '</div>';

    // $html .= '<div class="inline measures">';
    // foreach (array('breedte', 'hoogte') as $type) {
    //   $field = "kader_$type";
    //   $val = $record->$field;
    //   $html .= "<div class=\"inline-field $type\" style=\"margin-top: 5px;\">";
    //   $html .= "<div class=\"label\">" . strtoupper(t($type)) . " :</div><div class=\"value\" style=\"width:70px\">$val</div>";
    //   $html .= "</div>";
    // }
    // $html.= '</div>';

    return $html;
  }

  private static function parsePDFtable($record, $type) {
    $count = 9;

    $check = '<img style="width:15px;height:15px" src="'
           . drupal_get_path('module', 'manyforms')
           . '/images/check-box_{num}.png" />';
    $check0 = str_replace('{num}', 0, $check);
    $check1 = str_replace('{num}', 1, $check);

    $fields = array(
      'aantal',
      'breedte',
      'hoogte',
    );

    $html  = '<table class="maintable">';
    $html .= '<tr style="text-align: center;"><th>' . t('AANTAL') . '</th>';
    $html .= '<th>' . t('BREEDTE') . '<br>(mm)</th><th>' . t('HOOGTE') . '<br>(mm)</th>';

    if($type === 'table3' or $type === 'table2') {
      $fields[] = 'rails';
      $html .= '<th>' . t('LENGTE<BR>RAILS') . '</th>';
    }

    if($type === 'table2' or $type === 'table1') {
      $fields[] = 'stand';
      $fields[] = 't1';
      $fields[] = 't2';
      $html .= '<th>STAND.<br>T</th><th>T1</th><th>T2</th>';
    }

    if($type === 'table1') {
      $fields[] = 't3';
      $html .= '<th>T3</th>';
    }

    $fields[] = 'opmerking';
      $html .= '<th>' . t('OPMERKING') . '</th>';

    $html .= '</tr>';
    for($i = 1; $i <= $count; $i++) {
      // Skip empty rows
      if(self::emptyRow($record, $fields, $i)) continue;

      // Non-Empty row
      $html .= '<tr>';
      foreach ($fields as $field) {
        $db_field = "$field$i";
        $val = empty($record->$db_field) ? '' : $record->$db_field;
        if($field === 'stand') {
          $val = empty($val) ? $check0 : $check1;
        }
        $html .= '<td style="width:100px">'. $val . '</td>';
      }
      $html .= '</tr>';
    }
    $html .= '</table>';

    return $html;
  }

}
