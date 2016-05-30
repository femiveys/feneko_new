<?php
/**
 * @file
 * For settings
 */

function feneko_calculator_settings_form($form, &$form_state) {
  $form['fc_minimum_order_amount'] = array(
    '#type' => 'textfield',
    '#title' => 'Minimum facturatie bedrag',
    '#size' => 4,
    '#maxlength' => 30,
    '#field_prefix' => '€',
    '#default_value' => variable_get('fc_minimum_order_amount'),
    '#element_validate' => array('element_validate_number'),
  );

  $form['fc_notification_email'] = array(
    '#type' => 'textfield',
    '#title' => 'E-mail',
    '#size' => 20,
    '#maxlength' => 30,
    '#element_validate' => array('element_validate_mail'),
    '#default_value' => variable_get('fc_notification_email', variable_get('manyforms_notification_email', '')),
    '#description' => t('Email address where all submission notifications will be sent'),
  );

  $descr = 'Text of the email that will be sent to user who has submitted an order. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{id}</b>:<span>identifier of the order</span></li>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{client}</b>:<span>name of the client</span></li>'
         .   '<li><b>{client_number}</b>:<span>client number of the client</span></li>'
         . '</ul>'
  ;
  $form['fc_order_email_text'] = array(
    '#title' => t('Client e-mail text for an order'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_order_email_text', ''),
    '#description' => t($descr),
  );

  $descr = 'Text of the email that will be sent to user who has submitted an offer. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{id}</b>:<span>identifier of the offer</span></li>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{client}</b>:<span>name of the client</span></li>'
         .   '<li><b>{client_number}</b>:<span>client number of the client</span></li>'
         . '</ul>'
  ;
  $form['fc_offer_email_text'] = array(
    '#title' => t('Client e-mail text for an offer'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_offer_email_text', ''),
    '#description' => t('Text of the email that will be sent to user who has submitted an offer. You can use the
                         token <strong>{name}</strong> to provide the username of the submitter.'),
  );

  $descr = 'Text of the email that will be sent to the email provided above. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{id}</b>:<span>identifier of order or offer</span></li>'
         .   '<li><b>{type}</b>:<span>"het offer" or "de bestelling"</span></li>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{client}</b>:<span>name of the client</span></li>'
         .   '<li><b>{client_number}</b>:<span>client number of the client</span></li>'
         . '</ul>'
  ;
  $form['fc_notification_email_text'] = array(
    '#title' => t('Admin e-mail text'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_notification_email_text', ''),
    '#description' => t($descr),
  );

  return system_settings_form($form);
}

function element_validate_mail($element, &$form_state) {
  $value = $element['#value'];
  if (!valid_email_address($value)) {
    form_error($element, t('%name must be valid e-mail address.', array('%name' => $element['#title'])));
  }
}

