#include "Animal.hpp"

Animal::Animal( void ) : _type("NO TYPE")
{
	std::cout << "\033[1;31m< Animal > - Default constructor called !\033[0m" << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type)
{
	std::cout << "\033[1;31m< Animal > - Copy constructor called !\033[0m" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << "\033[1;31m< Animal >  - Assignment constructor called !\033[0m" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "\033[1;31m< Animal > - Destructor called !\033[0m" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->_type;
}