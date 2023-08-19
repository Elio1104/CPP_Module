#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( const Serializer& src ) { *this = src ;}

Serializer& Serializer::operator=( const Serializer& other ) { 
    if ( this != &other ) {}
    return *this ;
}

uintptr_t serialize(Data* ptr) {
    return ( reinterpret_cast< uintptr_t >( ptr ) );
}

Data* deserialize(uintptr_t raw) {
    return ( reinterpret_cast< Data* >( raw ) );
}