#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include <string>

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

Zombie* zombieHorde( int N, std::string name );
#endif