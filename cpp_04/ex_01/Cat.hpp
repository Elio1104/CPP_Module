#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
protected : 
	Brain *_brain = NULL;
public :
	Cat( void );
	Cat(Cat const& other);
	Cat& operator=(Cat const& other);
	~Cat();

	virtual void makeSound( void ) const;
};

#endif