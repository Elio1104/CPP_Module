#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <algorithm>

template< typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container> {
    private : 
    public : 
        MutantStack( void ) {};
        MutantStack( const MutantStack& other ) { *this = other; };
        MutantStack& operator=( const MutantStack& other ) { 
            std::stack< T, Container >::operator=(other);
            return *this;
        };
        ~MutantStack( void ) {};

        typedef typename Container::iterator iterator;

        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };
};