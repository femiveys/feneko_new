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

/*
$('#main-menu > ul ').each(function(){
        var highestBox = 0;
        $('> li', this).each(function(){

            if($(this).height() > highestBox)
               highestBox = $(this).height();
        });

        $('> li',this).height(highestBox);

});
*/

/*
function parallax(selector) {
  ypos = window.pageYOffset;
  selector.css('top', ypos*.4 + 'px');
}
*/

$('.view-feneko-shopping-cart-block tr').click(function() {
  $(this).toggleClass('open');
});


$('#menu-small').click(function() {
  $('#main_menu').toggleClass('show');
});

$('#search-small').click(function() {
  $('#header-wrapper').toggleClass('show');
});


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
