#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor created" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap a copy assignment operator constructor created" << std::endl;
	if (this != &other) // Check if you do not assign yourself (a = a;)
		ClapTrap::operator=(other);
	return (*this);
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: HIGH FIVE!" << std::endl;

}
