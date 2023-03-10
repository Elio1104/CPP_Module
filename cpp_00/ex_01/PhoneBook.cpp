#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact(void)
{
	static int  i;
	this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void PhoneBook::printContacts(void) const
{
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->_contacts[i].view(i);
    }
    std::cout << std::endl;
}

void PhoneBook::search(void) const
{
    int i = this->_readInput();
    this->_contacts[i].display(i);
}

int PhoneBook::_readInput() const {
    int     input = -1;
    bool    valid = false;
    do
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8)) {
            valid = true;
        } else {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Invalid index; please re-enter." << std::endl;
        }
    } while (!valid);
    return (input);
}