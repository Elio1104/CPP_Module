#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private :
	int _rawBits;
	static const int _fracBits = 8;

public :
	Fixed();
	Fixed( const int n );
	Fixed( const float n );
	Fixed( const Fixed &other );
	Fixed& operator=( const Fixed &other );
	~Fixed();

	float toFloat( void ) const ;
	int toInt( void ) const ;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif