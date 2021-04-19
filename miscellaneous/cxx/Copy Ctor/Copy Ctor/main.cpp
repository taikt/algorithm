#include "Integer.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b){
	Integer temp ;
	temp.SetValue(a.GetValue() + b.GetValue()) ;
	return temp ;
}

void testCopyConstructor(Integer a) {
	cout << "value:" << a.GetValue()<<"\n";
}

void testNotCopyConstructor(Integer &a) {
	cout << "value:" << a.GetValue()<<"\n";
}

Integer CopyConstructorFunctionReturn() {
	Integer temp(2);
	return temp;
}

Integer& NotCopyConstructorFunctionReturn(Integer &a) {
	a.SetValue(3);
	return a;
}

int main() {
	Integer a(1);
	//a.SetValue(Add(a,b).GetValue()) ;
	
	// Integer x(a); //==> call copy constructor, manully copy variable
	// testCopyConstructor(a); //==> call copy constructor, pass by value

	// testNotCopyConstructor(a); //==> not call copy constructor, pass by reference

	// copy constructor is called (return function by value) if not defined move constructor
	// othewise, move constructor is called
	// cout<<"value= "<<CopyConstructorFunctionReturn().GetValue()<<"\n";


	// copy constructor is not called (return function by reference)
	// cout << "value= " << NotCopyConstructorFunctionReturn(a).GetValue() << "\n";

	 Integer c;
	 c = a; // assigment operator is called
	 cout << "value: " << c.GetValue()<<"\n";


	return 0;
}