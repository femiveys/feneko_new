<?php
namespace FenekoCalculator;

class CsvHandler {
  private $config;
  private $name;
  private $lovs;

  const DELIM = ",";

  /**
   * Constructor
   *
   * @param array $config
   *   The configuration array that defines this handler
   * @param string $name
   *   The name of this handler
   */
  public function __construct($config, $name) {
    $this->config = $config;
    $this->name   = $name;
  }

  /**
   * Returns the configuration array
   *
   * @return array
   *   The configuration
   */
  public function getConfig() {
    return $this->config;
  }

  /**
   * Returns the name
   *
   * @return array
   *   The name of the handler
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Add an allowed value for a certain field
   *
   * @param string $field
   *   Name of the field to add an allowed value to.
   *   Example: body, field_type, ...
   */
  public function addAllowedValue($field, $value) {
    $this->lovs[$field][$value] = $value;
  }

  /**
   * Handle CSV split
   */
  public function handle() {
    require_once 'CsvLine.php';

    $output = FC_PATH . "/out/" . $this->name . ".csv";
    $out = fopen($output, 'w');

    // Make sure $source is an array
    $sources = $this->config['source'];
    if(!is_array($sources)) {
      $sources = array($sources);
    }

    $first_source = TRUE;
    foreach ($sources as $fileKey => $source) {
      $input  = FC_PATH . "/in/$source";

      // Make sure the $input file exists
      if (($in = fopen($input, "r")) !== FALSE) {

        $first = TRUE;
        while (($line = fgetcsv($in, 1000, self::DELIM)) !== FALSE) {
          if($first && $this->config['skipFirstLine']) {
            if($first_source) {
              $csvLine = new CsvLine($this, $line, $fileKey);
              $csvLine->handleHeader();
              $csvLine->write($out);
            } else {
              $first = FALSE;
              continue;
            }
          } else {
            if(!isset($this->config['filter'])) {
              $this->config['filter'] = array('none');
            }
            // Apply all the filters as logical OR
            // TODO: Extend so AND and OR are supported
            foreach ($this->config['filter'] as $colNum => $values) {
              if($values === 'none' or in_array($line[$colNum], $values)) {
                foreach ($this->config['priceCols'] as $key => $colNum) {
                  $csvLine = new CsvLine($this, $line, $fileKey, $key);
                  $csvLine->prepare();
                  $csvLine->write($out);
                }
              }
            }
          }
          $first = FALSE;
        }
        fclose($in);
        $this->setAllowedValues();
      } else {
        $msg = t(':file doesn\'t exist.', array(':file' => $input));
        drupal_set_message($msg, 'error');
      }

      $first_source = FALSE;
    }

    // Close the file and write a message
    if(fclose($out)) {
      $msg = t(':file has been written.', array(':file' => $output));
      drupal_set_message($msg, 'succes');
    }
  }

  /**
   * Set the allowed values to fields
   *
   * While adding values to fields of products, we also need to add those values
   * to the list of allowed values to have them in the dropdown. This is why
   * those values are saved in an internal variable.
   * This function processes this internal variable (for all fields defined in lovs).
   *
   * @param boolean $replace
   *   Set to TRUE if the values need to be replaced. Defaults to FALSE.
   *   Watch  out. If there are already values in the DB for the allowed value,
   *   that allowed value cannot be removed. So this will cause an error.
   */
  private function setAllowedValues($replace = FALSE) {
    if(isset($this->lovs)) {
      foreach ($this->lovs as $field => $values) {
        // Get the field info
        $info = field_info_field($field);

        // Get a reference to the values
        // $allowed_values = &$info['settings']['allowed_values'];

        if($replace) {
          // Careful with this branch
          $info['settings']['allowed_values'] = $values;
        } else {
          $info['settings']['allowed_values'] =
                        array_merge($info['settings']['allowed_values'], $values);
        }

        // Save the field
        field_update_field($info);
      }
    }
  }
}
