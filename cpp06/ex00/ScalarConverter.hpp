#ifndef _SCALAR_CONVERTER_H_
#define _SCALAR_CONVERTER_H_
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(const std::string &str);
};

#endif
