<?php

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */


/**
 * Implements hook_form().
 */

function noindex_nofollow_form($form, &$form_state) {

    $form = array();

    $form['develop'] = array(
      '#type' => 'fieldset',
      '#title' => t('URL(S)'),
      '#collapsible' => TRUE,
      '#group' => 'vertical_tabs',
    );

    $form['develop']['urls'] = array(
      '#title' => t('Add Urls'),
      '#type' => 'textarea',
      '#default_value' => variable_get('urls', ''),
      '#description' => t('Please add Url(s) separed by ";" <br> Example : node/1 or node/* '),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );

  return $form;
}

/**
 * Implementation of hook_form_validate().
 */

function noindex_nofollow_form_validate($form, $form_state) {
 // dpm('Form Validate');
}

/**
 * Implementation of hook_form_submit().
 */

function noindex_nofollow_form_submit($form, $form_state) {
  foreach ($form_state['values'] as $key => $value) {
    variable_set($key, $value);
  }
  return drupal_set_message(t('Saved configuration'), 'status', TRUE);
}