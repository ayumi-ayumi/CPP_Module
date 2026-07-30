#ifndef _DOG_H_
#define _DOG_H_
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();
		void	makeSound() const;
	private:
		Brain*	_dogBrain;
};

#endif
