#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n===== Test 1: Constructor =====\n";
	FragTrap unnamed; // Default constructor
	FragTrap ayumi("Ayumi");
	FragTrap clappy("Clappy");
	FragTrap trappy("Trappy");
	FragTrap clappyCopy(clappy); // Copy constructor
	trappy = unnamed; // Copy assignment operator
    std::cout << "========== 1. Constructor / Destructor Chain ==========" << std::endl;
    {
        std::cout << "--- Creating FragTrap ---" << std::endl;
        // Check if constructors are called in order: ClapTrap -> FragTrap
        FragTrap frag("Fraggy");

        std::cout << "\n--- Status Check ---" << std::endl;
        // Specifications: HP: 100, EP: 100, AD: 30
        frag.attack("Target Dummy");
        frag.takeDamage(40);
        frag.beRepaired(20);

        std::cout << "\n--- Special Ability Check ---" << std::endl;
        frag.highFivesGuys();

        std::cout << "\n--- Destroying FragTrap ---" << std::endl;
        // Check if destructors are called in reverse order: FragTrap -> ClapTrap
    }

    std::cout << "\n========== 2. Copy Semantics & Assignment ==========" << std::endl;
    {
        FragTrap original("Original");
        std::cout << "--- Copy Constructor ---" << std::endl;
        FragTrap copy(original);

        std::cout << "--- Assignment Operator ---" << std::endl;
        FragTrap assign("Assignee");
        assign = original;

        std::cout << "--- Testing Actions on Copied Object ---" << std::endl;
        copy.highFivesGuys();
    }

    std::cout << "\n========== 3. Resource Depletion & Death ==========" << std::endl;
    {
        FragTrap heavy("Heavy");

        std::cout << "--- Taking Lethal Damage ---" << std::endl;
        heavy.takeDamage(120); // HP drops to 0

        std::cout << "--- Action Checks While Dead ---" << std::endl;
        heavy.attack("Ghost");
        heavy.beRepaired(10);
        heavy.highFivesGuys(); // Should fail or show dead state based on your design
    }

    return 0;
}

/*
========== 1. Constructor / Destructor Chain ==========
--- Creating FragTrap ---
ClapTrap Fraggy created!
FragTrap Fraggy created!

--- Status Check ---
FragTrap Fraggy attacks Target Dummy, causing 30 points of damage!
FragTrap Fraggy takes 40 points of damage!
FragTrap Fraggy repairs itself, recovering 20 hit points!

--- Special Ability Check ---
FragTrap Fraggy requests a positive high five! 🙌 Give me five, guys!

--- Destroying FragTrap ---
FragTrap Fraggy destroyed!
ClapTrap Fraggy destroyed!

========== 2. Copy Semantics & Assignment ==========
ClapTrap Original created!
FragTrap Original created!
--- Copy Constructor ---
FragTrap Copy constructor called for Original
--- Assignment Operator ---
ClapTrap Assignee created!
FragTrap Assignee created!
FragTrap Copy assignment operator called
--- Testing Actions on Copied Object ---
FragTrap Original requests a positive high five! 🙌 Give me five, guys!
FragTrap Original destroyed!
ClapTrap Original destroyed!
FragTrap Original destroyed!
ClapTrap Original destroyed!

========== 3. Resource Depletion & Death ==========
ClapTrap Heavy created!
FragTrap Heavy created!
--- Taking Lethal Damage ---
FragTrap Heavy takes 120 points of damage!
FragTrap Heavy is dead!
--- Action Checks While Dead ---
FragTrap Heavy cannot attack because they have no hit points left!
FragTrap Heavy cannot repair itself because they have no hit points left!
FragTrap Heavy requests a high five... but nobody responds to a corpse.
FragTrap Heavy destroyed!
ClapTrap Heavy destroyed!

*/
