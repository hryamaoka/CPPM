/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:54 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:53:56 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  std::cout << "=== Test 1: Basic Construction ===" << std::endl;
  DiamondTrap diamond("HERO");
  diamond.whoAmI();

  std::cout << "\n=== Test 2: Attribute Values ===" << std::endl;
  std::cout << "Testing attack (AD should be 30 from FragTrap):" << std::endl;
  diamond.attack("Villain");  // ScavTrapのattack、30ダメージ

  std::cout << "\nTesting initial energy (should be 50 from ScavTrap):"
            << std::endl;
  for (int i = 0; i < 52; i++) {
    std::cout << "[" << i << "] ";
    diamond.attack("Target");  // 先に一回攻撃しているので、49回でエネルギー切れ
  }

  std::cout << "\n=== Test 3: Special Abilities ===" << std::endl;
  DiamondTrap robot("ROBOT");
  robot.guardGate();      // ScavTrapの能力
  robot.highFivesGuys();  // FragTrapの能力
  robot.whoAmI();         // DiamondTrapの能力

  std::cout << "\n=== Test 4: Name Verification ===" << std::endl;
  DiamondTrap named("Alice");
  named.whoAmI();
  // 期待される出力: I am DiamondTrap Alice, and my ClapTrap name is
  // Alice_clap_name

  std::cout << "\n=== Test 5: Copy Constructor ===" << std::endl;
  DiamondTrap original("Original");
  original.attack("Enemy");
  DiamondTrap copy(original);
  copy.whoAmI();
  copy.attack("Another Enemy");

  std::cout << "\n=== Test 6: Copy Assignment ===" << std::endl;
  DiamondTrap source("Source");
  DiamondTrap dest("Dest");
  dest.whoAmI();
  dest = source;
  dest.whoAmI();  // Sourceの名前になっているはず

  std::cout << "\n=== Test 7: Polymorphism ===" << std::endl;
  ClapTrap* ptr = new DiamondTrap("Poly");
  ptr->attack("Target");  // ScavTrapのattackが呼ばれる
  delete ptr;

  std::cout << "\n=== Test 8: Construction Order ===" << std::endl;
  {
    std::cout << "Creating DiamondTrap..." << std::endl;
    DiamondTrap temp("TEMP");
    std::cout << "About to destroy DiamondTrap..." << std::endl;
  }
  std::cout << "DiamondTrap destroyed." << std::endl;

  return 0;
}
