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

  $form['fc_order_email_text'] = array(
    '#title' => t('Client e-mail text for an order'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_order_email_text', ''),
    '#description' => t('Text of the email that will be sent to user who has submitted an order. You can use the
                         token <strong>{name}</strong> to provide the username of the submitter.'),
  );

  $form['fc_offer_email_text'] = array(
    '#title' => t('Client e-mail text for an offer'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_offer_email_text', ''),
    '#description' => t('Text of the email that will be sent to user who has submitted an offer. You can use the
                         token <strong>{name}</strong> to provide the username of the submitter.'),
  );

  $form['fc_notification_email_text'] = array(
    '#title' => t('Admin e-mail text'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_notification_email_text', ''),
    '#description' => t('Text of the email that will be sent to the email provided above. You can use following placeholders: <strong>{name}, {client_number}, {company}</strong>'),
  );

  return system_settings_form($form);
}


function element_validate_mail($element, &$form_state) {
  $value = $element['#value'];
  if (!valid_email_address($value)) {
    form_error($element, t('%name must be valid e-mail address.', array('%name' => $element['#title'])));
  }
}

