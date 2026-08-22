#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_
#include <string>
#include <stdint.h>

struct Data
{
	int			id;
	std::string	name;
	int			score;
	bool		isSelected;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
