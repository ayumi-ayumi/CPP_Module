#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

int main()
{
	std::cout << "========== TEST 1: Shrubbery Creation ==========" << std::endl;
	{
		try
		{
			Intern intern;
			Bureaucrat boss("Boss", 1);

			AForm* form = intern.makeForm("shrubbery creation", "garden");

			std::cout << *form << std::endl;

			boss.signForm(*form);
			boss.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n========== TEST 2: Robotomy Request ==========" << std::endl;
	{
		try
		{
			Intern intern;
			Bureaucrat boss("Boss", 1);

			AForm* form = intern.makeForm("robotomy request", "Bender");

			std::cout << *form << std::endl;

			boss.signForm(*form);

			for (int i = 0; i < 5; i++)
			{
				std::cout << "Attempt " << i + 1 << ":" << std::endl;
				boss.executeForm(*form);
			}

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n========== TEST 3: Presidential Pardon ==========" << std::endl;
	{
		try
		{
			Intern intern;
			Bureaucrat president("President", 1);

			AForm* form = intern.makeForm("presidential pardon", "Arthur Dent");

			std::cout << *form << std::endl;

			president.signForm(*form);
			president.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n========== TEST 4: Unknown Form ==========" << std::endl;
	{
		try
		{
			Intern intern;

			AForm* form = intern.makeForm("some random form", "target");

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n========== TEST 5: Grade Too Low ==========" << std::endl;
	{
		try
		{
			Intern intern;
			Bureaucrat lowGrade("LowGrade", 150);

			AForm* form = intern.makeForm("shrubbery creation", "garden");

			lowGrade.signForm(*form);
			lowGrade.executeForm(*form);

			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n========== TEST 6: Direct Form Creation Through Intern ==========" << std::endl;
	{
		Intern intern;

		AForm* form1 = NULL;
		AForm* form2 = NULL;
		AForm* form3 = NULL;

		try
		{
			form1 = intern.makeForm("shrubbery creation", "tree");
			form2 = intern.makeForm("robotomy request", "robot");
			form3 = intern.makeForm("presidential pardon", "criminal");

			std::cout << "Form 1: " << *form1 << std::endl;
			std::cout << "Form 2: " << *form2 << std::endl;
			std::cout << "Form 3: " << *form3 << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		delete form1;
		delete form2;
		delete form3;
	}

	return 0;
}