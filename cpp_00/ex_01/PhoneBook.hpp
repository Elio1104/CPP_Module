#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private :
		Contact _contacts[8];
		int _readInput() const;
	public :
		PhoneBook();
		~PhoneBook();
		void addContact(void);
		void printContacts(void) const;
		void search(void) const;
};

#endif