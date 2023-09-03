#include "Span.hpp"

Span::Span( unsigned int N ) : _n( N ) {}

Span::Span( const Span& other ) : _n( other._n ) {
    for ( std::vector<int>::const_iterator it = other._arr.begin(); it != other._arr.end(); it++ )
        _arr.push_back( *it );
}

Span::~Span( void ) {}

Span& Span::operator=(const Span &other) {
    if ( this != &other ) {
        this->_n = other._n;
        for ( std::vector<int>::const_iterator it = other._arr.begin(); it != other._arr.end(); it++ )
            this->_arr.push_back( *it );
    }
    return *this;
}

void Span::addNumber( int n )
{
    if ( _arr.size() >= _n)
        throw OutOfRangeException();
    _arr.push_back( n );
}

void Span::addNumber( std::vector<int>::const_iterator it_begin , std::vector<int>::const_iterator it_end )
{
    if ( _arr.size() + distance( it_begin, it_end ) > _n)
        throw OutOfRangeException();
    _arr.insert( _arr.end(), it_begin, it_end);
}

unsigned int Span::size( void ) const
{
    return _arr.size();
}

unsigned int Span::longestSpan( void ) const
{
    if ( _arr.size() < 2 )
        throw NoSpanException();
    return ( std::abs( *std::max_element( _arr.begin() , _arr.end() ) - *std::min_element( _arr.begin() , _arr.end() ) ) );
}

unsigned int Span::shortestSpan( void ) const
{
    unsigned int min = Span::longestSpan() ;
    if ( _arr.size() < 2 )
        throw NoSpanException();
    for ( std::vector<int>::const_iterator it1 = _arr.begin(); it1 != _arr.end(); it1++ )
        for ( std::vector<int>::const_iterator it2 = _arr.begin(); it2 != _arr.end(); it2++ )
            if ( std::abs(*it1 - *it2) < min && it1 != it2 )
                min = std::abs(*it1 - *it2);
    return min;
}

const char* Span::OutOfRangeException::what() const throw() {
	return "Can't add Number : Array is full";
}

const char* Span::NoSpanException::what() const throw() {
	return "No Span : Array is empty or only get 1 element";
}
