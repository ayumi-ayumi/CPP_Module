#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data originalData = {1, "Ayumi", 40, true};

	uintptr_t serializedAddress = Serializer::serialize(&originalData);
	Data *restoredData = Serializer::deserialize(serializedAddress);

	std::cout << "Original pointer: " << &originalData << std::endl;
	std::cout << "deserialized pointer: " << restoredData << std::endl;
}
