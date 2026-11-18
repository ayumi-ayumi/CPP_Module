#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data originalData = {7, "Ayumi", 80, true};
	Data *ptr = &originalData;

	uintptr_t serializedAddress = Serializer::serialize(ptr);
	Data *restoredData = Serializer::deserialize(serializedAddress);

	std::cout << "Original pointer: " << &originalData << std::endl;
	std::cout << "deserialized pointer: " << restoredData << std::endl;

	std::cout << std::endl;

	std::cout << "|--- Original data ---|" << std::endl;
	std::cout << "Id: " << originalData.id << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Score: " << originalData.score << std::endl;
	std::cout << "Is selected: " << originalData.isSelected << std::endl;

	std::cout << std::endl;

	std::cout << "|--- Restored data ---|" << std::endl;
	std::cout << "Id: " << restoredData->id << std::endl;
	std::cout << "Name: " << restoredData->name << std::endl;
	std::cout << "Score: " << restoredData->score << std::endl;
	std::cout << "Is selected: " << restoredData->isSelected << std::endl;
}
