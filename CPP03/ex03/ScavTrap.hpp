/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:54:06 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:54:10 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// 仮想継承 (Virtual Inheritance)
// DiamondTrapがScavTrapとFragTrapの両方を継承した際、
// 大元の基底クラス(ClapTrap)が重複して2つ生成される「ダイヤモンド継承問題」を防ぐ。
// これにより、DiamondTrapインスタンス内でClapTrapの実体が「唯一つ」に共有される。
class ScavTrap : virtual public ClapTrap {
 private:
  bool _guardMode;

 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  virtual ~ScavTrap();

  void guardGate();
  virtual void attack(const std::string& target);
};

#endif
