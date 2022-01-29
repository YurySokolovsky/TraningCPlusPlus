#include "Library.h"
#include <iostream>

//Method to add Book to Library
void Library::addBook(const Book &book) 
{
	books.push_back(book);
	std::cout << "Add to library ";
	book.printBook();
};

//Method to add Reader to Library
void Library::addReader(const Reader &reader) 
{
	readers.push_back(reader);
	std::cout << "Add to library ";
	reader.printReader();
};

//Method for printing Books in Library
void Library::printBooks() 
{
	if (!books.empty())
	{
		std::cout << "================ Books in Library ====================" << std::endl;
		for (auto n : books)
		{
			n.printBook();
		}
	}
	else
	{
		std::cout << "There aren't Books in Library!" << std::endl;
	}
	std::cout << std::endl;
};

//Method for printing Readers in Library
void Library::printReaders()
{
	if (!readers.empty())
	{
		std::cout << "=============== Readers in Library ===================" << std::endl;
		for (auto n : readers)
		{
			n.printReader();
		}
	}
	else
	{
		std::cout << "There aren't Readers in Library!" << std::endl;
	}
	std::cout << std::endl;
};
