#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
}

Cure::Cure( Cure const & src ) : AMateria("cure")
{
    *this = src;
}

Cure&   Cure::operator=( const Cure& other ) {
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
