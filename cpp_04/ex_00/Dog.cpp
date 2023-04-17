#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	this->_type = "Dog";

	std::cout << "\033[1;32m< Dog > - Default constructor called.\033[0m" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	this->_type = "Dog";
	std::cout << "\033[1;32m< Dog > - Copy constructor called.\033[0m" << std::endl;
}

Dog &Dog::operator=(Dog const& other)
{
	Animal::operator=(other);
	this->_type = "Dog";
	std::cout << "\033[1;32m< Dog > - Assignment constructor called.\033[0m" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "\033[1;32m< Dog > - Destructor called.\033[0m" << std::endl;
}

//----------------- Methode -----------------//

void Dog::makeSound() const {
	std::cout << "\033[1;32m< Dog > - Woof.\033[0m" << std::endl;
}