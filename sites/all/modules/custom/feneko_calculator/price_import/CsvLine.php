<?php
namespace FenekoCalculator;

class CsvLine {
  private $line;
  private $key;
  private $csv;
  private $fileKey;

  public function __construct($csv, $line, $fileKey, $key = '') {
    $this->line     = $line;
    $this->key      = $key;
    $this->csv      = $csv;
    $this->fileKey  = $fileKey;

    if(!empty($key)) {
      // Set the header to the key name
      $this->line[] = $key;
    }
  }

  public function handleHeader() {
    $name = $this->csv->getName();
    $config = $this->csv->getConfig();

    // Remove header columns
    if(isset($config['remove'])) {
      foreach ($config['remove'] as $i) {
        unset($this->line[$i]);
      }
    }

    $this->removePriceColumns();

    switch ($name) {
      case 'dorpel_hoeken':
      case 'dorpel_eindstukken':
      case 'dorpel_koppelstukken':
      case 'dorpel_anti_dreunstroken':
        $this->line[] = "SKU";
        $this->line[] = "titel";
        break;

      case 'dorpel_montagebeugels':
        $this->line[0] = "Maat";
        $this->line[1] = "MB Type";
        $this->line[] = "SKU";
        $this->line[] = "titel";
        break;

      case 'raamtablet_eindstukken':
        $this->line[] = "SKU";
        break;

      case 'plaatbewerking':
        $this->line[] = "lengte";
        $this->line[] = "dikte";
        $this->line[] = "SKU";
        $this->line[] = "titel";
        break;

      case 'raamtabletten':
        $this->line[] = "lengte";
        $this->line[] = "titel";
        break;

      case 'muurkappen':
      case 'sandwichpanelen_isolatie':
        $this->line[] = "lengte";
        $this->line[] = "SKU";
        $this->line[] = "titel";
        break;

      case 'sandwichpanelen':
        $this->line[0] = "Plaat 1";
        $this->line[1] = "Plaat 2";
        $this->line[] = "lengte";
        $this->line[] = "SKU";
        $this->line[] = "titel";
        break;

      case 'muurkap_eindstukken':
        $this->line[] = "MKE type";
        $this->line[] = "SKU";
        $this->line[] = "titel";
        break;

      case 'standaardprofielen':
        $this->line[] = "afwerking";
        $this->line[] = "type";
        $this->line[] = "maat";
        break;
    }

    $this->line[] = "price";
  }

  public function prepare() {
    $this->setMapping()->setFileKey();

    $name = $this->csv->getName();
    switch ($name) {
      case 'eenheden':
        $this->setColumn('sku')
        ;
        break;

      case 'standaardprofielen':
        $this->setColumn('utilo_type')
             ->setColumn('maat')
             ->setColumn('sku')
             // ->setColumn('image')
        ;
        break;

      case 'muurkappen':
      case 'muurkap_eindstukken':
        $this->setColumn('remove')
        ;

      case 'dorpel_hoeken':
      case 'dorpel_eindstukken':
      case 'dorpel_koppelstukken':
      case 'dorpel_anti_dreunstroken':
      case 'raamtablet_eindstukken':
      case 'raamtabletten':
      case 'muurkappen':
      case 'muurkap_eindstukken':
      case 'plaatbewerking':
      case 'sandwichpanelen_isolatie':
        $this->setColumn('sku')
             ->setColumn('titel')
        ;
        break;

      case 'dorpel_montagebeugels':
        $this->setColumn('mb_type')
             ->setColumn('sku')
             ->setColumn('titel')
        ;
        break;

      case 'sandwichpanelen':
        $this->setColumn('platen')
             ->setColumn('sku')
             ->setColumn('titel')
        ;
        break;
    }

    $this->setColumn('concat')
         ->setColumn('price')
         ->removePriceColumns()
         ->castScientifc()
         ->translateChars()
    ;
  }

  public function write(&$handle) {
    fputcsv($handle, $this->line);
  }

  private function castScientifc() {
    $lastCol = count($this->line) - 1;
    $this->line[$lastCol] = (float)$this->line[$lastCol] * 100 * 1000;
    return $this;
  }


  // Maybe this should be called removeExplodeCols
  private function removePriceColumns() {
    $config = $this->csv->getConfig();

    // Remove all price columns
    foreach ($config['priceCols'] as $colNum) {
      unset($this->line[$colNum]);
    }

    // Renumber the array
    $this->line = array_values($this->line);

    return $this;
  }

  private function setColumn($type) {
    $name = $this->csv->getName();
    $config = $this->csv->getConfig();

    switch ($type) {
      case 'concat':
        if(isset($config['concat'])) {
          foreach ($config['concat'] as $col) {
            $this->line[$col] .= "-" . $this->key;
          }
        }
        break;

      case 'image':
        $prefix = "private://calculator/in/images/";
        $this->line[14] = $prefix . $this->line[14] . '.jpg' ;
        break;

      case 'maat':
        switch ($name) {
          // TODO: Should be more specific by field
          // case 'plaatbewerking':
          // case 'sandwichpanelen_old':
          //   $this->csv->addAllowedValue('field_maat', $this->line[11]);
          //   break;

          case 'standaardprofielen':
            $replace = array(
              ',' => '.',
              ' x ' => 'x',
            );
            $descr = strtolower($this->line[$config['descr']]);
            preg_match ('/[0-9](.*)/', $descr, $matches);
            $value = $matches[0];
            $value = strtr($value, $replace);
            $this->line[] = $value;
            $this->csv->addAllowedValue('field_maat', $value);
            break;
        }
        break;

      case 'price':
        // standaardprofielen has commas that need to be replaced by points
        $this->line[] = $name === 'standaardprofielen'
          ? str_replace(',', '.', $this->line[$config['priceCols'][$this->key]])
          : $this->line[$config['priceCols'][$this->key]];
        break;

      case 'remove':
        if(isset($config['remove'])) {
          foreach ($config['remove'] as $i) {
            unset($this->line[$i]);
          }
        }
        break;

      case 'sku':
        switch ($name) {
          case 'dorpel_hoeken':
          case 'dorpel_eindstukken':
            if(isset($config['prefix'])) {
              $this->line[] = $config['prefix'] . $this->line[0] . "-" . $this->line[2];
            }
            break;

          case 'sandwichpanelen':
            if(isset($config['prefix'])) {
              $this->line[] = $config['prefix'] . $this->line[0] . "-"
                         . $this->line[1] . "-" . $this->line[12];
            }
            break;

          case 'dorpel_koppelstukken':
          case 'dorpel_anti_dreunstroken':
            if(isset($config['prefix'])) {
              $this->line[] = $config['prefix'] . $this->line[2];
            }
            break;

          case 'plaatbewerking':
          case 'sandwichpanelen_old':
            if(isset($config['prefix'])) {
              $sku = $config['prefix'] . $this->line[0] . "-" . $this->line[11];
              $sku = $this->fileKey ? $sku . '-' . $this->fileKey : $sku;
              $this->line[] = $sku;
            }
            break;

          case 'sandwichpanelen_isolatie':
            if(isset($config['prefix'])) {
              $this->line[] = $config['prefix'] . $this->line[0] . "-" . $this->line[11];
            }
            break;

          case 'muurkappen':
          case 'muurkap_eindstukken':
            if(isset($config['prefix'])) {
              $this->line[] = $config['prefix'] . $this->line[0] . "-" . $this->line[1] . "-" . $this->line[2];
            }
            break;

          case 'dorpel_montagebeugels':
            if(isset($config['prefix'])) {
              $this->line[] = $config['prefix'] . $this->line[1] . "-" . $this->line[0] . "-" . $this->line[2];
            }
            break;

          case 'raamtabletten':
            if(isset($config['prefix'])) {
              $this->line[0] = $config['prefix'] . $this->line[2] . "-" . $this->line[1];
            }
            break;

          case 'raamtablet_eindstukken':
            if($this->line[0] === 'AD') {
              $this->line[] = $this->line[2];
              $this->line[2] = '';
            } else {
              if(isset($config['prefix'])) {
                $this->line[] = $config['prefix'] . $this->line[0] . "-" . $this->line[2];
              }
            }
            break;

          default:
            if(isset($config['sku'])) {
              $prefix = isset($config['prefix']) ? $config['prefix'] : '';
              $replace = array(
                '.' => '_',
                ',' => '_',
                ' ' => '',
              );
              $safeSKU = strtr($prefix . $this->line[$config['sku']], $replace);
              $this->line[$config['sku']] = $safeSKU;
            }
            break;
        }
        break;

      case 'titel':
        switch ($name) {
          case 'dorpel_anti_dreunstroken':
            if(isset($config['prefix'])) {
              $info = field_info_field('field_anti_dreunstrook');
              $mapping = $info['settings']['allowed_values'];
              $this->line[] = 'Anti-Dreunstook ' . $mapping[$this->line[2]];
            }
            break;

          case 'dorpel_eindstukken':
            if(isset($config['prefix'])) {
              $this->line[] = 'Dorpel Eindstuk Type ' . $this->line[0] . "-" . $this->line[2];
            }
            break;

          case 'dorpel_hoeken':
            if(isset($config['prefix'])) {
              $this->line[] = 'Dorpel Hoek-' . $this->line[0] . "-" . $this->line[2];
            }
            break;

          case 'dorpel_koppelstukken':
            if(isset($config['prefix'])) {
              $this->line[] = 'Dorpel Koppelstuk' . "-" . $this->line[2];
            }
            break;

          case 'raamtablet_eindstukken':
            if($this->line[0] === 'AD') {
              $info = field_info_field('field_anti_dreunstrook');
              $mapping = $info['settings']['allowed_values'];
              $this->line[1] = 'Anti-Dreunstook ' . $mapping[$this->line[4]];
            } else {
              $mapping = array(
                'AD'  => 'Anti-Dreunstook',
                'BIH' => 'Binnenhoek',
                'BUH' => 'Buitenhoek',
                'ET1' => 'Eindstuk Type 1',
                'ET2' => 'Eindstuk Type 2',
                'K'   => 'Koppelstuk',
              );
              $this->line[1] = $mapping[$this->line[0]];
            }

            break;

          case 'muurkappen':
          case 'muurkap_eindstukken':
            $this->line[] = 'Muurkap-' . $this->line[0] . '-' . $this->line[1]
                                                           . '-' . $this->line[2];
            break;

          case 'plaatbewerking':
            $this->line[] = 'Plaatbewerking-' . $this->line[0]
                          . "-" . $this->line[11] . '-' . $this->fileKey;
            break;

          case 'raamtabletten':
            $this->line[] = 'Raamtablet-' . $this->line[2] . '-' . $this->line[1]
                                                           . '-' . $this->line[7];
            break;

          case 'sandwichpanelen':
            $this->line[] = 'Sandwichpaneel-' . $this->line[0] . "-"
                       . $this->line[1] . "-" . $this->line[12];
            break;

          case 'sandwichpanelen_old':
            $this->line[] = 'Sandwichpaneel-' . $this->line[0] . "-" . $this->line[11];
            break;

          case 'sandwichpanelen_isolatie':
            $this->line[] = 'Isolatie-' . $this->line[0] . "-" . $this->line[11];
            break;

          case 'dorpel_montagebeugels':
            $this->line[] = 'Montagebeugel-' . $this->line[1] . "-" . $this->line[0] . "-" . $this->line[2];
            break;
        }
        break;

      case 'utilo_type':
        preg_match ('/^(.*)[0-9]/U', $this->line[$config['sku']], $matches);
        $this->line[] = trim($matches[1]);
        break;

      case 'mb_type':
        $this->line[1] = $this->line[0] === 'all' ? 1 : 2;
        break;

      case 'platen':
        $chunks = explode('|', $this->line[0]);
        $this->line[0] = $chunks[0];
        array_splice( $this->line, 1, 0, array($chunks[1]) ); // insert at position 1
        break;
    }

    return $this;
  }

  private function setMapping() {
    $config = $this->csv->getConfig();
    if(isset($config['mapping'])) {
      foreach ($config['mapping'] as $col => $mapping) {
        $key = &$this->line[$col];
        $key = $config['mapping'][$col][$key];
      }
    }
    return $this;
  }

  private function setFileKey() {
    if($this->fileKey) {
      $this->line[] = $this->fileKey;
    }
    return $this;
  }

  // TODO: do this smarter
  private function translateChars() {
    $replace = array(
      ',' => ".", // We only want dots, no commas
    );

    foreach ($this->line as &$value) {
      $value = strtr($value, $replace);
    }

    return $this;
  }

}
