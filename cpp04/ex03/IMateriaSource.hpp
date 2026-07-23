#ifndef _IMATERIASOURCE_H_
#define _IMATERIASOURCE_H_
#include "AMateria.hpp"
#include <string>

class IMateriaSource
{
	public:
		IMateriaSource();
		IMateriaSource(const IMateriaSource& other);
		IMateriaSource& operator=(const IMateriaSource& other);
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif