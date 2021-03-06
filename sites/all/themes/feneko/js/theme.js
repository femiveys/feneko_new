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
    function parallax(selector, speed) {
      ypos = window.pageYOffset;
      selector.css('top', '-' + ypos*.2 + 'px');
    }

    function parallax2(selector) {
      ypos = window.pageYOffset;
      selector.css('padding-bottom', ypos*0.05 + 'px');
    }

    var elementPos = $('#mainmenu-wrapper').offset();
    elementTop = elementPos.top;

    $(window).scroll( function () {
      parallax($('.view-front-image img'));
      parallax2($('.node-info-pagina h2'));

      if ($(window).scrollTop() >= (elementTop)) {
        $('#mainmenu-wrapper').css({position: "fixed", top: "0px", width: "100%", zIndex: "500"});
        $('#main-wrapper').css({paddingTop: "100px"});
      } else {
        $('#mainmenu-wrapper').css({position: "relative", top: "0px"});
        $('#main-wrapper').css({paddingTop: "40px"});
      }
    });

    $('.form-radio.error').after('<div class="radio-error"></div>');





      //console.log($(document).top);



/*
    // STICKY MENU
    // Create a clone of the menuwrapper, right next to original.
    $('#mainmenu-wrapper').addClass('original')
      .clone()
      .insertAfter('#mainmenu-wrapper').
      addClass('cloned').
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
        $('.cloned').css('top',0).css('width',widthOrgElement).show();
        $('.original').css('visibility','hidden');
      } else {
        $('.cloned').hide();
        $('.original').css('visibility','visible');
      }
    }
*/
    // mobile menu
    $('#menu-small').click(function() {
      $('#mainmenu-wrapper').toggleClass('show');
      $('#header-wrapper.show').removeClass('show');
      $('#shoppingcart.show').removeClass('show');
    });


// commented because may come back
/*
    // mobile search
    $('#search-small').click(function() {
      $('#header-wrapper').toggleClass('show');
      $('#main_menu.show').removeClass('show');
    });
*/

    // mobile cart
    $('#cart-small').click(function() {
      $('#shoppingcart').toggleClass('show');
      $('#mainmenu-wrapper.show').removeClass('show');
    });

    // responsive table

    var order = [];

    $('#manyforms-form th, .view-commerce-cart-form-feneko th, .page-user-orders th, .page-user-feneko-orders th').each(function(index, value) {
      order[index] = $(this).text();
      $(this).wrapInner('<div><span>');
    });


    $('#manyforms-form tr td, .view-commerce-cart-form-feneko tr td, .page-user-orders tr td, .page-user-feneko-orders tr td').each(function() {
      $(this).attr('data-before',(order[$(this).index()]));
    });

    $('.view-commerce-cart-form-feneko tbody tr').each(function() {
      var product = $(this).find('td:nth-child(1)').text();
      $(this).attr('data-before', product);
    });

    $('.open-img').click(function() {
      $('.field-name-field-images').toggle();
      $(this).toggleClass('open');
    });

    $('.view-feneko-shopping-cart-block .node-header').click(function() {
      $('.view-feneko-shopping-cart-block .view-total').toggleClass('show');
    });

    $('.view-feneko-shopping-cart-block .title').click(function() {
      //alert('auw');
      $(this).toggleClass('toggle');
    });

    $(".front.nl .node-info-pagina a").attr("href", "/nl/about");

    $(".front.fr .node-info-pagina a").attr("href", "/fr/about");

    $('.ck-check').each(function() {
      $(this).next().not('[class=ck-check]').prev().addClass('last-check');
    });


  });
})(jQuery);
