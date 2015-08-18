<?php
/**
 * @file
 * feneko_calculator_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feneko_calculator_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'commerce_cart_form_feneko';
  $view->description = 'Display a shopping cart update form.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Feneko Shopping cart';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';

  /* Display: Overview */
  $handler = $view->new_display('attachment', 'Overview', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $export['commerce_cart_form_feneko'] = $view;

  $view = new view();
  $view->name = 'feneko_calculator_line_items';
  $view->description = 'Display a set of line items in a table.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'Feneko Calculator Line items';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $export['feneko_calculator_line_items'] = $view;

  $view = new view();
  $view->name = 'feneko_orders';
  $view->description = '';
  $view->tag = 'calculator';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Feneko Orders';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $export['feneko_orders'] = $view;

  $view = new view();
  $view->name = 'feneko_shopping_cart_block';
  $view->description = 'Display a list of line items added to cart.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Feneko Shopping cart block';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $export['feneko_shopping_cart_block'] = $view;

  return $export;
}
