#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	fs[0] = &PhoneBook::add_contact;
	fs[1] = &PhoneBook::search_contacts;
	fs[2] = &PhoneBook::exit_contacts;
}

PhoneBook::~PhoneBook() {};

void	PhoneBook::run()
{
	std::string	input;
	while (1)
	{
		std::cout << "\n--------- PHONEBOOK ---------\n";
		std::cout << "Commands: ADD | SEARCH | EXIT\n";
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (!execCommand(input))
			break;
	}
}

int	PhoneBook::execCommand(std::string cmd)
{
	if (cmd == "ADD")
		return ((this->*fs[0])(), 1);
	if (cmd == "SEARCH")
		return ((this->*fs[1])(), 1);
	if (cmd == "EXIT")
		return ((this->*fs[2])(), 0);
	else
	{
		std::cout << "|--- Invalid input ---|" << std::endl;
		return (1);
	}
}

void	PhoneBook::exit_contacts(void)
{
	return ;
}
