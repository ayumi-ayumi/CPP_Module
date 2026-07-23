#ifndef _CURE_H_
#define _CURE_H_
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();
		// std::string const & getType() const; //Returns the materia type
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif