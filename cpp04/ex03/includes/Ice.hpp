#ifndef _ICE_H_
#define _ICE_H_
#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif