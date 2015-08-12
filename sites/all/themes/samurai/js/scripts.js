/*
 * main scripts
 * author: pure sign
 */

(function ($) {

  $(document).ready(function(){

  function fancySelect () {
    var selection = $('select');
    selection.each(function() {
      var $this = $(this);
      var selectedValue = $this.parent().find('select option:selected').text();
      var newSelect = $('<div class="select">'+selectedValue+'</div>');
      newSelect.insertAfter($this);
      $this.change(function(){
        var str = "";
        str += $this.parent().find('select option:selected').text() + " ";
        $( newSelect ).text( str );
      });
    });
  }
/*
$('#colorbox').mouseover(function() {
  $(this).addClass('over');
});
*/

$('#cboxNext, #cboxPrevious').mouseleave(function() {
  $(this).removeClass('over');
});

$('#cboxNext, #cboxPrevious').mouseover(function() {
  $(this).addClass('over');
});

$('.view-feneko-shopping-cart-block .node-header').click(function(){
  $(this).siblings().toggleClass('show');
});

$('#cart-small').click(function() {
  $('.view-feneko-shopping-cart-block .view-content, .view-feneko-shopping-cart-block .view-footer').toggleClass('show');
});

// add pseudo last - of - type class to class

// function maken

  // blok link
  function blocklink (selector) {
    selector.click(function () {
      window.location = $(this).find('a').eq(0).attr('href');
    });
  }

if ( $(window).width() >= 850) {
  $('.view-id-nieuws').each(function(){
        var highestBox = 0;
        $('.nieuws-body', this).each(function(){

            if($(this).height() > highestBox)
               highestBox = $(this).height();
        });

        $('.nieuws-body',this).height(highestBox);

  });
}

$('.view-feneko-shopping-cart-block tr').click(function() {
  $(this).toggleClass('open');
});


$('#menu-small').click(function() {
  $('#main_menu').toggleClass('show');
  $('#header-wrapper.show').removeClass('show');
});

$('#search-small').click(function() {
  $('#header-wrapper').toggleClass('show');
  $('#main_menu.show').removeClass('show');
});



 function widthDependent () {
  if ( $(window).width() >= 850) {
    $('body').addClass('big').removeClass('small');

    } else {
      $('body').removeClass('big').addClass('small');
    }
  }

widthDependent();
  // listen resize :
  $(window).resize(function(e) {
    widthDependent();
  });

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
  $('body').animate( {scrollTop : 0}, 'slow' );
});

  //scrollTop($('.totop'));
  blocklink($('.blocklink'));
  blocklink($('.field-type-file .field-item'));
  //fancySelect();


  });
})(jQuery);
