#include "iter.hpp"

void multiDouble(int &num)
{
	num = num * 2;
	std::cout << num << std::endl;
}

void add_prefix(std::string &element)
{
	element.push_back('s');
	std::cout << element << std::endl;
}

void printElement(const int &element)
{
	std::cout << element << std::endl;
}

void printStrElement(const std::string &element)
{
	std::cout << element << std::endl;
}

int main()
{
	int array[5] = {0, 1, 2, 3, 4};
	const size_t len = sizeof(array) / sizeof(array[0]);
	std::cout << "\033[33m" << "const" << std::endl;
	::iter(array, len, printElement);
	std::cout << "\033[33m" << "non-const" << std::endl;
	::iter(array, len, multiDouble);

	std::string fruits[3] = {"apple", "banana", "watermelon"};
	const size_t arr_len = sizeof(fruits) / sizeof(fruits[0]);
	std::cout << "const" << std::endl;
	::iter(fruits, arr_len, printStrElement);
	std::cout << "non-const" << std::endl;
	::iter(fruits, arr_len, add_prefix);
}
