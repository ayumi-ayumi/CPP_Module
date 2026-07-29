#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "--- [1] Subject Standard Test ---" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "j type: " << j->getType() << std::endl;
		std::cout << "i type: " << i->getType() << std::endl;

		std::cout << "i sound: ";
		i->makeSound();

		std::cout << "j sound: ";
		j->makeSound();

		std::cout << "meta sound: ";
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}
// 	{
// 		std::cout << "--- [2] Polymorphic Array Test ---" << std::endl;

// 		const int count = 4;
// 		const Animal* zoo[count];

// 		zoo[0] = new Dog();
// 		zoo[1] = new Cat();
// 		zoo[2] = new Dog();
// 		zoo[3] = new Cat();

// 		for (int idx = 0; idx < count; ++idx)
// 		{
// 			std::cout << "[" << idx << "] Type: " << zoo[idx]->getType() << " -> Sound: ";
// 			zoo[idx]->makeSound();
// 		}

// 		for (int idx = 0; idx < count; ++idx)
// 		{
// 			delete zoo[idx];
// 		}
// 		std::cout << std::endl;
// 	}
// 	{
// 		std::cout << "--- [3] Copy & Assignment Test ---" << std::endl;

// 		Dog originalDog;
// 		Dog copyDog(originalDog);

// 		std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
// 		std::cout << "Copied Dog type:   " << copyDog.getType() << std::endl;

// 		Cat originalCat;
// 		Cat assignedCat;
// 		assignedCat = originalCat;

// 		std::cout << "Assigned Cat type: " << assignedCat.getType() << std::endl;
// 		std::cout << std::endl;
// 	}
// 	{
// 		std::cout << "--- [4] WrongAnimal vs WrongCat Test ---" << std::endl;

// 		const WrongAnimal* wrongMeta = new WrongAnimal();
// 		const WrongAnimal* wrongCat = new WrongCat();

// 		std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

// 		std::cout << "wrongCat sound: ";
// 		wrongCat->makeSound(); // MUST output WrongAnimal sound, NOT WrongCat sound!

// 		std::cout << "wrongMeta sound: ";
// 		wrongMeta->makeSound();

// 		delete wrongMeta;
// 		delete wrongCat;
// 		std::cout << std::endl;
// }
	return 0;
}
