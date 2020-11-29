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
      $(".field-type-commerce-product-reference select#edit-field-product-und").attr("size", 35);
    }
  };

  Drupal.behaviors.nologin = {
    attach: function(context, settings) {
      $("#block-system-user-menu a").click(function(event) {
        event.preventDefault();
        alert("Beste klant, wij zijn er op 1 december terug met onze nieuwe webshop.")
      });
    }
  };
}(jQuery));
