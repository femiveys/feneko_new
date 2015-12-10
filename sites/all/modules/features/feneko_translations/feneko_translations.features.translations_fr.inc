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
  $translations['fr:commerce']['dfe1d9859438d87edcb3bcf0944973fd'] = array(
    'source' => '<p>Je bestellingsnummer is: [commerce-order:order-number].</p>
<p>Je kan je <a href="[commerce-order:url]">bestelling bekijken</a> op je profiel.</p>
<p><a href="/cart/init">Bestel iets anders</a></p>',
    'context' => 'checkout:complete:message',
    'location' => 'commerce:checkout:complete:message',
    'translation' => '<p>Ton numéro de ordre est : [commerce-order:order-number].</p><p>Vous pouvez regarder vorte commande sur: <a href="/user/[commerce-order:uid]/feneko_orders">Ordres en cours</a> sur ton profil.</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p>Je bestellingsnummer is: [commerce-order:order-number].</p>
<p>Je kan je <a href="[commerce-order:url]">bestelling bekijken</a> op je profiel.</p>
<p><a href="/cart/init">Bestel iets anders</a></p>', array(), array('context' => 'checkout:complete:message'));
  $translations['fr:default']['09bc5f9df1cb5ea352fb427ef7a8080a'] = array(
    'source' => 'Plaats bestelling',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Placer la commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Plaats bestelling', array(), array('context' => ''));
  $translations['fr:default']['0b080119cbf1138edfa9132471e1a661'] = array(
    'source' => 'tot',
    'context' => '',
    'location' => '/nl/user/1/feneko_orders',
    'translation' => 'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('tot', array(), array('context' => ''));
  $translations['fr:default']['10b9486648b56ba44ab65c59df05dde5'] = array(
    'source' => 'Borstelprofiel VP1200',
    'context' => '',
    'location' => '/nl/vliegenraam-basic/bestel',
    'translation' => 'Profil de Brosse VP1200',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Borstelprofiel VP1200', array(), array('context' => ''));
  $translations['fr:default']['1be4d5724335ae5b04677832fd631e9a'] = array(
    'source' => 'Solliciteren tot (alle talen)',
    'context' => '',
    'location' => '/nl/node/205/edit/nl',
    'translation' => 'Solliciter jusqu\'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Solliciteren tot (alle talen)', array(), array('context' => ''));
  $translations['fr:default']['1c5a2314986393f826e7b3cb308731ae'] = array(
    'source' => 'Bereken korting',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Calculer la remise',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bereken korting', array(), array('context' => ''));
  $translations['fr:default']['1d03e968c40b69c6e88fefbe5833f517'] = array(
    'source' => 'Leverdatum',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Date de livraison',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Leverdatum', array(), array('context' => ''));
  $translations['fr:default']['1de4d5dfa38d97e77ebb3401582c49c6'] = array(
    'source' => 'Solliciteren tot',
    'context' => '',
    'location' => '/node/28/edit',
    'translation' => 'Solliciter jusqu\'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Solliciteren tot', array(), array('context' => ''));
  $translations['fr:default']['255259401ffd7c45547fc30a4ba29072'] = array(
    'source' => 'Verkoopsvoorwaarden',
    'context' => '',
    'location' => '/nl/admin/structure/views/ajax/add-item/about/page_3/field',
    'translation' => 'Conditions de vente',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verkoopsvoorwaarden', array(), array('context' => ''));
  $translations['fr:default']['25e3ae7384d662b1039dbd72d4cae42d'] = array(
    'source' => 'Klantennummer',
    'context' => 'field_klantennummer:user:label',
    'location' => '/nl/admin/structure/features/feneko_translations/status',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer', array(), array('context' => 'field_klantennummer:user:label'));
  $translations['fr:default']['2b05b5c27bba6e3b572e41fc7100e765'] = array(
    'source' => 'Opgepast! Meerprijs.',
    'context' => '',
    'location' => '/nl/cart/init?destination=node/426',
    'translation' => 'Attention! Frais supplémentaires.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Opgepast! Meerprijs.', array(), array('context' => ''));
  $translations['fr:default']['2d709a3eeddf7d0b6785b6c2547d3b97'] = array(
    'source' => 'Het midden van de tussenstijl (VP1005) komt op 917mm.<br />
                   Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                   Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.',
    'context' => '',
    'location' => '/nl/admin/feneko_screens/overview',
    'translation' => 'Le milieu de la traverse (VP1005) se trouve à 917mm.<br />
Si vous voulez la traverse sur une autre hauteur, vous remplissez le T1.<br />
Si vous voulez plusieurs traverses vous remplissez le T1,T2,T3.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Het midden van de tussenstijl (VP1005) komt op 917mm.<br />
                   Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                   Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.', array(), array('context' => ''));
  $translations['fr:default']['2da091108abf54b72117e0b07776002c'] = array(
    'source' => 'Onze producten',
    'context' => '',
    'location' => '/admin/structure/views/add',
    'translation' => 'Nos produits',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Onze producten', array(), array('context' => ''));
  $translations['fr:default']['33be3953588cc10edb3d6341919109b9'] = array(
    'source' => 'Order specific information',
    'context' => '',
    'location' => '/nl/admin/structure/features/feneko_calculator_feature/recreate?render=overlay',
    'translation' => 'Information spécifique à l ordre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Order specific information', array(), array('context' => ''));
  $translations['fr:default']['45acd6ac4b264cef2bccfdc5a5e048d1'] = array(
    'source' => 'Klant worden',
    'context' => '',
    'location' => '/nl/admin/structure/views/view/about/edit/page_2',
    'translation' => 'Devenir client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klant worden', array(), array('context' => ''));
  $translations['fr:default']['4a5e958b96161cfb039c482bf8923172'] = array(
    'source' => 'Motivatie',
    'context' => '',
    'location' => '/nl/admin/structure/features',
    'translation' => 'Motivation',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Motivatie', array(), array('context' => ''));
  $translations['fr:default']['4c5c21ffe644c221c6ff6b508587a4da'] = array(
    'source' => 'Lopende orders',
    'context' => '',
    'location' => '/user',
    'translation' => 'Commandes en cours',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Lopende orders', array(), array('context' => ''));
  $translations['fr:default']['4da26939619ccf77cae38bebef10e168'] = array(
    'source' => 'Al onze leveringen gebeuren tussen de 8 en 12 werkdagen.',
    'context' => '',
    'location' => '/fr/fa%C3%A7onnage/fa%C3%A7onnage',
    'translation' => 'Toutes nos livraisons se produisent entre 8 et 12 jours de travail.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Al onze leveringen gebeuren tussen de 8 en 12 werkdagen.', array(), array('context' => ''));
  $translations['fr:default']['648930cf62ba900667f41bd903a76a21'] = array(
    'source' => 'Solliciteren tot (toutes les langues)',
    'context' => '',
    'location' => '/fr/node/205/edit/add/nl/fr',
    'translation' => 'Solliciter jusqu\'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Solliciteren tot (toutes les langues)', array(), array('context' => ''));
  $translations['fr:default']['68125a15512031e938b712b5e3578034'] = array(
    'source' => 'Wij zoeken',
    'context' => '',
    'location' => '/nl/admin/structure/features',
    'translation' => 'Nous cherchons',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Wij zoeken', array(), array('context' => ''));
  $translations['fr:default']['6b0002988bab985c49e64959cd3f39d3'] = array(
    'source' => 'Kleur',
    'context' => 'field_color:commerce_order:label',
    'location' => '/nl/admin/structure/features/feneko_translations/status',
    'translation' => 'Couleur',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Kleur', array(), array('context' => 'field_color:commerce_order:label'));
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
  $translations['fr:default']['72eacb1fb5db6c9ae0f752fae1f3c7a1'] = array(
    'source' => 'Wij bieden',
    'context' => '',
    'location' => '/nl/admin/structure/features',
    'translation' => 'Nous offrons',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Wij bieden', array(), array('context' => ''));
  $translations['fr:default']['7d95fc465930fd6c2a668c6e0b41538d'] = array(
    'source' => 'Winkelwagen',
    'context' => '',
    'location' => '/nl/admin/structure/features?render=overlay&render=overlay',
    'translation' => 'Panier',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Winkelwagen', array(), array('context' => ''));
  $translations['fr:default']['7fb4910b2b2641a6da46bf06921a2085'] = array(
    'source' => 'Er zijn geen bestellingen in behandeling.',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Il n\'y a pas d\'ordres en cours',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Er zijn geen bestellingen in behandeling.', array(), array('context' => ''));
  $translations['fr:default']['816a78c8472f3f298a3a7bdf8d8013f2'] = array(
    'source' => 'Besteldatum',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Date d\'ordre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Besteldatum', array(), array('context' => ''));
  $translations['fr:default']['829f411f0f40a5fb68410a4dedd9e218'] = array(
    'source' => 'Catalogus',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Catalogue',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Catalogus', array(), array('context' => ''));
  $translations['fr:default']['88312199623a59a893fa2c0f5fb4a4af'] = array(
    'source' => 'Andere jobs',
    'context' => '',
    'location' => '/fr/jobs/test-vacature-fr-0',
    'translation' => 'Autres jobs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Andere jobs', array(), array('context' => ''));
  $translations['fr:default']['8abd91ae2854199b2c9be6794ef20b47'] = array(
    'source' => 'opmerking',
    'context' => '',
    'location' => '/forms/aliases',
    'translation' => 'remarque',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('opmerking', array(), array('context' => ''));
  $translations['fr:default']['8afa46be81acd3d7987f688c0bc3744b'] = array(
    'source' => 'Bereken korting (Stap 1/2)',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Calculer la remise (Étappe 1/2)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bereken korting (Stap 1/2)', array(), array('context' => ''));
  $translations['fr:default']['8c15478bbc2b63d85e1bea08d0b98942'] = array(
    'source' => 'standaard T',
    'context' => '',
    'location' => '/forms/aliases',
    'translation' => 'T standard',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('standaard T', array(), array('context' => ''));
  $translations['fr:default']['957d2fa52c19a5aff4ccf5d9a959adab'] = array(
    'source' => 'van',
    'context' => '',
    'location' => '/nl/user/1/feneko_orders',
    'translation' => 'de',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('van', array(), array('context' => ''));
  $translations['fr:default']['9b7ad10324fd47a162b262a78d285f1a'] = array(
    'source' => 'Er zijn op dit ogenblik gaan nieuwsberichten.',
    'context' => '',
    'location' => '/nl/admin/structure/features/feneko_views',
    'translation' => 'Il n\'y a pas de nouvelles maintenant.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Er zijn op dit ogenblik gaan nieuwsberichten.', array(), array('context' => ''));
  $translations['fr:default']['9e35cea985142d1f600543586e2e8ede'] = array(
    'source' => 'Klantennummers',
    'context' => '',
    'location' => '/nl/admin/structure/features',
    'translation' => 'Numéros de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummers', array(), array('context' => ''));
  $translations['fr:default']['a9a39524393245a842a5d6694f22ee6f'] = array(
    'source' => 'Leverconditie',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Condition de livraison',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Leverconditie', array(), array('context' => ''));
  $translations['fr:default']['c11e09df1574eed40e1f075f5fdd717f'] = array(
    'source' => 'Schuifvliegendeuren Elegance+',
    'context' => '',
    'location' => '/nl/admin/feneko_screens/overview',
    'translation' => 'Porte Moustiquaire coulissante Élégance+',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Schuifvliegendeuren Elegance+', array(), array('context' => ''));
  $translations['fr:default']['c5ea47e90c480be70ab8fce6259581ac'] = array(
    'source' => 'Klantennummer (field_klantennummer)',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer (field_klantennummer)', array(), array('context' => ''));
  $translations['fr:default']['c7c45e4d869a1a2dc18052a7555b6044'] = array(
    'source' => 'bestel',
    'context' => '',
    'location' => '/nl/schuif-vliegendeuren/vliegendeur-basic',
    'translation' => 'commandez',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('bestel', array(), array('context' => ''));
  $translations['fr:default']['c981adbb277d46d8e3ed26497b7ee096'] = array(
    'source' => 'Klantennummer',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer', array(), array('context' => ''));
  $translations['fr:default']['d4d537cf9231306d75c5d2aba0c22b00'] = array(
    'source' => 'Bedrag',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Montant',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bedrag', array(), array('context' => ''));
  $translations['fr:default']['dd8ace8df7e819fa3a8be48135c50107'] = array(
    'source' => 'Levertijden',
    'context' => '',
    'location' => '/nl/admin/structure/views/view/about/edit/page',
    'translation' => 'Délai de livraison',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Levertijden', array(), array('context' => ''));
  $translations['fr:default']['dea5d1f08521fb3b04397afb1852595b'] = array(
    'source' => 'Kleur',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Couleur',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Kleur', array(), array('context' => ''));
  $translations['fr:default']['e2ee5db3726b7f8f02b1b5c3a782874c'] = array(
    'source' => 'Tekens die in de referentie voorkomen',
    'context' => '',
    'location' => '/nl/user/1/feneko_orders',
    'translation' => 'Caractères dans la référence',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tekens die in de referentie voorkomen', array(), array('context' => ''));
  $translations['fr:default']['e5d49efb309c6145571b8e05c7428e68'] = array(
    'source' => 'Orderdatum',
    'context' => '',
    'location' => '/nl/user/124/feneko_screens_orders',
    'translation' => 'Date de commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Orderdatum', array(), array('context' => ''));
  $translations['fr:default']['e927095211969d0db2e3d18e154c1be7'] = array(
    'source' => 'aantal',
    'context' => '',
    'location' => 'forms/FenekoForm.php:527',
    'translation' => 'nombre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('aantal', array(), array('context' => ''));
  $translations['fr:default']['ea22a9e38ce6daabf42557163ec3f009'] = array(
    'source' => 'Naam',
    'context' => '',
    'location' => '/admin/structure/types/add',
    'translation' => 'Nom',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Naam', array(), array('context' => ''));
  $translations['fr:default']['ed36982788a88ca96078aaeb959f9c29'] = array(
    'source' => 'Screens bestellingen',
    'context' => '',
    'location' => '/nl/user/1',
    'translation' => 'Commandes screens',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Screens bestellingen', array(), array('context' => ''));
  $translations['fr:default']['f72c162cd7524cfcd8df67a5a5ed6d39'] = array(
    'source' => 'Gaatjes',
    'context' => 'field_ophanging:#allowed_values:gaatjes',
    'location' => '/nl/admin/structure/features/feneko_translations',
    'translation' => 'Trous',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes', array(), array('context' => 'field_ophanging:#allowed_values:gaatjes'));
  $translations['fr:default']['fede12f3430e83eb76f5176e64edf810'] = array(
    'source' => 'Gewenste functie',
    'context' => '',
    'location' => '/nl/admin/structure/features',
    'translation' => 'Fonction désirée',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gewenste functie', array(), array('context' => ''));
  $translations['fr:field']['0416b5af0fe66004270bbab826dd9727'] = array(
    'source' => 'Gaatjes in rug',
    'context' => 'field_gaatjes_rug:raamtablet:label',
    'location' => 'field:field_gaatjes_rug:raamtablet:label',
    'translation' => 'Trous dans le dos',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes in rug', array(), array('context' => 'field_gaatjes_rug:raamtablet:label'));
  $translations['fr:field']['09e27c799cd764b5939e2afd600b5bd1'] = array(
    'source' => 'Muurkap Diepte',
    'context' => 'field_muurkap_diepte:muurkap_eindstuk:label',
    'location' => 'field:field_muurkap_diepte:muurkap_eindstuk:label',
    'translation' => 'Profondeur couvre murs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Muurkap Diepte', array(), array('context' => 'field_muurkap_diepte:muurkap_eindstuk:label'));
  $translations['fr:field']['1b7053d1a7aed95068eedebb63a0e807'] = array(
    'source' => 'Ja',
    'context' => 'field_gaatjes_rug:#allowed_values:1',
    'location' => 'field:field_gaatjes_rug:#allowed_values:1',
    'translation' => 'Oui',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Ja', array(), array('context' => 'field_gaatjes_rug:#allowed_values:1'));
  $translations['fr:field']['1c54a6a124fad27d45e37ae53801218a'] = array(
    'source' => 'Naam',
    'context' => 'field_naam:contact:label',
    'location' => 'field:field_naam:contact:label',
    'translation' => 'Nom',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Naam', array(), array('context' => 'field_naam:contact:label'));
  $translations['fr:field']['22f5160682267b7851449c43593a07b7'] = array(
    'source' => 'Wij bieden',
    'context' => 'field_offering:vacature:label',
    'location' => 'field:field_offering:vacature:label',
    'translation' => 'Nous offrons',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Wij bieden', array(), array('context' => 'field_offering:vacature:label'));
  $translations['fr:field']['29c0cc0dfb633f65e7acba27cd329924'] = array(
    'source' => 'Muurkap Type',
    'context' => 'field_muurkap_type:muurkap_eindstuk:label',
    'location' => 'field:field_muurkap_type:muurkap_eindstuk:label',
    'translation' => 'Type de couvre murs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Muurkap Type', array(), array('context' => 'field_muurkap_type:muurkap_eindstuk:label'));
  $translations['fr:field']['2edbc23e387b743c32b68e7a81d83319'] = array(
    'source' => 'Uw vraag',
    'context' => 'field_uw_vraag:contact:label',
    'location' => 'field:field_uw_vraag:contact:label',
    'translation' => 'Votre question',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Uw vraag', array(), array('context' => 'field_uw_vraag:contact:label'));
  $translations['fr:field']['4faa6cf618e5f66d7026464eca31367a'] = array(
    'source' => 'Muurkap Type',
    'context' => 'field_muurkap_type:muurkap_eindstuk:attribute_widget_title',
    'location' => 'field:field_muurkap_type:muurkap_eindstuk:attribute_widget_title',
    'translation' => 'Type de couvre murs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Muurkap Type', array(), array('context' => 'field_muurkap_type:muurkap_eindstuk:attribute_widget_title'));
  $translations['fr:field']['5fb78386d474916f06fce099e170a82a'] = array(
    'source' => 'Bestelling',
    'context' => 'field_order_type:#allowed_values:order',
    'location' => 'field:field_order_type:#allowed_values:order',
    'translation' => 'Commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bestelling', array(), array('context' => 'field_order_type:#allowed_values:order'));
  $translations['fr:field']['61fd7f6c15ea2d8ad3298259ad90d226'] = array(
    'source' => 'Verkoopsvoorwaarden',
    'context' => 'field_verkoopsvoorwaarden:info_pagina:label',
    'location' => 'field:field_verkoopsvoorwaarden:info_pagina:label',
    'translation' => 'Conditions de vente',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verkoopsvoorwaarden', array(), array('context' => 'field_verkoopsvoorwaarden:info_pagina:label'));
  $translations['fr:field']['667d5390b792b72a634adf0215ae9045'] = array(
    'source' => 'Klantennummers',
    'context' => 'field_klantennummer:user:label',
    'location' => 'field:field_klantennummer:user:label',
    'translation' => 'Numéros de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummers', array(), array('context' => 'field_klantennummer:user:label'));
  $translations['fr:field']['6d1dbe4b85ebf9588816fdd06fa2eb84'] = array(
    'source' => 'Wij zoeken',
    'context' => 'field_wanted:vacature:label',
    'location' => 'field:field_wanted:vacature:label',
    'translation' => 'Nous cherchons',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Wij zoeken', array(), array('context' => 'field_wanted:vacature:label'));
  $translations['fr:field']['7638e76aa3ef72e5eb24df23560150a8'] = array(
    'source' => 'Nee',
    'context' => 'field_geblokkeerd:#allowed_values:0',
    'location' => 'field:field_geblokkeerd:#allowed_values:0',
    'translation' => 'Non',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Nee', array(), array('context' => 'field_geblokkeerd:#allowed_values:0'));
  $translations['fr:field']['7f81cd380c0deb5e984398a3bf646fcc'] = array(
    'source' => 'Solliciteren tot',
    'context' => 'field_ultimate_date:vacature:label',
    'location' => 'field:field_ultimate_date:vacature:label',
    'translation' => 'Solliciter jusqu\'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Solliciteren tot', array(), array('context' => 'field_ultimate_date:vacature:label'));
  $translations['fr:field']['81730bea484e5b05f2ccd84c3d97ed5f'] = array(
    'source' => 'Naam',
    'context' => 'field_naam:solliciteer:label',
    'location' => 'field:field_naam:solliciteer:label',
    'translation' => 'Nom',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Naam', array(), array('context' => 'field_naam:solliciteer:label'));
  $translations['fr:field']['9f7c2619b73ab3fae7fd366260639126'] = array(
    'source' => 'Nee',
    'context' => 'field_gaatjes_rug:#allowed_values:0',
    'location' => 'field:field_gaatjes_rug:#allowed_values:0',
    'translation' => 'Non',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Nee', array(), array('context' => 'field_gaatjes_rug:#allowed_values:0'));
  $translations['fr:field']['affb9247a339b7a31f3680f2ea1e6a82'] = array(
    'source' => 'Haakjes',
    'context' => 'field_ophanging:#allowed_values:haakjes',
    'location' => 'field:field_ophanging:#allowed_values:haakjes',
    'translation' => 'Crochets',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Haakjes', array(), array('context' => 'field_ophanging:#allowed_values:haakjes'));
  $translations['fr:field']['ba7257ef766f897aafbd4a7ae0901112'] = array(
    'source' => 'Gewenste functie',
    'context' => 'field_gewenste_functie:solliciteer:label',
    'location' => 'field:field_gewenste_functie:solliciteer:label',
    'translation' => 'Fonction désirée',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gewenste functie', array(), array('context' => 'field_gewenste_functie:solliciteer:label'));
  $translations['fr:field']['c48d24e60835b807834d575ab9046a32'] = array(
    'source' => 'Ja',
    'context' => 'field_geblokkeerd:#allowed_values:1',
    'location' => 'field:field_geblokkeerd:#allowed_values:1',
    'translation' => 'Oui',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Ja', array(), array('context' => 'field_geblokkeerd:#allowed_values:1'));
  $translations['fr:field']['ca6b5213eae4d8d0d4cd96dda1d4ed58'] = array(
    'source' => 'Z-profiel',
    'context' => 'field_standaardprofiel_type:#allowed_values:Z',
    'location' => 'field:field_standaardprofiel_type:#allowed_values:Z',
    'translation' => 'Profil-Z',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Z-profiel', array(), array('context' => 'field_standaardprofiel_type:#allowed_values:Z'));
  $translations['fr:field']['dd3fa585ccfc13c237705e5d7d15a4ae'] = array(
    'source' => 'Beugel',
    'context' => 'field_mke_type:#allowed_values:Beugel',
    'location' => 'field:field_mke_type:#allowed_values:Beugel',
    'translation' => 'Pièce de montage',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Beugel', array(), array('context' => 'field_mke_type:#allowed_values:Beugel'));
  $translations['fr:field']['de6f960f856781a2ba5fd67f65e0dbac'] = array(
    'source' => 'Muurkap Type',
    'context' => 'field_muurkap_type:muurkap:label',
    'location' => 'field:field_muurkap_type:muurkap:label',
    'translation' => 'Type de couvre murs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Muurkap Type', array(), array('context' => 'field_muurkap_type:muurkap:label'));
  $translations['fr:field']['dec81d11cc6b2d233141e79ddd671bb9'] = array(
    'source' => 'Offerte',
    'context' => 'field_order_type:#allowed_values:offer',
    'location' => 'field:field_order_type:#allowed_values:offer',
    'translation' => 'Offre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Offerte', array(), array('context' => 'field_order_type:#allowed_values:offer'));
  $translations['fr:field']['e5d842ed6aee41e86c9ed8ffcdfd4553'] = array(
    'source' => 'Motivatie',
    'context' => 'field_motivatie:solliciteer:label',
    'location' => 'field:field_motivatie:solliciteer:label',
    'translation' => 'Motivation',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Motivatie', array(), array('context' => 'field_motivatie:solliciteer:label'));
  $translations['fr:field']['eceb4edec30124b435533645a28362f2'] = array(
    'source' => 'Muurkap Diepte',
    'context' => 'field_muurkap_diepte:muurkap_eindstuk:attribute_widget_title',
    'location' => 'field:field_muurkap_diepte:muurkap_eindstuk:attribute_widget_title',
    'translation' => 'Profondeur couvre murs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Muurkap Diepte', array(), array('context' => 'field_muurkap_diepte:muurkap_eindstuk:attribute_widget_title'));
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
  $translations['fr:node']['fb7dd62d2d4e3577bcd83d120a54581b'] = array(
    'source' => 'Naam',
    'context' => 'type:product:title_label',
    'location' => 'node:type:product:title_label',
    'translation' => 'Nom',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Naam', array(), array('context' => 'type:product:title_label'));
  $translations['fr:views']['1ea22b368209f831ec13e75bbbd3ffca'] = array(
    'source' => 'Solliciteren tot',
    'context' => 'jobs:default:field:field_data_field_ultimate_date:field_ultimate_date:label',
    'location' => 'views:jobs:default:field:field_data_field_ultimate_date:field_ultimate_date:label',
    'translation' => 'Solliciter jusqu\'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Solliciteren tot', array(), array('context' => 'jobs:default:field:field_data_field_ultimate_date:field_ultimate_date:label'));
  $translations['fr:views']['203698dac95c31a51a98afcb9d39217c'] = array(
    'source' => 'Er zijn op dit ogenblik geen openstaande vacatures.',
    'context' => 'jobs:default:empty:views:area:content',
    'location' => 'views:jobs:default:empty:views:area:content',
    'translation' => 'Il n\'y a pas de vacatures pour le moment.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Er zijn op dit ogenblik geen openstaande vacatures.', array(), array('context' => 'jobs:default:empty:views:area:content'));
  $translations['fr:views']['24195f44641bdddee7127bb55792ad7f'] = array(
    'source' => 'Gerelateerde producten',
    'context' => 'related:default:title',
    'location' => 'views:related:default:title',
    'translation' => 'Produits liées',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gerelateerde producten', array(), array('context' => 'related:default:title'));
  $translations['fr:views']['36ffc637509316482326c4054f2aa88d'] = array(
    'source' => 'Over FenekO',
    'context' => 'about:default:title',
    'location' => 'views:about:default:title',
    'translation' => ' À propos de FenekO',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Over FenekO', array(), array('context' => 'about:default:title'));
  $translations['fr:views']['43504b2d151f64c579850b3076c32555'] = array(
    'source' => 'Verkoopsvoorwaarden',
    'context' => 'about:page_3:title',
    'location' => 'views:about:page_3:title',
    'translation' => 'Conditions de vente',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verkoopsvoorwaarden', array(), array('context' => 'about:page_3:title'));
  $translations['fr:views']['4ce94f61c3ed56dfd9262f83dcfb246b'] = array(
    'source' => 'Meer lezen',
    'context' => 'nieuws:default:field:views_entity_node:view_node:text',
    'location' => 'views:nieuws:default:field:views_entity_node:view_node:text',
    'translation' => 'Lire la suite',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Meer lezen', array(), array('context' => 'nieuws:default:field:views_entity_node:view_node:text'));
  $translations['fr:views']['51708dcec6cc3b605d77ca276f39824b'] = array(
    'source' => 'Meer lezen',
    'context' => 'jobs:default:field:views_entity_node:view_node:text',
    'location' => 'views:jobs:default:field:views_entity_node:view_node:text',
    'translation' => 'Lire la suite',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Meer lezen', array(), array('context' => 'jobs:default:field:views_entity_node:view_node:text'));
  $translations['fr:views']['5de9a64cf1702e844a29f4ed5d8f6cea'] = array(
    'source' => 'Nieuws',
    'context' => 'nieuws:default:title',
    'location' => 'views:nieuws:default:title',
    'translation' => 'Nouvelles',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Nieuws', array(), array('context' => 'nieuws:default:title'));
  $translations['fr:views']['637531ffc5b7a9c4f23d98e80f48cf30'] = array(
    'source' => 'Onze producten',
    'context' => 'main_categories:default:title',
    'location' => 'views:main_categories:default:title',
    'translation' => 'Nos produits',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Onze producten', array(), array('context' => 'main_categories:default:title'));
  $translations['fr:views']['83341be8545fbd9bbcc65100100b9faa'] = array(
    'source' => 'Winkelwagen',
    'context' => 'commerce_cart_form_feneko:default:title',
    'location' => 'views:commerce_cart_form_feneko:default:title',
    'translation' => 'Panier',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Winkelwagen', array(), array('context' => 'commerce_cart_form_feneko:default:title'));
  $translations['fr:views']['89aed2265d57cd92921c62dff7bfe607'] = array(
    'source' => 'Er zijn op dit ogenblik gaan nieuwsberichten.',
    'context' => 'nieuws:default:empty:views:area:content',
    'location' => 'views:nieuws:default:empty:views:area:content',
    'translation' => 'Il n\'y a pas de nouvelles maintenant.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Er zijn op dit ogenblik gaan nieuwsberichten.', array(), array('context' => 'nieuws:default:empty:views:area:content'));
  $translations['fr:views']['a461cc755107ba2c96b6b636c3ec8116'] = array(
    'source' => 'Klant worden',
    'context' => 'about:page_2:title',
    'location' => 'views:about:page_2:title',
    'translation' => 'Devenir client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klant worden', array(), array('context' => 'about:page_2:title'));
  $translations['fr:views']['b98b6800cf191eea3f76cee072c94d47'] = array(
    'source' => 'Naam',
    'context' => 'commerce_orders:default:field:field_data_commerce_customer_address:commerce_customer_address:label',
    'location' => 'views:commerce_orders:default:field:field_data_commerce_customer_address:commerce_customer_address:label',
    'translation' => 'Nom',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Naam', array(), array('context' => 'commerce_orders:default:field:field_data_commerce_customer_address:commerce_customer_address:label'));
  $translations['fr:views']['ddfa5e952149a2889dc5f008c5da9dcb'] = array(
    'source' => 'Levertijden',
    'context' => 'about:page_1:title',
    'location' => 'views:about:page_1:title',
    'translation' => 'Délai de livraison',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Levertijden', array(), array('context' => 'about:page_1:title'));
  $translations['fr:views']['e4936909ce1eba923c58fdd892a0b1dd'] = array(
    'source' => 'Andere jobs',
    'context' => 'jobs:block_1:title',
    'location' => 'views:jobs:block_1:title',
    'translation' => 'Autres jobs',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Andere jobs', array(), array('context' => 'jobs:block_1:title'));
  return $translations;
}
