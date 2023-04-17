#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("NO TYPE")
{
	std::cout << "\033[1;31m< WrongAnimal > - Default constructor called !\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type)
{
	std::cout << "\033[1;31m< WrongAnimal > - Copy constructor called !\033[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "\033[1;31m< WrongAnimal >  - Assignment constructor called !\033[0m" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;31m< WrongAnimal > - Destructor called !\033[0m" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "\033[1;31m< WrongAnimal > - Sound is not setup.\033[0m" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}