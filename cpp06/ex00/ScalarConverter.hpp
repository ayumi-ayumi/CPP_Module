#ifndef _SCALAR_CONVERTER_H_
#define _SCALAR_CONVERTER_H_
#include <string>

using std::string;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const string &str);
};

#endif
