/*
 * main scripts
 * author: esther
 */

(function ($) {

  $(document).ready(function(){

    // COLORBOX
    $('#cboxNext, #cboxPrevious').mouseleave(function() {
      $(this).removeClass('over');
    });

    $('#cboxNext, #cboxPrevious').mouseover(function() {
      $(this).addClass('over');
    });

    // SCROLL TO TOP LINK
    var topLink = $('.totop');
    var showTopLink = 500;
    topLink.hide();

    var scrollbarTimeout;

    $(window).scroll(function() {
      var y = $(window).scrollTop();
      if( y > showTopLink  ) {
        topLink.fadeIn();
        clearTimeout(scrollbarTimeout);
        scrollbarTimeout = setTimeout(function()
        {
          topLink.fadeOut();
        }, 2000);
      } else {
        topLink.fadeOut('slow');
      }
    });

    topLink.click( function(e) {
      e.preventDefault();
      $('body, html').animate( {scrollTop : 0}, 'slow' );
    });

    // EDIT PAGE COG
    $('div.tabs .fa').click(function(e) {
      e.preventDefault();
      $(this).parents().closest('.tabs').find('ul.tabs, .edit').toggle();
    });

    // LINK ON BLOCK
    function blocklink (selector) {
      selector.click(function () {
        window.location = $(this).find('a').eq(0).attr('href');
      });
    }

    blocklink($('.blocklink'));
    blocklink($('.field-type-file .field-item'));
    blocklink($('.line-item-summary-view-cart'));

    // EQUAL HEIGHT DIVS
    function equalHeight (container, div) {
      if ( $(window).width() >= 850) {
        container.each(function(){
              var highestBox = 0;
              $(div, this).each(function(){
                  if($(this).height() > highestBox)
                     highestBox = $(this).height();
              });
              $(div, this).height(highestBox);
        });
      }
    }

  });
})(jQuery);
