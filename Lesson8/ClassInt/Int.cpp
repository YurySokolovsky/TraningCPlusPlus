#include "Int.h"
//Default constructor
Int::Int(){}

//Destructor
Int::~Int() {};

//Constructor
Int::Int(const int val) : val(val) {};

//Copy constructor
Int::Int(const Int& value) : val(value.val) {};

//Operator =
Int Int::operator=(const Int& value)
{
	if (this == &value)
		return *this;
	
	val = value.val;
	
	return *this;
}

//Operator +
Int Int::operator+(const Int& value)
{
	return Int(this->val + value.val);
}

//Operator -
Int Int::operator-(const Int& value)
{
	return Int(this->val - value.val);
}

//Operator *
Int Int::operator*(const Int& value)
{
	return Int(this->val * value.val);
}

//Operator /
Int Int::operator/(const Int& value)
{
	return Int(this -> val / value.val);
}

//Operator <<
std::ostream& operator<<(std::ostream& os, const Int& value) 
{
	return os << value.val;
}

//Operator >>
std::istream& operator>>(std::istream& in, Int& value)
{
	return in >> value.val;
}

