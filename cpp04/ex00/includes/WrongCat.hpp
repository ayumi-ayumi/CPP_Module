#ifndef _WRONGCAT_H_
#define _WRONGCAT_H_
#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		virtual ~WrongCat();
		void	makeSound() const;
};

#endif
