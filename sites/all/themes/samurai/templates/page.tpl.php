  <div id="wrapper">
    <?php if ($logo): ?>
    <a class="logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
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


<?php if (($page['main_menu'])||($is_front)): ?>
  <?php print render($page['main_menu']); ?>
<?php endif; ?>





  <?php if ($page['breadcrumb']): ?>
    <?php print render($page['breadcrumb']); ?>
  <?php endif; ?>



  <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>

      <?php if ($page['sidebar_first']): ?>
      <?php print render($page['sidebar_first']); ?>
  <?php endif; ?>


<section id="main-content">
      <?php if ($messages) : ?>
  <?php print $messages; ?>
<?php endif; ?>
  <?php if ($tabs): ?>
  <div class="tabs">
    <?php print render($tabs); ?>
  </div>
<?php endif; ?>

    <?php print render($page['content']); ?>
</section>





  <?php if ($page['sidebar_second']): ?>
      <?php print render($page['sidebar_second']); ?>
  <?php endif; ?>

  <?php if ($page['full_size']): ?>
      <?php print render($page['full_size']); ?>
  <?php endif; ?>

  <?php if ($page['triple']): ?>
      <?php print render($page['triple']); ?>
  <?php endif; ?>





  <?php if ($page['footer']): ?>
   <footer id="footer-footer" class="footer">
      <?php print render($page['footer']); ?>
    </footer>
  <?php endif; ?>




<?php if(isset($closure)){print $closure;} ?>


</div>

<div class="totop"><i class="fa fa-arrow-up"></i></div>
