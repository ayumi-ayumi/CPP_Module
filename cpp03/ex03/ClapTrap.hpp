#ifndef _CLAPTRAP_H_
#define _CLAPTRAP_H_
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& input);
		ClapTrap& operator=(const ClapTrap& input);
		virtual ~ClapTrap();
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
