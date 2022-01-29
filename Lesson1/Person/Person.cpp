#include "iostream"
#include "Person.h"

Person::Person() {}

Person::Person(std::string surname, std::string name, std::string patronymic, int age, int assestmentScore):
					surname(surname), name(name), patronymic(patronymic), age(age), assestmentScore(assestmentScore) {}

int Person::getAge()
{
	return age;
}

int Person::getAssestmentScore()
{
	return assestmentScore;
}

void Person::printPerson()
{
	std::cout << surname << " " << name << " " << patronymic << ", age: " << age << ". Assestment score: " << assestmentScore << std::endl;
}
