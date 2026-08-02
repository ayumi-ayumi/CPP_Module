#ifndef _FORM_H_
#define _FORM_H_
#include <string>

class Form
{
	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
	private:
		const std::string _name;
		bool isSigned;
		const int grade;
		const 
};

#endif