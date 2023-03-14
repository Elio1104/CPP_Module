#include "Zombie.hpp"

#define N 4

int main(void)
{
    Zombie *horde = zombieHorde(N, "Bob");

    for (int i = 0; i < N; i++)
	{
		std::cout << i << " : " ;
        horde[i].announce();
    }

    delete [] horde;
    return 0;
}