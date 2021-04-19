#include "integer.h"

integer::integer() : integer(0)
{
}

integer::integer(int value)
{
	cout << "integer(int)" << endl;
	m_pint = new int(value);

}

integer::integer(const integer & obj)
{
	cout << "integer(const integer& obj)" << endl;
	m_pint = new int(*obj.m_pint);
}

int integer::getValue() const
{
	cout << "getValue" << endl;
	return *m_pint;
}

void integer::setValue(int value)
{
	cout << "setValue" << endl;
	*m_pint = value;
}

integer::~integer()
{
	cout << "~integer" << endl;
}

integer integer::operator+(const integer & a) const
{
	cout << "operator+(const integer& a)" << endl;
	integer temp;
	*temp.m_pint = *m_pint + *a.m_pint;
	return temp;
}
