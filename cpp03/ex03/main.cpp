#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "========== 1. Constructor / Destructor & Status Test ==========" << std::endl;
    {
        std::cout << "--- Creating DiamondTrap ---" << std::endl;
        // Check if constructors are called in order: ClapTrap -> ScavTrap -> FragTrap -> DiamondTrap
        DiamondTrap diamond("Dia");

        std::cout << "\n--- Status / Shadowing Check ---" << std::endl;
        // Specifications: HP (FragTrap: 100), EP (ScavTrap: 50), AD (FragTrap: 30)
        // This should invoke ScavTrap's attack() as requested by the subject
        diamond.attack("TargetDummy");

        std::cout << "\n--- Special Ability Check ---" << std::endl;
        diamond.whoAmI();          // Unique DiamondTrap method
        diamond.guardGate();       // Inherited from ScavTrap
        diamond.highFivesGuys();   // Inherited from FragTrap

        std::cout << "\n--- Destroying DiamondTrap ---" << std::endl;
        // Check if destructors are called in the exact reverse order
    }

    std::cout << "\n========== 2. Copy Constructor & Assignment Operator ==========" << std::endl;
    {
        DiamondTrap original("Original");
        std::cout << "--- Copy Constructor ---" << std::endl;
        DiamondTrap copy(original);

        std::cout << "--- Assignment Operator ---" << std::endl;
        DiamondTrap assign("Assignee");
        assign = original;

        std::cout << "--- Verifying Copied Objects ---" << std::endl;
        // copy.whoAmI();
        // assign.whoAmI();
    }

    std::cout << "\n========== 3. Edge Case (Death & No Energy) Test ==========" << std::endl;
    {
        DiamondTrap tyler("Tyler");

        std::cout << "--- Taking Damage & Repairing ---" << std::endl;
        tyler.takeDamage(50);
        tyler.beRepaired(25);

        std::cout << "--- Depleting HP to 0 ---" << std::endl;
        tyler.takeDamage(100);

        std::cout << "--- Actions while dead ---" << std::endl;
        tyler.attack("Enemy");
        tyler.beRepaired(10);
    }

    return 0;
}

/*
========== 1. Constructor / Destructor & Status Test ==========
--- Creating DiamondTrap ---
ClapTrap Dia_clap_name created!
ScavTrap Dia derived from ClapTrap created!
FragTrap Dia derived from ClapTrap created!
DiamondTrap Dia created!

--- Status / Shadowing Check ---
ScavTrap Dia attacks TargetDummy, causing 30 points of damage!

--- Special Ability Check ---
DiamondTrap Name: Dia, ClapTrap Name: Dia_clap_name
ScavTrap Dia is now in Gate keeper mode.
FragTrap Dia requests a high five! Give me five guys!

--- Destroying DiamondTrap ---
DiamondTrap Dia destroyed!
FragTrap Dia destroyed!
ScavTrap Dia destroyed!
ClapTrap Dia_clap_name destroyed!

========== 2. Copy Constructor & Assignment Operator ==========
ClapTrap Original_clap_name created!
ScavTrap Original derived from ClapTrap created!
FragTrap Original derived from ClapTrap created!
DiamondTrap Original created!
--- Copy Constructor ---
DiamondTrap Copy Constructor called for Original
--- Assignment Operator ---
ClapTrap Assignee_clap_name created!
ScavTrap Assignee derived from ClapTrap created!
FragTrap Assignee derived from ClapTrap created!
DiamondTrap Assignee created!
DiamondTrap Copy Assignment operator called
--- Verifying Copied Objects ---
DiamondTrap Name: Original, ClapTrap Name: Original_clap_name
DiamondTrap Name: Original, ClapTrap Name: Original_clap_name
DiamondTrap Original destroyed!
DiamondTrap Original destroyed!
DiamondTrap Original destroyed!

========== 3. Edge Case (Death & No Energy) Test ==========
ClapTrap Tyler_clap_name created!
ScavTrap Tyler derived from ClapTrap created!
FragTrap Tyler derived from ClapTrap created!
DiamondTrap Tyler created!
--- Taking Damage & Repairing ---
DiamondTrap Tyler takes 50 points of damage!
DiamondTrap Tyler repairs itself, recovering 25 hit points!
--- Depleting HP to 0 ---
DiamondTrap Tyler takes 100 points of damage!
DiamondTrap Tyler is dead!
--- Actions while dead ---
DiamondTrap Tyler cannot attack because they are dead!
DiamondTrap Tyler cannot repair itself because they are dead!
DiamondTrap Tyler destroyed!
FragTrap Tyler destroyed!
ScavTrap Tyler destroyed!
ClapTrap Tyler_clap_name destroyed!

*/
