#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <string>

class Animal // Abstract class
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void makeSound() const;
		const std::string getType() const;
	protected:
		std::string _type;
};

#endif