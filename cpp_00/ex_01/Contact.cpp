#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::init(void)
{

}

void	Contact::setIndex(int index
{
	
}

void	Contact::display(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << std::endl;
}