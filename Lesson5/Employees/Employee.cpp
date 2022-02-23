#include <iostream>
#include "Employee.h"

Employee::Employee() {};

Employee::Employee(std::string surname, std::string name, std::string patronymic, int day, int month, int year, char sex) 
					:surname(surname), name(name), patronymic(patronymic), day(day), month(month), year(year), sex(sex) {};

std::string Employee::employeeToString() const
{
	std::string employee = name + " " + surname + " " + patronymic + " " + std::to_string(day) 
							+ " " + std::to_string(month) + " " + std::to_string(year) + " " + sex;
	return employee;
}

std::string Employee::getSurname() const
{
	return surname;
}

int Employee::getDay() const
{
	return day;
}

int Employee::getMonth() const
{
	return month;
}

int Employee::getYear() const
{
	return year;
}

void Employee::print() const
{
	std::cout << surname << " " << name << " " << patronymic << ", "
		<< "birth date: " << day << "." << month << "." << year << ", " << "sex: " << sex;
}