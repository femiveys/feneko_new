<?php
namespace FenekoCalculator;

class PriceImport {
  /**
   * - key: name
   *   - source: Name of source CSV
   *   - concat: Array of column indexes that should be concatenated with the
   *             key of the priceCols array
   *   - sku: index of the column holding the unique identifier
   *   - descr: index of the description column
   *   - skipFirstLine: TRUE if the first line holds the header. Defaults to FALSE
   *   - priceCols: array where
   *     - keys: names of the variations
   *     - values: indexes of the columns holding the price for that variation
   *   - mapping: array where
   *     - keys: index of column in which to map values
   *     - values: mapping table (array)
   *   - filter: array where
   *     - keys: index of column to filter on
   *     - values: Value to filter on that column
   *
   */
    private static $globalConfig;

    /**
     * Initialize variables
     */
    private static function init() {
      self::$globalConfig = array(
        'dorpel_anti_dreunstroken' => array(
          'source' => 'Prijs_Raamtablet_einstukken.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'concat' => array(3),
          'prefix' => "DA-",
          'mapping' => array(
            2 => array(
              4  => 'VA9051',
              5  => 'VA9052',
              6  => 'VA9053',
              7  => 'VA9054',
              8  => 'VA9055',
              9  => 'VA9056',
              10 => 'VA9057',
            ),
          ),
          'filter' => array(
            0 => range(82, 88),
          ),
        ),
        'dorpel_eindstukken' => array(
          'source' => 'Prijs_Raamtablet_einstukken.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'concat' => array(3),
          'prefix' => "DE-",
          'mapping' => array(
            0 => array(
              66 => '1',
              67 => '1',
              68 => '1',
              70 => '2',
              71 => '2',
              72 => '2',
            ),
            2 => array(
              1  => 'brut',
              2  => 'ral',
              3  => 'str',
            ),
          ),
          'filter' => array(
            0 => array(66, 67, 68, 70, 71, 72),
          ),
        ),
        'dorpel_koppelstukken' => array(
          'source' => 'Prijs_Raamtablet_einstukken.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'concat' => array(3),
          'prefix' => "DK-",
          'mapping' => array(
            2 => array(
              1  => 'brut',
              2  => 'ral',
              3  => 'str',
            ),
          ),
          'filter' => array(
            0 => array(73, 74, 75),
          ),
        ),
        'dorpel_hoeken' => array(
          'source' => 'Prijs_Raamtablet_einstukken.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'concat' => array(3),
          'prefix' => "DH-",
          'mapping' => array(
            0 => array(
              76 => 'buiten',
              77 => 'buiten',
              78 => 'buiten',
              79 => 'binnen',
              80 => 'binnen',
              81 => 'binnen',
            ),
            2 => array(
              1  => 'brut',
              2  => 'ral',
              3  => 'str',
            ),
          ),
          'filter' => array(
            0 => range(76, 81),
          ),
        ),
        'eenheden' => array(
          'source' => 'Eenheidsprijzen.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'sku' => 1,
          'prefix' => "EH-",
          'concat' => array(3),
        ),
        'muurkappen' => array(
          'source' => 'Prijs_Muurkap.csv',
          'concat' => array(12, 13),
          // 'sku' => 0,
          'prefix' => "MK-",
          'skipFirstLine' => TRUE,
          'priceCols' => array(
            '1000' => 3,
            '2000' => 4,
            '3000' => 5,
            '4000' => 6,
          ),
          'mapping' => array(
            2 => array(
              1 => 'brut',
              2 => 'ral',
              3 => 'str',
            ),
            0 => array(
              'Type 1' => 1,
              'Type 2' => 2,
              'Type 3' => 3,
            ),
          ),
          'remove' => array(7, 8, 9, 10),
        ),
        'muurkap_eindstukken' => array(
          'source' => 'Prijs_Muurkap.csv',
          'concat' => array(12, 13),
          'prefix' => "MKE-",
          'skipFirstLine' => TRUE,
          'priceCols' => array(
            'Eindstuk'   => 7,
            'Koppelstuk' => 8,
            'Hoek'       => 9,
            'Beugel'     => 10,
          ),
          'mapping' => array(
            2 => array(
              1 => 'brut',
              2 => 'ral',
              3 => 'str',
            ),
            0 => array(
              'Type 1' => 1,
              'Type 2' => 2,
              'Type 3' => 3,
            ),
          ),
          'remove' => array(3, 4, 5, 6),
        ),
        'raamtabletten' => array(
          'source' => 'Prijs_raamtabletten.csv',
          'concat' => array(0),
          'sku' => 0,
          'prefix' => "RT-",
          'skipFirstLine' => TRUE,
          'priceCols' => array(
            '1000' => 3,
            '2000' => 4,
            '3000' => 5,
            '4000' => 6,
          ),
          'mapping' => array(
            2 => array(
              1 => 'brut',
              2 => 'ral',
              3 => 'str',
              4 => 'reno',
            ),
          ),
        ),
        'raamtablet_eindstukken' => array(
          'source' => 'Prijs_Raamtablet_einstukken.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'concat' => array(3),
          'prefix' => "RT-",
          'filter' => array(
            1 => array(50, 70, 90),
          ),
          'mapping' => array(
            0 => array(
              66 => 'ET1',
              67 => 'ET1',
              68 => 'ET1',
              70 => 'ET2',
              71 => 'ET2',
              72 => 'ET2',
              73 => 'K',
              74 => 'K',
              75 => 'K',
              76 => 'BUH',
              77 => 'BUH',
              78 => 'BUH',
              79 => 'BIH',
              80 => 'BIH',
              81 => 'BIH',
              82 => 'AD',
              83 => 'AD',
              84 => 'AD',
              85 => 'AD',
              86 => 'AD',
              87 => 'AD',
              88 => 'AD',
            ),
            1 => array(
              50 => 'eind-koppel',
              70 => 'hoek',
              90 => 'anti-dreunstrook',
            ),
            2 => array(
              1  => 'brut',
              2  => 'ral',
              3  => 'str',
              4  => 'VA9051',
              5  => 'VA9052',
              6  => 'VA9053',
              7  => 'VA9054',
              8  => 'VA9055',
              9  => 'VA9057',
              10 => 'VA9056',
            ),
          ),
        ),
        'sandwichpanelen' => array(
          'source' => 'Prijs_SWopmaat2.csv',
          'priceCols' => array(
            '500'  => 2,
            '1000' => 3,
            '1250' => 4,
            '1500' => 5,
            '1750' => 6,
            '2000' => 7,
            '2500' => 8,
            '3000' => 9,
            '3500' => 10,
            '4000' => 11,
          ),
          'mapping' => array(
            0 => array(
              1 => 'brut|brut',
              2 => 'brut|ral',
              3 => 'brut|str',
              4 => 'brut|reno',
              5 => 'ral|ral',
              6 => 'ral|str',
              7 => 'ral|reno',
              8 => 'str|str',
              9 => 'reno|str',
              10 => 'reno|reno',
            ),
          ),
          'prefix' => "SW-",
          'skipFirstLine' => TRUE,
        ),
        'sandwichpanelen_isolatie' => array(
          'source' => 'Prijs_ISOopmaat.csv',
          'priceCols' => array(
            '500'  => 1,
            '1000' => 2,
            '1250' => 3,
            '1500' => 4,
            '1750' => 5,
            '2000' => 6,
            '2500' => 7,
            '3000' => 8,
            '3500' => 9,
            '4000' => 10,
          ),
          'skipFirstLine' => TRUE,
          'prefix' => "SW-ISO-",
          'mapping' => array(
            0 => array(
              'XPS25' => '25',
              'XPS30' => '30',
              'XPS35' => '35',
              'XPS40' => '40',
              'XPS42' => '42',
              'XPS50' => '50',
            ),
          ),
        ),
        'standaardprofielen' => array(
          'source' => 'Materialen.csv',
          'concat' => array(2, 3),
          'sku' => 2,
          'descr' => 3,
          'skipFirstLine' => TRUE,
          'priceCols' => array(
            'brut' => 4,
            'ral'  => 19,
            'str'  => 20,
          ),
          'filter' => array(
            1 => array('UTILO'),
            // 5 => array(6000),
          ),
        ),
        'plaatbewerking' => array(
          'source' => array(
            '1.5mm' => 'Prijs_Plaatwerk_15mm.csv',
            '2mm'   => 'Prijs_Plaatwerk_2mm.csv',
            '3mm'   => 'Prijs_Plaatwerk_3mm.csv',
          ),
          'priceCols' => array(
            '500'  => 1,
            '1000' => 2,
            '1250' => 3,
            '1500' => 4,
            '1750' => 5,
            '2000' => 6,
            '2500' => 7,
            '3000' => 8,
            '3500' => 9,
            '4000' => 10,
          ),
          'concat' => array(2),
          'prefix' => "PB-",
          'skipFirstLine' => TRUE,
          'mapping' => array(
            0 => array(
              1 => 'brut',
              2 => 'ral',
              3 => 'ral2',
              4 => 'str',
              5 => 'str2',
              6 => 'reno',
            ),
          ),
        ),
        'dorpel_montagebeugels' => array(
          'source' => 'Prijs_Raamtablet_einstukken.csv',
          'skipFirstLine' => TRUE,
          'priceCols' => array(3),
          'concat' => array(3),
          'prefix' => "MB-",
          'mapping' => array(
            0 => array(
              89  => '35-25',
              90  => '35-25',
              109 => '35-25',
              91  => '45-35',
              92  => '45-35',
              110 => '45-35',
              93  => '55-35',
              94  => '55-35',
              111 => '55-35',
              95  => '55-45',
              96  => '55-45',
              112 => '55-45',
              97  => '75-55',
              98  => '75-55',
              113 => '75-55',
              99  => '100-75',
              100 => '100-75',
              114 => '100-75',
              101 => '140-110',
              102 => '140-110',
              115 => '140-110',
              103 => '200-110',
              104 => '200-110',
              116 => '200-110',
              105 => '260-110',
              106 => '260-110',
              117 => '260-110',
              107 => 'all',
              108 => 'all',
              118 => 'all',
            ),
            2 => array(
              1  => 'brut',
              2  => 'ral',
              3  => 'str',
            ),
          ),
          'filter' => array(
            0 => range(89, 118),
          ),
        ),

      );

      // self::$globalConfig = array(
      //   'standaardprofielen' => self::$globalConfig['standaardprofielen'],
      // );

      // unset(self::$globalConfig['standaardprofielen']); // Materialen doesn't exist
    }


  /**
   * Splits source CSV files in target CSV files
   */
  public static function split() {
    require_once 'CsvHandler.php';

    self::init();

    foreach (self::$globalConfig as $key => $config) {
      $set = new CsvHandler($config, $key);
      $set->handle();
    }
  }
}


