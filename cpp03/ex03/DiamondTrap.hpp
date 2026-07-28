#ifndef _DIAMONDTRAP_H_
#define _DIAMONDTRAP_H_
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();
		void		attack(const std::string& target);
		void		whoAmI();
	private:
		std::string	_name;
};


#endif
