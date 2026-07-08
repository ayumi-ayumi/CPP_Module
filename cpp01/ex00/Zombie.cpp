#include "Zombie.hpp"

// Constructor, initializing name as name
Zombie::Zombie(const std::string name) : name(name)
{
	std::cout <<  name << ": Zombie created" << std::endl;
};

// Destructor
Zombie::~Zombie()
{
	std::cout << name << ": Zombie destroyed" << std::endl;
};

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
