#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor created" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor created" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain() 
{
	std::cout << "Brain destroyed" << std::endl;
}