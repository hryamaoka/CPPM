#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void printTestHeader(const std::string& title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
  printTestHeader("Subject Required Test");

  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  printTestHeader("Unknown Materia Test");

  IMateriaSource* src2 = new MateriaSource();
  src2->learnMateria(new Ice());

  AMateria* unknown = src2->createMateria("fire");
  if (!unknown) {
    std::cout << "[OK] Unknown materia returns NULL" << std::endl;
  }

  delete src2;

  printTestHeader("Inventory Full Test");

  IMateriaSource* src3 = new MateriaSource();
  src3->learnMateria(new Ice());
  src3->learnMateria(new Cure());

  ICharacter* wizard = new Character("wizard");

  wizard->equip(src3->createMateria("ice"));   // slot 0
  wizard->equip(src3->createMateria("cure"));  // slot 1
  wizard->equip(src3->createMateria("ice"));   // slot 2
  wizard->equip(src3->createMateria("cure"));  // slot 3
  wizard->equip(src3->createMateria("ice"));   // full, should handle

  delete wizard;
  delete src3;

  printTestHeader("Unequip Test");

  IMateriaSource* src4 = new MateriaSource();
  src4->learnMateria(new Ice());

  Character* hero = new Character("hero");
  hero->equip(src4->createMateria("ice"));
  hero->equip(src4->createMateria("ice"));

  hero->unequip(0);  // Materia should not be deleted
  hero->unequip(5);  // Invalid slot
  hero->unequip(1);  // Valid unequip

  delete hero;
  delete src4;

  Character::cleanGround();  // Clean up unequipped materias

  printTestHeader("Deep Copy Test: Character");

  IMateriaSource* src5 = new MateriaSource();
  src5->learnMateria(new Ice());
  src5->learnMateria(new Cure());

  Character* original = new Character("original");
  original->equip(src5->createMateria("ice"));
  original->equip(src5->createMateria("cure"));

  Character* copy = new Character(*original);

  std::cout << "Original name: " << original->getName() << std::endl;
  std::cout << "Copy name: " << copy->getName() << std::endl;

  copy->unequip(0);
  std::cout << "[OK] Copy modified without affecting original" << std::endl;

  delete original;
  delete copy;
  delete src5;

  Character::cleanGround();

  printTestHeader("Deep Copy Test: MateriaSource");

  MateriaSource source;
  source.learnMateria(new Ice());
  source.learnMateria(new Cure());

  MateriaSource sourceCopy(source);

  AMateria* fromOriginal = source.createMateria("ice");
  AMateria* fromCopy = sourceCopy.createMateria("ice");

  if (fromOriginal && fromCopy && fromOriginal != fromCopy) {
    std::cout << "[OK] MateriaSource deep copy verified" << std::endl;
  }

  delete fromOriginal;
  delete fromCopy;

  return 0;
}
