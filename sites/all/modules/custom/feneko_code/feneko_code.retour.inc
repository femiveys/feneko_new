<?php
function feneko_code_retours_form($form, &$form_state) {
  return array(
    'type'        => array(
      '#type' => 'radios',
      '#title' => t('Type'),
      '#options' => array('screens' => 'Screens', 'colors' => 'Colors'),
      '#required' => true,
    ),
    'chauffeur'   => feneko_code_get_text_widget('chauffeur'),
    'client'      => feneko_code_get_text_widget('client'),
    'reference'   => feneko_code_get_text_widget('reference'),
    'contact'     => feneko_code_get_text_widget('contact'),
    'product'     => feneko_code_get_text_widget('product'),
    'num_prod'    => feneko_code_get_text_widget('num_prod', 'textfield', null),
    'description' => feneko_code_get_text_widget('description', 'textarea'),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Send'),
    ),
  );
}

function feneko_code_get_text_widget($key, $type = 'textfield', $size = 20) {
  global $language;

  $lang = $language->language;
  $mapping = feneko_code_retours_mapping();

  return array(
    '#type' => $type,
    '#title' => $mapping[$key][$lang],
    '#size' => $size,
    '#element_validate' => $size ? null : array('element_validate_number'),
    '#required' => true,
  );
}

function feneko_code_retours_mapping() {
  return array(
    'created' => array(
      'nl' => 'Datum',
      'fr' => 'Date',
    ),
    'chauffeur' => array(
      'nl' => 'Chauffeur',
      'fr' => 'Chauffeur',
    ),
    'client' => array(
      'nl' => 'Klant',
      'fr' => 'Client',
    ),
    'reference' => array(
      'nl' => 'Referentie',
      'fr' => 'Référence',
    ),
    'contact' => array(
      'nl' => 'Contact',
      'fr' => 'Contact',
    ),
    'screens' => 'Screens',
    'colors' => 'Colors',
    'product' => array(
      'nl' => 'Product',
      'fr' => 'Produit',
    ),
    'num_prod' => array(
      'nl' => 'Aantal stukken',
      'fr' => 'Nombre de pièces',
    ),
    'description' => array(
      'nl' => 'Omschrijving',
      'fr' => 'Description',
    ),
  );
}

function feneko_code_retours_form_submit($form, &$form_state) {
  global $user;

  $record = array(
    'uid' => $user->uid,
    'created' => time(),
  );

  $record = array_merge($form_state['values'], $record);

  drupal_write_record(FENEKO_CODE_RETOUR_TABLE, $record);

  // Send mails
  $to = array(
    'user' => $user->mail,
    'feneko' => "bestellingen@feneko.be",
  );
  $subject = array(
    'user' => t('[Feneko Online] Retouropdracht verzonden'),
    'feneko' => t('[Feneko Online] Retouropdracht verzonden door :user', array(':user' => $user->name)),
  );

  $message = array(
    'user' => "TODO",
    'feneko' => "TODO",
  );

  $attachments = array(array(
    'filecontent' => feneko_code_retours_pdf($record),
    'filename' => "retour.pdf",
    'filemime' => 'application/pdf',
  ));

  FenekoForm::sendMail($to['user'], $subject['user'], $message['user'], $attachments);
  FenekoForm::sendMail($to['feneko'], $subject['feneko'], $message['feneko'], $attachments);
}

function feneko_code_retours_pdf($record) {
  libraries_load('mpdf');

  $border = "1px solid black";
  $height = "40px";

  $html="
  <html>
  <head>
  <style>
  .feneko_logo {
    font-family: 'Times New Roman', Georgia, serif;
  }

  .feneko_logo span {
    font-size: 85px;
  }

  .feneko_logo span.feneko_o {
    color: #295D8F;
  }

  .id {
    width: 66%;
    margin-left: 34%;
    border-bottom: $border;
    border-right: $border;
  }

  .field {
    border-left: $border;
    border-top: $border;
    clear: both;
  }

  .field .label,
  .field .value {
    padding: 5px;
    float: left;
    text-transform: uppercase;
  }

  .fr {
    font-style: italic;
  }

  .field .value {
    height: $height;
    line-height: $height;
    border-left: $border;
  }

  .id .field .label,
  .id .field .value {
    width: 213px;
  }

  .order {
    margin-top: 3em;
  }

  .order .field {
    margin-top: 1.5em;
    border-bottom: $border;
  }

  .order .field .label,
  .order .field .value {
    width: 328.5px;
  }

  .order .field .value {
    border-right: $border;
  }

  .order .field-colors .label {
    border-right: $border;
  }

  .order .field-screens,
  .order .field-colors {
    width: 339px;
    float: left;
    clear: none;
    margin: 0;
    text-align: center;
  }

  .order .field-screens .label,
  .order .field-colors .label {
    width: 266px;
    float: right;
    height: $height;
    line-height: $height;
  }

  .order .field-screens .value,
  .order .field-colors .value {
    width: 50px;
    float: left;
    border-left: none;
  }

  .order .field-screens .field-colors {
    width: 50%;
    float: left;
  }

  .order .field-description {
    border: none
  }

  .order .field-description .label,
  .order .field-description .value {
    float: inherit;
    width: auto;
  }

  .field-description .value {
    border: $border;
    height: 200px;
    margin: 0;
  }

  .help {
    margin-top: 2em;
    margin-left: 350px;
  }

  footer {
    border-top: $border;
    padding-top: 1em;
  }

  </style>
  </head>
  <body>";

  $html.= '<div class="feneko_logo">';
  $html.= '<span class="feneko_fenek">Fenek</span><span class="feneko_o">O</span>';
  $html .= '</div>';
  $html .= '<div class="id">';
  $html .= feneko_code_parse_pdf_field('created', $record);
  $html .= feneko_code_parse_pdf_field('chauffeur', $record);
  $html .= feneko_code_parse_pdf_field('client', $record);
  $html .= feneko_code_parse_pdf_field('reference', $record);
  $html .= feneko_code_parse_pdf_field('contact', $record);
  $html .= '</div>';
  $html .= '<div class="order">';
  $html .= '<div class="type">';
  $html .= feneko_code_parse_pdf_field('screens', $record);
  $html .= feneko_code_parse_pdf_field('colors', $record);
  $html .= '</div>';
  $html .= feneko_code_parse_pdf_field('product', $record);
  $html .= feneko_code_parse_pdf_field('num_prod', $record);
  $html .= feneko_code_parse_pdf_field('description', $record);
  $html .= '</div>';
  $html .= '<div class="help">';
  $html .= '<div class="nl">Opgelet: 1 formulier per teruggezonden pakket</div>';
  $html .= '<div class="fr">Attention : un formulaire par colis retourné</div>';
  $html .= '</div>';
  $html .= "</body></html>";

  $footer = '<footer>RETOUR - ' . date('F Y', $record['created']) . "</footer>";

// For test
// echo $html;
// exit;

  $mpdf = new mPDF('UTF-8-s', 'A4');
  // $mpdf->SetAutoFont(AUTOFONT_ALL);
  $mpdf->WriteHTML($html);
  $mpdf->SetHTMLFooter($footer);

  // For test
  // $mpdf->Output();
  // exit;

  return $mpdf->Output('', 'S');
}

function feneko_code_parse_pdf_field($name, $record) {
  $form = feneko_code_retours_form(array());
  $mapping = feneko_code_retours_mapping();

  switch ($name) {
    case 'screens':
    case 'colors':
      $label = "<div>" . $mapping[$name] . "</div>";
      $value = $record['type'] === $name ? 'X' : '';
      break;

    default:
      $label  = "<div class=\"nl\">" . $mapping[$name]['nl'] . "</div>";
      $label .= "<div class=\"fr\">" . $mapping[$name]['fr'] . "</div>";

      switch ($name) {
        case 'created':
          $value  = date('d-m-Y', $record[$name]);
          break;

        case 'description':
          $value  = nl2br($record[$name]);
          break;

        default:
          $value  = $record[$name];
          break;
      }
      break;
  }

  $html  = "<div class=\"field field-$name\">";
  $html .= "<div class=\"label\">$label</div>";
  $html .= "<div class=\"value\">$value</div>";
  $html .= "</div>";

  return $html;
}