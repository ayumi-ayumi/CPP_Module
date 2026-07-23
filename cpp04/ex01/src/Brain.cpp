#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor created" << std::endl;
}

// Brain::Brain(const Brain& other) : _ideas(other._ideas)
// {
// 	std::cout << "Brain copy constructor created" << std::endl;
// }

// Brain& Brain::operator=(const Brain& other)
// {
// 	if (this != &other)
// 		_ideas = other._ideas;
// 	std::cout << "Brain copy assignment operator called" << std::endl;
// 	return (*this);
// }

Brain::~Brain() 
{
	std::cout << "Brain destroyed" << std::endl;
}