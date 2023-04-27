#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private :
	const std::string _target;
public :
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm& other);

	void execute( const Bureaucrat& executor ) const;
};

#endif