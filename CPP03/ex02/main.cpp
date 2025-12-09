/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:52:42 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:52:44 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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
  scavtrap.takeDamage(5);
  scavtrap.beRepaired(3);
  scavtrap.guardGate();

  std::cout << "\n=== Test 3: FragTrap basic operations ===" << std::endl;
  FragTrap fragtrap("FT-003");
  fragtrap.attack("Target");
  fragtrap.takeDamage(50);
  fragtrap.beRepaired(20);
  fragtrap.highFivesGuys();

  std::cout << "\n=== Test 4: FragTrap death scenario ===" << std::endl;
  FragTrap deadTrap("DEAD");
  deadTrap.takeDamage(500);
  deadTrap.attack("Ghost");
  deadTrap.beRepaired(100);
  deadTrap.highFivesGuys();

  std::cout << "\n=== Test 5: Construction/Destruction chain ===" << std::endl;
  {
    FragTrap temp("TEMP");
  }
  std::cout << "After temp destruction" << std::endl;

  std::cout << "\n=== Test 6: Copy operations ===" << std::endl;
  FragTrap original("Original");
  FragTrap copy(original);  // コピーコンストラクタ
  FragTrap assigned("Assigned");
  assigned = original;  // コピー代入演算子

  std::cout << "\n=== Test 7: Energy depletion ===" << std::endl;
  FragTrap energyTest("Energy");
  for (int i = 0; i < 102; i++) {  // 100回でエネルギー切れ
    std::cout << "[" << i << "] ";
    energyTest.attack("Enemy");
  }

  std::cout << "\n=== Test 8: Polymorphism ===" << std::endl;
  ClapTrap* ptr1 = new FragTrap("Poly1");
  ClapTrap* ptr2 = new ScavTrap("Poly2");

  ptr1->attack("Target");  // FragTrapのattackが呼ばれる
  ptr2->attack("Target");  // ScavTrapのattackが呼ばれる

  delete ptr1;  // 正しいデストラクタが呼ばれる
  delete ptr2;

  std::cout << "\n=== Test 9: Attribute comparison ===" << std::endl;
  ClapTrap ct("Compare1");
  ScavTrap st("Compare2");
  FragTrap ft("Compare3");

  std::cout << "Testing different attack damages:" << std::endl;
  ct.attack("Target");  // 0 damage
  st.attack("Target");  // 20 damage
  ft.attack("Target");  // 30 damage

  return 0;
}
