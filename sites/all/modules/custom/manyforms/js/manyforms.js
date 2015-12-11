(function ($) {
  Drupal.behaviors.table_help = {
    attach: function (context, settings) {
      $('.manyform_table caption').wrapInner('<div class="help-text">');
      $('.manyform_table caption').prepend($('<div>', { "class": "help" }));

      $('.manyform_table caption div').click(function() {
        $(this).parents('caption').find('.text').slideToggle();
      });
    }
  };

  Drupal.behaviors.dep_values = {
    attach: function (context, settings) {
      // Hide ondergeleider dependant value if uitvoering is not double
      $('#edit-ondergeleider-u15x25x15x2, #edit-bovengeleider-u20x25x20x2')
        .parent().addClass('visible-when-double');
      $('input[name=uitvoering]').change(function() {
        if($(this).val() === 'dubbel') {
          $(this).parents('form').addClass('double');
        } else {
          $(this).parents('form').removeClass('double');
        }
      });
    }
  };

}(jQuery));

