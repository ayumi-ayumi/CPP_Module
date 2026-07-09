#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class Contact;

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void run();
	private:
		Contact *friends;
		void(PhoneBook::*fs[3])(void);
		void execCommand(std::string cmd);
		void add_contact(void);
		void search_contacts(void);
		void exit_contacts(void);
};
#endif
