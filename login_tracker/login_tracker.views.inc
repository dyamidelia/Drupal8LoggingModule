<?php

/**
 * @file
 * Views integration for the Login Tracker module.
 */

/**
 * Implements hook_views_data().
 */
function user_logins_views_data() {
  $data = [];
  $data['user_logins']['table']['group'] = t('User logins');
  $data['user_logins']['table']['base'] = [
    'field' => 'lid',
    'title' => t('User logins'),
    'help'  => t('Contains data about user logins.'),
  ];
  $data['user_logins']['table']['join'] = [
    'users_field_data' => [
      'left_field' => 'uid',
      'field'      => 'uid',
    ],
  ];
  // The UID field.
  $data['user_logins']['lid'] = [
    'title' => t('Login record ID'),
    'help'  => t("The unique ID referring to this login record."),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'title' => t('Record ID'),
      'id' => 'numeric',
    ],
  ];
  $data['user_logins']['uid'] = [
    'title' => t('UID'),
    'help'  => t("The user UID."),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'title' => t('UID'),
      'id' => 'numeric',
    ],
    'relationship' => [
      'title'              => t('User who logged in'),
      'help'               => t('The user associated with the login record.'),
      'id'                 => 'standard',
      'base'               => 'users_field_data',
      'base field'         => 'uid',
      'field'              => 'uid',
      'label'              => t('User who logged in'),
    ],
  ];
  // The login timestamp field.
  $data['user_logins']['timestamp'] = [
    'title'  => t('Login timestamp'),
    'help'   => t('The timestamp that the user logged in at.'),
    'field'  => [
      'id' => 'date',
    ],
    'sort'   => [
      'id' => 'date',
    ],
    'filter' => [
      'id' => 'date',
    ],
  ];
  $data['user_logins']['host'] = [
    'title' => t('Host IP'),
    'help'  => t('Login record information for Host IP.'),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'title' => t('HostIP'),
      'id' => 'numeric',
    ],
  ];
  return $data;
}
