#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat1("Leo", 1);

        std::cout << bureaucrat1 << std::endl;

        //bureaucrat1.incrementGrade();
        bureaucrat1.decrementGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}