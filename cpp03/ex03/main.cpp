#include "DiamondTrap.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================\n";
}

int main() {
    printHeader("1. CREATION & DESTRUCTION CHAINING");
    {
        std::cout << "--> Constructing DiamondTrap 'Sparkle':" << std::endl;
        DiamondTrap diamond("Sparkle");

        std::cout << "\n--> Destroying 'Sparkle' (Observe reverse order):" << std::endl;
    }

    printHeader("2. IDENTIFICATION & METHOD OVERRIDES");
    {
        DiamondTrap diamond("Sparkle");

        std::cout << "\n--> Testing whoAmI():" << std::endl;
        diamond.whoAmI();

        std::cout << "\n--> Testing attack() (Must use ScavTrap's attack!):" << std::endl;
        diamond.attack("Target Dummy");

        std::cout << "\n--> Testing inherited special capabilities:" << std::endl;
        diamond.guardGate();       // From ScavTrap
        diamond.highFivesGuys();   // From FragTrap
    }

    printHeader("3. COPY CONSTRUCTOR & ASSIGNMENT OPERATOR");
    {
        DiamondTrap original("Original");

        std::cout << "\n--> Copy Constructor:" << std::endl;
        DiamondTrap copy(original);
        copy.whoAmI();

        std::cout << "\n--> Copy Assignment Operator:" << std::endl;
        DiamondTrap assigned("Temp");
        assigned = original;
        assigned.whoAmI();
    }

    return 0;
}

/*
========================================
  1. CREATION & DESTRUCTION CHAINING
========================================
--> Constructing DiamondTrap 'Sparkle':
ClapTrap Sparkle_clap_name created
FragTrap Sparkle created
ScavTrap Sparkle created
DiamondTrap Sparkle created

--> Destroying 'Sparkle' (Observe reverse order):
DiamondTrap Sparkle destroyed
ScavTrap Sparkle destroyed
FragTrap Sparkle destroyed
ClapTrap Sparkle_clap_name destroyed

========================================
  2. IDENTIFICATION & METHOD OVERRIDES
========================================
ClapTrap Sparkle_clap_name created
FragTrap Sparkle created
ScavTrap Sparkle created
DiamondTrap Sparkle created

--> Testing whoAmI():
I am DiamondTrap 'Sparkle' and my ClapTrap name is 'Sparkle_clap_name'

--> Testing attack() (Must use ScavTrap's attack!):
ScavTrap Sparkle_clap_name attacks Target Dummy, causing 30 points of damage!

--> Testing inherited special capabilities:
ScavTrap Sparkle is now in Gatekeeper mode!
FragTrap Sparkle requests a positive high five! 🖐️

========================================
  3. COPY CONSTRUCTOR & ASSIGNMENT OPERATOR
========================================
ClapTrap Original_clap_name created
FragTrap Original created
ScavTrap Original created
DiamondTrap Original created

--> Copy Constructor:
ClapTrap Original_clap_name created
FragTrap Original created
ScavTrap Original created
DiamondTrap copy constructor created
I am DiamondTrap 'Original' and my ClapTrap name is 'Original_clap_name'

--> Copy Assignment Operator:
ClapTrap Temp_clap_name created
FragTrap Temp created
ScavTrap Temp created
DiamondTrap Temp created
DiamondTrap copy assignment operator created
I am DiamondTrap 'Original' and my ClapTrap name is 'Original_clap_name'

DiamondTrap Original destroyed
ScavTrap Original destroyed
FragTrap Original destroyed
ClapTrap Original_clap_name destroyed
DiamondTrap Original destroyed
ScavTrap Original destroyed
FragTrap Original destroyed
ClapTrap Original_clap_name destroyed
DiamondTrap Original destroyed
ScavTrap Original destroyed
FragTrap Original destroyed
ClapTrap Original_clap_name destroyed
DiamondTrap Sparkle destroyed
ScavTrap Sparkle destroyed
FragTrap Sparkle destroyed
ClapTrap Sparkle_clap_name destroyed
*/
