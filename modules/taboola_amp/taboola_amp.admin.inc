<?php
/**
 * @file
 * Contains the administrative functions of the taboola_amp_amp module.
 */

/**
 * Implements hook_form_id_alter().
 */
function taboola_amp_form_taboola_admin_settings_form_alter(&$form, &$form_state, $form_id) {
  $form['taboola_amp'] = array(
    '#title' => t('AMP'),
    '#type' => 'fieldset',
    '#weight' => 2,
  );
  $form['taboola_amp']['taboola_data_publisher'] = array(
    '#type' => 'textfield',
    '#title' => t('Data publisher'),
    '#default_value' => taboola_get_setting('taboola_data_publisher'),
  );
}
