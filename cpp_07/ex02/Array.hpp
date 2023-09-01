#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename T >
class Array {
    private:
        T*              _arr;
        unsigned int    _size;

    public:
        Array( void ) : _arr( new T() ), _size( 0 ) {};
        
        Array( unsigned int n ) : _arr( new T[n] ), _size( n ) {};

        Array( const Array& other ) : _arr( new T[ other._size ] ), _size( other._size ) {
            for ( unsigned int i( 0 ); i < other._size ; i++ )
                _arr[ i ] = other._arr[ i ];
        };

        Array& operator=( const Array& other ) {
            if (this != &other ) {
                delete _arr;
                _arr = new T[ other._size ];
                _size = other._size ;
                for ( unsigned int i( 0 ); i < _size ; i++ )
                    _arr[ i ] = other._arr[ i ];
            }
            return *this;   
        }

        T& operator[]( unsigned int i ) const {
            if ( i >= _size )
                throw OutOfRangeException();
            return _arr[i];
        }

        unsigned int  size( void ) const { return _size; }

        ~Array( void ) { delete [] _arr; };

        class OutOfRangeException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Index is out of range"; }
        };
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}

#endif