#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
private :
	const std::string _target;
public :
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm& other);

	void execute( const Bureaucrat& executor ) const;
};

#endif