#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <sstream>

static void	display_selected_index(Contact selected)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "First name: " << selected.getField("firstName") <<std::endl;
	std::cout << "Last name: " << selected.getField("lastName") <<std::endl;
	std::cout << "Nickname: " << selected.getField("nickName") <<std::endl;
	std::cout << "Phone number: " << selected.getField("phoneNumber") <<std::endl;
	std::cout << "Darkest secret: " << selected.getField("darkestSecret") <<std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
}

static int	get_selected_index(Contact friends[])
{
	std::string	selected_index;
	int	index;
	while (1)
	{
		std::cout << "\nSelect an index to display\n" << std::endl;
		std::cout << "> " << std::flush;
		if (!std::getline(std::cin, selected_index))
			return (0);
		std::istringstream iss(selected_index);
		iss >> index;
		if (index >= 1 && index <= 8)
		{
			if (friends[index - 1].getField("firstName").empty())
				std::cout << "\n|--- There is no contact in this index ---|\n" << std::endl;
			else
				break;
		}
	}
	return (index);
}

static void	print_contacts(Contact friends[])
{
	std::string	fields[3] = {"firstName", "lastName", "nickName"};
	for (int i = 0; i < 8; i++)
	{
		if (!friends[i].getField("firstName").empty())
		{
			std::cout << "|";
			std::cout << std::setw(10) << i + 1;
			for (int j = 0; j < 3; j++)
			{
				std::string text = friends[i].getField(fields[j]);
				if (text.length() >= 10)
				{
					text.erase(10);
					text.replace(9, 1, ".");
				}
				std::cout << "|" << std::setw(10) << text;
			}
			std::cout << "|" << std::endl;
			std::cout << "|----------|----------|----------|----------| " << std::endl;
		}
	}
}

static void	print_header()
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
	std::cout << "|----------|----------|----------|----------| " << std::endl;
}

void	PhoneBook::search_contacts(void)
{
	if (friends[0].getField("firstName").empty())
	{
		std::cout << "|--- There are no contacts in the phone book ---|" << std::endl;
		return ;
	}
	print_header();
	print_contacts(friends);
	int	idx = get_selected_index(friends);
	if (idx == 0)
		return ;
	display_selected_index(friends[idx - 1]);
}
