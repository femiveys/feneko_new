/*
 * main scripts
 * author: pure sign
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

    // TOTOP LINK SCROLL
    var topLink = $('.totop');
    var showTopLink = 500;
    topLink.hide();

    $(window).scroll( function(){
      var y = $(window).scrollTop();
      if( y > showTopLink  ) {
        topLink.fadeIn('slow');
      } else {
        topLink.fadeOut('slow');
      }
    });

    topLink.click( function(e) {
      e.preventDefault();
      $('body, html').animate( {scrollTop : 0}, 'slow' );
    });

    $('div.tabs .fa').click(function() {
      $('ul.tabs').toggle();
      $(this).toggleClass('open');
    });


    // LINK ON BLOCK
    function blocklink (selector) {
      selector.click(function () {
        window.location = $(this).find('a').eq(0).attr('href');
      });
    }

    blocklink($('.blocklink'));
    blocklink($('.field-type-file .field-item'));

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

    equalHeight($('.view-id-nieuws'), $('.nieuws-body'));


  });
})(jQuery);
