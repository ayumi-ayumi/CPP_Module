#include "Contact.hpp"
#include <iomanip>
#include <stdio.h>

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")  {};

Contact::~Contact() {};

void Contact::setField(int field, std::string input)
{
	switch (field)
	{
		case 0:
			this->firstName = input;
			break;
		case 1:
			this->lastName = input;
			break;
		case 2:
			this->nickName = input;
			break;
		case 3:
			this->phoneNumber = input;
			break;
		case 4:
			this->darkestSecret = input;
			break;
	}
};

std::string	Contact::getField(std::string field)
{
	if (field == "firstName")
        return firstName;
    if (field == "lastName")
        return lastName;
    if (field == "nickName")
        return nickName;
    if (field == "phoneNumber")
        return phoneNumber;
    if (field == "darkestSecret")
        return darkestSecret;
    return "";
}