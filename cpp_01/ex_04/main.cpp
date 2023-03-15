#include <iostream>
#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Try : ./Replace <filename> <to_find> <replace>" << std::endl;
		return 1;
	} else {
		Sed sed(av[1]);
		sed.replace(av[2], av[3]);
	}
	return 0;
}