#pragma once
#include <sstream>

template <class TValue>
class ListVector
{
public:
	ListVector();
	~ListVector();
	ListVector<TValue>* Add(const TValue& value);
	std::string ToString();

private:
	void ExpandCapacity();

	TValue* data;
	size_t count;
	size_t capacity;
	const int expandFactor = 2;
};

template <class TValue>
ListVector<TValue>::ListVector()
{
	this->capacity = 100;
	this->count = 0;
	this->data = new TValue[this->capacity];
}

template <class TValue>
ListVector<TValue>::~ListVector()
{
	delete[] this->data;
}

template<class TValue>
ListVector<TValue>* ListVector<TValue>::Add(const TValue& value)
{
	if (this->count >= this->capacity)
		this->ExpandCapacity();

	this->data[this->count++] = value;

	return this;
}

template<class TValue>
inline std::string ListVector<TValue>::ToString()
{
	if (this->count == 0)
		return "";

	std::stringstream tmpStream;
	size_t lastIndex = this->count - 1;
	for (size_t index = 0; index < lastIndex; index++)
		tmpStream << this->data[index] << ", ";
	tmpStream << this->data[lastIndex];
	return tmpStream.str();
}

template<class TValue>
inline void ListVector<TValue>::ExpandCapacity()
{
	this->capacity *= this->expandFactor;
	auto buffer = new TValue[this->capacity];
	std::copy(this->data, this->data + this->count, buffer);
	delete[] this->data;
	this->data = buffer;
}
