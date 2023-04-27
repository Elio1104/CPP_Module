#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name( other._name ) , _grade( other._grade )
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if ( this != &other )
        _grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

/* ---------------- Methodes ---------------- */

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade() {
    if ( _grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm( Form& form ) {
    try {
        form.beSigned( *this );
        std::cout << *this << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cerr << _name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

/* ---------------- Exception Classes ---------------- */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

/* ---------------- Surcharge de la sortie ---------------- */

std::ostream& operator<<( std::ostream& o, const Bureaucrat& objet ) {
    o << objet.getName() << ", bureaucrat grade " << objet.getGrade();
    return o;
}

