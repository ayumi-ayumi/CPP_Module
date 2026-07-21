#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== Test 1: Constructor =====\n";
	ClapTrap unnamed; // Default constructor
	ClapTrap ayumi("Ayumi");
	ClapTrap clappy("Clappy");
	ClapTrap trappy("Trappy");
	ClapTrap clappyCopy(clappy); // Copy constructor
	trappy = unnamed; // Copy assignment operator

	std::cout << "\n===== Test 2: Basic attack =====\n";
	ayumi.attack("Monster");

	std::cout << "\n===== Test 3: Take damage =====\n";
	ayumi.takeDamage(3);

	std::cout << "\n===== Test 4: Repair =====\n";
	ayumi.beRepaired(5);

	std::cout << "\n===== Test 5: Multiple actions =====\n";
	ayumi.attack("Monster");
	ayumi.takeDamage(2);
	ayumi.beRepaired(1);

	std::cout << "\n===== Test 6: Use all energy =====\n";
	ClapTrap alice("Alice");

	for (int i = 0; i < 10; i++)
		alice.attack("Target");

	std::cout << "\nTrying to attack with 0 energy:\n";
	alice.attack("Target");

	std::cout << "\nTrying to repair with 0 energy:\n";
	alice.beRepaired(1);

	std::cout << "\n===== Test 7: HP reaches 0 =====\n";
	ClapTrap enemy("Enemy");

	enemy.takeDamage(5);
	enemy.takeDamage(5);

	std::cout << "\nTrying to attack with 0 HP:\n";
	enemy.attack("Someone");

	std::cout << "\nTrying to repair with 0 HP:\n";
	enemy.beRepaired(5);

	std::cout << "\n===== End of tests =====\n";

	return (0);
}
