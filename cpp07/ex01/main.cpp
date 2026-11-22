#include "iter.hpp"

using std::string;

void doubleInt(int &num)
{
	num = num * 2;
	std::cout << num << std::endl;
}

void addSuffix(string &element)
{
	element.push_back('s');
	std::cout << element << std::endl;
}

void printInt(const int &element)
{
	std::cout << element << std::endl;
}

void printString(const string &element)
{
	std::cout << element << std::endl;
}

int main()
{
	{
		int array[5] = {0, 1, 2, 3, 4};
		const size_t len = sizeof(array) / sizeof(array[0]);
		std::cout << "\033[35m" << "const" << "\033[0m" << std::endl;
		::iter(array, len, printInt);
		std::cout << "\033[35m" << "non-const" << "\033[0m" << std::endl;
		::iter(array, len, doubleInt);
	}

	{
		string fruits[3] = {"apple", "banana", "watermelon"};
		const size_t arr_len = sizeof(fruits) / sizeof(fruits[0]);
		std::cout << "\033[35m" << "const" << "\033[0m" << std::endl;
		::iter(fruits, arr_len, printString);
		std::cout << "\033[35m" << "non-const" << "\033[0m" << std::endl;
		::iter(fruits, arr_len, addSuffix);
	}
}
