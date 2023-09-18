#include "PmergeMe.hpp"
#include "colors.h"

int main( int ac, char **av ) {
    if ( ac < 3 ) {
        std::cout << FRED( "Error: " ) << "wrong argument."  << std::endl ;
        exit( 1 );
    }
    PmergeMe sort( av );
}