#include "Zombie.hpp"
#include <iostream>

// Constructor, initializing _name as name
Zombie::Zombie(const std::string name) : _name(name)
{
	std::cout <<  name << ": Zombie created" << std::endl;
};

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << ": Zombie destroyed" << std::endl;
};

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
