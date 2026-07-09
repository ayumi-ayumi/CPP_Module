#ifndef _CONTACT_H_
#define _CONTACT_H_
#include <string>
#include <iostream>

class PhoneBook;

class Contact
{
	public:
		Contact();
		~Contact();
		void setField(int field, std::string input);
		std::string getField(std::string input);
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		phoneNumber;
		std::string		darkestSecret;
};
#endif
