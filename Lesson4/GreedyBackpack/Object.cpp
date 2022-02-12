#include <iostream>
#include <limits>
#include "Object.h"


Object::Object(const double weight, const double cost) : weight(weight), cost(cost) {};

bool Object::operator<(const Object& object) const
{
	return object.cost / object.weight < cost / weight;
}

double Object::getWeight() const
{
	return weight;
}

void Object::print() const
{
	std::cout << "Object weight = " << weight << ", cost = " << cost << std::endl;
}
