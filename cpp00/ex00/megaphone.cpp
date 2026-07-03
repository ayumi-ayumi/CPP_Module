#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str = av[i];
			int len = str.length();
			for (int j = 0; j < len; j++)
				std::cout << (char)toupper(str[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
