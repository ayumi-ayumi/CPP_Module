#ifndef _HUMANB_H_
#define _HUMANB_H_
#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(const std::string name);
        ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack();
    private:
        std::string name;
        Weapon *m_weapon;
};
#endif