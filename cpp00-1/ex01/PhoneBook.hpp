#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_
#include "Contact.hpp"
#include <string>

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	run();
	private:
		Contact	friends[8];
		void(PhoneBook::*fs[3])(void);
		int		execCommand(std::string cmd);
		void	add_contact(void);
		void	search_contacts(void);
		void	exit_contacts(void);
};

#endif
