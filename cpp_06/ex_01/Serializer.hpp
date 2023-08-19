#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{
    std::string name;
    int         age;
};

class Serializer {
    private :
        Serializer( void );
        ~Serializer( void );
        Serializer( const Serializer& src );
        Serializer& operator=( const Serializer& other );

    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif