#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    std::cout << "========== Test 1: Valid Bureaucrat & AForm ==========\n";
    try
    {
        Bureaucrat bob("Bob", 42);
        ShrubberyCreationForm form1("form1");
        ShrubberyCreationForm form2("form2");
        form2 = form1;

        form2.execute(bob);
        // AForm contract("Contract", 50, 25);

        std::cout << bob << std::endl;
        // std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // std::cout << "\n========== Test 2: AForm grade too high ==========\n";
    // try
    // {
    //     AForm f("Invalid", 0, 10);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n========== Test 3: AForm grade too low ==========\n";
    // try
    // {
    //     AForm f("Invalid", 10, 151);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n========== Test 4: Successful signing ==========\n";
    // try
    // {
    //     Bureaucrat boss("Boss", 1);
    //     AForm tax("Tax AForm", 50, 30);

    //     std::cout << tax << std::endl;

    //     boss.signForm(tax);

    //     std::cout << tax << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n========== Test 5: Failed signing ==========\n";
    // try
    // {
    //     Bureaucrat intern("Intern", 100);
    //     AForm secret("Top Secret", 20, 10);

    //     std::cout << secret << std::endl;

    //     intern.signForm(secret);

    //     std::cout << secret << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n========== Test 6: Sign already signed form ==========\n";
    // try
    // {
    //     Bureaucrat alice("Alice", 1);
    //     Bureaucrat john("John", 10);
    //     AForm form("Agreement", 20, 20);

    //     alice.signForm(form);
    //     john.signForm(form);

    //     std::cout << form << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n========== Test 7: Copy constructor ==========\n";
    // try
    // {
    //     AForm original("Original", 30, 40);
    //     AForm copy(original);

    //     std::cout << original << std::endl;
    //     std::cout << copy << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n========== Test 8: Assignment operator ==========\n";
    // try
    // {
    //     AForm first("First", 50, 60);
    //     AForm second("Second", 10, 20);

    //     std::cout << "Before assignment:\n";
    //     std::cout << first << std::endl;
    //     std::cout << second << std::endl;

    //     first = second;

    //     std::cout << "After assignment:\n";
    //     std::cout << first << std::endl;
    //     std::cout << second << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    return 0;
}