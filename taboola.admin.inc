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

  // Global enabled flag.
  $form['taboola_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => taboola_get_setting('taboola_enabled'),
  );

  // Tab group.
  $form['vertical_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'edit-block-group',
  );

  // Block group.
  $form['block_group'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Settings'),
    '#group' => 'vertical_tabs',
  );

  foreach (taboola_get_widget_types() as $type) {
    // Block settings for each type.
    $form['block_group']['taboola_block_subject_' . $type] = array(
      '#type' => 'textfield',
      '#title' => t(ucwords($type) . ' Block Title'),
      '#default_value' => taboola_get_setting('taboola_block_subject_' . $type),
      '#description' => 'The title you want to be displayed on the block. Use &lt;none&gt; if no title is desired.',
    );
    // Type group.
    $form[$type . '_group'] = array(
      '#type' => 'fieldset',
      '#title' => t(ucwords($type) . ' Settings'),
      '#group' => 'vertical_tabs',
    );
    // Mode.
    $form[$type . '_group']['taboola_mode_' . $type] = array(
      '#type' => 'textfield',
      '#title' => t('Mode'),
      '#default_value' => taboola_get_setting('taboola_mode_' . $type),
      '#description' => '',
    );
    // Placement.
    $form[$type . '_group']['taboola_placement_' . $type] = array(
      '#type' => 'textfield',
      '#title' => t('Placement'),
      '#default_value' => taboola_get_setting('taboola_placement_' . $type),
      '#description' => '',
    );
    // Target Type.
    $form[$type . '_group']['taboola_target_type_' . $type] = array(
      '#type' => 'textfield',
      '#title' => t('Target Type'),
      '#default_value' => taboola_get_setting('taboola_target_type_' . $type),
      '#description' => '',
    );
    // Container.
    $form[$type . '_group']['taboola_container_' . $type] = array(
      '#type' => 'textfield',
      '#title' => t('Container'),
      '#default_value' => taboola_get_setting('taboola_container_' . $type),
      '#description' => '',
    );
  }

  return system_settings_form($form);
}