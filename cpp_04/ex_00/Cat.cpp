#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	this->_type = "Cat";

	std::cout << "\033[1;32m< Cat > - Default constructor called.\033[0m" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other)
{
	this->_type = "Cat";
	std::cout << "\033[1;32m< Cat > - Copy constructor called.\033[0m" << std::endl;
}

Cat &Cat::operator=(Cat const& other)
{
	Animal::operator=(other);
	this->_type = "Cat";
	std::cout << "\033[1;32m< Cat > - Assignment constructor called.\033[0m" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "\033[1;32m< Cat > - Destructor called.\033[0m" << std::endl;
}

//----------------- Methode -----------------//

void Cat::makeSound() const {
	std::cout << "\033[1;32m< Cat > - Meowww.\033[0m" << std::endl;
}