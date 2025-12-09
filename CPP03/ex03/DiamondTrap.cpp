/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* DiamondTrap.cpp                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/12/08 16:53:28 by hyamaoka          #+#    #+#             */
/* Updated: 2025/12/10 16:53:30 by hyamaoka         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), _name("default") {
  // 課題要件: HP(Frag), EP(Scav), AD(Frag) の値を採用する
  _hitPoints = 100;    // FragTrap::_hitPoints
  _energyPoints = 50;  //  ScavTrap::_energyPoints
  _attackDamage = 30;  //  FragTrap::_attackDamage

  std::cout << "DiamondTrap : default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      _name(name) {
  // 課題要件: HP(Frag), EP(Scav), AD(Frag) の値を採用する
  _hitPoints = 100;    // FragTrap::_hitPoints
  _energyPoints = 50;  //  ScavTrap::_energyPoints
  _attackDamage = 30;  //  FragTrap::_attackDamage

  std::cout << "DiamondTrap " << _name << ": constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
  std::cout << "DiamondTrap : copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  std::cout << "DiamondTrap : copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    // ScavTrap, FragTrapの代入演算子はClapTrapを呼ぶだけなので省略可だが、
    // 固有メンバがある場合は注意。今回は_nameのみ更新。
    _name = other._name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << _name << ": destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
  // 自分の名前(_name)と、親のClapTrapの名前を表示する
  std::cout << "I am DiamondTrap " << _name << ", and my ClapTrap name is "
            << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  // 課題要件: ScavTrapクラスのattack関数を使用する
  ScavTrap::attack(target);
}
