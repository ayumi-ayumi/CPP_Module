#ifndef _CAT_H_
#define _CAT_H_
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();
		void	makeSound() const;
	private:
		Brain*	_catBrain;
};

#endif
