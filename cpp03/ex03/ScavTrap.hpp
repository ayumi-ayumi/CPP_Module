#ifndef _SCAVTRAP_H_
#define _SCAVTRAP_H_
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		virtual ~ScavTrap();
		virtual void	attack(const std::string& target);
		void	guardGate();
};

#endif
