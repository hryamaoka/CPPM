/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:52:02 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:52:04 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  std::cout << "=== Test 1: Basic Operations ===" << std::endl;
  ClapTrap claptrap("CT-001");
  claptrap.attack("Target");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);

  std::cout << "\n=== Test 2: Energy Depletion ===" << std::endl;
  ClapTrap energyTest("CT-002");
  for (int i = 0; i < 12; i++) {  // 10回でエネルギー切れ
    energyTest.attack("Enemy");
  }

  std::cout << "\n=== Test 3: Death ===" << std::endl;
  ClapTrap deathTest("CT-003");
  deathTest.takeDamage(15);   // HP=10なので死亡
  deathTest.attack("Ghost");  // 死亡状態で攻撃を試みる
  deathTest.beRepaired(5);    // 死亡状態で修理を試みる

  std::cout << "\n=== Test 4: Copy ===" << std::endl;
  ClapTrap original("Original");
  ClapTrap copy(original);  // コピーコンストラクタ
  ClapTrap assigned("Temp");
  assigned = original;  // コピー代入演算子

  return 0;
}
