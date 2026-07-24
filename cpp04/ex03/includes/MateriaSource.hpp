#ifndef _MATERIASOURCE_H_
#define _MATERIASOURCE_H_
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif