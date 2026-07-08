#include "Zombie.hpp"

int main()
{
    Zombie ayumi("AYUMI");
    ayumi.announce();
    Zombie* tama = newZombie("NEW");
    tama->announce();
    delete tama;
    randomChump("RANDOM");
}