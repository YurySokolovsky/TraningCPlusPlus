#pragma once
#include <string>

class Reader
{
private:
	unsigned long readerCode;
	std::string surname;
	std::string name;
	std::string patronymic;
	unsigned long registrationCardNumber;

public:
	Reader(int readerCode, std::string surname, std::string name, std::string patronymic, int registrationCardNumber);
	void printReader() const;
};