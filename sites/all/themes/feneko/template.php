<?php

function feneko_preprocess_pager(&$variables, $hook) {
  $variables['tags'][0] = '<<';
  $variables['tags'][1] = '<';
  $variables['tags'][3] = '>';
  $variables['tags'][4] = '>>';
}

function feneko_preprocess_node(&$variables) {
  $variables['submitted'] = format_date($variables['node']->created, 'custom', 'd F Y');
  if(($variables['type']==='product') && isset($variables['field_productcategorie']['und'][0]['tid'])) {
    $tid = $variables['field_productcategorie']['und'][0]['tid'];
    $parents = taxonomy_get_parents($tid);
    $term = array_pop($parents);
    $name = $term->name;
    $variables['product_grandparent'] = strtolower($name);
  }
}

function feneko_order_urls($node_url, $title) {
 $order = t('bestel');
 $prefixNl = '<a href="/nl/inzetvliegenraam/' . $order;
 $prefixFr = '<a href="/fr/moustiquaires-encastrée/' . $order;
 $suffix = "\">$order $title</a>";

 switch ($node_url) {
   case '/nl/inzetvliegenraam-vr033-ultra':
     $html = "$prefixNl?ultra=true";
     break;
   case '/nl/inzetvliegenraam-vr033':
     $html = "$prefixNl";
     break;
   case '/fr/moustiquaires-encastr%C3%A9e-vr033-ultra':
     $html = "$prefixFr?ultra=true";
     break;
   case '/fr/moustiquaires-encastr%C3%A9e-vr033':
     $html = "$prefixFr";
     break;
   default:
     $html = '<a href="' . $node_url . '/' . $order;
     break;
 }

 return $html . $suffix;
}
