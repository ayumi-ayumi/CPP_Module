#include "Zombie.hpp"
#include <iostream>
#include <string>

// Default constructor
Zombie::Zombie() : m_name("") 
{
	std::cout << "Zombie created" << std::endl;
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

void	Zombie::setName(const std::string name)
{
	m_name = name;
}
