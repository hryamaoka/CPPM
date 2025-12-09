/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ClapTrap.cpp                                       :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 16:51:53 by hyamaoka          #+#    #+#             */
/* Updated: 2025/12/08 16:51:55 by hyamaoka         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <limits>

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap : default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << _name << ": constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap : copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap : copy assignment operator called" << std::endl;
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << ": destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  // 先に行動可能かチェックする
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    std::cout << "ClapTrap " << _name
              << " tries to attack but has no energy or hit points left!"
              << std::endl;
    return;
  }

  // コスト支払い
  _energyPoints--;

  // 課題指定のログ（成功時のみ表示）
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    return;
  }

  // ダメージ処理
  if (_hitPoints > amount) {
    _hitPoints -= amount;
  } else {
    _hitPoints = 0;
  }

  // 状況説明ログ
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage! (Current HP: " << _hitPoints << ")"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  // 修正箇所: HPが0の場合も修理できないようにチェックを追加
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    std::cout << "ClapTrap " << _name
              << " tries to repair itself but has no energy or hit points left!"
              << std::endl;
    return;
  }

  // コスト支払い
  _energyPoints--;

  // 回復処理（オーバーフロー対策）
  if (amount > std::numeric_limits<unsigned int>::max() - _hitPoints) {
    _hitPoints = std::numeric_limits<unsigned int>::max();
  } else {
    _hitPoints += amount;
  }

  // 成功ログ
  std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount
            << " hit points! (Current HP: " << _hitPoints << ")" << std::endl;
}
