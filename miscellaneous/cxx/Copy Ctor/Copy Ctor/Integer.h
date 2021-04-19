#pragma once
#include <iostream>
//#include <string>
//#include <fstream>
using namespace std;
class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer &obj);
	// overload assignment operator
	Integer& operator =(const Integer &a);
	//Move constructor: TODO overload move assigment operator
	//Integer(Integer &&obj);
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};
