<?php

namespace Drupal\login_tracker\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\login_tracker\Controller\DisplayTableController;

/**
 * Provides a Block that uses the DisplayTableController.
 * @Block(
 * id = "login_block",
 * admin_label = @Translation("Login block"),
 * category = @Translation("Login Tracker"),
 * )
 */
class LogintrackerBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {

     $controller_variable = new DisplayTableController;
     $rendering_in_block = $controller_variable->ConnectToUserLoginsAndGetLoginData();
     return $rendering_in_block;

  }
}
