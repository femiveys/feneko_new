<?php
function feneko_code_orders_form($form, &$form_state) {
  global $user;
  global $language;
  $date_format = "d/m/Y";

  $klantennummers = array_keys(feneko_code_get_clients_options());

  $header = array(
    'orderbon' => array(
      'data' => t('Ordernummer'),
      'field' => 'orderbon',
    ),
    'ref' => array(
      'data' => t('Referentie'),
      'field' => 'ref',
    ),
    'kleur' => array(
      'data' => t('Kleur'),
      'field' => 'kleur',
    ),
    'order_datum' => array(
      'data' => t('Orderdatum'),
      'field' => 'order_datum',
    ),
    'lever_datum' => array(
      'data' => t('Leverdatum'),
      'field' => 'lever_datum',
    ),
    'aantal' => t('Aantal'),
    'fase' => array(
      'data' => t('Fase') . "<span class=\"help\"></span>",
      'field' => 'fase',
    ),
    'bedrag' => t('Bedrag'),
    'leverconditie' => t('Leverconditie'),
  );

  $mapping = array(
    'INGEVOERD'           => array(
      'label' => array(
        'nl' => 'INGEVOERD',
        'fr' => 'ENCODÉE',
      ),
      'description' => array(
        'nl' => 'Order werd ingegeven',
        'fr' => 'Encodage effectué',
      ),
    ),
    'OFFERTE' => array(
      'label' => array(
        'nl' => 'OFFERTE',
        'fr' => 'OFFRE',
      ),
      'description' => array(
        'nl' => 'Er werd een offerte verstuurd',
        'fr' => 'Offre envoyée au client',
      ),
    ),
    'BACKORDER' => array(
      'label' => array(
        'nl' => 'BACKORDER',
        'fr' => 'BACKORDER',
      ),
      'description' => array(
        'nl' => 'Er wordt informatie van de klant verwacht',
        'fr' => 'Nous attendons des informations supplémentaires',
      ),
    ),
    'BEVESTIGD' => array(
      'label' => array(
        'nl' => 'BEVESTIGD',
        'fr' => 'CONFIRMÉE',
      ),
      'description' => array(
        'nl' => 'Orderbevestiging vertuurd',
        'fr' => 'Confirmations de commande envoyées',
      ),
    ),
    'PRODUCTIE' => array(
      'label' => array(
        'nl' => 'PRODUCTIE',
        'fr' => 'PRODUCTION',
      ),
      'description' => array(
        'nl' => 'Order is in productie',
        'fr' => 'Produits en production',
      ),
    ),
    'GELEVERD' => array(
      'label' => array(
        'nl' => 'GELEVERD',
        'fr' => 'LIVRÉE',
      ),
      'description' => array(
        'nl' => 'Order is geleverd',
        'fr' => 'Ordre est livré',
      ),
    ),
    'CONTROLE' => array(
      'label' => array(
        'nl' => 'CONTROLE',
        'fr' => 'CONTRÔLE',
      ),
      'description' => array(
        'nl' => 'Interne controle van ingevoerde order',
        'fr' => 'Controle interne d’ordre encodée',
      ),
    ),
    'GECONTROLEERD' => array(
      'label' => array(
        'nl' => 'GECONTROLEERD',
        'fr' => 'CONTROLÉE',
      ),
      'description' => array(
        'nl' => 'Goedkeuring van de klant gewenst',
        'fr' => 'Nous attendons l’accord du client',
      ),
    ),
    'GEREED GEMELD'           => array(
      'label' => array(
        'nl' => 'PRODUCTIE',
        'fr' => 'PRODUCTION',
      ),
      'description' => array(
        'nl' => 'Orders is klaar voor levering',
        'fr' => 'Produits près pour livraison',
      ),
    ),
    'BESTELD' => array(
      'label' => array(
        'nl' => 'BESTELD',
        'fr' => 'COMMANDÉE',
      ),
    ),
    'KLAAR VOOR LEVERING' => array(
      'label' => array(
        'nl' => 'KLAAR VOOR LEVERING',
        'fr' => 'PRÊT POUR LIVRAISON',
      ),
    ),
    'GEFACTUREERD' => array(
      'label' => array(
        'nl' => 'GEFACTUREERD',
        'fr' => 'FACTURÉE',
      ),
    ),
    'ONBEKEND' => array(
      'label' => array(
        'nl' => 'ONBEKEND',
        'fr' => 'INCONNUE',
      ),
    ),
    'GEBLOKKEERD' => array(
      'label' => array(
        'nl' => 'GEBLOKKEERD',
        'fr' => 'BLOQUÉE',
      ),
    ),
    'GEANNULEERD' => array(
      'label' => array(
        'nl' => 'GEANNULEERD',
        'fr' => 'ANNULÉE',
      ),
    ),
    'leveren' => array(
      'label' => array(
        'nl' => 'leveren',
        'fr' => 'livrer',
      ),
    ),
    'ophalen' => array(
      'label' => array(
        'nl' => 'ophalen',
        'fr' => 'venir chercher',
      ),
    ),
  );

  $fields = array(
    'orderbon',
    'ref',
    'omschrijving',
    'kleur',
    'order_datum',
    'lever_datum',
    'aantal',
    'fase',
    'bedrag',
    'leverconditie',
  );

  if(count($klantennummers) > 1) {
    $header['klant'] = array(
      'data' => t('Klantennummer'),
      'field' => 'klant',
    );
    $fields[] = 'klant';
  }

  $unknown = t("ONBEKEND");

  $query = db_select(FENEKO_CODE_ORDER_STATUSES_TABLE)
               ->condition('klant', $klantennummers, 'IN')
               ->condition('fase', 'GEFACTUREERD', '<>')
               ->condition('fase', 'GEBLOKKEERD', '<>')
               ->condition('fase', 'GEANNULEERD', '<>')
               ->fields(NULL, $fields)
               ->extend('TableSort')
               ->orderByHeader($header)
              ;

  feneko_code_orders_filters($form_state, $header, $query);

  $results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  // Create the table
  $table = array();
  if(count($results) === 0) {
    // Show a message when nothing has been found
    $table = array(
      '#markup' => t('Er zijn geen bestellingen gevonden.')
    );
  } else {
    // Transform some values
    $rows = array();
    $count = 0;
    foreach ($results as $result) {
      $result['bedrag'] = "€" . str_replace('.', ',', sprintf("%01.2f", $result['bedrag']));
      $result['order_datum'] = $result['order_datum'] ? date($date_format, $result['order_datum']) : $unknown;
      $result['lever_datum'] = $result['lever_datum'] ? date($date_format, $result['lever_datum']) : $unknown;


      $result['fase']          = $mapping[$result['fase']]['label'][$language->language];
      $result['leverconditie'] = $mapping[$result['leverconditie']]['label'][$language->language];

      // Make the orderbon span over 2 rows
      $result['orderbon'] = array('data' => $result['orderbon'], 'rowspan' => 2);

      // Set the omschrijving row and remove the omschrijving from the result
      $omschrijving = array(
        array('data' => $result['omschrijving'], 'colspan' => count($header) - 1),
      );
      unset($result['omschrijving']);

      $evenodd = $count++ % 2 === 0 ? 'even' : 'odd';

      $rows[] = array('data' => $result      , 'no_striping' => TRUE, 'class' => $evenodd);
      $rows[] = array('data' => $omschrijving, 'no_striping' => TRUE, 'class' => $evenodd);
    }

    $table = array(
      '#theme'  => 'table',
      '#header' => $header,
      '#rows'   => $rows,
    );
  }

  // Create the help text
  $text  = '';
  foreach ($mapping as $key => $value) {
    if(isset($value['description'])) {
      $text .= '<div>';
      $text .= '<span class="label">' . $value['label'][$language->language] . ': </span>';
      $text .= '<span class="descr">' . $value['description'][$language->language] . '</span>';
      $text .= '</div>';
    }
  }

  $help = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('help-text')),
    'text' => array('#markup' => $text),
  );

  // Add the filters
  $filter_click = isset($form_state['clicked_button']['#parents'][0])
                    and $form_state['clicked_button']['#parents'][0] === 'filter';
  $form['filter'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => !$filter_click,
    '#attributes' => array('class' => array('filters')),
    '#tree' => TRUE,
    '#title' => t('Filters'),
    'ref' => array(
      '#type' => 'textfield',
      '#title' => $header['ref']['data'],
      '#size' => 20,
      '#description' => t('Tekens die in de referentie voorkomen'),
    ),
    'lever_from' => array(
      '#type' => 'date_popup',
      '#title' => $header['lever_datum']['data'] . " " . t('van'),
      '#attributes' => array('class' => array('lever-from')),
      '#date_format' => $date_format,
    ),
    'lever_to' => array(
      '#type' => 'date_popup',
      '#title' => $header['lever_datum']['data'] . " " . t('tot'),
      '#attributes' => array('class' => array('lever-to')),
      '#date_format' => $date_format,
    ),
    'actions' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('actions')),
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Filter'),
      ),
      'reset' => array(
        '#type' => 'submit',
        '#value' => t('Reset filters'),
      ),
    ),
  );

  // Add the help text
  $form['help'] = $help;

  // Finally add the table to the form
  $form['orders'] = $table;

  return $form;
}

function feneko_code_orders_filters($form_state, $header, $query) {
  if(isset($form_state['input']['filter'])) {
    $form_item = $form_state['input']['filter'];

    // Ref
    $filter = 'ref';
    if(!empty($form_item[$filter])) {
      $value = '%' . db_like($form_item[$filter]) . '%';
      $query->condition('ref', $value, 'LIKE');
    }

    // Leverdatum from
    $filter = 'lever_from';
    if(!empty($form_item[$filter]['date'])) {
      $timestamp = _feneko_code_get_timestamp($filter, $form_item);
      $query->condition('lever_datum', $timestamp, '>=');
    }

    // Leverdatum to
    $filter = 'lever_to';
    if(!empty($form_item[$filter]['date'])) {
      $timestamp = _feneko_code_get_timestamp($filter, $form_item);
      $query->condition('lever_datum', $timestamp, '<=');
    }

  }
}

function _feneko_code_get_timestamp($filter, $form_item) {
  $date_format = 'd/m/Y H:i';
  $date_string = check_plain($form_item[$filter]['date']) . " 00:00";
  return date_create_from_format($date_format, $date_string)->getTimestamp();
}

function feneko_code_orders_form_submit($form, &$form_state) {
  // If a filter button has been clicked, we need to rebuild the form
  if(isset($form_state['clicked_button']['#parents'][0])
    and $form_state['clicked_button']['#parents'][0] === 'filter') {

    $form_state['rebuild'] = TRUE;

    // If the reset button has been clicked, we need to reset the input values
    // and the the values values
    if($form_state['clicked_button']['#parents'][2] === 'reset') {
      $form_state['values']['filter']['ref'] = '';
      $form_state['input']['filter']['ref'] = '';
      $form_state['values']['filter']['lever_from']['date'] = '';
      $form_state['input']['filter']['lever_from']['date'] = '';
      $form_state['values']['filter']['lever_to']['date'] = '';
      $form_state['input']['filter']['lever_to']['date'] = '';
    }
  }
}
