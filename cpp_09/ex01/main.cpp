#include "RPN.hpp"
#include "colors.h"

int main( int ac, char **av ) {
    if ( ac != 2 ) {
        std::cout << FRED( "Error: " ) << "wrong argument."  << std::endl ;
        exit( 1 );
    }
    RPN equation( av[1] );
}