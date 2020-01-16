<?php

// TODO: Create form
function handshake_feeds_configure($form, &$form_state) {
    $form['feeds_list'] = array(
        '#title' => t("Add new Handshake feed."),
        '#type' => 'fieldset',
        '#prefix' => '<div id="feeds_list">',
        '#suffix' => '</div>',
        '#description' => t('Enter the Handshake feed name and URL. This will create a new block which can be added to a page. 
        For any assistance please contact scott.may14@uky.edu.'),
    );
    $form['feeds_list']['name'] = array(
        '#type' => 'textfield',
        '#title' => t('Feed name'),
        '#description' => t('Enter name for feed. For example, "ME Alumni Jobs", "CME Job Postings" etc.'),
        '#required' => TRUE,
    );
    $form['feeds_list']['url'] = array(
        '#type' => 'textfield',
        '#title' => t('Feed URL'),
        '#description' => t('Paste in the URL provided by Handshake.'),
        '#required' => TRUE,
    );
    $form['feeds_list']['submit'] = array(
        '#type' => 'submit',
        '#ajax' => array(
          'callback' => 'handshake_feeds_configure_submit_callback',
          'wrapper' => 'feeds_list',
          'effect' => 'fade',
          'method' => 'replace',
          'progress' => array('type' => 'throbber', 'message' => t('Please wait. The data is being saved.')),
        ),
        '#value' => t('Save'),
      );
    return $form;
}

// TODO: Validate the data
/**
 * Implements validation from the Form API
 * 
 * @param $form
 *  A structured array containing the elements and properties of the form.
 * @param $form_state
 *  An array that stores information about the form's current state during processing
 */
function handshake_feeds_form_validate($form, &$form_state) {
    // TODO: Actually validate for RSS feed url
    $url = $form_state['values']['url'];
}

// TODO: Save to DB