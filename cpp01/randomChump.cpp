#include "Zombie.hpp"
#include <iostream>

void	randomChump(std::string name)
{
	Zombie new_zombie;

	new_zombie.name = name;
	new_zombie.announce();

};
