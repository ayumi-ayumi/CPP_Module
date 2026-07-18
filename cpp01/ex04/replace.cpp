#include "replace.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

static void replaceStr(std::string &buf, std::string s1, std::string s2)
{
	size_t pos = 0;
	while (1)
	{
		pos = buf.find(s1, pos);
		if (pos == std::string::npos) break; // npos indicates "not found"
		buf.erase(pos, s1.length());
		buf.insert(pos, s2);
		pos += s1.length();
	}
}

void	createNewFile(std::string filename, std::string s1, std::string s2)
{
	if (s1 == "" || s2 == "")
	{
		std::cerr << "|--- Invalid parameter ---|" << std::endl;
		std::exit(1);
	}

	std::ifstream filein(filename.c_str()); // c_str() changes a string to char *
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
		std::cerr << "|--- Failed to create a file ---|" << std::endl;
		std::exit(1);
	}

	std::string buf;
	while (getline(filein, buf))
	{
		replaceStr(buf, s1, s2);
		if (!filein.eof())
			fileout << buf << std::endl;
		else
			fileout << buf;
	}

	if (filein.eof())
		std::cout << "|--- Reached end of file ---|" << std::endl;
	else
		std::cerr << "|--- Error: File reading failed ---|!" << std::endl;

	filein.close();
}
