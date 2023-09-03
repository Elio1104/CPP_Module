#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template < typename T >
void    easyfind ( T& container , int value ) {
    if ( std::find( container.begin(), container.end(), value) != container.end() )
        std::cout << "\033[1;36mValue Found.\033[0m" << std::endl;
    else
        std::cout << "\033[1;31mValue not found.\033[0m" << std::endl;
}

#endif