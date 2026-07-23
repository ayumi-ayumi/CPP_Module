#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <string>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		const std::string getType() const;
	protected:
		std::string _type;
};

#endif