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
  // Global enabled flag.
  $form['taboola_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => taboola_get_setting('taboola_enabled'),
  );

  // Publisher.
  $form['taboola_publisher'] = array(
    '#type' => 'textfield',
    '#title' => t('Publisher ID'),
    '#default_value' => taboola_get_setting('taboola_publisher'),
    '#description' => '',
  );

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

  // Configure number of available blocks.
  $form['taboola_block_count'] = array(
    '#type' => 'select',
    '#title' => t('Number of blocks'),
    '#options' => array_combine(range(1,30), range(1,30)),
    '#default_value' => variable_get('taboola_block_count'),
    '#description' => t('The number of taboola blocks.'),
  );

  // Output block configure links.
  if ($block_info = module_invoke('taboola', 'block_info')) {
    $form['block_links'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Blocks'),
    );
    foreach ($block_info as $block_delta => $block_config) {
      $form['block_links'][$block_delta . '_settings'] = array(
        '#type' => 'link',
        '#title' => $block_config['info'],
        '#href' => '/admin/structure/block/manage/taboola/' . $block_delta . '/configure',
        '#suffix' => '</br>',
      );
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array(
      'taboola_admin_settings_form_submit',
      'system_settings_form_submit',
    ),
    '#weight' => 10,
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
