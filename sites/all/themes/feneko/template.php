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
 $prefixNl = "/nl/inzetvliegenraam/$order";
 $prefixFr = "/fr/moustiquaires-encastrée/$order";

 switch ($node_url) {
   case '/nl/inzetvliegenraam-vr033-ultra':
     $url = "$prefixNl?ultra=true";
     break;
   case '/nl/inzetvliegenraam-vr033':
     $url = "$prefixNl";
     break;
   case '/fr/moustiquaires-encastr%C3%A9e-vr033-ultra':
     $url = "$prefixFr?ultra=true";
     break;
   case '/fr/moustiquaires-encastr%C3%A9e-vr033':
     $url = "$prefixFr";
     break;
   default:
     $url = "$node_url/$order";
     break;
 }

 return "<a href=\"$url\">$order $title</a>";
}
