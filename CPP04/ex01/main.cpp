#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void printTestHeader(const std::string& title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
  printTestHeader("Subject Required Test: Memory Safety");

  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;  // should not create a leak
  delete i;

  printTestHeader("Array Test: Half Dogs, Half Cats");

  const int SIZE = 6;
  Animal* animals[SIZE];

  for (int idx = 0; idx < SIZE; idx++) {
    if (idx < SIZE / 2) {
      animals[idx] = new Dog();
    } else {
      animals[idx] = new Cat();
    }
  }

  std::cout << "\nDeleting all animals..." << std::endl;
  for (int idx = 0; idx < SIZE; idx++) {
    delete animals[idx];
  }

  printTestHeader("Deep Copy Test: Copy Constructor");

  Dog original;
  original.setIdea(0, "Original idea");

  Dog copy(original);
  original.setIdea(0, "Modified idea");

  std::cout << "Original's brain: " << original.getBrain() << std::endl;
  std::cout << "Copy's brain: " << copy.getBrain() << std::endl;
  std::cout << "Copy's idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

  if (copy.getBrain()->getIdea(0) == "Original idea") {
    std::cout << "[OK] Deep copy verified (data is isolated)" << std::endl;
  }

  printTestHeader("Deep Copy Test: Assignment Operator");

  Cat cat1;
  cat1.setIdea(0, "Cat1 idea");

  Cat cat2;
  Brain* oldBrain = cat2.getBrain();

  cat2 = cat1;

  std::cout << "Cat1's brain: " << cat1.getBrain() << std::endl;
  std::cout << "Cat2's new brain: " << cat2.getBrain() << std::endl;
  std::cout << "Cat2's old brain: " << oldBrain << " (deleted)" << std::endl;

  if (cat1.getBrain() != cat2.getBrain()) {
    std::cout << "[OK] Deep copy verified (different addresses)" << std::endl;
  }

  return 0;
}
