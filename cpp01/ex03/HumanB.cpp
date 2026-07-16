#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {
	std::cout <<  name << ": B created" << std::endl;
};

HumanB::~HumanB() {
	std::cout <<  "B destroyed" << std::endl;

};

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
};

void HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	return ;
};
