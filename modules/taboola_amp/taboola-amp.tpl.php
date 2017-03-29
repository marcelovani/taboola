<?php
/**
 * @file
 * Template for an amp-taboola.
 *
 * Available variables:
 * - $height: The height.
 * - $heights: The heights.
 * - $width: The width.
 * - $layout: The layout.
 * - $publisher: Publisher.
 * - $mode: mode.
 * - $placement: placement.
 * - $target_type: target type.
 * - $article: Article.
 *
 * @see template_preprocess_amp_ad()
 */
?>
<amp-embed type="taboola"
           height="<?php print $height; ?>"
           width="<?php print $width; ?>"
           layout="<?php print $layout; ?>"
           heights="<?php print $heights; ?>"
           data-publisher="<?php print $publisher; ?>"
           data-mode="<?php print $mode; ?>"
           data-placement="<?php print $placement; ?>"
           data-target_type="<?php print $target_type; ?>"
           data-article="<?php print $article; ?>"
>
</amp-embed>
