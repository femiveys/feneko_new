<?php
/*
function samurai_preprocess_page(&$variables) {
}
*/

function samurai_preprocess_html(&$vars) {
	//unset ($vars['classes_array']);
}

function samurai_preprocess_node(&$variables) {

  $variables['submitted'] = format_date($variables['node']->created, 'custom', 'd F Y');

}

/**
 * Implements hook_html_head_alter().
 * This will overwrite the default meta character type tag with HTML5 version.
 */
function samurai_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

// change calendar heading to month / year
function samurai_date_nav_title($params) {
$granularity = $params['granularity'];
$view = $params['view'];
$date_info = $view->date_info;
$link = !empty($params['link']) ? $params['link'] : FALSE;
$format = !empty($params['format']) ? $params['format'] : NULL;
switch ($granularity) {
case 'year':
$title = $date_info->year;
$date_arg = $date_info->year;
break;
case 'month':
$format = !empty($format) ? $format : (empty($date_info->mini) ? 'F Y' : 'F Y');
$title = date_format_date($date_info->min_date, 'custom', $format);
$date_arg = $date_info->year .'-'. date_pad($date_info->month);
break;
case 'day':
$format = !empty($format) ? $format : (empty($date_info->mini) ? 'l, F j Y' : 'l, F j');
$title = date_format_date($date_info->min_date, 'custom', $format);
$date_arg = $date_info->year .'-'. date_pad($date_info->month) .'-'. date_pad($date_info->day);
break;
case 'week':
$format = !empty($format) ? $format : (empty($date_info->mini) ? 'F j Y' : 'F j');
$title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
$date_arg = $date_info->year .'-W'. date_pad($date_info->week);
break;
}
if (!empty($date_info->mini) || $link) {
// Month navigation titles are used as links in the mini view.
$attributes = array('title' => t('View full page month'));
$url = date_pager_url($view, $granularity, $date_arg, TRUE);
return l($title, $url, array('attributes' => $attributes));
}
else {
return $title;
}
}