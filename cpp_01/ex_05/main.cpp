#include "Harl.hpp"

int main( void ) {
	std::string input = "";
	Harl harl;

	do {
		std::cout << "Enter à complain level : " << std::flush;
		std::cin >> input;
		harl.complain(input);
	} while (input.compare("exit"));

	return 0;
}