#pragma once
#include <string>
#include <ctime>

class Book
{
private:
	unsigned long bookCode;
	std::string title;
	std::string author;
	std::tm registrationDate;
	bool isLended;

public:
	Book(int bookCode, std::string title, std::string author, std::tm registrationDate, bool isLended = false);
	bool isLendedCheck() const;
	void printBook() const;
}; 

