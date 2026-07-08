#ifndef _HUMANA_H_
#define _HUMANA_H_
#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
    public:
        HumanA(const std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
    private:
        std::string name;
        Weapon &m_weapon;
};
#endif