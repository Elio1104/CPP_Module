#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	srand(time(NULL));
    try {
        Bureaucrat bureaucrat("Leo", 2); // error with 200
		{
			Intern intern1;
			Form* form1 = intern1.makeForm("shrubbery creation", "Shrubbery");
			Form* form2 = intern1.makeForm("robotomy request", "Robotomy");
			Form* form3 = intern1.makeForm("presidential pardon", "President");
			delete form1;
			delete form2;
			delete form3;
		}
		ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");
        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}