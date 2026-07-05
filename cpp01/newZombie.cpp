#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
	Zombie *new_zombie;

	new_zombie->name = name;
	return new_zombie;
};
