<?php
/**
 * @file
 * Template for an amp-taboola.
 *
 * Available variables:
 * - height: The height.
 * - heights: The heights.
 * - width: The width.
 * - layout: The layout.
 * - data_publisher: Publisher.
 * - data_mode: Data mode.
 * - data_placement: Data placement.
 * - data_target_type: Data target type.
 * - data_article: Data Article.
 *
 * @see template_preprocess_amp_ad()
 */
?>
<amp-embed type="taboola"
           height="<?php print $height; ?>"
           width="<?php print $width; ?>"
           layout="<?php print $layout; ?>"
           heights="<?php print $heights; ?>"
           data-publisher="<?php print $data_publisher; ?>"
           data-mode="<?php print $data_mode; ?>"
           data-placement="<?php print $data_placement; ?>"
           data-target_type="<?php print $data_target_type; ?>"
           data-article="<?php print $data_article; ?>"
>
</amp-embed>
