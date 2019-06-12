<?php
   
namespace Drupal\login_tracker\Controller;

use Drupal\Core\Database\Connection;


    class DisplayTableController {

         public function ConnectToUserLoginsAndGetLoginData(){

              $connection = \Drupal::database();

              $query = $connection->select('user_logins', 'u');

              $query->fields('u',['uid', 'timestamp', 'host']);

              $query->orderBy('timestamp', 'DESC');

              $query->range(0, 5);

              $result = $query->execute();

            // Create the row element.
              $rows = array();
              foreach ($result as $row => $content) {
                $rows[] = array(
                  'data' => array($content->uid, $content->timestamp, $content->host));
              }
          // Create the header.
              $header = array('uid', 'timestamp', 'host');
              $output = array(
                '#theme' => 'table',    // Here you can write #type also instead of #theme.
                '#header' => $header,
                '#rows' => $rows
              );
              return $output;

         }
    }