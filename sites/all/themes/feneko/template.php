<?php

/*
function werkplekarchitecten_preprocess_page(&$variables) {
  dmp($variables);
}
*/
/*
function feneko_preprocess_html(&$variables) {


}


function feneko_preprocess_page(&$variables, $hook) {

}
*/


function feneko_preprocess_pager(&$variables, $hook) {
  $variables['tags'][0] = '<<';
  $variables['tags'][1] = '<';
  $variables['tags'][3] = '>';
  $variables['tags'][4] = '>>';
}

function feneko_preprocess_node(&$variables) {
  $variables['submitted'] = format_date($variables['node']->created, 'custom', 'd F Y');



  if(($variables['type']='product') && $variables['is_front']!='true') {

    $tid = $variables['field_productcategorie']['und'][0]['tid'];
    $parents = taxonomy_get_parents($tid);
    $term = array_pop($parents);
    $name = $term->name;

    $variables['product_grandparent'] = $name;

    dpm($parents);
    dpm($term);
    dpm($name);
  }


}
