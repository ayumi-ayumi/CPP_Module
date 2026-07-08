#ifndef _ZOMBIEHORDE_H_
#define _ZOMBIEHORDE_H_
#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setName(const std::string name);
	private:
		std::string m_name;
};

Zombie* zombieHorde(int N, std::string name);
#endif