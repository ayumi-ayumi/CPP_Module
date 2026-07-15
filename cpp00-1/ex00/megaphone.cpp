#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			size_t len = str.length();
			std::string result = str;
			for (size_t j = 0; j < len; j++)
				result[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
			std::cout << result;
		}
		std::cout << std::endl;
	}
	return (0);
}
