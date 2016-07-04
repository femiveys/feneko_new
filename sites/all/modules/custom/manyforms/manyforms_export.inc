<?php
/**
 * @file
 * Export Many Forms
 */

function manyforms_export_form($form, &$form_state) {
  $options = array();
  $page_size = 200;

  $filters = array('type', 'user', 'client', 'ref');

  $only_exported = $form_state['build_info']['args'][0];

  $destination = array(
    'destination' => $destination = current_path() . "?" . http_build_query($_REQUEST),
  );

  // The header defines the order of the columns
  $header = array(
    'id' => array(
      'data' => t('ID'),
      'field' => 'id',
    ),
    'name' => array(
      'data' => t('Name'),
      'field' => 'form_id',
    ),
    'type' => array(
      'data' => t('Type'),
      'field' => 'kies_een_optie',
    ),
    'user' => array(
      'data' => t('User'),
      'field' => 'name',
    ),
    'client' => array(
      'data' => t('Klant'),
      'field' => 'klant',
    ),
    'ref' => array(
      'data' => t('Referentie'),
      'field' => 'referentie',
    ),
    'date' => array(
      'data' => t('Date'),
      'field' => 'datesubmit',
    ),
    'download' => 'Download',
  );

  // Get the totals
  for ($i = 1; $i <= FENEKO_SCREENS_NUM; $i++) {
    $form_id = sprintf('%02d', $i);

    $query = db_select("manyforms_$form_id", 'f');
    $query->join('users', 'u', 'f.uid = u.uid');
    $query->condition('exported', $only_exported);
    $query->fields('f', array('id'));

    // Apply the filters
    manyforms_export_form_filters($filters, $form_state, $header, $query);

    // Drupal takes a distinct for some reason, so we add this so results are unique
    $query->addExpression($i, 'form');

    if($i == 1) { $union = $query; }
    else { $union->union($query); }
  }
  $total = $union->execute()->rowCount();

  if($only_exported) {
    // Get the current page
    $page = pager_find_page();

    // Initialize the pager
    pager_default_initialize($total, $page_size);
    $pager = theme('pager');
  }

  // Construct a UNION select query for all forms
  for ($i = 1; $i <= FENEKO_SCREENS_NUM; $i++) {
    $form_id = sprintf('%02d', $i);
    $ff = new FenekoSpecificForm($form_id);

    $query = db_select("manyforms_$form_id", 'p')->extend('TableSort');
    $query->join('users', 'u', 'p.uid = u.uid');
    $query->condition('exported', $only_exported);
    $query->fields('u', array('name'))
          ->fields('p', array(
                          'id',
                          'exported',
                          'klant',
                          'referentie',
                          'kies_een_optie',
                          'datesubmit',
                        )
            )
          ;

    // Apply the filters
    manyforms_export_form_filters($filters, $form_state, $header, $query);

    $query->addExpression("'" . $ff->title . "'", 'title');
    $query->addExpression("'" . $form_id . "'", 'form_id');

    switch ($i) {
      case 1:
        $union = $query;
        break;

      case FENEKO_SCREENS_NUM:
        $query->orderByHeader($header);                // hack: should not work
        if($only_exported) {
          $query->range($page * $page_size, $page_size); // hack: should not work
        }

      default:
        $union->union($query);
        break;
    }
  }

  // Execute the UNION select query
  $results = $union->execute();

  // Loop over every result to fill the rows
  foreach ($results as $row) {
    $key = $row->form_id . "_" . $row->id;

    $pdf = array(
      '#theme' => 'link',
      '#text' => t('PDF'),
      '#path' => "forms/pdf_generator/" . $row->form_id . "/" . $row->id,
      '#options' => array(
        'attributes' => array('target' => '_blank'),
        'html' => FALSE,
      ),
    );

    $fiche = array(
      '#theme' => 'link',
      '#text' => t('fiche'),
      '#path' => "forms/export/" . $row->form_id . "_" . $row->id,
      '#options' => array(
        'attributes' => array(),
        'html' => FALSE,
        'query' => $destination,
      ),
    );

    $links = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#attributes' => array('class' => array('inline')),
      '#items' => array(
        drupal_render($pdf),
        drupal_render($fiche),
      ),
    );

    $options[$key] = array(
      'id'       => $row->id,
      'name'     => $row->title,
      'client'   => $row->klant,
      'ref'      => $row->referentie,
      'type'     => $row->kies_een_optie,
      'user'     => $row->name,
      'date'     => date('d-m-Y', $row->datesubmit),
      'download' => drupal_render($links),
    );
  }

  // Add the actions
  $form['actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Acties'),
    '#attributes' => array('class' => array('container-inline')),
    'options' => array(
      '#type' => 'select',
      '#options' => array(
        'export' => 'Exporteer',
        'undo_export' => 'Export ongedaan maken',
        'remove' => 'Definitief verwijderen',
      ),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Uitvoeren',
    ),
  );

  if($only_exported) {
    unset($form['actions']['options']['#options']['export']);
  } else {
    unset($form['actions']['options']['#options']['undo_export']);
  }

  // Add the filters
  $filter_click = isset($form_state['clicked_button']['#parents'][0])
                    and $form_state['clicked_button']['#parents'][0] === 'filter';
  $form['filter'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => !$filter_click,
    '#attributes' => array('class' => array('container-inline')),
    '#tree' => TRUE,
    '#title' => t('Filters'),
  );
  foreach ($filters as $filter) {
    $form['filter'][$filter] = array(
      '#type' => 'textfield',
      '#title' => $header[$filter]['data'],
      '#size' => 10,
    );
  }
  $form['filter']['type']['#type'] = 'select';
  $form['filter']['type']['#options'] = array(
    '' => 'beide',
    'offerte' => 'offerte',
    'bestelling' => 'bestelling',
  );
  unset($form['filter']['type']['#size']);
  $form['filter']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  $form['filter']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset filters'),
  );

  // Finally add the table to the form
  $form['submissions'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('Alles is geëxporteerd.'),
  );

  // Add the pager
  if($only_exported) {
    $form['pager'] = array('#markup' => $pager);
  }

  if( !isset( $form_state['storage']['confirm'] ) ) {
    return $form;
  } else {
    unset($form['submissions']);
    $path = current_path();

    // TODO: be more precise on what will be removed

    return confirm_form($form, 'Bevestiging', $path,
                        'Zeker dat je wilt verwijderen? Dit kan niet ongedaan gemaakt worden',
                        'Ja, verwijder', 'Ik twijfel, ga terug');
  }

}

function manyforms_export_form_filters($filters, $form_state, $header, $query) {
  foreach ($filters as $filter) {
    if(!empty($form_state['input']['filter'][$filter])) {
      $field = $header[$filter]['field'];
      $value = '%' . db_like($form_state['input']['filter'][$filter]) . '%';
      $query->condition($field, $value, 'LIKE');
    }
  }
}

function manyforms_export_form_submit($form, &$form_state) {
  // If a filter button has been clicked, we need to rebuild the form
  if(isset($form_state['clicked_button']['#parents'][0])
    and $form_state['clicked_button']['#parents'][0] === 'filter') {

    $form_state['rebuild'] = TRUE;

    // If the reset button has been clicked, we need to reset the input values
    // and the the values values
    if($form_state['clicked_button']['#parents'][1] === 'reset') {
      foreach ($form_state['values']['filter'] as $key => $value) {
        $form_state['values']['filter'][$key] = '';
        $form_state['input']['filter'][$key] = '';
      }
    }

  } else {
    if(isset($form_state['storage']['values'])) {
      $form_state['values'] = $form_state['storage']['values'];
    }

    // Limit the checkbox ids to only those selected by the user
    $selected = array_filter($form_state['values']['submissions']);

    // For some reason, the options value is not stored
    $operation = $form_state['values']['options'];

    if($operation === 'remove') {
      if( !isset( $form_state['storage']['confirm'] ) ) {
        $form_state['storage']['values'] = $form_state['values']; // temporarily store the values
        $form_state['storage']['confirm'] = TRUE; // this will cause the form to be rebuilt, entering the confirm part of the form
        $form_state['rebuild'] = TRUE;
      } else {
        FenekoForm::doFiches('remove', $selected);
      }
    } else {
      FenekoForm::doFiches($operation, $selected);
    }
  }
}

function manyforms_export_single($id) {
  FenekoForm::doFiches('single', $id);
}
