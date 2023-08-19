#include "Serializer.hpp"

int main ( void ) {
    Data *data = new Data;

    data->name = "alondot";
    data->age = 23;

    std::cout << "Name: " << Serializer::deserialize( Serializer::serialize( data ) )->name << std::endl;
    std::cout << "Age: " << Serializer::deserialize( Serializer::serialize( data ) )->age << std::endl;

    delete data;

    return EXIT_SUCCESS;
}