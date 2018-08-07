<div id="mobile-header"<?php if (!$page['shopping_cart']) print(' class="no-shopping-cart"') ?>>
  <div id="menu-small" class="small-block first">
    <div class="inner-wrapper">
      <i class="fa fa-bars menu-icon"></i> menu
    </div>
  </div><!--menu-small-->
  <div id="logo-small" class="small-block blocklink">
    <div class="inner-wrapper">
      <a href="<?php print $front_page; ?>">
        <div class="feneko_logo">
          <span class="feneko_fenek">F</span>
          <span class="feneko_o">O</span>
        </div>
      </a>
    </div>
  </div><!--logo-small-->
  <div id="user-small" class="small-block blocklink">
    <div class="inner-wrapper">
      <a href="/user">login <i class="fa fa-user"></i></a>
    </div>
  </div><!--menu-small-->
  <?php if ($page['shopping_cart']): ?>
    <div id="cart-small" class="small-block">
      <div class="inner-wrapper">
        Shopping cart <i class="fa fa-shopping-cart"></i>
      </div>
    </div><!--menu-small-->
  <?php endif; ?>

  <!--
  <div id="search-small" class="small-block last">
    <div class="inner-wrapper">
      <i class="fa fa-search"></i>search
    </div>
  </div>
  -->
</div><!--mobile-header-->

<?php if ($page['user_menu']): ?>
  <div id="usermenu-wrapper" class="wrapper">
    <div class="inner-wrapper">
      <div id="user-menu">
        <?php print render($page['user_menu']); ?>
      </div>
    </div> <!-- .inner-wrapper -->
  </div> <!-- #usermenu-wrapper -->
<?php endif; ?>

<div id="header-wrapper" class="wrapper">
  <div class="inner-wrapper">
    <h2 class="logo">
      <a href="<?php print $front_page; ?>">
        <img src="/sites/all/themes/feneko/img/logo.png">
<!--
        <div class="feneko_logo">
          <span class="feneko_fenek">Fenek</span>
          <span class="feneko_o">O</span>
        </div>
-->
      </a>
    </h2>
    <?php if ($site_name): ?>
    <h1 id="site-name">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
    </h1>
    <?php endif; ?>
    <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
    <?php endif; ?>
    <?php if ($page['banner']): ?>
      <?php print render($page['banner']); ?>
    <?php endif; ?>
  </div> <!-- .inner-wrapper -->
</div> <!-- #header-wrapper -->


<?php if ($page['main_menu']): ?>
  <div id="mainmenu-wrapper" class="wrapper">
    <div class="inner-wrapper">
      <?php print render($page['main_menu']); ?>
      <?php if ($page['shopping_cart']): ?>
        <div id="shoppingcart">
          <?php print render($page['shopping_cart']); ?>
        </div> <!-- #shoppingcart -->
      <?php endif; ?>
    </div> <!-- .inner-wrapper -->
  </div> <!-- #mainmenu-wrapper -->
<?php endif; ?>



<?php if ($page['breadcrumb']): ?>
  <div id="breadcrumb-wrapper" class="wrapper">
    <div class="inner-wrapper">
      <?php print render($page['breadcrumb']); ?>
    </div> <!-- .inner-wrapper -->
  </div> <!-- #breadcrumb-wrapper -->
<?php endif; ?>

<?php if ($page['cover']): ?>
  <div id="cover-wrapper" class="wrapper">
      <?php print render($page['cover']); ?>
  </div> <!-- #cover-wrapper -->
<?php endif; ?>

<?php if ($page['banner']): ?>
  <div class="hide-desk">
    <?php print render($page['banner']); ?>
  </div>
<?php endif; ?>

<?php if ($action_links): ?>
  <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>


<div id="main-wrapper" class="wrapper">
  <div class="inner-wrapper">

    <?php if ($messages) : ?>
      <?php print $messages; ?>
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
      <?php if ($page['sidebar_first']): ?>
      <?php print render($page['sidebar_first']); ?>
    <?php endif; ?>

      <?php print render($page['content']); ?>

    </div> <!-- /.div, /#content -->

    <?php if ($page['sidebar_second']): ?>
      <?php print render($page['sidebar_second']); ?>
    <?php endif; ?>

      </div> <!-- .inner-wrapper -->
</div> <!-- #main-wrapper -->

<?php if ($page['front_block']): ?>
  <div id="frontblock-wrapper" class="wrapper">
    <div class="inner-wrapper">
      <?php print render($page['front_block']); ?>
    </div> <!-- .inner-wrapper -->
  </div> <!-- #frontblock-wrapper -->
<?php endif; ?>

<?php if ($page['catalogus']): ?>
  <div id="catalogus-wrapper" class="wrapper">
    <div class="inner-wrapper">
      <?php print render($page['catalogus']); ?>
    </div> <!-- .inner-wrapper -->
  </div> <!-- #catalogus-wrapper -->
<?php endif; ?>

<?php if ($page['bottom_block']): ?>
  <div id="bottomblock-wrapper" class="wrapper">
    <div class="inner-wrapper">
      <?php print render($page['bottom_block']); ?>
    </div> <!-- .inner-wrapper -->
  </div> <!-- #bottomblock-wrapper -->
<?php endif; ?>

<?php if ($page['footer']): ?>
  <footer id="footer-footer" class="footer wrapper">
    <div class="inner-wrapper">
      <?php print render($page['footer']); ?>
    </div> <!-- .inner-wrapper -->
  </footer>
<?php endif; ?>

<?php if(isset($closure)){print $closure;} ?>



<div class="totop"><i class="fa fa-arrow-up"></i></div>
