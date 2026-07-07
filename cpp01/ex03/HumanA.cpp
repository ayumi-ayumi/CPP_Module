#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon &weapon) : name(name), m_weapon(weapon) {};

HumanA::~HumanA(){};

void HumanA::attack()
{
    std::cout << name << " attacks with their " << m_weapon.getType() << std::endl;
}