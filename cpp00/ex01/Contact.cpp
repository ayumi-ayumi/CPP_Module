#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void Contact::displayContact()
{

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << std::setfill(' ') << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << firstName;
	std::cout << "|" << std::setw(10) << lastName;
	std::cout << "|" << std::setw(10) << nickName << std::endl;
	// std::cout << "Phone number: " << phoneNumber << std::endl;
	// std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
