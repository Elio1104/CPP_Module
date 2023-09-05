#include "ScalarConverter.hpp"

char ScalarConverter::_c;
int ScalarConverter::_n;
float ScalarConverter::_f;
double ScalarConverter::_d;

e_type ScalarConverter::_type;
std::string ScalarConverter::_str;

bool ScalarConverter::_impossible;

int main (int ac, char **av) {
    if ( ac != 2 ) {
        std::cout << "Usage : ./convert <number>" << std::endl;
        return 0;
    }
    try
    {
        ScalarConverter::convert( av[1] );
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}