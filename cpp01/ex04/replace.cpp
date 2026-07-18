#include "replace.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

static	std::string replaceStr(std::string &buf, std::string s1, std::string s2)
{
	size_t pos = buf.find(s1);
	std::string temp = buf.erase(pos, s1.length());
	temp.insert(pos, s2);
	return (temp);
}

void	createNewFile(std::string filename, std::string s1, std::string s2)
{
	if (s1 == "" || s2 == "")
	{
		std::cerr << "|--- Invalid parameter ---|" << std::endl;
		std::exit(1);
	}

	std::ifstream filein(filename.c_str()); // c_str() changes the string to char *
	if (!filein)
	{
		std::cerr << "|--- Failed to open a file ---|" << std::endl;
		std::exit(1);
	}
	if (filein.peek() == EOF) // peek() checks the next char in the input stream
	{
		std::cerr << "|--- File is empty ---|" << std::endl;
		std::exit(1);
	}

	std::string outputFileName = filename + ".replace";
	std::ofstream fileout(outputFileName.c_str());
	if (!fileout)
	{
		std::cerr << "|--- Failed to open a file ---|" << std::endl;
		std::exit(1);
	}

	std::string buf;
	while (getline(filein, buf))
	{
		std::string temp = replaceStr(buf, s1, s2);
		if (!filein.eof())
			fileout << temp << std::endl;
		else
			fileout << temp;
	}

	if (filein.eof())
		std::cout << "|--- Reached end of file ---|" << std::endl;
	else
		std::cerr << "|--- Error: File reading failed ---|!" << std::endl;

	filein.close();
}
