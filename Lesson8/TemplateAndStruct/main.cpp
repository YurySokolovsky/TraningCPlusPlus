#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "S.h"
#include "S1.h"
#include "S2.h"

int main()
{
    //=================== First part =====================
    //Using public fields for struct variable
    //Create structs
    S<int> intValue(5);
    S<char> charValue('a');
    S<double> doubleValue(5.5);
    S <std::string> stringValue("Hello!");
    S <std::vector<int>> vectorValues{ std::vector<int>{1, 2, 3, 4, 5} };

    //Print structs values from public field
    std::cout << "========== Print structs values from public field ==========" << "\n"
        << "Integer struct value: " << intValue.val << "\n"
        << "Char struct value: " << charValue.val << "\n"
        << "Double struct value: " << doubleValue.val << "\n"
        << "String struct value: " << stringValue.val << "\n"
        << "Vector struct values: ";
    std::for_each(vectorValues.val.begin(), vectorValues.val.end(), [](int x) {std::cout << x << " "; });

    //=================== Second part =====================
    //Using private field for struct variable
    S1<int> intValue1;
    S1<char> charValue1;
    S1<double> doubleValue1;
    S1 <std::string> stringValue1;
    S1 <std::vector<int>> vectorValues1;

    intValue1.set(16);
    charValue1.set('b');
    doubleValue1.set(10.10);
    stringValue1.set("World!");
    vectorValues1.set(std::vector<int>{6, 7, 8, 9, 10});

    std::cout << "\n\n========== Print structs values from private field ==========" << "\n"
        << "Integer struct value: " << intValue1.get() << "\n"
        << "Char struct value: " << charValue1.get() << "\n"
        << "Double struct value: " << doubleValue1.get() << "\n"
        << "String struct value: " << stringValue1.get() << "\n"
        << "Vector struct values: ";
    std::for_each(vectorValues1.get().begin(), vectorValues1.get().end(), [](int x) {std::cout << x << " "; });

    //=================== Third part =====================
    //Using non-const operator []
    S2<int> array(5);

    for (int i = 0; i < 5; i++)
        array[i] = 11 + i;

    std::cout << "\n\n===== Print arrays values (using non-const operator[]) ======" << "\n";
    for (int i = 0; i < 5; i++)
        std::cout << array[i] << " ";

    //Using const operator []
    const S2<int> constArray(5, 5);
    std::cout << "\n\n======= Print arrays values (using const operator[]) ========" << "\n";
    for (int i = 0; i < 5; i++)
        std::cout << constArray[i] << " ";

    //=================== Fourth part =====================
    //Using function read_val puting values from std::cin to variable
    intValue1.read_val();
    charValue1.read_val();
    doubleValue1.read_val();
    stringValue1.read_val();

    std::cout << "\n\n====== Print inputed structs values from private field =======" << "\n"
        << "Integer struct value: " << intValue1.get() << "\n"
        << "Char struct value: " << charValue1.get() << "\n"
        << "Double struct value: " << doubleValue1.get() << "\n"
        << "String struct value: " << stringValue1.get() << std::endl;
}



