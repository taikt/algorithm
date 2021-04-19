#pragma once
#include <iostream>
using namespace std;

class integer {
	int *m_pint;
public:
	integer();
	integer(int value);
	//copy constructor
	integer(const integer& obj);
	int getValue() const;
	void setValue(int value);
	~integer();
	// plus overloading operator, implemented as member function
	// i.e integer sum = a+b; will invoke
	integer operator +(const integer &a) const;
};