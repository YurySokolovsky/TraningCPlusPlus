#include <iostream>
#include <memory>
#include "EmployeesDatabase.h"

int main()
{
    auto database = std::make_unique<EmployeesDatabase>("EmployeesData.txt");
    database->printMenu();
    return 0;
}

