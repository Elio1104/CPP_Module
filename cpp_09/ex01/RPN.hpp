#include "colors.h"
#include <string>
#include <iostream>
#include <stack>

class RPN {
    private :
        std::string         _input;
        std::stack<int>     _numbers;
        std::stack<char>    _operators;

    public :
        RPN( std::string input );
        RPN( const RPN& other );
        ~RPN( void ) ;
        RPN& operator=( const RPN& other );

        void readInput( void );
        void error( std::string type );
        int checkOperator( char action );
        void singleOperation( void );
};