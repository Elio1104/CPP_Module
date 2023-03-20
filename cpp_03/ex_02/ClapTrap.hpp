#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected :
	std::string _name;
	int _hp;
	int _mana;
	int _dmg;

public :
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& other);
	ClapTrap& operator=(ClapTrap const& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void view( void );
};

#endif