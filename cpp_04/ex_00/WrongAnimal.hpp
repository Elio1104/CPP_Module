#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected :
	std::string _type;

public :
	WrongAnimal( void );
	WrongAnimal(WrongAnimal const& other);
	WrongAnimal& operator=(WrongAnimal const& other);
	~WrongAnimal();

	void makeSound( void ) const;
	std::string getType( void ) const;

};

#endif