#ifndef _HUMANA_H_
#define _HUMANA_H_
#include "Weapon.hpp"
#include <string>

class HumanA
{
	public:
		HumanA(const std::string name, Weapon &weapon);
		~HumanA();
		void attack();
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif
