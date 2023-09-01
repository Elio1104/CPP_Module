#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
#define SIZE 10

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    {
        std::cout << "-----------------------------------------------------" << std::endl;

        Array< float > test;

        Array< int > intArray( SIZE );
        Array< int > intArray2( SIZE - 5 );

        for ( unsigned int i = 0; i < intArray.size(); i++ )
            intArray[i] = i * 2;

        std::cout << "Int Array 1: " << intArray << std::endl;

        intArray2 = intArray;

        std::cout << "int Array 2: " << intArray2 << std::endl;

        try {
            std::cout << "\033[1;36mAccessing a valid index: \033[0m" << intArray[5] << std::endl;
            std::cout << "\033[1;36mAccessing an invalid index: \033[0m" << intArray[SIZE] << std::endl;
        } catch ( Array< int >::OutOfRangeException& e ) {
            std::cout << "\033[1;31mError: \033[0m" << e.what() << std::endl;
        }

        std::cout << "-----------------------------------------------------" << std::endl;
    }
    return 0;
}