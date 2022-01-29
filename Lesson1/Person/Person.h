#pragma once
#include <string>

class Person
{
	private:
		std::string surname;
		std::string name;
		std::string patronymic;
		int age;
		int assestmentScore;

	public:
		Person();
		Person(std::string surname, std::string name, std::string patronymic, int age, int assestmentScore);
		int getAge();
		int getAssestmentScore();
		void printPerson();
};

