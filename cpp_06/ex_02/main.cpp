#include <iostream>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate ( void ) {
    int i = std::rand() % 3;
    if ( i == 0 ) {
        std::cout << "Creating Base A" << std::endl;
        return ( new A );
    }
    else if ( i == 1 ) {
        std::cout << "Creating Base B" << std::endl;
        return ( new B );
    }
    else {
        std::cout << "Creating Base C" << std::endl;
        return ( new C );
    }
}

void identify ( Base* p ) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << "\033[1;33mIt's a A base.\033[0m" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "\033[1;33mIt's a B base.\033[0m" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "\033[1;33mIt's a C base.\033[0m" << std::endl;
    else
        std::cout << "\033[1;33mUnknown base.\033[0m" << std::endl;
}

void identify ( Base& p ) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "\033[1;32mIt's a A base.\033[0m" << std::endl;
        (void)a;
    } catch ( const std::exception& e ) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "\033[1;32mIt's a B base.\033[0m" << std::endl;
        (void)b;
    } catch ( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "\033[1;32mIt's a C base.\033[0m" << std::endl;
        (void)c;
    } catch ( const std::exception& e ) {}
}

int main ( void ) {
    std::srand(time(0));
    std::cout << " ------------------- Generating ------------------- " << std::endl;
    Base*   a = generate();
    identify( a );
    identify( *a );
    delete a;

    std::cout << " ------------------- Generating ------------------- " << std::endl;
    Base*   b = generate();
    identify( b );
    identify( *b );
    delete b;

    std::cout << " ------------------- Generating ------------------- " << std::endl;
    Base*   c = generate();
    identify( c );
    identify( *c );
    delete c;

    std::cout << " ------------------- Generating ------------------- " << std::endl;
    Base*   d = generate();
    identify( d );
    identify( *d );
    delete d;
    
    return ( 0 );
}