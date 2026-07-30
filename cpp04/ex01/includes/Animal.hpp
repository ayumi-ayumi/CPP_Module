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
		virtual ~Animal(); // Without virtual, skip all the destructor from derived classes when deleting
		virtual void		makeSound() const;
		const std::string	getType() const;
	protected:
		std::string			_type;
};

#endif
