#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <string>

class Weapon
{
    public:
        Weapon(const std::string type);
        ~Weapon();
        const std::string& getType();
        void setType(const std::string type);
    private:
        std::string m_type;
};
#endif