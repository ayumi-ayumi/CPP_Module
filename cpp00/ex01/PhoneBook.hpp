#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include "Contact.hpp"
#include <vector>
#include <string>
#include <unordered_map>

class PhoneBook
{
	public:
		// PhoneBook(std::string n) : Contact(){};
		std::vector <Contact> phone_book;
		void	add_contact(Contact person)
		{
			phone_book.push_back(person);
		}
	// void displayContact();
	void print_contacts();
	// std::unordered_map<Contact> contacts;

	// private:
	// 	void add();
	// 	void search();
	// 	void exit();
};
#endif
