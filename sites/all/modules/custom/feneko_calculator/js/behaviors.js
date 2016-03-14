(function ($) {
  Drupal.behaviors.calculator = {
    attach: function (context, settings) {
      // Hide disabled multi-value fields
      $('.field-multiple-table .form-item.form-disabled')
                            .parents('tr.draggable').addClass('element-hidden');


      // CUSTOM AJAX FUNCTIONS
      $.fn.handleFocus = function(selector) {
        // Find next input element and set focus
        input_selector = ':input:not(:disabled)'; //only the active input fields
        current_idx = $(input_selector).index($(selector));
        next_idx = current_idx + 1;
        $(input_selector + ':eq(' + next_idx + ')').focus().select();

        // Set focus on current element
        // $(selector).focus();
      };

      // Fire the right trigger
      $('.commerce-add-to-cart input:not(.form-autocomplete), .commerce-add-to-cart select').change(function(e) {
        $(this).trigger('fc_change');
      });

      $('.commerce-add-to-cart input.form-autocomplete').blur(function(e) {
        $(this).trigger('fc_change');
      });

      // Prevent tab when bicolor field is not complete
      // This should be done more elegantly, but we just check if there are parentheses
      $('.commerce-add-to-cart .field-name-field-bicolor-kleur input').keydown(function(objEvent) {
        if (objEvent.keyCode == 9) {  //tab pressed
          if(!$(this).hasClass('default-prevented')) {
            $(this).addClass('default-prevented');
            objEvent.preventDefault(); // stops its action
          }
        }
      });


      // Prevent anything during AJAX call
      $(document).ajaxStart(function(){
        // console.log('prevent triggered.');
        // $(".commerce-add-to-cart input, .commerce-add-to-cart select").attr('disabled','disabled');
      });

      // Disable submit button when an ajax textfield is edited
      $('form.commerce-add-to-cart .field-type-number-integer input.ajax-processed').each(function() {
        $(this).keyup(function() {
          if(this.value !== this.defaultValue) {
            $('form.commerce-add-to-cart .form-submit').attr('disabled', 'disabled');
          } else {
            $('form.commerce-add-to-cart .form-submit').attr('disabled', null);
          }
        });
      });

      // // Change hidden diepte and rug fields for dorpel united page
      // diepte = $('.form-item-attributes-field-raamtablet-diepte select').val();
      // $('.field-name-field-raamtablet-diepte select').val(diepte);
      // $('.field-name-field-dorpels .field-name-field-rug select').change(function() {
      //   $('.field-name-field-rug select').val(this.value);
      // });

      // // Replace the Hoeveelheid label by a submit button
      // $('.commerce-add-to-cart').each(function(value, key) {
      //   $(this).find('.form-item-quantity label').replaceWith($(this).find('.form-submit'));
      // });
    }
  };

  Drupal.behaviors.extra_fields = {
    attach: function (context, settings) {
      $('.view-feneko-shopping-cart-block tr:not(.toggle-processed)').click(function() {
        $(this).find('.detail').slideToggle();
      })
      .addClass('toggle-processed')
      ;
    }
  };
})(jQuery);
