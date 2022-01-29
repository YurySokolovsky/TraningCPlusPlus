#include <iostream>
#include <memory>
#include "Library.h"

//Test function to add Books to Library
void addBooks(std::unique_ptr<Library> &library)
{
	std::cout << "================ Add Books to Library ===================" << std::endl;

	Book firstBook(1, "The Adventures of Tom Sawyer", "Mark Twain", {0,0,0,10,10,2020});
	Book secondBook(2, "The Last of the Mohicans", "James Fenimore Cooper", {0,0,0,11,11,2021}, true);
	Book thirdBook(3, "The Call of the Wild", " Jack London", {0,0,0,12,12,2022}, true);

	library->addBook(firstBook);
	library->addBook(secondBook);
	library->addBook(thirdBook);

	std::cout << std::endl;
}

//Test function to add Readers to Library
void addReaders(std::unique_ptr<Library> &library)
{
	std::cout << "=============== Add Readers to Library ==================" << std::endl;

	Reader firstReader(1, "Ivanov", "Ivan", "Ivanovich", 10000001);
	Reader secondReader(2, "Antonov", "Anton", "Antonovich", 10000002);
	
	library->addReader(firstReader);
	library->addReader(secondReader);

	std::cout << std::endl;
}

int main()
{	
	auto library = std::make_unique<Library>();

	//Add Books and Readers in Library
	addBooks(library);
	addReaders(library);
	
	//Check Books and Readers in Library
	library->printBooks();
	library->printReaders();

	return 0;
}