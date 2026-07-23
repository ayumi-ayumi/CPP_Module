#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void) 
{
	{
		std::cout << "========= 1. DEFAULT CONSTRUCTOR =========" << std::endl;
		DiamondTrap defaultDiamond; // Default constructor (HP: 100, EP: 50, AD: 30)
		
		defaultDiamond.whoAmI();
		defaultDiamond.attack("Target Dummy"); // Should use ScavTrap::attack
		std::cout << "--- Scope ending for Section 1 ---" << std::endl;
	} // Destructors run in reverse construction order
	std::cout << std::endl;

	{
		std::cout << "========= 2. PARAMETER & COPY CONSTRUCTORS =========" << std::endl;
		DiamondTrap dia("Dia");

		std::cout << "\n--- Checking Initial Identity & Special Abilities ---" << std::endl;
		dia.whoAmI();
		dia.guardGate();      // Inherited from ScavTrap
		dia.highFivesGuys();  // Inherited from FragTrap

		std::cout << "\n--- Copying DiamondTrap ---" << std::endl;
		DiamondTrap diaCopy(dia);

		diaCopy.whoAmI();
		diaCopy.attack("a clone target");
		std::cout << "--- Scope ending for Section 2 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 3. COPY ASSIGNMENT OPERATOR (=) =========" << std::endl;
		DiamondTrap diaOriginal("OriginalDia");
		DiamondTrap diaAssign("TempDia");

		std::cout << "\n--- Executing Operator= ---" << std::endl;
		diaAssign = diaOriginal; // Assign attributes of diaOriginal to diaAssign

		diaAssign.whoAmI();
		diaAssign.guardGate();
		diaAssign.highFivesGuys();
		std::cout << "--- Scope ending for Section 3 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 4. COMBAT & REPAIR FLOW =========" << std::endl;
		DiamondTrap dia("Dia");  // HP: 100 (from FragTrap), EP: 50 (from ScavTrap), AD: 30 (from FragTrap)
		ClapTrap clap("Clappy"); // HP: 10, EP: 10, AD: 0

		std::cout << "\n--- Combat ---" << std::endl;
		dia.attack("Clappy");   // Should output ScavTrap's attack message!
		clap.takeDamage(30);    // Clappy HP drops to 0 (Dead)

		std::cout << "\n--- Action on Dead Object ---" << std::endl;
		clap.attack("Dia");     // Should fail
		clap.beRepaired(10);    // Should fail

		std::cout << "\n--- Repairing & Special Ability ---" << std::endl;
		dia.beRepaired(15);
		dia.whoAmI();
		std::cout << "--- Scope ending for Section 4 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 5. POLYMORPHISM & VIRTUAL DESTRUCTOR =========" << std::endl;
		
		std::cout << "--- Base Pointer to DiamondTrap (ClapTrap*) ---" << std::endl;
		ClapTrap* clapPtr = new DiamondTrap("PolymorphicDia");
		clapPtr->attack("Target"); // Calls ScavTrap::attack() via ClapTrap virtual mechanism
		delete clapPtr;            // Triggers ~DiamondTrap -> ~ScavTrap -> ~FragTrap -> ~ClapTrap chain!

		std::cout << "\n--- Base Pointer to DiamondTrap (FragTrap*) ---" << std::endl;
		FragTrap* fragPtr = new DiamondTrap("FragDia");
		fragPtr->highFivesGuys();
		delete fragPtr;            // Triggers complete destruction chain
		
		std::cout << "--- Scope ending for Section 5 ---" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========= ALL TESTS COMPLETE =========" << std::endl;
	return 0;
}

  // FragTrap *ayumi = new DiamondTrap("abc");
  // delete ayumi;