#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include <string>

class Zombie
{
	public:
		Zombie(const std::string name);
		~Zombie();
		void announce(void);
	private:
		std::string m_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif