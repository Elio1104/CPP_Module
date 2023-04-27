#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private :
	const std::string   _name;
    bool                _signed;
    const int			_gradeToSign;
    const int			_gradeToExecute;

public :
	Form( const std::string name, int gradeToSign );
	Form( const Form& other );
	Form& operator=( const Form& other );
	~Form();

	/* ---------------- Methodes ---------------- */

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream&   operator<<( std::ostream& o, const Form& objet );

#endif