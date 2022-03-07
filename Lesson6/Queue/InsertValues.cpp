#include <string>

#include "InsertValues.h"

//Print main menu
void InsertValues::printMenu()
{
    std::cout << "Choose your action:\n"
        << "1 - Create queue\n"
        << "2 - Add values to queue\n"
        << "3 - Delete values from queue\n"
        << "4 - Print queue values\n"
        << "0 - Exit\n";

    selectAction();
}

//Select action function
void InsertValues::selectAction()
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
                createQueue();
                isCorrectNumber = true;
                break;
            case 2:
                addValues();
                isCorrectNumber = true;
                break;
            case 3:
                deleteValues();
                isCorrectNumber = true;
                break;
            case 4:
                printQueue();
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

//Create queue
void InsertValues::createQueue()
{
    std::cout << "Insert queue size: ";
    int queueSize = readIntValue();
    queue = std::make_unique<Queue<int>>(queueSize);
    std::cout << "Add values to queue (only integer values avaliable)." << std::endl;
    addValues();
}

//Add new value to queue
void InsertValues::addValues()
{
    if (queue == nullptr) {
        std::cout << "The element cannot be added. Queue not created yet!";
        confirmationOfWorkContinue();
    }

    char c;
    bool confirmation = false;

    while (!confirmation) {
        std::cout << "\nDo you want add new value to Queue (Y / N): ";
        std::cin >> c;
        c = std::toupper(c);

        switch (c) {
        case 'Y':
            try {
                std::cin.clear();
                std::cin.ignore(32767, '\n');

                std::cout << "Input new value: ";
                int value = readIntValue();
                queue->push(value);

                std::cout << "Value succesfuly add." << std::endl;
                confirmation = false;
            }
            catch (const char* exception) {
                std::cout << exception << std::endl;
                confirmation = false;
            }
            break;
        case 'N':
            confirmation = true;
            system("cls");
            printMenu();
            break;
        default:
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            break;
        }
    }
}

//Delete value from queue
void InsertValues::deleteValues()
{
    if (queue == nullptr) {
        std::cout << "The element cannot be deleted.Queue not created yet!";
        confirmationOfWorkContinue();
    }

    char c;
    bool confirmation = false;

    while (!confirmation) {
        std::cout << "\nDo you want delete value from Queue (Y / N): ";
        std::cin >> c;
        c = std::toupper(c);

        switch (c) {
        case 'Y':
            try {
                std::cin.clear();
                std::cin.ignore(32767, '\n');

                auto deletedValue = queue->front();
                queue->pop();

                std::cout << "Value " + std::to_string(deletedValue) + " succesfuly deleted." << std::endl;
                confirmation = false;
            }
            catch (const char* exception) {
                std::cout << exception << std::endl;
                confirmation = false;
            }
            break;
        case 'N':
            confirmation = true;
            system("cls");
            printMenu();
            break;
        default:
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            break;
        }
    }
}

//Print queue values
void InsertValues::printQueue()
{
    if (queue == nullptr) {
        std::cout << "The queue cannot be printed.Queue not created yet!";
        confirmationOfWorkContinue();
    }

    queue->print();
    confirmationOfWorkContinue();
}

//Confirmation of work continue function
void InsertValues::confirmationOfWorkContinue() {
    char c;
    bool confirmation = false;

    while (!confirmation) {
        std::cout << "\nDo you want continue (Y / N): ";
        std::cin >> c;
        c = std::toupper(c);

        switch (c) {
        case 'Y':
            confirmation = true;
            system("cls");
            printMenu();
            break;
        case 'N':
            std::exit(0);
            break;
        default:
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            break;
        }
    }
}

//Read int value function
int InsertValues::readIntValue()
{
    int intValue;
    bool isCorrectValue = false;

    while (!isCorrectValue) {
        std::cin >> intValue;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nIncorrect value.Repeat input please : ";
        }
        else {
            isCorrectValue = true;
        }
    }
    return intValue;
}