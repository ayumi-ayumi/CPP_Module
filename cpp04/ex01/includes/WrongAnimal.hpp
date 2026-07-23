#ifndef _WRONGANIMAL_H_
#define _WRONGANIMAL_H_
#include <string>

class WrongAnimal // Abstract class
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		void makeSound() const;
		const std::string getType() const;
	protected:
		std::string _type;
};

#endif