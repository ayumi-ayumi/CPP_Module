#ifndef _INTERN_H_
#define _INTERN_H_
#include "AForm.hpp"
#include <string>

class Intern
{
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(std::string name, std::string target);
};

#endif
