<?php
/**
 * Returns the PDF as a string to attach to a mail
 *
 * @param $order_id
 *   The Order ID
 * @return
 *   PDF as a string to attach to a mail
 */
function fc_get_attachment($order_id, $outputAsString = TRUE, $includePrice = TRUE) {
  libraries_load('mpdf');
  module_load_include('inc', 'feneko_calculator', 'extra_fields');
  module_load_include('inc', 'feneko_calculator', 'feneko_calculator.export');

  $order = commerce_order_load($order_id);
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  $client = $order_wrapper->field_client->value();

  $path =  drupal_get_path('module', 'feneko_calculator');
  $style = file_get_contents("$path/css/extra_fields.css");

  $border_dotted = "1px dotted black";
  $border_solid  = "1px solid black";

  $html = '<html>';
  $html .= "<head><style>";
  $html .= $style;
  $html .= "
    .left {
      width: 65%;
      float: left;
    }

    .right {
      width: 35%;
      float: left;
    }

    .client-logo {
      float: right;
      max-height: 70px;
      max-width: 170px;
    }

    .client .field-label {
      width: 160px;
      float: left;
    }

    h1 {
      text-align: center;
    }

    .field-name-field-color,
    .field-name-field-reference {
      font-size: 2em;
      line-height: 2em;
    }

    .field-name-field-color .field-label,
    .field-name-field-comment .field-label,
    .field-name-field-reference .field-label {
      display: none;
    }

    table {
      margin: 3em 0;
      width: 100%;
      border-top: $border_solid;
      border-bottom: $border_solid;
      border-collapse: collapse;
    }

    table.total {
      width: 50%;
    }

    td {
      text-align: right;
      border-bottom: $border_dotted;
    }

    th {
      border-bottom: $border_solid;
    }

    .product, .details {
      text-align: left;
    }

    .amount {
      text-align: center;
    }

    img {
      max-height: 100px;
    }

    .field-name-field-comment {
      border: $border_solid;
      padding: 1em;
    }

    .prices .subtotal {
      float: left;
      width: 50%;
    }

    .prices .total {
      float: right;
      text-align: right;
      width: 50%;
    }

    .top-line {
      border-top: 2px solid black;
      padding-bottom: 10px;
      width: 100%;
      text-align: center;
    }
    .pagenum {
      width: 2em;
      float: right;
      padding-top: 40px;
    }
    .feneko_logo {
      float: left;
      width: 200px;
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
  ";
  $html .= "</style></head>";

  $user = user_load($order->uid);
  if(isset($user->picture->uri)) {
    $logo = "<img class=\"client-logo\" src=\"" . $user->picture->uri . "\">";
  } else {
    $logo = '';
  }

  // get the client for whom the order is
  $client_ra = field_view_field('commerce_order', $order, 'field_client');

  // The user field
  $user_ra = $client_ra; // Little hack, Just for convenience
  $user_ra['#title'] = ucfirst(t('user'));
  $user_ra[0]['#label'] = $user->name;

  // The date field
  $date_ra = $client_ra; // Little hack, Just for convenience
  $date_ra['#title'] = ucfirst(t('date'));
  $date_ra[0]['#label'] = format_date(intval($order->changed), 'short');

  $client_data = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('client')),
    'left' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('left')),
      'date'   => $date_ra,
      'tel'    => field_view_field('node', $client, 'field_phone'),
      'tva'    => field_view_field('node', $client, 'field_tva_number'),
      'num'    => field_view_field('node', $client, 'field_client_number'),
      'client' => $client_ra,
      'user'   => $user_ra,
    ),
    'right' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('right')),
      'logo' => array('#markup' => $logo),
    ),
  );

  $table_header  = '<thead><tr>';
  $table_header .= '<th class="product">' . t('Product') . '</th>';
  $table_header .= '<th class="details">' . t('Productspecificatie') . '</th>';
  if($includePrice) {
    $table_header .= '<th>' . t('Price') . '</th>';
  }
  $table_header .= '<th class="amount">' . t('Aantal') . '</th>';
  if($includePrice) {
    $table_header .= '<th>' . t('Total') . '</th>';
  }
  $table_header .= '</tr></thead>';

  $line_items = '';
  $count = $order_wrapper->commerce_line_items->count();
  foreach ($order_wrapper->commerce_line_items as $delta => $line) {
    if($line->type->value() !== 'commerce_discount') {
      $price = $line->commerce_unit_price->value();
      $total = $line->commerce_total->value();
      $even_odd = $delta % 2 ? 'even' : 'odd';
      $first_last = $delta === 0 ? 'first' : ($delta === $count - 1 ? 'last' : '');
      $label = $line->type->label();
      if('product' === $line->type->value()) {
        if(substr($line->value()->line_item_label, 0, 3) === 'DA-') {
          $label = t("Anti-Dreunstrook");
        }
      }

      $line_items .= "<tr class=\"$even_odd $first_last\">";
      $line_items .= '<td class="product">';
      $line_items .= $label . _fc_get_pdf_image($line);
      $line_items .= '</td>';
      $line_items .= '<td class="details">';
      $line_items .= nl2br(fc_line_item_details($line->value(), 'text'));
      $line_items .= '</td>';
      if($includePrice) {
        $line_items .= '<td class="price">';
        $line_items .= _fc_format_amount($price['amount']);
        $line_items .= '</td>';
      }
      $line_items .= '<td class="amount">';
      $line_items .= intval($line->quantity->value());
      $line_items .= '</td>';
      if($includePrice) {
        $line_items .= '<td class="total">';
        $line_items .= _fc_format_amount($total['amount']);
        $line_items .= '</td>';
      }
      $line_items .= '</tr>';
    }
  }

  if($includePrice) {
    $totals = _fc_totals_order($order_wrapper);
    $sub_total  = '<tr class="subtotal"><td colspan="4">' . t('Subtotal') . '</td>';
    $sub_total .= '<td>' . $totals['formatted']['subtotal'] . '</td></tr>';
    $total  = '<tr class="total"><td colspan="4">' . t('Total') . '</td>';
    $total .= '<td><strong>' . $totals['formatted']['total'] . '</strong></td></tr>';
    $vat  = '<tr class="vat"><td colspan="4">' . t('VAT') . '</td>';
    $vat .= '<td>' . $totals['formatted']['vat'] . '</td></tr>';
    $total_vat  = '<tr class="total_vat"><td colspan="4">' . t('Total VAT included') . '</td>';
    $total_vat .= '<td>' . $totals['formatted']['total_vat'] . '</td></tr>';

    $discounts = '';
    foreach ($order_wrapper->commerce_line_items as $line) {
      if($line->type->value() === 'commerce_discount') {
        $sections = _fc_get_discount_sections($line->commerce_unit_price->data->value());

        foreach ($sections as $section) {
          $discounts .= '<tr class="' . $section['key'] . '">';
          $discounts .= '<td colspan="4">' . $section['label'] . '</td>';
          $discounts .= '<td>' . $section['price'] . '</td>';
          $discounts .= '</tr>';
        }
      }
    }
  }

  $maritime = field_view_field('commerce_order', $order, 'field_maritime');
  if($maritime['#items'][0]['value']) {
    $maritime = $maritime['#title'];
  } else {
    $maritime = '';
  }

  $reference = field_view_field('commerce_order', $order, 'field_reference');
  $comment = field_view_field('commerce_order', $order, 'field_comment');
  $color = field_view_field('commerce_order', $order, 'field_color');

  $order_type = $order_wrapper->field_order_type->label();
  if(empty($order_type)) {
    $order_type = t('Bestelling');
  }

  // Compile the HTML
  $html .= '<body>';
  $html .= drupal_render($client_data);
  $html .= "<h1>$order_type $order_id</h1>";
  $html .= drupal_render($reference);
  $html .= drupal_render($color);
  $html .= $maritime;
  $html .= '<table>';
  $html .= $table_header;
  $html .= '<tbody>';
  $html .= $line_items;
  $html .= '</tbody>';
  $html .= '</table>';
  $html .= drupal_render($comment);
  $html .= '<table class="total" align="right">';
  $html .= '<tbody>';
  if($includePrice) {
    $html .= $sub_total;
    $html .= $discounts;
    $html .= $total;
    $html .= $vat;
    $html .= $total_vat;
  }
  $html .= '</tbody>';
  $html .= '</table>';
  $html .= '</body></html>';

// dpm($html);

  if($includePrice) {
    $footer = '<div class="prices">';
    $footer.= '<div class="subtotal"></div>';
    $footer.= '<div class="total">' . t('Total VAT included') . ': ';
    $footer.= $totals['formatted']['total_vat'] . '</div>';
    $footer.= '</div>';
  }
  $footer.= '<div class="top-line"></div>';
  $footer.= '<div class="pagenum">{PAGENO}/{nbpg}</div>';
  $footer.= '<div class="feneko_logo">';
  // $footer.= '<div class="feneko_logo" style="line-height: 20px">';
  // $footer.= '<span class="feneko_fenek">Fenek</span><span class="feneko_o">O</span>';
  $footer.= '<img src="/sites/all/themes/feneko/img/logo.png" height="200">';
  $footer.= '<div class="slogan">' . t('vliegenramen & plaatbewerking') . '</div>';
  $footer.= '</div>';

  $mpdf = new mPDF('UTF-8', 'A4', 0, 'Arial', 20, 20, 20, 30, 0, 5);
  $mpdf->SetAutoFont(AUTOFONT_ALL);
  $mpdf->SetHTMLFooter($footer);
  $mpdf->WriteHTML($html);

  if($outputAsString) {
    return $mpdf->Output('', 'S');
  } else {
    $mpdf->Output();
    exit;
  }

}

function _fc_get_pdf_image($line_item_wrapper) {
  switch ($line_item_wrapper->type->value()) {
    case 'plaatbewerking':
      $type = $line_item_wrapper->field_type_bewerking->value();
      if($type !== FC_PB_SPECIAL) {
        $lakzijde = $line_item_wrapper->field_lakzijde->value();
        $ra = _fc_get_plaatbewerking_image($type . $lakzijde);
        return '<br>' . drupal_render($ra);
      } else {
        return;
      }

    case 'standaardprofiel':
      $type = $line_item_wrapper->commerce_product->field_standaardprofiel_type->value();
      $ra = _fc_get_standaardprofiel_image($type);
      return '<br>' . drupal_render($ra);
  }

}
