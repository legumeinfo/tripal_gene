<?php

/* @file
 * Purpose: This Handler provides a generic select list for any chado field that is a string
 *  The select list includes all distinct values for that field
 */
class views_handler_filter_chado_select_string extends views_handler_filter_string {

 /**
  * Defines the value field in both the views filter options form
  *   and the exposed form
  */
  function value_form(&$form, &$form_state) {
    parent::value_form(&$form, &$form_state);
    
    // Get Options
    $options[''] = '<Any>';
    $options['<select '.$this->table.'>'] = '<None>';
    $results = tripal_core_chado_select(
      $this->table,
      array($this->field),
      array()
    );
    $max_length = 40;
    foreach ($results as $r) {
      if (strlen($r->{$this->field}) > $max_length) {
        $options[$r->{$this->field}] = substr($r->{$this->field},0,$max_length) . '...';
      } else {
        $options[$r->{$this->field}] = $r->{$this->field};    
      }
    }
    
    //Select List
    $form['value'] = array(
        '#type' => 'select',
        '#title' => $this->options['label'],
        '#options' => $options,
        '#default_value' => $this->value,
    );
  }

 /**
  * Ensures the select list gets rendered when the filter is exposed
  */
  function exposed_form(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    $value = $this->options['expose']['identifier'];
    $this->value_form($form, $form_state);
    $form[$value] = $form['value'];

    if (isset($form[$value]['#title']) && !empty($form[$value]['#type']) && $form[$value]['#type'] != 'checkbox') {
      unset($form[$value]['#title']);
    }

    $this->exposed_translate($form[$value], 'value');

    if (!empty($form['#type']) && ($form['#type'] == 'checkboxes' || ($form['#type'] == 'select' && !empty($form['#multiple'])))) {
      unset($form[$value]['#default_value']);
    }

    if (!empty($form['#type']) && $form['#type'] == 'select' && empty($form['#multiple'])) {
      $form[$value]['#default_value'] = 'All';
    }

    if ($value != 'value') {
      unset($form['value']);
    }

  }


  /**
   * Handle the 'right' side fo the exposed options form.
   * Removing the option to make this field Optional. Instead it is always optional.
   * This was done because the optional field didn't allow you to select <Any> as the default
   *   which was a needed feature.
   */
  function expose_form_right(&$form, &$form_state) {
    parent::expose_form_right($form, $form_state);
    
    unset($form['expose']['optional']);
  }
}