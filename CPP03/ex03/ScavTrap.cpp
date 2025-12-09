/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ScavTrap.cpp                                       :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 16:52:19 by hyamaoka          #+#    #+#             */
/* Updated: 2025/12/10 16:52:20 by hyamaoka         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default"), _guardMode(false) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap : default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name), _guardMode(false) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap " << _name << ": constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  _guardMode = other._guardMode;
  std::cout << "ScavTrap : copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "ScavTrap : copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    _guardMode = other._guardMode;
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << _name << ": destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  // ClapTrapと同様、先に行動可能かチェックする
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    std::cout << "ScavTrap " << _name
              << " tries to attack but has no energy or hit points left!"
              << std::endl;
    return;
  }

  // コスト支払い
  _energyPoints--;

  // ScavTrap特有の攻撃ログ
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
  if (_guardMode) {
    std::cout << "ScavTrap " << _name << " is already in Gate keeper mode."
              << std::endl;
  } else {
    _guardMode = true;
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode."
              << std::endl;
  }
}
