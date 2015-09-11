(function ($) {
  Drupal.behaviors.fase_help = {
    attach: function (context, settings) {
      $('.page-user-feneko-orders .help').click(function() {
        $('.page-user-feneko-orders .help-text').slideToggle();

        return false;
      });
    }
  }
}(jQuery));

