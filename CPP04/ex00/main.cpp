#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void printTestHeader(const std::string& title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
  printTestHeader("Subject Required Test: Polymorphism");

  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  printTestHeader("Wrong Animal Test: No Polymorphism");

  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound();  // will output WrongAnimal sound (not polymorphic)
  wrongMeta->makeSound();

  delete wrongMeta;
  delete wrongCat;

  printTestHeader("Additional Test: Copy Constructor & Assignment");

  Dog originalDog;
  Dog copiedDog(originalDog);
  Dog assignedDog;
  assignedDog = originalDog;

  std::cout << "Original: ";
  originalDog.makeSound();
  std::cout << "Copied: ";
  copiedDog.makeSound();
  std::cout << "Assigned: ";
  assignedDog.makeSound();

  return 0;
}
