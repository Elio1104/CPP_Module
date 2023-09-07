#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : Form( "RobotomyRequestForm", 72, 45 ), _target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : Form( src ), _target( src._target ) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm& other ) {
    (void)other;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    static bool srandExecuted = false; 
    if (!srandExecuted) {
        std::srand(time(0));
        srandExecuted = true;
    }
	if(this->getSigned() == false)
		throw Form::notSignedException();
	else if(executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	bool i = (rand() % 2) != 0;
	if (i)
		std::cout << "BZZZZZT! " << _target << " has been robotomized !" << std::endl;
	else
		std::cout << "BZZZZZT! " << _target << " robotomy failed !" << std::endl;
}
