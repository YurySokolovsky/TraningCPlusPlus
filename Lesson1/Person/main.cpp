#include <iostream>
#include <memory>
#include <algorithm>
#include "Person.h"

//Fill array function
std::unique_ptr<Person[]> fillArray(int &arraySize)
{
    arraySize = 5;

    auto persons = std::make_unique<Person[]>(arraySize);
    persons[0] = Person("Ivanov","Ivan","Ivanovich", 36, 75);
    persons[1] = Person("Petrov", "Petr", "Petrovich", 40, 90);
    persons[2] = Person("Nicolaev", "Nicolay", "Nicolaevich", 27, 80);
    persons[3] = Person("Sidorov", "Sidor", "Sidorovich", 50, 70);
    persons[4] = Person("Dmitriev", "Dmitriy", "Dmitrievich", 45, 85);
    
    return persons;
}

//Get Persons avearge age function
void averageAge(std::unique_ptr<Person[]> &persons, int arraySize)
{
    int summ = 0;

    for (int i = 0; i < 5; i++)
    {
        summ += persons[i].getAge();
    }

    std::cout << "Average age: " << summ / arraySize << std::endl;
    std::cout << std::endl;
}

//Compare two Persons by Assestment Score function
bool compareByAssesmentScore(Person& first, Person& second)
{
    return first.getAssestmentScore() < second.getAssestmentScore();
}

//Persons sort by Assestment Score function 
void sortPersonByAssesmentScore(std::unique_ptr<Person[]>& persons, int arraySize)
{
    std::sort(&persons[0], &persons[arraySize], compareByAssesmentScore);
}

//Function for print Persons
void printPersons(std::unique_ptr<Person[]>& persons, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        persons[i].printPerson();
    }
    std::cout << std::endl;
}


int main()
{
    int arraySize = 0;
    auto persons = fillArray(arraySize);

    std::cout << "============ Unsorted array ===========" << std::endl;
    printPersons(persons, arraySize);

    averageAge(persons, arraySize);
    sortPersonByAssesmentScore(persons, arraySize);

    std::cout << "======== Array sorted by Assestment Score ========" << std::endl;
    printPersons(persons, arraySize);

    return 0;
}

