#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "\033[1;36m< Brain > - Default constructor called !\033[0m" << std::endl;
}

Brain::~Brain( void )
{
    std::cout << "\033[1;36m< Brain > - Destructor called !\033[0m" << std::endl;
}

Brain::Brain( const Brain& other )
{
	std::cout << "\033[1;36m< Brain > - Copy constructor called !\033[0m" << std::endl;
    *this = other;
}

Brain& Brain::operator=( const Brain& other )
{
    std::cout << "\033[1;36m< Brain > - Assignment constructor called !\033[0m" << std::endl;
    if ( this != &other ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return *this;
}


