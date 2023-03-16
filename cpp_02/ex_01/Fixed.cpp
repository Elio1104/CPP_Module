#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _rawBits(n << _fracBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _rawBits( roundf( n * ( 1 << _fracBits ) )) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=( const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>( this->getRawBits() ) / ( 1 << this->_fracBits );
}

int Fixed::toInt(void) const {
	return (this->_rawBits >> this->_fracBits);
}

int Fixed::getRawBits( void ) const {
	return this->_rawBits;
}

void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}