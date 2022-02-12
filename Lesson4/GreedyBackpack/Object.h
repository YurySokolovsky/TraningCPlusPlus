#pragma once
class Object
{
private:
	double weight;
	double cost;

public:
	Object(const double weight, const double cost);
	bool operator<(const Object& object) const;
	double getWeight() const;
	void print() const;
};

