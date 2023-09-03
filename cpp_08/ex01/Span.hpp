#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
    private :
        std::vector<int> _arr;
        unsigned int _n;

        Span( void );
    public :
        /*---------------- Vector ----------------*/
        Span( unsigned int N );
        Span( const Span& other );
        ~Span( void );
        Span& operator=( const Span& other);

        void addNumber( int n );
        void addNumber( std::vector<int>::const_iterator it_begin , std::vector<int>::const_iterator it_end );
        unsigned int size( void ) const;
        
        /*----------------- Span -----------------*/

        unsigned int longestSpan( void ) const ;
        unsigned int shortestSpan( void ) const ;

        /*----------------- Exception -----------------*/

        class OutOfRangeException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif