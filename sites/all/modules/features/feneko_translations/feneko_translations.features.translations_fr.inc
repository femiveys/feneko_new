<?php
/**
 * @file
 * feneko_translations.features.translations_fr.inc
 */

/**
 * Implements hook_translations_fr_defaults().
 */
function feneko_translations_translations_fr_defaults() {
  $translations = array();
  $translatables = array();
  $translations['fr:default']['09bc5f9df1cb5ea352fb427ef7a8080a'] = array(
    'source' => 'Plaats bestelling',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Placer la commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Plaats bestelling', array(), array('context' => ''));
  $translations['fr:default']['10b9486648b56ba44ab65c59df05dde5'] = array(
    'source' => 'Borstelprofiel VP1200',
    'context' => '',
    'location' => '/nl/vliegenraam-basic/bestel',
    'translation' => 'Profil de Brosse VP1200',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Borstelprofiel VP1200', array(), array('context' => ''));
  $translations['fr:default']['1c5a2314986393f826e7b3cb308731ae'] = array(
    'source' => 'Bereken korting',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Calculer la remise',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bereken korting', array(), array('context' => ''));
  $translations['fr:default']['2b05b5c27bba6e3b572e41fc7100e765'] = array(
    'source' => 'Opgepast! Meerprijs.',
    'context' => '',
    'location' => '/nl/cart/init?destination=node/426',
    'translation' => 'Attention! Frais supplémentaires.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Opgepast! Meerprijs.', array(), array('context' => ''));
  $translations['fr:default']['6e419ce654124356fd3bd39fb144557a'] = array(
    'source' => 'Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.',
    'context' => '',
    'location' => '/nl/forms/form13',
    'translation' => 'La largeur du panneau de la porte moustiquaire coulissante.<br />Hauteur de la porte moustiquaire coulissante, rails inclus.<br />Longueurs des rails.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.', array(), array('context' => ''));
  $translations['fr:default']['7177fee9c196a572b9e3e1787336ee47'] = array(
    'source' => 'Standaardprofiel',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Profil standard',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Standaardprofiel', array(), array('context' => ''));
  $translations['fr:default']['8afa46be81acd3d7987f688c0bc3744b'] = array(
    'source' => 'Bereken korting (Stap 1/2)',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Calculer la remise (Étappe 1/2)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bereken korting (Stap 1/2)', array(), array('context' => ''));
  $translations['fr:default']['c11e09df1574eed40e1f075f5fdd717f'] = array(
    'source' => 'Schuifvliegendeuren Elegance+',
    'context' => '',
    'location' => '/nl/admin/feneko_screens/overview',
    'translation' => 'Porte Moustiquaire coulissante Élégance+',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Schuifvliegendeuren Elegance+', array(), array('context' => ''));
  $translations['fr:default']['f72c162cd7524cfcd8df67a5a5ed6d39'] = array(
    'source' => 'Gaatjes',
    'context' => 'field_ophanging:#allowed_values:gaatjes',
    'location' => '/nl/admin/structure/features/feneko_translations',
    'translation' => 'Trous',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes', array(), array('context' => 'field_ophanging:#allowed_values:gaatjes'));
  $translations['fr:field']['0416b5af0fe66004270bbab826dd9727'] = array(
    'source' => 'Gaatjes in rug',
    'context' => 'field_gaatjes_rug:raamtablet:label',
    'location' => 'field:field_gaatjes_rug:raamtablet:label',
    'translation' => 'Trous dans le dos',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes in rug', array(), array('context' => 'field_gaatjes_rug:raamtablet:label'));
  $translations['fr:field']['5fb78386d474916f06fce099e170a82a'] = array(
    'source' => 'Bestelling',
    'context' => 'field_order_type:#allowed_values:order',
    'location' => 'field:field_order_type:#allowed_values:order',
    'translation' => 'Commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bestelling', array(), array('context' => 'field_order_type:#allowed_values:order'));
  $translations['fr:field']['affb9247a339b7a31f3680f2ea1e6a82'] = array(
    'source' => 'Haakjes',
    'context' => 'field_ophanging:#allowed_values:haakjes',
    'location' => 'field:field_ophanging:#allowed_values:haakjes',
    'translation' => 'Crochets',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Haakjes', array(), array('context' => 'field_ophanging:#allowed_values:haakjes'));
  $translations['fr:field']['ca6b5213eae4d8d0d4cd96dda1d4ed58'] = array(
    'source' => 'Z-profiel',
    'context' => 'field_standaardprofiel_type:#allowed_values:Z',
    'location' => 'field:field_standaardprofiel_type:#allowed_values:Z',
    'translation' => 'Profil-Z',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Z-profiel', array(), array('context' => 'field_standaardprofiel_type:#allowed_values:Z'));
  $translations['fr:field']['dec81d11cc6b2d233141e79ddd671bb9'] = array(
    'source' => 'Offerte',
    'context' => 'field_order_type:#allowed_values:offer',
    'location' => 'field:field_order_type:#allowed_values:offer',
    'translation' => 'Offre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Offerte', array(), array('context' => 'field_order_type:#allowed_values:offer'));
  $translations['fr:field']['f47812f22bf86412bafc09c6bcbd4589'] = array(
    'source' => 'U-profiel',
    'context' => 'field_standaardprofiel_type:#allowed_values:U',
    'location' => 'field:field_standaardprofiel_type:#allowed_values:U',
    'translation' => 'Profil-U',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('U-profiel', array(), array('context' => 'field_standaardprofiel_type:#allowed_values:U'));
  $translations['fr:field']['f72c162cd7524cfcd8df67a5a5ed6d39'] = array(
    'source' => 'Gaatjes',
    'context' => 'field_ophanging:#allowed_values:gaatjes',
    'location' => 'field:field_ophanging:#allowed_values:gaatjes',
    'translation' => 'Trous',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes', array(), array('context' => 'field_ophanging:#allowed_values:gaatjes'));
  return $translations;
}
