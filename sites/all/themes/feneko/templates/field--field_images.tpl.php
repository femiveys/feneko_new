<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php if (!$label_hidden) : ?>
<div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
<?php endif; ?>
<div class="field-items"<?php print $content_attributes; ?>>
<?php if ($element['#view_mode']=="teaser") { ?>
<div class="field-item even"<?php print $item_attributes[0]; ?>><?php print render($items[0]); ?></div>
<?php } else { ?>
<?php foreach ($items as $delta => $item) : ?>
<div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
<?php endforeach; ?>
<?php } ?>
</div>
</div>
