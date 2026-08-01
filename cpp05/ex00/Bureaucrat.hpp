#ifndef _BUREAUCRAT_H_
#define _BUREAUCRAT_H_
#include <string>
#include <ostream>

class Bureaucrat 
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string getName() const;
		unsigned int getGrade() const;
		void setName(std::string name);
		void setGrade(unsigned int grade);
		void increaseGrade(); // grade++;
		void decreaseGrade(); // grade--;
	private:
		const std::string _name;
		unsigned int _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& other);

#endif