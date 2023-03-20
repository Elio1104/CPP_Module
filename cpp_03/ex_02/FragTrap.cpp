#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_mana = 50;
	this->_dmg = 20;

	std::cout << "\033[1;32m<FragTrap> - "<< name << " default constructor called.\033[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
	std::cout << "\033[1;32m<FragTrap> - "<< this->_name << " copy constructor called.\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const& other)
{
	ClapTrap::operator=(other);
	std::cout << "\033[1;32m<FragTrap> - "<< this->_name << " assignment constructor called.\033[0m" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "\033[1;32m<FragTrap> - "<< this->_name << " destructor called.\033[0m" << std::endl;
}

//----------------- Methode -----------------//

void FragTrap::attack(const std::string &target)
{
	if (_hp > 0 && _mana > 0) {
		_mana--;
		std::cout << "\033[1;32m<FragTrap> - " << _name <<" attacks "<< target << ", causing " << _dmg << " points of damage!\033[0m" << std::endl;
	} else if (_hp <= 0)
		std::cout << "\033[1;32m<FragTrap> - " << _name << " is KO!\033[0m" << std::endl;
	else if (_mana <= 0)
		std::cout << "\033[1;32m<FragTrap> - " << _name << " got no mana to perform an attack.\033[0m" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (_hp > 0 && _mana > 0) {
		_mana--;
		std::cout << "\033[1;31m<ScavTrap> - " << _name <<" high five everybody !\033[0m" << std::endl;
	} else if (_hp <= 0)
		std::cout << "\033[1;31m<ScavTrap> - " << _name << " is KO!\033[0m" << std::endl;
	else if (_mana <= 0)
		std::cout << "\033[1;31m<ScavTrap> - " << _name << " got no mana to perform this action.\033[0m" << std::endl;
}