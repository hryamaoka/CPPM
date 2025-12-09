/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:52:10 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:53:08 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
  // ex00 では private だったメンバを protected に変更。
  // → ex01 以降で作る ScavTrap / FragTrap などの「派生クラス」から
  //    直接 _name / _hitPoints などを読み書きできるようにするため。
 protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);

  // デストラクタを virtual に変更。
  // → ClapTrap* ポインタ経由で派生クラス（ScavTrap など）を delete したとき、
  //    派生クラス側のデストラクタまで正しく呼ばれるようにするため。
  virtual ~ClapTrap();

  // attack を virtual に変更。
  // → 派生クラス側で「メッセージ内容だけ差し替えた attack()」を
  //    オーバーライドできるようにするため（多態性を持たせる）。
  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
