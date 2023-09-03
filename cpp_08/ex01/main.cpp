#include "Span.hpp"

int main( void )
{
    try {
        Span sp1 = Span(20);
        std::vector<int> vec;
        for (int i(0); i < 30; i+= 3)
            vec.push_back(i);
        sp1.addNumber(vec.begin(), vec.end());
        std::cout << sp1.longestSpan() << std::endl;
        std::cout << sp1.shortestSpan() << std::endl;
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
        Span sp = Span(20);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
        Span error = Span(1);
        error.addNumber(2);
        //std::cout << error.longestSpan() << std::endl;
        //std::cout << error.shortestSpan() << std::endl;
        error.addNumber(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}