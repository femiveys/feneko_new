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

      // Replace the Hoeveelheid label by a submit button
      $('.commerce-add-to-cart').each(function(value, key) {
        // $(this).find('.form-item-quantity label').replaceWith($(this).find('.form-submit'));
      });

      // Add the dorpel images: This is dirty
      var selector = '.node-raamtablet .commerce-add-to-cart #field-eindstukken-values ';
      var p = '<td rowspan="2" class="thumb">';
      var eindstukImage1 = $('.commerce-add-to-cart img[title$=1]');
      var eindstukImage2 = $('.commerce-add-to-cart img[title$=2]');
      $(selector + 'tbody tr:nth-child(1)').prepend(p).find('td').first().prepend(eindstukImage1);
      $(selector + 'tbody tr:nth-child(3)').prepend(p).find('td').first().prepend(eindstukImage2);

      $(selector + 'thead th').attr('colspan', 2); // As we have added a cell, we need to add a colspan
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
