#include "Harl.hpp"
#include <iostream>

int main()
{
	std::cout << "Select a level" << std::endl;
	std::cout << "1. DEBUG" << std::endl;
	std::cout << "2. INFO" << std::endl;
	std::cout << "3. WARNING" << std::endl;
	std::cout << "4. ERROR" << std::endl;
	int input;
	std::cin >> input;
	std::string level;
	switch (input)
	{
		case 1:
			level = "DEBUG";
			break;
		case 2:
			level = "INFO";
			break;
		case 3:
			level = "WARNING";
			break;
		case 4:
			level = "ERROR";
			break;
	}
	Harl harl;
	harl.complain(level);
};
