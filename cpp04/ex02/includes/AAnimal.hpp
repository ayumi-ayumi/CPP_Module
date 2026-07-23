#ifndef _AANIMAL_H_
#define _AANIMAL_H_
#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		const std::string getType() const;
	protected:
		std::string _type;
};

#endif