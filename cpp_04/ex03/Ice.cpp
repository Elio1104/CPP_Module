#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice( Ice const & src ) : AMateria("ice")
{
    *this = src;
}

Ice&   Ice::operator=( const Ice& other ) {
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}