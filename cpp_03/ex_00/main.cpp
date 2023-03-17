#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap robot("R2-D2");

	robot.view();
	
	std::cout << std::endl;

	robot.attack("C3-PO");
	robot.takeDamage(3);
	robot.takeDamage(2);
	robot.beRepaired(4);

	std::cout << std::endl;

	robot.view();

	std::cout << std::endl;

	ClapTrap anotherRobot(robot);
	anotherRobot.takeDamage(9);
	anotherRobot.takeDamage(2);

	std::cout << std::endl;

	anotherRobot.view();
	robot.view();
	anotherRobot = robot;
	anotherRobot.view();
}