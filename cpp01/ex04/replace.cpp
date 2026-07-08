#include "replace.hpp"

static std::string replaceStr(std::string &buf, std::string s1, std::string s2)
{
    size_t pos = buf.find(s1);
    std::string temp = buf.erase(pos, s1.length());
    temp.insert(pos, s2);
    return (temp);
}

void    createNewFile(std::string filename, std::string s1, std::string s2)
{
    if (s1 == "" || s2 == "")
    {
        std::cerr << "|--- Invalid parameter ---|" << std::endl;
        std::exit(1);
    }

    std::ifstream filein(filename);
    if (!filein)
    {
        std::cerr << "|--- Failed to open a file ---|" << std::endl;
        std::exit(1);
    }
    
    std::ofstream fileout(filename + ".replace");
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