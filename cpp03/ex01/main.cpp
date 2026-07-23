#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) 
{
	{
		std::cout << "========= 1. DEFAULT CONSTRUCTOR =========" << std::endl;
		ScavTrap defaultScav;  // Tests ScavTrap default constructor
		ClapTrap defaultClap;  // Tests ClapTrap default constructor
		defaultScav.attack("Target Dummy");
		defaultClap.attack("Target Dummy");
		std::cout << "--- Scope ending for Section 1 ---" << std::endl;
	} // defaultScav and defaultClap destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 2. PARAMETER & COPY CONSTRUCTORS =========" << std::endl;
		ScavTrap scav("Scavvy");
		ClapTrap clap("Clappy");

		std::cout << "\n--- Copying ScavTrap & ClapTrap ---" << std::endl;
		ScavTrap scavCopy(scav); 
		ClapTrap clapCopy(clap);

		scavCopy.attack("a clone target");
		clapCopy.attack("a clone target");
		std::cout << "--- Scope ending for Section 2 ---" << std::endl;
	} // Destructors run in reverse order: clapCopy, scavCopy, clap, scav
	std::cout << std::endl;

	{
		std::cout << "========= 3. COPY ASSIGNMENT OPERATOR (=) =========" << std::endl;
		ScavTrap scavOriginal("OriginalScav");
		ScavTrap scavAssign("TempScav");

		std::cout << "\n--- Executing Operator= ---" << std::endl;
		scavAssign = scavOriginal; // Assign scavOriginal to scavAssign

		scavAssign.guardGate();
		std::cout << "--- Scope ending for Section 3 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 4. COMBAT & REPAIR FLOW =========" << std::endl;
		ScavTrap scav("Scavvy"); // HP: 100, EP: 50
		ClapTrap clap("Clappy"); // HP: 10,  EP: 10

		std::cout << "\n--- Combat ---" << std::endl;
		scav.attack("Clappy");
		clap.takeDamage(20); // Clappy HP drops to 0 (Dead)

		std::cout << "\n--- Action on Dead Object ---" << std::endl;
		clap.attack("Scavvy"); // Should fail
		clap.beRepaired(10);   // Should fail

		std::cout << "\n--- Repairing ---" << std::endl;
		scav.beRepaired(15);
		scav.guardGate();
		std::cout << "--- Scope ending for Section 4 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	std::cout << "========= ALL TESTS COMPLETE =========" << std::endl;
	return 0;
}