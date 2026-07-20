#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Constructor with a parameter
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DiamondTrap " << name << " created" << std::endl;
	this->_name = ClapTrap::_name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
	std::cout << "DiamondTrap copy constructor created" << std::endl;
	this->_name = _name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

// Copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap a copy assignment operator constructor created" << std::endl;
	if (this != &other) // Check if you do not assign yourself (a = a;)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << _name << "ClapTrap: "<< ClapTrap::_name << std::endl;

}
