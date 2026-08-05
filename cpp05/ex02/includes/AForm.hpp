#ifndef _FORM_H_
#define _FORM_H_
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &formName, int requiredGrade, int executedGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getRequiredGrade() const;
		int					getExecutedGrade() const;
		
		virtual void		beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const;
		virtual void		action() const = 0;

		class GradeTooHighException : public std::exception
		{
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*		what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			const char*		what() const throw();
		};

	private:
		const std::string	_name;
		bool					_isSigned;
		const int			_requiredGrade;
		const int			_executedGrade;
};

std::ostream& operator<<(std::ostream &out, const AForm& other);

#endif