#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void) 
{
	{
		std::cout << "========= 1. DEFAULT CONSTRUCTOR =========" << std::endl;
		FragTrap defaultFrag;  // Tests FragTrap default constructor (HP: 100, EP: 100, AD: 30)
		ClapTrap defaultClap;  // Tests ClapTrap default constructor (HP: 10, EP: 10, AD: 0)

		defaultFrag.attack("Target Dummy");
		defaultClap.attack("Target Dummy");
		std::cout << "--- Scope ending for Section 1 ---" << std::endl;
	} // defaultFrag and defaultClap destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 2. PARAMETER & COPY CONSTRUCTORS =========" << std::endl;
		FragTrap frag("Fraggy");
		ClapTrap clap("Clappy");

		std::cout << "\n--- Copying FragTrap & ClapTrap ---" << std::endl;
		FragTrap fragCopy(frag); 
		ClapTrap clapCopy(clap);

		fragCopy.attack("a clone target");
		clapCopy.attack("a clone target");
		std::cout << "--- Scope ending for Section 2 ---" << std::endl;
	} // Destructors run in reverse order: clapCopy, fragCopy, clap, frag
	std::cout << std::endl;

	{
		std::cout << "========= 3. COPY ASSIGNMENT OPERATOR (=) =========" << std::endl;
		FragTrap fragOriginal("OriginalFrag");
		FragTrap fragAssign("TempFrag");

		std::cout << "\n--- Executing Operator= ---" << std::endl;
		fragAssign = fragOriginal; // Assign fragOriginal to fragAssign

		fragAssign.highFivesGuys();
		std::cout << "--- Scope ending for Section 3 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	{
		std::cout << "========= 4. COMBAT & REPAIR FLOW =========" << std::endl;
		FragTrap frag("Fraggy"); // HP: 100, EP: 100, AD: 30
		ClapTrap clap("Clappy"); // HP: 10,  EP: 10,  AD: 0

		std::cout << "\n--- Combat ---" << std::endl;
		frag.attack("Clappy");
		clap.takeDamage(30); // Clappy HP drops to 0 (Dead)

		std::cout << "\n--- Action on Dead Object ---" << std::endl;
		clap.attack("Fraggy"); // Should fail
		clap.beRepaired(10);   // Should fail

		std::cout << "\n--- Repairing & Special Ability ---" << std::endl;
		frag.beRepaired(20);
		frag.highFivesGuys();  // FragTrap's special capacity
		std::cout << "--- Scope ending for Section 4 ---" << std::endl;
	} // Destructors run here
	std::cout << std::endl;

	std::cout << "========= ALL TESTS COMPLETE =========" << std::endl;
	return 0;
}