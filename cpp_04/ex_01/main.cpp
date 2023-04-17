#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main ( void ) {

	std::cout << std::endl << "\033[4;33m--- TEST 1 ---\033[0m" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

	std::cout << std::endl << "\033[4;33m--- TEST 2 ---\033[0m" << std::endl;
    {
		Dog basic;
		{
			Dog tmp = basic;
		}
	}

	std::cout << std::endl << "\033[4;33m--- TEST 3 ---\033[0m" << std::endl;
    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

    return 0;
}