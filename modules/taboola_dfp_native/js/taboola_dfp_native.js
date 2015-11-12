(function ($) {

  Drupal.behaviors.appendTaboolaDfpNative = {
    attach: function (context, settings) {

      var appendDfp = {
        settings: Drupal.settings.taboolaDfpNative,

        // Append the rendered Dfp slot to specified element.
        appendDfp: function (tags) {
          $.each(tags, function (index, item) {
            var slotName = item.slotMachinename,
              position = (item.position != undefined && item.position > 0) ? item.position : 0;
            $(item.selector).eq(position).before(item.renderedDfp);
            googletag.pubads().addEventListener('slotRenderEnded', function (e) {
              // Detect if the Ad is actually delivered.
              if ((e.slot == googletag.slots[slotName]) && (e.isEmpty === false)) {
                // Hide the last element from selector if this this
                // is requested on context reaction.
                if (item.last_el_hide != undefined && item.position > 0) {
                  $(item.selector).last().addClass('element-invisible');
                }
              }
              // Otherwise, make sure to hide it.
              else {
                $('#' + item.slotDfpWrapperID).addClass('element-invisible');
              }
            });
          });
        },
        // appendDfp initialization function.
        init: function () {
          return !!(window.googletag &&
          Drupal.settings.taboolaDfpNative &&
          Drupal.settings.taboolaDfpNative.tags &&
          this.appendDfp(Drupal.settings.taboolaDfpNative.tags));
        }
      };

      // Initial call.
      appendDfp.init();
    }
  };

})(jQuery);
