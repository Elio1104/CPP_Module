#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap robot1("Henry");
	ScavTrap robot2("Jacky");

	std::cout << std::endl << "\033[4;33m--- COPY / ASSIGNMENT ---\033[0m" << std::endl;
	ScavTrap robot3(robot2);
	robot3 = robot2;

	std::cout << std::endl << "\033[4;33m--- SCAVTRAP ---\033[0m" << std::endl;
	robot2.attack("Henry");
	robot2.takeDamage(20);
	robot2.takeDamage(15);
	robot2.beRepaired(25);
	robot2.view();
	robot2.guardGate();
}