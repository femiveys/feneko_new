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
}
