#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
};

void HumanB::attack()
{
	if (_weapon)
		std::cout << _weapon << " attacks with their " << _weapon->getType() << std::endl;
	return ;
};
