#include "Zombie.hpp"

// Constructor, initializing name as name
Zombie::Zombie(const std::string name) : m_name(name)
{
	std::cout <<  name << ": Zombie created" << std::endl;
};

// Destructor
Zombie::~Zombie()
{
	std::cout << m_name << ": Zombie destroyed" << std::endl;
};

void	Zombie::announce(void)
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
