<?php if ($search_results): ?>
  <ul class="search-results">
    <?php print $search_results; ?>
  </ul>
  <?php print $pager; ?>
<?php else : ?>
  <p><?php print t('Your search yielded no results');?></p>
  <?php print search_help('search#noresults', drupal_help_arg()); ?>
<?php endif; ?>
