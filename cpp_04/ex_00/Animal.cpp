#include "Animal.hpp"

Animal::Animal( void ) : _type(0)
{
	std::cout << "\033[1;31m< Animal > - Constructor called !\033[0m" << std::endl;
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
