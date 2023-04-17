#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << "\033[1;32m< Cat > - Default constructor called.\033[0m" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &other) : Animal(other)
{
	std::cout << "\033[1;32m< Cat > - Copy constructor called.\033[0m" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain( *other._brain );
}

Cat &Cat::operator=(Cat const& other)
{
	std::cout << "\033[1;32m< Cat > - Assignment constructor called.\033[0m" << std::endl;
	if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain( *other._brain );
    }
	return *this;
}

Cat::~Cat() {
	std::cout << "\033[1;32m< Cat > - Destructor called.\033[0m" << std::endl;
	delete this->_brain;
}

//----------------- Methode -----------------//

void Cat::makeSound() const {
	std::cout << "\033[1;32m< Cat > - Meowww.\033[0m" << std::endl;
}