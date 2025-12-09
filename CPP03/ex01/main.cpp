/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:52:14 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:52:17 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  std::cout << "=== Test 1: ClapTrap basic operations ===" << std::endl;
  ClapTrap claptrap("CT-001");
  claptrap.attack("Target");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);

  std::cout << "\n=== Test 2: ScavTrap basic operations ===" << std::endl;
  ScavTrap scavtrap("ST-002");
  scavtrap.attack("Target");
  scavtrap.takeDamage(120);
  scavtrap.beRepaired(3);
  scavtrap.guardGate();
  scavtrap.guardGate();

  std::cout << "\n=== Test 3: Construction/Destruction chain ===" << std::endl;
  {
    ScavTrap temp("TEMP");
    // スコープを抜けると自動的にデストラクタが呼ばれる
  }
  std::cout << "After temp destruction" << std::endl;

  std::cout << "\n=== Test 4: Copy operations ===" << std::endl;
  ScavTrap original("Original");
  original.guardGate();

  ScavTrap copy(original);  // コピーコンストラクタ
  copy.attack("Enemy");

  ScavTrap assigned("Assigned");
  assigned = original;  // コピー代入演算子
  assigned.attack("Enemy");

  std::cout << "\n=== Test 5: Energy depletion ===" << std::endl;
  ScavTrap energyTest("Energy");
  for (int i = 0; i < 52; i++) {  // 50回でエネルギー切れ
    std::cout << "[" << i << "] ";
    energyTest.attack("Enemy");
  }

  std::cout << "\n=== Test 6: Polymorphism ===" << std::endl;
  ClapTrap* ptr = new ScavTrap("Poly");
  ptr->attack("Target");  // ScavTrapのattackが呼ばれる（virtualの影響）
  delete ptr;             // 正しくデストラクタが呼ばれる（virtualの影響）

  return 0;
}
