#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected :
	std::string _type;

public :
	Animal( void );
	Animal(Animal const& other);
	Animal& operator=(Animal const& other);
	virtual ~Animal();

	virtual void makeSound( void ) const = 0;
	std::string getType( void ) const;

};

#endif