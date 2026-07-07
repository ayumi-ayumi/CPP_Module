#include "Zombie.hpp"

int main()
{
    Zombie ayumi("Ayumi_Zombie");
    ayumi.announce();
    Zombie* tama = newZombie("Tama");
    tama->announce();
    delete tama;
    randomChump("YOLO");
}