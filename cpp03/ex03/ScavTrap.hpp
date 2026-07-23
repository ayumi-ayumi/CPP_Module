#ifndef _SCAVTRAP_H_
#define _SCAVTRAP_H_
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& input);
		ScavTrap& operator=(const ScavTrap& input);
		virtual ~ScavTrap();
		virtual void	attack(const std::string& target);
		void	guardGate();
};

#endif
