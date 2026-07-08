#include "Harl.hpp"

Harl::Harl()
{
    fs[0] = &Harl::debug;
    fs[1] = &Harl::info;
    fs[2] = &Harl::warning;
    fs[3] = &Harl::error;
};

Harl::~Harl() {};

static int getIdx(std::string level)
{
    std::string levelType[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int idx = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levelType[i] == level)
        {
            idx = i;
            break;
        }
    }
    return (idx);
};

void Harl::complain(std::string level)
{
    int idx = getIdx(level);
    if (idx < 0 || idx >= 4)
    {
        std::cout << "|--- Invalid input ---|" << std::endl;
        return;
    }
    (this->*fs[idx])();
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