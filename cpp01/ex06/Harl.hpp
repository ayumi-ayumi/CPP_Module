#ifndef _HARL_H_
#define _HARL_H_
#include <string>
#include <iostream>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
    private:
        void(Harl::*fs[4])(void);
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};
#endif