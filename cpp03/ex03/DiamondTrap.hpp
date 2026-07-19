#ifndef _DIAMONDTRAP_H_
#define _DIAMONDTRAP_H_
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DaimondTrap : public FragTrap, public ScavTrap
{
	public:
	private:
		std::string _name;
		
};


#endif