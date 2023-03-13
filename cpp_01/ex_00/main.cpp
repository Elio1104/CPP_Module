#include "Zombie.hpp"

int main()
{
	{
		std::cout << "Creating zombie on the stack. (Bob)" << std::endl;

		Zombie zombi1("Bob");
		zombi1.announce();
	}

	{
		std::cout << "Creating zombie on the heap. (Patrick)" << std::endl;

		Zombie *zombi2 = newZombie("Patrick");
		zombi2->announce();
		delete zombi2;
	}

	{
		std::cout << "Calling randomChump(). (Randi)" << std::endl;
		randomChump("Randi");
	}

    return 0;
}