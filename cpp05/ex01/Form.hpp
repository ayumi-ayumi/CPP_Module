#ifndef _FORM_H_
#define _FORM_H_
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &formName, int requiredGrade, int executedGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getRequiredGrade() const;
		int					getExecutedGrade() const;
		
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*		what() const throw();
		};

	private:
		const std::string	_name;
		bool					_isSigned;
		const int			_requiredGrade;
		const int			_executedGrade;
};

std::ostream& operator<<(std::ostream &out, const Form& other);

#endif