/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* FragTrap.cpp                                       :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 16:52:35 by hyamaoka          #+#    #+#             */
/* Updated: 2025/12/10 16:52:36 by hyamaoka         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap : default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap " << _name << ": constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap : copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap : copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << _name << ": destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
  // 先に行動可能かチェックする（死んでいたらハイタッチできない）
  if (_hitPoints <= 0) {
    std::cout << "FragTrap " << _name
              << " tries to high five but is too weak..." << std::endl;
    return;
  }

  // 課題指定のアクション（ハイタッチ要求）
  std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
  // 先に行動可能かチェックする
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    std::cout << "FragTrap " << _name
              << " tries to attack but has no energy or hit points left!"
              << std::endl;
    return;
  }

  // コスト支払い
  _energyPoints--;

  // 課題指定のログ（成功時のみ表示）
  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}
