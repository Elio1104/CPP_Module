#include "easyfind.hpp"
#include <algorithm>

int main( void )
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );

    std::cout << "\033[1;30m---------------- Vector ----------------\033[0m" << std::endl;

    easyfind( vect, 4);
    easyfind( vect, -3);
    easyfind( vect, 15);

    std::cout << "\033[1;30m---------------- List ----------------\033[0m" << std::endl;

    easyfind( list, 7);
    easyfind( list, -3);
    easyfind( list, 17);

    return EXIT_SUCCESS;
}
