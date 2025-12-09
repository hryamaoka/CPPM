#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "Brain constructor called" << std::endl;
  for (int i = 0; i < IDEA_COUNT; i++) {
    this->ideas[i] = "";
  }
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructor called" << std::endl;
  for (int i = 0; i < IDEA_COUNT; i++) {
    this->ideas[i] = other.ideas[i];
  }
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "Brain assignment operator called" << std::endl;
  if (this != &other) {
    for (int i = 0; i < IDEA_COUNT; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

void Brain::setIdea(int index, const std::string& idea) {
  if (index >= 0 && index < IDEA_COUNT) {
    this->ideas[index] = idea;
  }
}

std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < IDEA_COUNT) {
    return this->ideas[index];
  }
  return "";
}

void Brain::printIdeas(int count) const {
  if (count > IDEA_COUNT) count = IDEA_COUNT;
  for (int i = 0; i < count; i++) {
    if (!this->ideas[i].empty()) {
      std::cout << "  [" << i << "] " << this->ideas[i] << std::endl;
    }
  }
}
