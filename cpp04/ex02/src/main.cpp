#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "========================================" << std::endl;
		std::cout << "  1. Subject Required Array Test        " << std::endl;
		std::cout << "========================================" << std::endl;

		const int size = 4;
		AAnimal* animals[size];

		for (int i = 0; i < size / 2; ++i)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; ++i)
			animals[i] = new Cat();
		for (int i = 0; i < size; ++i)
		{
			std::cout << "AAnimal [" << i << "] (" << animals[i]->getType() << "): ";
			animals[i]->makeSound();
		}
		for (int i = 0; i < size; ++i)
			delete animals[i];
	}

	{
		std::cout << "\n========================================" << std::endl;
		std::cout << "  2. Deep Copy Test (Dog)               " << std::endl;
		std::cout << "========================================" << std::endl;

		Dog basic;
		Dog temp = basic;
		std::cout << temp.getType() << std::endl;
		basic.makeSound();
		// If it is a shallow copy, basic and temp point the same _dogBrain address.
	}

	{
		std::cout << "\n========================================" << std::endl;
		std::cout << "  3. Assignment Operator Deep Copy Test " << std::endl;
		std::cout << "========================================" << std::endl;

		Cat neko1;
		Cat neko2;
		neko2 = neko1;
		std::cout << neko1.getType() << std::endl;
		neko1.makeSound();
		neko2.makeSound();
	}
	return (0);
}