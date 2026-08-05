#ifndef _ROBOROMY_H_
#define _ROBOROMY_H_
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	public: 
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		void				execute(Bureaucrat const & executor) const;
		void				action() const;
		const std::string	_target;
};

#endif