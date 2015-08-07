<li class="<?php print $classes; ?> node-teaser teaser"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <h2 <?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h2>
  <?php print render($title_suffix); ?>
  <p class="search-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
  <a class="more-link" href="<?php print $url; ?>"><?php print t('Read more'); ?></a>
</li>
