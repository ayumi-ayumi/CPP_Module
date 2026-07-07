#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : name(name), m_weapon(NULL){};

HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon &weapon)
{
    m_weapon = &weapon;
}
void HumanB::attack()
{
    if (m_weapon)
        std::cout << name << " attacks with their " << m_weapon->getType() << std::endl;
}