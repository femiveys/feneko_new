  <?php if ($logo): ?>
    <a class="logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
      <img src="<?php print $logo; ?>" class="big" alt="<?php print t('Home'); ?>" />
    </a>
  <?php endif; ?>

   <?php if ($site_name): ?>
    <h1 id="site-name">
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
    </h1>
  <?php endif; ?>

   <?php if ($page['header']): ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>

  <?php if ($page['main_menu']): ?>
    <?php print render($page['main_menu']); ?>
  <?php endif; ?>

  <?php if (($page['cover'])||($is_front)): ?>
    <?php print render($page['cover']); ?>
  <?php endif; ?>

  <?php if (($page['slideshow'])||($is_front)): ?>
    <?php print render($page['slideshow']); ?>
  <?php endif; ?>

  <?php if ($page['breadcrumb']): ?>
    <?php print render($page['breadcrumb']); ?>
  <?php endif; ?>

  <?php if ($action_links): ?>
    <ul class="action-links"><?php print render($action_links); ?></ul>
  <?php endif; ?>

  <?php if ($messages) : ?>
    <?php print $messages; ?>
  <?php endif; ?>

  <?php if ($page['highlighted']): ?>
    <?php print render($page['highlighted']); ?>
  <?php endif; ?>

    <div id="content">
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="title" id="page-title">
          <?php print $title; ?>
        </h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($tabs): ?>
        <div class="tabs">
          <i class="fa fa-cog"></i>
          <?php print render($tabs); ?>
        </div>
      <?php endif; ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>

    </div> <!-- /.div, /#content -->

    <?php if ($page['sidebar_first']): ?>
      <?php print render($page['sidebar_first']); ?>
    <?php endif; ?>

    <?php if ($page['sidebar_second']): ?>
      <?php print render($page['sidebar_second']); ?>
    <?php endif; ?>

    <?php if ($page['footer']): ?>
      <div id="footer" class="clearfix">
        <?php print render($page['footer']); ?>
      </div> <!-- /#footer -->
    <?php endif; ?>


