#include<iostream>

#include "ListVector.h"

using namespace std;
int main()
{
	auto myList = new ListVector<int>();
	myList->Add(1);
	myList->Add(2);
	myList->Add(3)->Add(4)->Add(5);
	cout << myList->ToString();
}