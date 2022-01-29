#include <iostream>
#include "Book.h"

Book::Book(int bookCode, std::string title, std::string author, std::tm registrationDate, bool isLended) :
			bookCode(bookCode), title(title), author(author), registrationDate(registrationDate), isLended(isLended) {}

//Method for checking whether the book is in hand
bool Book::isLendedCheck() const
{
	return isLended;
}

//Method for printing Book Information
void Book::printBook() const
{
	auto lendedMark = isLended ? "lended" : "not lended";
	std::cout << "Book: N" << bookCode << ", '" << title << "', " << author << ". Registred: " << registrationDate.tm_mday 
			<< "." << registrationDate.tm_mon << "." << registrationDate.tm_year << ". Lended mark: " << lendedMark << std::endl;
};