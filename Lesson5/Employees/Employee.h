#pragma once

#include <string>

class Employee
{
	private:
		std::string surname;
		std::string name;
		std::string patronymic;
		int day;
		int month;
		int year;
		char sex;

	public:
		Employee();
		Employee(std::string surname, std::string name, std::string patronymic, int day, int month, int year, char sex);
		std::string employeeToString() const;
		std::string getSurname() const;
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		void print() const;
};

