<?php
/**
 * @file
 * Contains the administrative functions of the taboola_amp_amp module.
 */

/**
 * Implements hook_taboola_block_configure_alter().
 */
function taboola_amp_taboola_block_config_alter(&$form, $delta) {
  if (($block_index = taboola_get_block_array_index($delta)) !== FALSE) {
    // Type group.
    $form['taboola_amp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Taboola AMP Settings'),
      '#group' => 'vertical_tabs',
    );
    // Mode.
    $form['taboola_amp']['amp_heights'] = array(
      '#type' => 'textarea',
      '#title' => t('Heights'),
      '#default_value' => taboola_get_block_setting($block_index, 'amp_heights', $default = ''),
      '#description' => '',
    );
  }

  return $form;
}

/**
 * Implements hook_taboola_block_save_alter();
 */
function taboola_amp_taboola_block_save_alter(&$block_config, $form_values) {
  $block_config['amp_heights'] = $form_values['amp_heights'];
}
