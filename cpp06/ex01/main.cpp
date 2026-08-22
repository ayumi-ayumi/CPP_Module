#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data ayumi = {1, "Ayumi", 40, true};
	uintptr_t raw = Serializer::serialize(&ayumi);
	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "Original pointer: " << &ayumi << std::endl;
	std::cout << "deserialized pointer: " << deserialized << std::endl;
}
