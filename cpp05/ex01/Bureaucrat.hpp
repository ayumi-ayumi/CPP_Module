#ifndef _BUREAUCRAT_H_
#define _BUREAUCRAT_H_
#include "Form.hpp"
#include <string>
#include <ostream>

class Bureaucrat : public Form
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;

		void				increaseGrade(); // grade++;
		void				decreaseGrade(); // grade--;

		// void				signForm();

		// class GradeTooHighException : public std::exception
		// {
		// 	const char*		what() const throw();
		// };

		// class GradeTooLowException : public std::exception
		// {
		// 	const char*		what() const throw();
		// };
		
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& other);

#endif