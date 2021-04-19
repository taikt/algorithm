#include "Integer.h"
#include <iostream>
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int): " <<value<< std::endl;
	m_pInt = new int(value);
}

// copy constructor, se dc chay de deep copy cho temporary object neu khong explicit khai bao move constructor
// copy constructor dc call khi
// 1. pass object to function by value
// 2. function return object by value
// 3. manually create copy of variable i.e Integer i2(i)
Integer::Integer(const Integer & obj) {
	std::cout << "copy constructor: Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

// assigment operator.
// if user not declare, compiler create default assigment operator using shallow copy, which shoub be avoided
Integer & Integer::operator=(const Integer & a)
{
	cout << "assigment operator is called" << "\n";
	if (this != &a) { // avoid assign by itself by comparing address
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}

// tu dong move temporary object, su dung 'shawdow copy', khong can deep copy nhu copy constructor
#if 0
Integer::Integer(Integer && obj) {
	std::cout << "move constructor: Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}
#endif


int Integer::GetValue() const {
	cout <<"getvalue:"<< *m_pInt << endl;
	return *m_pInt;
}

void Integer::SetValue(int value) {
	cout << "setvalue: " << value << endl;
	*m_pInt = value;
}

Integer::~Integer() {
	//std::cout << "~Integer(): value=" <<*m_pInt<<std::endl;
	//cout << *m_pInt << endl;
	std::cout << "~Integer()" <<std::endl;
	delete m_pInt;
}






