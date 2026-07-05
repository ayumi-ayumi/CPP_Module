#ifndef _CONTACT_H_
#define _CONTACT_H_
#include <string>

class Contact
{
	private:
		unsigned int	index;
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		int				phoneNumber;
		std::string		darkestSecret;
	public:
		Contact(
			unsigned int index,
			std::string firstName,
			std::string lastName,
			std::string nickName,
			int phoneNumber,
			std::string darkestSecret
		)
		: index(index),
		firstName(firstName),
		lastName(lastName),
		nickName(nickName),
		phoneNumber(phoneNumber),
		darkestSecret(darkestSecret) {};

};
#endif
