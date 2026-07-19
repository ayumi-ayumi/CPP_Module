#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. 構築テスト ---" << std::endl;
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");
    ClapTrap unnamed; // デフォルトコンストラクタ

    std::cout << "\n--- 2. 基本アクション＆エネルギー消費テスト ---" << std::endl;
    clappy.attack("TargetA");
    clappy.beRepaired(5);
    // この時点で Clappy のエネルギーは 10 -> 8 になっているはず

    std::cout << "\n--- 3. コピーコンストラクタのテスト ---" << std::endl;
    // Clappy（エネルギー8、HP15の状態）をコピー
    ClapTrap clappyCopy(clappy);

    std::cout << "\n--- 4. コピー代入演算子のテスト ---" << std::endl;
    // Trappy に unnamed の状態を代入
    trappy = unnamed;

    std::cout << "\n--- 5. ダメージ＆死亡テスト ---" << std::endl;
    clappyCopy.takeDamage(5);  // HP 15 -> 10
    clappyCopy.takeDamage(20); // HP 10 -> 0 (オーバーキル)
    clappyCopy.attack("TargetB"); // HP 0 なので行動できないはず
    clappyCopy.beRepaired(5);    // HP 0 なので修理できないはず

    std::cout << "\n--- 6. エネルギー枯渇テスト ---" << std::endl;
    // 残りエネルギー8のClappyを限界まで行動させる
    for (int i = 0; i < 9; i++) {
        clappy.attack("Dummy");
    }

    std::cout << "\n--- 7. デストラクタのテスト（スコープ終了） ---" << std::endl;
    return 0;
}

/*
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== Test 1: Constructor =====\n";
    ClapTrap unnamed; // Default constructor
	ClapTrap bob("Bob");
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");
	ClapTrap clappyCopy(clappy); // Copy constructor
	trappy = unnamed; // Copy assignment operator

	std::cout << "\n===== Test 2: Basic attack =====\n";
	bob.attack("Jim");

	std::cout << "\n===== Test 3: Take damage =====\n";
	bob.takeDamage(3);

	std::cout << "\n===== Test 4: Repair =====\n";
	bob.beRepaired(5);

	std::cout << "\n===== Test 5: Multiple actions =====\n";
	bob.attack("Monster");
	bob.takeDamage(2);
	bob.beRepaired(1);

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
*/
