#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(150)
{
	if ( gradeToSign > 150 )
		throw Form::GradeTooLowException();
	if ( gradeToSign < 1 )
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if ( this != &other )
        _signed = other._signed;
    return *this;
}

Form::~Form()
{
}

/* ---------------- Methodes ---------------- */

std::string Form::getName() const {
    return _name;
}

bool   Form::getSigned() const {
    return _signed;
}

int   Form::getGradeToSign() const {
    return _gradeToSign;
}

int   Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

/* ---------------- Exception Classes ---------------- */

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

/* ---------------- Surcharge de sortie ---------------- */

std::ostream& operator<<( std::ostream& o, const Form& objet ) {
    o << "Name : " << objet.getName() << std::endl;
	o << "Signed : " << objet.getSigned() << std::endl;
	o << "Grade to Sign : " << objet.getGradeToSign() << std::endl;
	o << "Grade to Execute : " << objet.getGradeToExecute() << std::endl;
    return o;
}