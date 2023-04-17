#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
protected : 
	Brain *_brain = NULL;
public :
	Dog( void );
	Dog(Dog const& other);
	Dog& operator=(Dog const& other);
	~Dog();

	virtual void makeSound( void ) const;
};

#endif