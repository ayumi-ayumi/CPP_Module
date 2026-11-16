#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_
#include <string>
#include <stdint.h>

using std::string;

struct Data
{
	int		id;
	string	name;
	int		score;
	bool	isSelected;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* dataPtr);
		static Data* deserialize(uintptr_t raw);
};

#endif
