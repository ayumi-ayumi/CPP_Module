#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

static void	find_spot_and_id(Contact friends[], int &index, int &id)
{
	for (int i = 0; i < 8; i++)
	{
		if (friends[i].getField("firstName").empty())
		{
			index = i;
			id = i;
			return ;
		}
	}

	int	smallestIndex = 0;
	int	smallestId = friends[0].getId();
	int	biggestId = friends[0].getId();
	for (int i = 1; i < 8; i++)
	{
		int currentId = friends[i].getId();
		if (currentId < smallestId)
		{
			smallestId = currentId;
			smallestIndex = i;
		}
		if (currentId > biggestId)
			biggestId = currentId;
	}
	index = smallestIndex;
	id = biggestId + 1;
}

void	PhoneBook::add_contact(void)
{
	int	index;
	int	id;
	find_spot_and_id(this->friends, index, id);
	std::string fields[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string input;
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << "Input " << fields[i] << std::endl;
			std::cout << "> " << std::flush;
			if (!std::getline(std::cin, input, '\n'))
				return;
			if (!input.empty())
				break;
		}
		friends[index].setField(i, input);
	}
	friends[index].setIndex(index);
	friends[index].setId(id);
	std::cout << "\n|--- Your contact has been saved ---|" << std::endl;
}
