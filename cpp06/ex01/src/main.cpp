#include "Serializer.hpp"

int main()
{
	Data* data = new Data;
	data->str = "ez";
	data->i = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data* newData = Serializer::deserialize(raw);

	std::cout << newData->str << std::endl << newData->i << std::endl;

	delete data;
}