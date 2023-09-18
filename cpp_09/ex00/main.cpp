#include "BitcoinExchange.hpp"
#include "colors.h"

int main( int ac, char **av ) {
    ( void )av;
    if ( ac != 2 ) {
        std::cout << FRED( "Error: " ) << "wrong argument."  << std::endl ;
        exit( 1 );
    }
    BitcoinExchange converter( av[1] );
}