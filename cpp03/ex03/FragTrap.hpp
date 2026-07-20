#ifndef _FRAGTRAP_H_
#define _FRAGTRAP_H_
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& input);
		FragTrap& operator=(const FragTrap& input);
		~FragTrap();
		void	highFivesGuys(void);
};

#endif
