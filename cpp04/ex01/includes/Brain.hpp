#ifndef _BRAIN_H_
#define _BRAIN_H_
#include "Animal.hpp"
#include <string>

class Brain
{
	public:
		Brain();
		// Brain(const Brain& other);
		// Brain& operator=(const Brain& other);
		virtual ~Brain();
		std::string _ideas[100];
};

#endif