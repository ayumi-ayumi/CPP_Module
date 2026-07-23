#ifndef _ICHARACTER_H_
#define _ICHARACTER_H_
#include "AMateria.hpp"
#include <string>

class ICharacter
{
	public:
		ICharacter();
		ICharacter(std::string name);
		ICharacter(const ICharacter& other);
		ICharacter& operator=(const ICharacter& other);
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	protected:
		AMateria* slot[4];
};

#endif