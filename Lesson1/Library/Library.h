#pragma once
#include <vector>
#include "Book.h"
#include "Reader.h"

class Library
{
private:
	std::vector<Book> books;
	std::vector<Reader> readers;

public:
	void addBook(const Book& book);
	void addReader(const Reader& reader);
	void printBooks();
	void printReaders();
};

