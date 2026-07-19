#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "========= 1. INITIALIZATION =========" << std::endl;
    ScavTrap scav("Scavvy"); // Scavvy: [HP: 100] [EP: 50]
    ClapTrap clap("Clappy"); // Clappy: [HP:  10] [EP: 10]
    std::cout << std::endl;

    std::cout << "========= 2. COMBAT FLOW =========" << std::endl;

    // Scavvy attacks: Costs 1 Energy Point
    scav.attack("Clappy");   // Scavvy: [HP: 100] [EP: 49]

    // Clappy takes 20 damage: Drops from 10 HP to 0 HP (Dead)
    clap.takeDamage(20);     // Clappy: [HP:   0] [EP: 10]
    std::cout << std::endl;

    std::cout << "========= 3. DEAD OBJECT FLOW =========" << std::endl;

    // Clappy has 0 HP, so actions fail. No Energy points should be spent!
    clap.attack("Scavvy");   // Clappy: [HP:   0] [EP: 10] (Fails to attack)
    clap.beRepaired(10);     // Clappy: [HP:   0] [EP: 10] (Fails to repair)
    std::cout << std::endl;

    std::cout << "========= 4. REPAIR FLOW =========" << std::endl;

    // Scavvy repairs: Costs 1 Energy Point, recovers 15 HP
    scav.beRepaired(15);     // Scavvy: [HP: 115] [EP: 48]
    std::cout << std::endl;

    std::cout << "========= 5. SPECIAL ABILITY =========" << std::endl;
    scav.guardGate();        // Scavvy: [HP: 115] [EP: 48]
    std::cout << std::endl;

    std::cout << "========= 6. DESTRUCTOR CHAINING =========" << std::endl;
    // Objects leave scope: ScavTrap destructor fires first, then ClapTrap base.
    return 0;
}
