#include "Harl.hpp"

Harl::Harl()
{
    fs[0] = &Harl::debug;
    fs[1] = &Harl::info;
    fs[2] = &Harl::warning;
    fs[3] = &Harl::error;
};

Harl::~Harl() {};

enum levelType
{
    debug = 0,
    info,
    warning,
    error,
    unknown,
};

levelType getlevelType(const std::string level)
{
    if (level == "DEBUG")
        return debug;
    if (level == "INFO")
        return info;
    if (level == "WARNING")
        return warning;
    if (level == "ERROR")
        return error;
    return unknown;
};

void Harl::complain(std::string level)
{
    int levelType = getlevelType(level);
    if (levelType >= 4)
    {
        std::cout << "|--- Invalid input ---|" << std::endl;
        return;
    }
    (this->*fs[levelType])();
};

void Harl::debug(void)
{
    std::cout << "<<DEBUG>> I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};
void Harl::info(void)
{
    std::cout << "<<INFO>> I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};
void Harl::warning(void)
{
    std::cout << "<<WARNING>> I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
};
void Harl::error(void)
{
    std::cout << "<<ERROR>> This is unacceptable! I want to speak to the manager now." << std::endl;
};