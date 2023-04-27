#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& other ) {
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern& other ) {
    ( void ) other;
    return (*this);
}

Form* Intern::makeForm(std::string name, std::string target) {
	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	Form* forms[] = {
		new RobotomyRequestForm( target ),
		new ShrubberyCreationForm( target ),
		new PresidentialPardonForm( target )
	};

	for (int i(0); i < 3; i++) {
		if ( name == formNames[i] ) {
			std::cout << "Intern creates " << name << std::endl;
			return forms[i];
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
    return 0;
}