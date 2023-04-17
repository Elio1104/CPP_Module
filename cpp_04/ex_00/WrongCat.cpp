#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->_type = "WrongCat";

	std::cout << "\033[1;32m< WrongCat > - Default constructor called.\033[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	this->_type = "WrongCat";
	std::cout << "\033[1;32m< WrongCat > - Copy constructor called.\033[0m" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const& other)
{
	WrongAnimal::operator=(other);
	this->_type = "WrongCat";
	std::cout << "\033[1;32m< WrongCat > - Assignment constructor called.\033[0m" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "\033[1;32m< WrongCat > - Destructor called.\033[0m" << std::endl;
}

//----------------- Methode -----------------//

void WrongCat::makeSound() const {
	std::cout << "\033[1;32m< WrongCat > - Meowww.\033[0m" << std::endl;
}