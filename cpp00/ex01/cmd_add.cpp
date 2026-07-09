#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

static int findNextPage(Contact friends[])
{
    for (int i = 0; i < 8```; i++)
    {
        if (friends[i].getField("firstName").empty())
            return (i);
    }
    return (-1);
}

void PhoneBook::add_contact(void)
{
    int idx = findNextPage(this->friends);
    if (idx == -1)
        return;
    std::string fields[] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
    std::string input;
    for (int i = 0; i < 5; i++)
    {
        while (1)
        {
            std::cout << "Input " << fields[i] << std::endl;
            std::cout << "> " << std::flush;
            std::getline(std::cin, input);
            if (!input.empty())
               break;
        }
        friends[idx].setField(i, input); 
    }
    std::cout << "\n|--- Your contact has been saved ---|" << std::endl; 
}