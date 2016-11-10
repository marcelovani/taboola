<?php
/**
 * @file
 * Contains the administrative functions of the taboola module.
 *
 * This file is included by the core Taboola module, and includes the
 * settings form.
 */

/**
 * Implements hook_admin_settings_form().
 *
 * Used to create the admin form to configure the taboola blocks.
 */
function taboola_admin_settings_form() {
  $form = array();
  // Service path.
  $form['taboola_service_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Service Path'),
    '#default_value' => taboola_get_setting('taboola_service_path'),
    '#description' => '',
  );

  // Taboola-X Service path.
  $form['taboola_x_service_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Taboola-X Service Path'),
    '#default_value' => taboola_get_setting('taboola_x_service_path'),
    '#description' => '',
  );

  // Global enabled flag.
  $form['taboola_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => taboola_get_setting('taboola_enabled'),
  );
  $form['taboola_block_count'] = array(
    '#type' => 'select',
    '#title' => t('Number of blocks'),
    '#options' => array_combine(range(1,30), range(1,30)),
    '#default_value' => variable_get('taboola_block_count'),
    '#description' => t('The number of taboola blocks.'),
  );

  for ($i = 1; $i < variable_get('taboola_block_count')+1; $i++) {
    $form['block_'.$i.'_settings'] = array(
      '#type' => 'link',
      '#title' => t('Block ' . $i . ' Settings'),
      '#href' => '/admin/structure/block/manage/taboola/taboola_block' . $i . '/configure',
      '#suffix' => '</br>',
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array(
      'taboola_admin_settings_form_submit',
      'system_settings_form_submit',
    ),
  );

  return $form;
}


/**
 * Submit handler for Taboola settings.
 */
function taboola_admin_settings_form_submit($form, &$form_state) {
  $selected_taboola_count  = $form_state['values']['taboola_block_count'];

  // Resize block array to new block count.
  $taboola_blocks = variable_get('taboola_blocks', array());
  array_splice($taboola_blocks, $selected_taboola_count);
  variable_set('taboola_blocks', $taboola_blocks);
}
