#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_mana = 50;
	this->_dmg = 20;

	std::cout << "\033[1;31m<ScavTrap> - "<< name << " default constructor called.\033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
	std::cout << "\033[1;31m<ScavTrap> - "<< this->_name << " copy constructor called.\033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const& other)
{
	ClapTrap::operator=(other);
	std::cout << "\033[1;31m<ScavTrap> - "<< this->_name << " assignment constructor called.\033[0m" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "\033[1;31m<ScavTrap> - "<< this->_name << " destructor called.\033[0m" << std::endl;
}

//----------------- Methode -----------------//

void ScavTrap::attack(const std::string &target)
{
	if (_hp > 0 && _mana > 0) {
		_mana--;
		std::cout << "\033[1;31m<ScavTrap> - " << _name <<" attacks "<< target << ", causing " << _dmg << " points of damage!\033[0m" << std::endl;
	} else if (_hp <= 0)
		std::cout << "\033[1;31m<ScavTrap> - " << _name << " is KO!\033[0m" << std::endl;
	else if (_mana <= 0)
		std::cout << "\033[1;31m<ScavTrap> - " << _name << " got no mana to perform an attack.\033[0m" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "\033[1;31m<ScavTrap> - " << _name <<" is now guarding the Gate !\033[0m" << std::endl;
}