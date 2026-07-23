#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "========= 1. INITIALIZATION =========" << std::endl;
	ScavTrap scav("Scavvy"); // Scavvy: [HP: 100] [EP: 50] [AD: 20]
	ClapTrap clap("Clappy"); // Clappy: [HP:  10] [EP: 10] [AD:  0]
	std::cout << std::endl;

	std::cout << "========= 2. DEFAULT CONSTRUCTOR =========" << std::endl;
	ScavTrap defaultScav;  // Tests ScavTrap default constructor
	ClapTrap defaultClap;  // Tests ClapTrap default constructor
	defaultScav.attack("Target Dummy");
	defaultClap.attack("Target Dummy");
	std::cout << std::endl;

	std::cout << "========= 3. COPY CONSTRUCTOR =========" << std::endl;
	// Test ScavTrap copy constructor
	ScavTrap scavCopy(scav); 
	scavCopy.attack("a clone target"); // Should reflect scav's original stats

	// Test ClapTrap copy constructor
	ClapTrap clapCopy(clap);
	clapCopy.attack("a clone target");
	std::cout << std::endl;

	std::cout << "========= 4. COPY ASSIGNMENT OPERATOR (=) =========" << std::endl;
	ScavTrap scavAssign("TempScav");
	scavAssign = scav; // Copy attributes of scav ("Scavvy") into scavAssign

	ClapTrap clapAssign("TempClap");
	clapAssign = clap; // Copy attributes of clap ("Clappy") into clapAssign

	scavAssign.guardGate(); // Verify it retains full functionality
	std::cout << std::endl;

	std::cout << "========= 5. COMBAT FLOW =========" << std::endl;

	// Scavvy attacks: Costs 1 Energy Point
	scav.attack("Clappy");   // Scavvy: [HP: 100] [EP: 49]

	// Clappy takes 20 damage: Drops from 10 HP to 0 HP (Dead)
	clap.takeDamage(20);     // Clappy: [HP:   0] [EP: 10]
	std::cout << std::endl;

	std::cout << "========= 6. DEAD OBJECT FLOW =========" << std::endl;

	// Clappy has 0 HP, so actions fail. No Energy points should be spent!
	clap.attack("Scavvy");   // Clappy: [HP:   0] [EP: 10] (Fails to attack)
	clap.beRepaired(10);     // Clappy: [HP:   0] [EP: 10] (Fails to repair)
	std::cout << std::endl;

	std::cout << "========= 7. REPAIR FLOW =========" << std::endl;

	// Scavvy repairs: Costs 1 Energy Point, recovers 15 HP
	scav.beRepaired(15);     // Scavvy: [HP: 115] [EP: 48]
	std::cout << std::endl;

	std::cout << "========= 8. SPECIAL ABILITY =========" << std::endl;
	scav.guardGate();        // Scavvy: [HP: 115] [EP: 48]
	scavCopy.guardGate();    // Verify copied object also works
	std::cout << std::endl;

	std::cout << "========= 9. DESTRUCTOR CHAINING =========" << std::endl;
	// All objects leave scope in reverse order of creation.
	// You will observe child destructors firing first, followed by base destructors.
	return 0;
}