#ifndef _AMATERIA_H_
#define _AMATERIA_H_
#include "ICharacter.hpp"
#include <string>

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		~AMateria();
		std::string const&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
	protected:
		std::string			_type;
};

#endif