#include "Zombie.hpp"

int main()
{
	Zombie ayumi("AYUMI");
	ayumi.announce();
	Zombie* newbie = newZombie("NEW");
	newbie->announce();
	delete newbie;
	randomChump("RANDOM");
}
