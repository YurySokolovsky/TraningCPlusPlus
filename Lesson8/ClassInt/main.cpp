#include <iostream>
#include "Int.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Int first;
    Int second;

    std::cout << "==== Рекомендуемые значения для проверки first = 10, second = 5 ====" << std::endl;
    std::cout << "Введите первое значение (first): ";
    std::cin >> first;
    std::cout << "Введите второе значение (second): ";
    std::cin >> second;

    std::cout << "\n===========Результаты операций над объектами класса Int==========="
        <<"\n====Рекомендуемые значения для проверки first = 10, second = 5 ====="
        << "Значение первого объекта (first) = " << first << "\n"
        << "Значение первого объекта (second) = " << second << "\n"
        << "first + second = " << (first + second) << "\n"
        << "first - second = " << (first - second) << "\n"
        << "first * second = " << (first * second) << "\n"
        << "first / second = " << (first / second) << std::endl;
    std::cout << "first = second = " << (first = second) << std::endl;
}
