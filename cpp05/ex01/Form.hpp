#ifndef _FORM_H_
#define _FORM_H_
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Form
{
	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string getName();
		bool getIsSigned();
		int getRequiredGrade();
		int getExecutedGrade();
		// void beSigned(const Bureaucrat& input);

		class GradeTooHighException : public std::exception
		{
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*		what() const throw();
		};

	private:
		const std::string _name;
		bool _isSigned;
		const int _requiredGrade;
		const int _executedGrade;
};

std::ostream& operator<<(std::ostream &out, const Form& other);


#endif