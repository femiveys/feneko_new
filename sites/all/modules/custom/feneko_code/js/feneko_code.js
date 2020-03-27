(function ($) {
  Drupal.behaviors.fase_help = {
    attach: function (context, settings) {
      $('.page-user-feneko-orders .help').click(function() {
        $('.page-user-feneko-orders .help-text').slideToggle();

        return false;
      });
    }
  };

  Drupal.behaviors.expand_select = {
    attach: function(context, settings) {
      $(".field-type-commerce-product-reference select").attr("size", 35);
    }
  };
}(jQuery));
