#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private :
	const std::string	_name;
	int					_grade;

public :
	Bureaucrat( const std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat();

	/* ---------------- Methodes ---------------- */

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm( Form& Form );
	void executeForm( Form& Form );

	/* ---------------- Exception Classes ---------------- */

	class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& objet );

#endif