#ifndef _CAT_H_
#define _CAT_H_
#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();
		void makeSound() const;
};

#endif