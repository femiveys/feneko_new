/*
 * main scripts
 * author: esther
 */

(function ($) {
  $(document).ready(function(){

    function widthDependent () {
      if ( $(window).width() >= 850) {
        $('body').addClass('big').removeClass('small');
      } else {
        $('body').removeClass('big').addClass('small');
      }
    }

    widthDependent();
    $(window).resize(function(e) {
      widthDependent();
    });

    // paralax
    function parallax(selector) {
      ypos = window.pageYOffset;
      selector.css('top', '-' + ypos*.2 + 'px');
    }

    function parallax2(selector) {
      ypos = window.pageYOffset;
      selector.css('padding-bottom', ypos*0.05 + 'px');
    }

    $(window).scroll( function () {
      parallax($('.view-front-image img'));
      parallax2($('.node-info-pagina h2'));
    });

    $('.form-radio.error').after('<div class="radio-error"></div>');

    // STICKY MENU
    // Create a clone of the menu, right next to original.
    $('#mainmenu-wrapper').addClass('original')
      .clone()
      .insertAfter('#mainmenu-wrapper').
      addClass('cloned').
      css('position','fixed').
      css('top','0').
      css('margin-top','0').
      css('z-index','500').
      removeClass('original').hide();

    scrollIntervalID = setInterval(stickIt, 10);


    function stickIt() {

      var orgElementPos = $('.original').offset();
      orgElementTop = orgElementPos.top;

      if ($(window).scrollTop() >= (orgElementTop)) {
        // scrolled past the original position; now only show the cloned, sticky element.

        // Cloned element should always have same left position and width as original element.
        orgElement = $('.original');
        coordsOrgElement = orgElement.offset();
        leftOrgElement = coordsOrgElement.left;
        widthOrgElement = orgElement.css('width');
        $('.cloned').css('left',leftOrgElement+'px').css('top',0).css('width',widthOrgElement).show();
        $('.original').css('visibility','hidden');
      } else {
        // not scrolled past the menu; only show the original menu.
        $('.cloned').hide();
        $('.original').css('visibility','visible');
      }
    }

    // mobile menu
    $('#menu-small').click(function() {
      $('#mainmenu-wrapper').toggleClass('show');
      $('#header-wrapper.show').removeClass('show');
    });

    // mobile search
    $('#search-small').click(function() {
      $('#header-wrapper').toggleClass('show');
      $('#main_menu.show').removeClass('show');
    });

    // responsive table

    var order = [];

    $('#manyforms-form th, .view-commerce-cart-form-feneko th').each(function(index, value) {
      order[index] = $(this).text();
      $(this).wrapInner('<div><span>');
    });


    $('#manyforms-form tr td, .view-commerce-cart-form-feneko tr td').each(function() {
      $(this).attr('data-before',(order[$(this).index()]));
    });

    $('.view-commerce-cart-form-feneko tbody tr').each(function() {
      var product = $(this).find('td:nth-child(1)').text();
      $(this).attr('data-before', product)
    });

    $('.open-img').click(function() {
      $('.field-name-field-images').toggle();
      $(this).toggleClass('open');
    });

    $('.view-feneko-shopping-cart-block .node-header').click(function() {
      $('.view-total').toggle();
    });


  });
})(jQuery);
