#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <tuple>
#include <time.h>

#include "EmployeesDatabase.h"

EmployeesDatabase::EmployeesDatabase(std::string fileName) : fileName(fileName) {};

//Print main menu
void EmployeesDatabase::printMenu()
{
    std::cout << "Choose your action:\n"
        << "1 - View file data\n"
        << "2 - Add data to file\n"
        << "3 - Sort database alphabetically (by surname)\n"
        << "4 - Output: list of people born in a given month\n"
        << "5 - Output: the surname of the oldest man\n"
        << "6 - Output: all surname starting with the given letter\n"
        << "0 - Exit\n";

    selectAction();
}

//Select action function
void EmployeesDatabase::selectAction()
{
    int actionNumber;
    bool isCorrectNumber = false;

    while (!isCorrectNumber) {
        std::cout << "Select number: ";
        std::cin >> actionNumber;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect number!";
            confirmationOfWorkContinue();
        }
        else {
            switch (actionNumber)
            {
            case 1:
                viewFileData();
                isCorrectNumber = true;
                break;
            case 2:
                addEmployee();
                isCorrectNumber = true;
                break;
            case 3:
                sortDatabase();
                isCorrectNumber = true;
                break;
            case 4:
                getBornThisMonth();
                isCorrectNumber = true;
                break;
            case 5:
                getOldestManSurname();
                isCorrectNumber = true;
                break;
            case 6:
                getSurnameStartingWithLetter();
                isCorrectNumber = true;
                break;
            case 0:
                std::exit(0);
                break;
            default:
                std::cout << "Wrong number, try again!!!" << std::endl;
                break;
            }

        }
    }
}

//Add persons to list of employees
void EmployeesDatabase::fillData()
{
    std::ifstream inputFile(fileName);
    
    //If file not exist
    if (!inputFile)
    {
        std::cerr << "File " << fileName << " is't open!" << std::endl;
        exit(0);
    }

    //Read file and fill employees database
    while (inputFile)
    {
        std::string inputString;
        std::getline(inputFile, inputString);

        char delimiter = ' ';
        std::stringstream stringStream(inputString);
        std::string personInfo;

        std::vector<std::string> person;

        //Reading string from file and add words in to person using delimiter
        while (std::getline(stringStream, personInfo, delimiter))
        {
            person.push_back(personInfo);
        }

        //Create and add new person to employees list
        if (!person.empty()) {
            std::string surname = person[0];
            std::string name = person[1];
            std::string patronymic = person[2];
            int day = std::stoi(person[3]);
            int month = std::stoi(person[4]);
            int year = std::stoi(person[5]);
            char sex = person[6][0];

            Employee newEmployee(surname, name, patronymic, day, month, year, sex);
            employees.push_back(newEmployee);
        }
    }
}

//View file data
void EmployeesDatabase::viewFileData()
{
    //Fill data if vector is empty
    if (employees.empty()) {
        fillData();
    }

    std::cout << "\nEmployees list:\n";

    //Print all employees
    for (auto e : employees) {
        e.print();
        std::cout<< "\n";
    }

    confirmationOfWorkContinue();
}

//Add new employee
void EmployeesDatabase::addEmployee()
{
    //Input new employee data
    std::cout << "\nInput new employee data: \n";

    std::cout << "Input surname: ";
    std::string surname = readString("Surname");

    std::cout << "Input name: ";
    std::string name = readString("Name");

    std::cout << "Input patronymic: ";
    std::string patronymic = readString("Patronymic");

    //Get current year
    std::tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int currentYear = newtime.tm_year + 1900;

    std::cout << "Input year of birth: ";
    int year = readIntValue("Year" , 1900, currentYear);

    std::cout << "Input month of birth: ";
    int month = readIntValue("Month", 1, 12);

    std::cout << "Input day of birth: ";
    int day;

    //Getting the day, checking the number of days in the month
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        day = readIntValue("Day", 1, 31);
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        day = readIntValue("Day", 1, 30);
    } 
    
    if (month == 2){
        if (year % 4 == 0) {
            day = readIntValue("Day", 1, 29);
        }
        else {
            day = readIntValue("Day", 1, 28);
        }
    }

    std::cout << "Input sex (m / w): ";
    char sex = ' ';

    //Check sex value
    while (sex != 'm' && sex !='w') {
        sex = (readChar("Sex"));
        sex = std::tolower(sex);

        if (sex != 'm' && sex != 'w') {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nIncorrect sex value. Repeat input please: ";
        }
    }

    //Add new empoyees to file
    Employee newEmployee(surname, name, patronymic, day, month, year, sex);
    std::ofstream outputFile(fileName, std::ios::app);
    outputFile << newEmployee.employeeToString() << std::endl;
    outputFile.close();

    //Add new employees to vector
    if (!employees.empty()) {
        employees.push_back(newEmployee);
    }

    confirmationOfWorkContinue();
}

//Function for database sort
void EmployeesDatabase::sortDatabase()
{
    //Fill data if vector is empty
    if (employees.empty()) {
        fillData();
    }

    //Sort employees by surname
    std::sort(employees.begin(), employees.end(), [](const Employee& first, const Employee& second)->bool {return first.getSurname() < second.getSurname(); });
    
    //Print employees list
    std::cout << "\nEmployees list sorted by surname:\n";
    for (auto e : employees) {
        e.print();
        std::cout << "\n";
    }

    confirmationOfWorkContinue();
}

//Function for get all who born in selected month
void EmployeesDatabase::getBornThisMonth()
{
    //Fill data if vector is empty
    if (employees.empty()) {
        fillData();
    }

    //Input employees month of birth
    if (!employees.empty()){
        std::cout << "Input employees month of birth: ";
        int month = readIntValue("Month", 1, 12);

        int count = 0;

        //Search employee by month of birth
        for (auto e : employees) {
            if (e.getMonth() == month) {
                if (count == 0) {
                    std::cout << "\nEmployees born this month:\n";
                }

                e.print();
                std::cout << "\n";
                count++;
            }
        }

        if (count == 0){
            std::cout << "\nNo births this month...\n";
        }
    }
    else {
        std::cout << "\nList of employees is empty!\n";
    }

    confirmationOfWorkContinue();
}

//Function for get oldest employee Surname
void EmployeesDatabase::getOldestManSurname()
{
    //Fill data if vector is empty
    if (employees.empty()) {
        fillData();
    }

    Employee oldestEmployee(employees[0]);

    //Search oldest employees
    for (auto e : employees) {
        if (e.getYear() < oldestEmployee.getYear() ||
            (e.getYear() == oldestEmployee.getYear() && e.getMonth() < oldestEmployee.getMonth()) ||
            (e.getYear()  == oldestEmployee.getYear() && (e.getMonth() == oldestEmployee.getMonth() && e.getDay() < oldestEmployee.getDay()))) {
            oldestEmployee = e;
        }
    }

    std::cout << "\n Oldest employee is ";
    oldestEmployee.print();
    std::cout << "\n";

    confirmationOfWorkContinue();
}

//Function for search Surname by starting letter
void EmployeesDatabase::getSurnameStartingWithLetter()
{
    //Fill data if vector is empty
    if (employees.empty()) {
        fillData();
    }

    //Input the first letter of surname
    std::cout << "\nInsert the first letter of surname: ";
    char firstLetter = readChar("Surname first letter");

    int count = 0;

    //Search employees by the first letter of surname
    for (auto e : employees) {
        if (e.getSurname()[0] == std::toupper(firstLetter)) {
            if (count == 0) {
                std::cout << "\nPeople with surname start with this letter:\n";
            }
            e.print();
            std::cout << "\n";
            count++;
        }
    }

    if (count == 0) {
        std::cout << "\nPeople with surname start with this letter is absent...\n";
    }

    confirmationOfWorkContinue();
}

//Confirmation of work continue function
void EmployeesDatabase::confirmationOfWorkContinue() {
    char c;
    bool confirmation = false;

    while (!confirmation) {
        std::cout << "\nDo you want continue (Y / N): ";
        std::cin >> c;
        c = std::toupper(c);

        switch(c) {
            case 'Y':
                confirmation = true;
                system("cls");
                printMenu();
                break;
            case 'N':
                std::exit(0);
                break;
            default:
                break;
        }
    }
}

//Read int value function
int EmployeesDatabase::readIntValue(const std::string& name, const int min, const int max) 
{
    int intValue;
    bool isCorrectValue = false;

    while (!isCorrectValue) {
        std::cin >> intValue;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nIncorrect " << name <<" value.Repeat input please : ";
        }
        else {
            if (intValue < min || max < intValue) {
                std::cout << "\n" << name << " value can't be less " << min << " and greater " << max << ". Repeat input please: ";
            }
            else {
                isCorrectValue = true;
            }
        }
    }
    return intValue;
}

//Read string value function
std::string EmployeesDatabase::readString(const std::string& name) 
{
    std::string string;
    bool isCorrectValue = false;

    while (!isCorrectValue) {
        std::cin >> string;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nIncorrect " << name << " value. Repeat input please : ";
        }
        else {
            if (string.length() < 2){
                std::cout << "\n"  << name << " size can't be less 2 symbols! Repeat input please: ";
            }
            else {
                isCorrectValue = true;
            }
        }
    }

    return string;
}

//Read char value function
char EmployeesDatabase::readChar(const std::string& name) 
{
    char c;
    bool isCorrectValue = false;

    while (!isCorrectValue) {
        std::cin >> c;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nIncorrect " << name << " value. Repeat input please : ";
        }
        else {
          std::cin.clear();
          std::cin.ignore(32767, '\n');
          isCorrectValue = true;
        }
    }

    return c;
}


