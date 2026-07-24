#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "AMateria.hpp"
#include "IChatacter.hpp"
#include <string>

class Character
{
	public:
		Character();
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, Character& target) = 0;
};

#endif