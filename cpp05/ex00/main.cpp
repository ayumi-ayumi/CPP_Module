#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== Basic construction =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);

		std::cout << bob << std::endl;
		std::cout << "Name: " << bob.getName() << std::endl;
		std::cout << "Grade: " << bob.getGrade() << std::endl;

		std::cout << "\n===== Increment grade =====" << std::endl;
		bob.increaseGrade();
		std::cout << bob << std::endl;

		std::cout << "\n===== Decrement grade =====" << std::endl;
		bob.decreaseGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Constructor exception (too high) =====" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Constructor exception (too low) =====" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Increment exception =====" << std::endl;
	try
	{
		Bureaucrat high("High", 1);

		std::cout << high << std::endl;
		high.increaseGrade(); // should throw
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Decrement exception =====" << std::endl;
	try
	{
		Bureaucrat low("Low", 150);

		std::cout << low << std::endl;
		low.decreaseGrade(); // should throw
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Copy constructor =====" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Assignment operator =====" << std::endl;
	try
	{
		Bureaucrat a("A", 100);
		Bureaucrat b("B", 20);

		std::cout << "Before assignment:" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		a = b;

		std::cout << "After assignment:" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

/*
===== Basic construction =====
Bob, bureaucrat grade 50
Name: Bob
Grade: 50

===== Increment grade =====
Bob, bureaucrat grade 49

===== Decrement grade =====
Bob, bureaucrat grade 50

===== Constructor exception (too high) =====
Exception: Grade too high

===== Constructor exception (too low) =====
Exception: Grade too low

===== Increment exception =====
High, bureaucrat grade 1
Exception: Grade too high

===== Decrement exception =====
Low, bureaucrat grade 150
Exception: Grade too low

===== Copy constructor =====
Original: Original, bureaucrat grade 42
Copy:     Original, bureaucrat grade 42

*/