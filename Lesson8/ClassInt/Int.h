#pragma once
#include <iostream>

class Int
{
private:
	int val;

public:
	Int();
	// The destructor, copy constructor, and copy assignment operator
	// are used in accordance with the Rule of three.
	~Int();
	Int(const int val);
	Int(const Int& value);
	Int operator=(const Int& value);
	Int operator+(const Int& value);
	Int operator-(const Int& value);
	Int operator*(const Int& value);
	Int operator/(const Int& value);
	
	//Operators << and >> must be situated outside of the class!!!
	friend std::ostream& operator<<(std::ostream& os, const Int& value);
	friend std::istream& operator>>(std::istream& in, Int& value);
};

