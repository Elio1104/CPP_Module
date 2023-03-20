#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap robot1("Henry");
	ScavTrap robot2("Jacky");
	FragTrap robot3("Chappy");

	std::cout << std::endl << "\033[4;33m--- COPY / ASSIGNMENT ---\033[0m" << std::endl;
	FragTrap robot4("NOTHING");
	robot4 = robot3;

	std::cout << std::endl << "\033[4;33m--- SCAVTRAP ---\033[0m" << std::endl;
	robot3.attack("Henry");
	robot3.takeDamage(20);
	robot3.takeDamage(15);
	robot3.beRepaired(25);
	robot3.view();
	robot3.highFivesGuys();
}