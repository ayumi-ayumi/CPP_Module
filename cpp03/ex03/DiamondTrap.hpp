#ifndef _DIAMONDTRAP_H_
#define _DIAMONDTRAP_H_
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& input);
		DiamondTrap& operator=(const DiamondTrap& input);
		~DiamondTrap();
		void attack(const std::string& target);
		void whoAmI();

		std::string _name;
	private:

};


#endif
