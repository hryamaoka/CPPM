/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:46 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:53:50 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// 仮想継承 (Virtual Inheritance)
// DiamondTrapがScavTrapとFragTrapの両方を継承した際、
// 大元の基底クラス(ClapTrap)が重複して2つ生成される「ダイヤモンド継承問題」を防ぐ。
// これにより、DiamondTrapインスタンス内でClapTrapの実体が「唯一つ」に共有される。
class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  virtual ~FragTrap();

  void highFivesGuys(void);
  virtual void attack(const std::string& target);
};

#endif
