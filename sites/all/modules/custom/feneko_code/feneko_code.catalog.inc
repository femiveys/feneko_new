<?php

function feneko_catalog($type, $format) {
  global $language;

  $lang = $language->language;

  switch($format) {
    case 'pdf':
      return feneko_catalog_pdf($type . "_" . $lang . ".pdf");
    case 'flipper':
      return feneko_catalog_flipper("$type/$lang");
  }
}

function feneko_catalog_flipper($flip_url) {
  echo feneko_catalog_flipper_html($flip_url);
  drupal_exit();
}

function feneko_catalog_pdf($filename) {
  $file = "public://pdfs/$filename";
  if (file_exists($file)) {
    header('Content-type: application/pdf');
    header('Content-Disposition: inline; filename="' . $filename . '"');
    header('Content-Transfer-Encoding: binary');
    header('Content-Length: ' . filesize($file));
    header('Accept-Ranges: bytes');
    @readfile($file);
    die();
  }
}

function feneko_catalog_flipper_html($url) {
  $general = 'public://pageflip';
  $general = file_create_url($general);
  $url = "$general/$url/";
  $mag = "$general/swf/Magazine";

  $html = "
    <html>
      <head>
        <base href=\"$url\" />
        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />
        <title>Feneko Catalogus</title>
        <meta name=\"Description\" content=\"Feneko catalogus\">
        <meta name=\"Keywords\" content=\"Feneko catalogus\">
        <script src=\"$general/js/AC_RunActiveContent.js\" type=\"text/javascript\"></script>
        <script src=\"$general/js/PopUpWin.js\" type=\"text/javascript\"></script>
        <style type=\"text/css\">
          <!--
          body {
            background-color: #ccc;
            margin-left: 0px;
            margin-top: 0px;
            margin-right: 0px;
            margin-bottom: 0px;
          }
          -->
        </style>
      </head>
      <body>
        <script type=\"text/javascript\">
          AC_FL_RunContent( 'codebase','http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8,0,0,0','width','100%','height','100%','src','$mag','quality','high','pluginspage','http://www.macromedia.com/go/getflashplayer','bgcolor','#cccccc','allowFullScreen','true','allowScriptAccess','sameDomain','movie','$mag' ); //end AC code
        </script>
        <noscript>
          <object classid=\"clsid:D27CDB6E-AE6D-11cf-96B8-444553540000\" codebase=\"http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8,0,0,0\" width=\"100%\" height=\"100%\">
            <param name=\"movie\" value=\"$mag\" />
            <param name=\"quality\" value=\"high\" />
            <param name=\"bgcolor\" value=\"#cccccc\" />
            <param name=\"allowFullScreen\" value=\"true\" />
            <param name=\"allowScriptAccess\" value=\"sameDomain\" />
            <embed src=\"$mag\" width=\"100%\" height=\"100%\" quality=\"high\" pluginspage=\"http://www.macromedia.com/go/getflashplayer\" type=\"application/x-shockwave-flash\" wmode=\"transparent\" allowFullScreen=\"true\" allowScriptAccess=\"sameDomain\"></embed>
          </object>
        </noscript>
      </body>
    </html>";

  return $html;
}
