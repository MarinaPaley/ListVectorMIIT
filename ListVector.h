#pragma once
#include <sstream>
using namespace std;

template <class TValue>
class ListVector
{
public:
	ListVector();
	~ListVector();
	ListVector<TValue>* Add(const TValue& value);
	string ToString();

private:
	TValue* data;
	size_t count;
	size_t capacity;
	const int expandFactor = 2;
	void ExpandCapacity();
};

template <class TValue>
ListVector<TValue>::ListVector()
{
	this->capacity = 100;
	this->count = 0;
	this->data = new TValue[this->capacity]();
}

template <class TValue>
ListVector<TValue>::~ListVector()
{
	delete[]data;
}

template<class TValue>
ListVector<TValue>* ListVector<TValue>::Add(const TValue& value)
{
	if (this->count + 1 > this->capacity)
		this->ExpandCapacity();

	size_t lastIndex = this->count;
	this->data[lastIndex] = value;
	++this->count;
	return this;
}

template<class TValue>
inline string ListVector<TValue>::ToString()
{
	stringstream tmpStream;
	size_t lastIndex = this->count - 1;
	for (size_t index = 0; index < lastIndex; index++)
		tmpStream << this->data[index] << " , ";
	tmpStream << this->data[lastIndex];
	return tmpStream.str();
}

template<class TValue>
inline void ListVector<TValue>::ExpandCapacity()
{
	this->capacity *= this->expandFactor;
	auto tmpData = new TValue[this->capacity];
	size_t lastIndex = this->count;
	for (size_t index = 0; index < lastIndex; index++)
		tmpData[index] = this->data[index];
	delete[] this->data;
	this->data = tmpData;
}
