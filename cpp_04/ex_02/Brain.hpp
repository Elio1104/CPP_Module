#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
protected :
	std::string _ideas[100];

public :
	Brain( void );
	Brain(Brain const& other);
	Brain& operator=(Brain const& other);
	~Brain();
};

#endif