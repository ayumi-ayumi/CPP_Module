#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Contact person1 = Contact(0, "AyumiAyumiAyumi", "SatoSatoSatoSato", "0123456789ABCDEF", 5567, "NA");
	Contact person2 = Contact(1, "JohnJohnJohnJohn", "SmithSmithSmithSmith", "0123456789ABCDEF", 5567, "NA");
	Contact person3 = Contact(2, "AppleAppleAppleApple", "JobsJobsJobs", "0123456789ABCDEF", 5567, "NA");
	Contact person4 = Contact(3, "Gabriel", "McDonalds", "0123456789ABCDEF", 5567, "NA");

	PhoneBook phone_book1;
	phone_book1.add_contact(person1);
	// person1.displayContact();
	// person2.displayContact();
	// person3.displayContact();
	// person4.displayContact();
	return (0);
}
