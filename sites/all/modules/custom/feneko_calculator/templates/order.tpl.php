
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <div class="content-left">
      <?php
        print render($content['group_order_info']);

        // Render the elements assigned to the left column.
        print render($content['commerce_line_items']);
        print render($content['commerce_order_total']);
        if (isset($content['commerce_message_messages_order_view'])) {
          print render($content['commerce_message_messages_order_view']);
        }

        // Ignore the fields assigned to the right column.
        hide($content['status']);
        hide($content['commerce_customer_billing']);
        if (isset($content['commerce_customer_shipping'])) {
          hide($content['commerce_customer_shipping']);
        }
        if (isset($content['commerce_backoffice_order_payments_quick_edit_payment'])) {
          hide($content['commerce_backoffice_order_payments_quick_edit_payment']);
        }

        // Render all additional, unknown elements.
        print render($content);
      ?>
    </div>

    <div class="content-right">
      <?php
        // Render the elements assigned to the right column.
        print render($content['status']);
        print render($content['commerce_customer_billing']);
        if (isset($content['commerce_customer_shipping'])) {
          print render($content['commerce_customer_shipping']);
        }
        if (isset($content['commerce_backoffice_order_payments_quick_edit_payment'])) {
          print render($content['commerce_backoffice_order_payments_quick_edit_payment']);
        }
      ?>
    </div>
  </div>
</div>
