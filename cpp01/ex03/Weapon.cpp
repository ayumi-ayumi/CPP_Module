#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string type) : m_type(type){};

Weapon::~Weapon(){};

const std::string& Weapon::getType()
{
    return (m_type);
};

void Weapon::setType(const std::string type)
{
    m_type = type;
};

