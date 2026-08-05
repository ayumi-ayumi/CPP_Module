#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "========== Test 1: Shrubbery ==========\n";
    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm tree("garden");

        bob.signForm(tree);
        bob.executeForm(tree);

        std::cout << "Check that 'garden_shrubbery' was created.\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 2: Execute unsigned form ==========\n";
    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm tree("home");

        bob.executeForm(tree);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 3: Grade too low to sign ==========\n";
    try
    {
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm tree("forest");

        low.signForm(tree);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 4: Grade too low to execute ==========\n";
    try
    {
        Bureaucrat signer("Signer", 100);
        Bureaucrat executor("Executor", 140);

        ShrubberyCreationForm tree("park");

        signer.signForm(tree);
        executor.executeForm(tree);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 5: Robotomy ==========\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Bender");

        boss.signForm(robot);

        for (int i = 0; i < 5; i++)
        {
            std::cout << "Attempt " << i + 1 << ":" << std::endl;
            boss.executeForm(robot);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 6: Presidential Pardon ==========\n";
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 7: Form constructor exceptions ==========\n";
    try
    {
        ShrubberyCreationForm bad("");
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== Test 8: Different Bureaucrat grades ==========\n";
    try
    {
        Bureaucrat a("A", 150);
        Bureaucrat b("B", 145);
        Bureaucrat c("C", 137);

        ShrubberyCreationForm tree("school");

        a.signForm(tree);      // fail
        b.signForm(tree);      // success
        b.executeForm(tree);   // fail
        c.executeForm(tree);   // success
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}