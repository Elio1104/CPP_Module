#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "Form.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public Form {
private :
	const std::string _target;
public :
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);

	void execute( const Bureaucrat& executor ) const;
};

#endif