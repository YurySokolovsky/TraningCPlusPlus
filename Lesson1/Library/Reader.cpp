#include <iostream>
#include "Reader.h"

Reader::Reader(int readerCode, std::string surname, std::string name, std::string patronymic, int registrationCardNumber) :
	readerCode(readerCode), surname(surname), name(name), patronymic(patronymic), registrationCardNumber(registrationCardNumber) {}

//Method for printing Reader Information
void Reader::printReader() const 
{
	std::cout << "Reader: N" << readerCode << ", " << surname << " " << name << " " 
				<< patronymic << ". Registrtion card N" << registrationCardNumber << std::endl;
}
