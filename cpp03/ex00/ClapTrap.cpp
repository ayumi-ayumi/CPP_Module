#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {};

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	*this = rhs;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
	}
	return (*this);
};

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {};

ClapTrap::~ClapTrap() {};

void ClapTrap::attack(const std::string& target)
{

};
void ClapTrap::takeDamage(unsigned int amount)
{

};
void ClapTrap::beRepaired(unsigned int amount)
{

};