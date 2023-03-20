#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private :

public :
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& other);
	ScavTrap& operator=(ScavTrap const& other);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate( void );
};

#endif