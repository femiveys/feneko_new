<?php
/**
 * Returns the PDF as a string to attach to a mail
 *
 * @param $order_id
 *   The Order ID
 * @return
 *   PDF as a string to attach to a mail
 */
function fc_get_attachment($order_id, $outputAsString = TRUE) {
  libraries_load('mpdf');
  module_load_include('inc', 'feneko_calculator', 'extra_fields');

  $order = commerce_order_load($order_id);
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  $path =  drupal_get_path('module', 'feneko_calculator');
  $style = file_get_contents("$path/css/extra_fields.css");

  $border_dotted = "1px dotted black";
  $border_solid  = "1px solid black";

  $html = '<html>';
  $html .= "<head><style>";
  $html .= $style;
  $html .= "
    .left,
    .right {
      width: 50%;
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

  $client = user_load($order->uid);
  if(isset($client->picture->uri)) {
    $logo = "<img class=\"client-logo\" src=\"" . $client->picture->uri . "\">";
  } else {
    $logo = '';
  }

  $order4 = empty($order->field_order4)
    ? field_view_field('user', $client, 'field_klantennummer')
    : field_view_field('commerce_order', $order, 'field_order4')
  ;

  $client_data = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('client')),
    'left' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('left')),
      'tel'  => field_view_field('user', $client, 'field_telefoon'),
      'tva'  => field_view_field('user', $client, 'field_btw_nummer'),
      'num'  => $order4,
      'name' => field_view_field('user', $client, 'field_naam_bedrijf'),
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
  $table_header .= '<th>' . t('Price') . '</th>';
  $table_header .= '<th class="amount">' . t('Amount') . '</th>';
  $table_header .= '<th>' . t('Total') . '</th>';
  $table_header .= '</tr></thead>';

  $line_items = '';
  $count = $order_wrapper->commerce_line_items->count();
  foreach ($order_wrapper->commerce_line_items as $delta => $line) {
    if($line->type->value() !== 'commerce_discount') {
      $price = $line->commerce_unit_price->value();
      $total = $line->commerce_total->value();
      $even_odd = $delta % 2 ? 'even' : 'odd';
      $first_last = $delta === 0 ? 'first' : ($delta === $count - 1 ? 'last' : '');

      $line_items .= "<tr class=\"$even_odd $first_last\">";
      $line_items .= '<td class="product">';
      $line_items .= $line->type->label() . _fc_get_pdf_image($line);
      $line_items .= '</td>';
      $line_items .= '<td class="details">';
      $line_items .= nl2br(fc_line_item_details($line->value(), 'text'));
      $line_items .= '</td>';
      $line_items .= '<td class="price">';
      $line_items .= _fc_format_amount($price['amount']);
      $line_items .= '</td>';
      $line_items .= '<td class="amount">';
      $line_items .= intval($line->quantity->value());
      $line_items .= '</td>';
      $line_items .= '<td class="total">';
      $line_items .= _fc_format_amount($total['amount']);
      $line_items .= '</td>';
      $line_items .= '</tr>';
    }
  }

  $totals = _fc_totals_order($order_wrapper);
  $sub_total  = '<tr class="subtotal"><td colspan="4">' . t('Subtotal') . '</td>';
  $sub_total .= '<td>' . $totals['formatted']['subtotal'] . '</td></tr>';
  $total  = '<tr class="total"><td colspan="4">' . t('Total') . '</td>';
  $total .= '<td><strong>' . $totals['formatted']['total'] . '</strong></td></tr>';

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
  $html .= $sub_total;
  $html .= $discounts;
  $html .= $total;
  $html .= '</tbody>';
  $html .= '</table>';
  $html .= '</body></html>';

// dpm($html);

  $footer = '<div class="prices">';
  $footer.= '<div class="subtotal">' . t('Subtotal') . ': ';
  $footer.= $totals['formatted']['subtotal'] . '</div>';
  $footer.= '<div class="total">' . t('Total') . ': ';
  $footer.= $totals['formatted']['total'] . '</div>';
  $footer.= '</div>';
  $footer.= '<div class="top-line"></div>';
  $footer.= '<div class="pagenum">{PAGENO}/{nbpg}</div>';
  $footer.= '<div class="feneko_logo" style="line-height: 20px">';
  $footer.= '<span class="feneko_fenek">Fenek</span><span class="feneko_o">O</span>';
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

function _fc_get_discount_sections($data) {
  $mapping = commerce_price_component_titles();

  foreach ($data['components'] as $component) {
    $key = $component['name'];
    if($key === 'minimum_invoice_amount') {
      $sections[$key]['weight'] = 0;
      $sections[$key]['key'] = $key;
      $sections[$key]['label'] = $mapping[$key];
      _fc_set_price($sections[$key], $component['price']['amount']);
    } elseif (substr($key, 0, 9) === 'discount|') {
      $sections[$key]['weight'] = 10;
      $sections[$key]['key'] = drupal_clean_css_identifier($component['price']['data']['discount_name']);
      $sections[$key]['label'] = $component['price']['data']['discount_component_title'];
      _fc_set_price($sections[$key], $component['price']['amount']);
    }
  }

  // Set the price in a readible way
  foreach ($sections as &$section) {
    $section['price'] = _fc_format_amount($section['price']);
  }

  // Sort the array
  uasort($sections, 'drupal_sort_weight');

  return $sections;
}

function _fc_set_price(&$section, $price) {
  if(isset($section['price'])) {
    $section['price'] += $price;
  } else {
    $section['price'] = $price;
  }
}
