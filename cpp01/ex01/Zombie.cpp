#include "Zombie.hpp"
#include <iostream>

// Default constructor
Zombie::Zombie() : _name("")
{
	std::cout << "Zombie created" << std::endl;
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

void	Zombie::setName(const std::string name)
{
	_name = name;
};
