<?php
/**
 * @file
 * For settings
 */

function manyforms_setting_form($form, &$form_state) {
  $form['manyforms_notification_email'] = array(
    '#type' => 'textfield',
    '#title' => 'e-mail',
    '#size' => 20,
    '#maxlength' => 30,
    '#element_validate' => array('element_validate_mail'),
    '#default_value' => variable_get('manyforms_notification_email', variable_get('site_mail', '')),
    '#description' => t('Email address where all submission notifications will be sent'),
  );

  $descr = 'Text of the email that will be sent to user who has submitted an order. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{id}</b>:<span>identifier of order</span></li>'
         . '</ul>'
  ;
  $form['manyforms_order_email_text'] = array(
    '#title' => t('Client e-mail text for an order'),
    '#type' => 'textarea',
    '#default_value' => variable_get('manyforms_order_email_text', ''),
    '#description' => t($descr),
  );

  $descr = 'Text of the email that will be sent to user who has submitted an offer. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{id}</b>:<span>identifier of offer</span></li>'
         . '</ul>'
  ;
  $form['manyforms_offer_email_text'] = array(
    '#title' => t('Client e-mail text for an offer'),
    '#type' => 'textarea',
    '#default_value' => variable_get('manyforms_offer_email_text', ''),
    '#description' => t($descr),
  );


  $descr = 'Text of the email that will be sent to the email provided above. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{type}</b>:<span>offer or order</span></li>'
         .   '<li><b>{id}</b>:<span>identifier of order or offer</span></li>'
         . '</ul>'
  ;

  $form['manyforms_notification_email_text'] = array(
    '#title' => t('Admin e-mail text'),
    '#type' => 'textarea',
    '#default_value' => variable_get('manyforms_notification_email_text', ''),
    '#description' => t($descr),
  );

  $descr = 'Text that will be shown to the user after successfull form submission. '
         . 'Following tokens can be used:'
         . '<ul>'
         .   '<li><b>{name}</b>:<span>username of the submitter</span></li>'
         .   '<li><b>{type}</b>:<span>offer or order</span></li>'
         .   '<li><b>{id}</b>:<span>identifier of order or offer</span></li>'
         . '</ul>'
  ;
  $form['manyforms_submiting_text'] = array(
    '#title' => t('After submit message'),
    '#type' => 'textarea',
    '#default_value' => variable_get('manyforms_submiting_text', ''),
    '#description' => t($descr),
  );

  $form['manyforms_soort_bevestiging_options'] = array(
    '#title' => t('The values for the <b>soort bevestiging</b> field'),
    '#type' => 'textarea',
    '#default_value' => variable_get('manyforms_soort_bevestiging_options', ''),
    '#description' => t('The options for the <b>soort bevestiging</b> field. Every line should hold an option and should have key, Dutch value and French value separated by a pipe.<br />Example: 4|4groot|4grand<br />In this example <em>4</em> will be stored in the DB. <em>4groot</em> will be the value shown for Dutch. <em>4grand</em> will be the value for French.<br />If no French value is given, the Dutch one is assumed.<br />If also no Dutch value is given, the Dutch and French value will be the same as the key.'),
  );

  return system_settings_form($form);
}

function element_validate_mail($element, &$form_state) {
  $value = $element['#value'];
  if (!valid_email_address($value)) {
    form_error($element, t('%name must be valid e-mail address.', array('%name' => $element['#title'])));
  }
}
