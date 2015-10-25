<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <title><?php print $head_title; ?></title>
  <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">
  <?php
    print $head;
    print $styles;
    print $scripts;
  ?>
  <!--[if lt IE 9]>
    <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <script src="sites/all/themes/samurai/js/respond.min.js"></script>
  <![endif]-->
  <meta name="viewport" content="width=device-width, initial-scale=1"/>
  <meta name="HandheldFriendly" content="true" />
  <meta name="MobileOptimized" content="width" />
  <meta http-equiv="cleartype" content="on" />

  <!-- http://www.favicon-generator.org/ -->
  <link rel="apple-touch-icon" sizes="57x57" href="sites/all/themes/samurai/apple-icon-57x57.png">
  <link rel="apple-touch-icon" sizes="60x60" href="sites/all/themes/samurai/apple-icon-60x60.png">
  <link rel="apple-touch-icon" sizes="72x72" href="sites/all/themes/samurai/apple-icon-72x72.png">
  <link rel="apple-touch-icon" sizes="76x76" href="sites/all/themes/samurai/apple-icon-76x76.png">
  <link rel="apple-touch-icon" sizes="114x114" href="sites/all/themes/samurai/apple-icon-114x114.png">
  <link rel="apple-touch-icon" sizes="120x120" href="sites/all/themes/samurai/apple-icon-120x120.png">
  <link rel="apple-touch-icon" sizes="144x144" href="sites/all/themes/samurai/apple-icon-144x144.png">
  <link rel="apple-touch-icon" sizes="152x152" href="sites/all/themes/samurai/apple-icon-152x152.png">
  <link rel="apple-touch-icon" sizes="180x180" href="sites/all/themes/samurai/apple-icon-180x180.png">
  <link rel="icon" type="image/png" sizes="192x192"  href="sites/all/themes/samurai/android-icon-192x192.png">
  <link rel="icon" type="image/png" sizes="32x32" href="sites/all/themes/samurai/favicon-32x32.png">
  <link rel="icon" type="image/png" sizes="96x96" href="/sites/all/themes/samurai/favicon-96x96.png">
  <link rel="icon" type="image/png" sizes="16x16" href="sites/all/themes/samurai/favicon-16x16.png">
  <link rel="manifest" href="/manifest.json">
  <meta name="msapplication-TileColor" content="#ffffff">
  <meta name="msapplication-TileImage" content="sites/all/themes/samurai/ms-icon-144x144.png">
  <meta name="theme-color" content="#ffffff">
</head>

<body class="<?php print $classes; ?> <?php print $language->language; ?>" <?php print $attributes;?>>

<a id="skip-link" href="#main" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>

  <?php
    print $page_top;
    print $page;
    print $page_bottom;

  ?>
</body>
</html>
