#pragma once

#include <vector>
#include <string>
#include "Employee.h"

class EmployeesDatabase
{
	private:
		std::vector<Employee> employees;
		std::string fileName;

	public:
		EmployeesDatabase(std::string fileName);
		void printMenu();
		void selectAction();
		void fillData();
		void viewFileData();
		void addEmployee();
		void sortDatabase();
		void getBornThisMonth();
		void getOldestManSurname();
		void getSurnameStartingWithLetter();
		void confirmationOfWorkContinue();
		int readIntValue(const std::string& name, const int min, const int max);
		std::string readString(const std::string& name);
		char readChar(const std::string& name);
};

