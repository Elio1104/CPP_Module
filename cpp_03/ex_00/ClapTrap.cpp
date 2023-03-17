#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _mana(10), _dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) : _name(other._name), _hp(other._hp), _mana(other._mana), _dmg(other._dmg)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Assignment constructor called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_mana = other._mana;
		_dmg = other._dmg;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

//----------------- Methode -----------------//

void ClapTrap::attack(const std::string &target)
{
	if (_hp > 0 && _mana > 0) {
		_mana--;
		std::cout << _name <<" attacks "<< target << ", causing " << _dmg << " points of damage!" << std::endl;
	} else if (_hp <= 0)
		std::cout << _name << " is KO!" << std::endl;
	else if (_mana <= 0)
		std::cout << _name << " got no mana to perform an attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " is attacked." << std::endl;
	if (_hp > 0) {
		std::cout << _name << " took damage. (-" << amount << "HP)" << std::endl;
		_hp -= amount;
		if (_hp <= 0){
			std::cout << _name << " is KO!" << std::endl;
			_hp = 0;
		}
	}
	else
		std::cout << _name <<" is already KO !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp > 0 && _mana > 0) {
		_hp += amount;
		if (_hp > 10)
			_hp = 10;
		_mana--;
		std::cout << _name <<" got repaired. (+" << amount << "HP)." << std::endl;
	} else if (_hp <= 0)
		std::cout << _name << " is KO!" << std::endl;
	else if (_mana <= 0)
		std::cout << _name << " got no mana to perform a repair." << std::endl;
}

void ClapTrap::view( void ) {
	std::cout << "--- " << _name << " ---" << std::endl;
	std::cout << "HP : " << _hp << " / 10" << std::endl;
	std::cout << "Mana : " << _mana << " / 10" << std::endl;
	std::cout << "Dmg : " << _dmg << std::endl;
}