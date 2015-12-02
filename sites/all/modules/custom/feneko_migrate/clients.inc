<?php
class ClientsMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $path = 'private://clients.csv';

    $columns = array(
       0 => array('field_client_number', 'Number'),
       1 => array('title', 'Name'),
       2 => array('street', 'Street'),
       3 => array('zip', 'Zip'),
       4 => array('city', 'City'),
       5 => array('field_phone', 'Phone'),
       6 => array('field_fax', 'Fax'),
       12 => array('del_name', 'Delivery Name'),
       13 => array('del_street', 'Delivery Street'),
       14 => array('del_zip', 'Delivery Zip'),
       15 => array('del_city', 'Delivery City'),
       16 => array('field_payment_condition', 'Payment condition'),
       17 => array('field_price_code', 'Price Code'),
       18 => array('field_tva_code', 'TVA Code'),
       19 => array('country', 'Country'),
       20 => array('field_tva_number', 'TVA number'),
       21 => array('language', 'Language'),
       23 => array('field_representative', 'Representative'),
       25 => array('field_delivery_condition', 'Delivery condition'),
       28 => array('field_block_order_input', 'Block Order input'),
       29 => array('field_client_group', 'Client group'),
       30 => array('field_delivery_day', 'Delivery day'),
    );

    $csvOptions = array(
      'header_rows' => 1,
      'delimiter' => ';',
    );
    $this->source = new MigrateSourceCSV($path, $columns, $csvOptions);

    $this->destination = new MigrateDestinationNode('client');

    $this->map = new MigrateSQLMap($this->machineName, array(
      'field_client_number' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => t('Klantennummer'),
      )),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addSimpleMappings(array(
      'title',
      'language',
      'field_client_number',
      'field_client_group',
      'field_block_order_input',
      'field_phone',
      'field_fax',
      'field_representative',
      'field_payment_condition',
      'field_price_code',
      'field_tva_code',
      'field_tva_number',
      'field_delivery_condition',
      'field_delivery_day',
    ));

    $this->addFieldMapping('field_address', 'country');
    $this->addFieldMapping('field_address:thoroughfare','street');
    $this->addFieldMapping('field_address:postal_code','zip');
    $this->addFieldMapping('field_address:locality','city');

    $this->addFieldMapping('field_delivery_address', 'country');
    $this->addFieldMapping('field_delivery_address:organisation_name','del_name');
    $this->addFieldMapping('field_delivery_address:thoroughfare','del_street');
    $this->addFieldMapping('field_delivery_address:postal_code','del_zip');
    $this->addFieldMapping('field_delivery_address:locality','del_city');
}


  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $mapping = array(
      'country' => array(
        1 => 'NL',
        2 => 'BE',
        3 => 'LU',
        4 => 'IT',
        5 => 'PL',
        6 => 'FR',
        7 => 'CH',
      ),
      'language' => array(
        0 => 'nl',
        1 => 'fr',
        2 => 'en',
      ),
      'field_block_order_input' => array(
        'N' => 0,
        'J' => 1,
      ),
    );

    // foreach ($row as &$field) {
    //   trim($field);
    // }

    foreach (array_keys($mapping) as $name) {
      $row->$name = $mapping[$name][$row->$name];
    }

    self::handlePhone($row->field_phone);
    self::handlePhone($row->field_fax);

    $row->title = str_replace('sprl', 'SPRL', $row->title);
    $row->title = str_replace('bvba', 'BVBA', $row->title);

    if(empty(trim($row->field_delivery_day))) {
      $row->field_delivery_day = 0;
    }

    return TRUE;
  }

  public function prepare(&$row) {
    $row->path['pathauto'] = 0;
  }

  private static function handlePhone(&$phone) {
    feneko_migrate_handle_phone($phone);
  }

}
