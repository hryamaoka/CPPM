#include <iostream>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void printTestHeader(const std::string& title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
  printTestHeader("Abstract Class Verification");

  std::cout << "The following code would cause compilation errors:"
            << std::endl;
  std::cout << "  // AAnimal animal;        // Error: cannot instantiate"
            << std::endl;
  std::cout
      << "  // AAnimal* ptr = new AAnimal();  // Error: cannot instantiate"
      << std::endl;

  std::cout << "\nBut polymorphism still works:" << std::endl;

  AAnimal* dog = new Dog();
  AAnimal* cat = new Cat();

  std::cout << dog->getType() << ": ";
  dog->makeSound();

  std::cout << cat->getType() << ": ";
  cat->makeSound();

  delete dog;
  delete cat;

  printTestHeader("Array Test: Polymorphism with Abstract Base");

  const int SIZE = 4;
  AAnimal* animals[SIZE];

  for (int idx = 0; idx < SIZE; idx++) {
    if (idx % 2 == 0) {
      animals[idx] = new Dog();
    } else {
      animals[idx] = new Cat();
    }
  }

  std::cout << "\nTesting polymorphic behavior:" << std::endl;
  for (int idx = 0; idx < SIZE; idx++) {
    std::cout << "animals[" << idx << "]: ";
    animals[idx]->makeSound();
  }

  std::cout << "\nDeleting all animals..." << std::endl;
  for (int idx = 0; idx < SIZE; idx++) {
    delete animals[idx];
  }

  printTestHeader("Deep Copy Test: Maintained from Ex01");

  Dog original;
  original.setIdea(0, "Deep copy test");

  Dog copy(original);
  original.setIdea(0, "Modified");

  if (copy.getBrain()->getIdea(0) == "Deep copy test") {
    std::cout << "[OK] Deep copy still works correctly" << std::endl;
  }

  return 0;
}
