#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t rtn_ptr = reinterpret_cast<uintptr_t>(ptr);
	return (rtn_ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *rtn_data = reinterpret_cast<Data *>(raw);
	return (rtn_data);
}
