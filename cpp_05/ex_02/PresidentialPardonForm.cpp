#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : Form( "PresidentialPardonForm", 25, 5 ), _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : Form( src ), _target( src._target ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm& other ) {
    (void)other;
    return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if(this->getSigned() == false)
		throw Form::notSignedException();
	else if(executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}