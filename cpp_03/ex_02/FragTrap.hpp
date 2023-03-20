#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private :

public :
	FragTrap(std::string name);
	FragTrap(FragTrap const& other);
	FragTrap& operator=(FragTrap const& other);
	~FragTrap();

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif