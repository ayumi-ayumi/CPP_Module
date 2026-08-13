#ifndef _AFORM_H_
#define _AFORM_H_
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &formName, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

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
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream &out, const AForm& input);

#endif
