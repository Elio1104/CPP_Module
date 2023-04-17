#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "\033[1;32m< Dog > - Default constructor called.\033[0m" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();

}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "\033[1;32m< Dog > - Copy constructor called.\033[0m" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain( *other._brain );
}

Dog &Dog::operator=(Dog const& other)
{
	std::cout << "\033[1;32m< Dog > - Assignment constructor called.\033[0m" << std::endl;
	if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain( *other._brain );
    }
	return *this;
}

Dog::~Dog() {
	std::cout << "\033[1;32m< Dog > - Destructor called.\033[0m" << std::endl;
	delete this->_brain;
}

//----------------- Methode -----------------//

void Dog::makeSound() const {
	std::cout << "\033[1;32m< Dog > - Woof.\033[0m" << std::endl;
}