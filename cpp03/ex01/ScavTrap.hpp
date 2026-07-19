#ifndef _SCAVTRAP_H_
#define _SCAVTRAP_H_
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& input);
		ScavTrap& operator=(const ScavTrap& input);
		~ScavTrap();
		void			attack(const std::string& target);
		void			guardGate();
};

#endif
