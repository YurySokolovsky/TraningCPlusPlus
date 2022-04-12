#include <iostream>
#include "Vector.h"

//Function for moving constructor check
Vector<int> func()
{
    Vector<int> values(10);
    return values;
}

int main()
{
    //Create new vector
    Vector<int> values;

    std::cout << "\n=============== Different vector methods calling ===============";
    for (int i = 0; i < 5; i++) {
        values.push_back(i+1);
        std::cout << "\nPush_back(" << i+1 <<")";
    }

    //Check vector methods
    std::cout << "\nVector size = " << values.size();
    std::cout << "\nVector capacity = " << values.capacity();
    std::cout << "\nVector values: ";

    //Print vector values and check begin()/end() methods
    for (auto v : values) {
        std::cout << v << " ";
    }

    //Chech methods and operator[] 
    std::cout << "\nRemove element " << values[3] << " in position 4";
    values.remove(3);
    std::cout << "\nPop_back(). Delete value " << values[values.size()-1];
    values.pop_back();
    std::cout << "\nInsert value 0 in position 0";
    values.insert(0, 0);
    std::cout << "\nSet value 10 in position 3";
    values[3] = 10;

    //Print vector values and check operator[]
    std::cout << "\nVector values: ";
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << " ";
    }

    //Check clear() and empty() methods
    values.clear();
    std::cout << "\nClear vector";

    if (values.empty())
    {
        std::cout << "\nVector values is empty" << std::endl;
    }

    //Different constructors and operators calling
    std::cout << "\n================ Different constructors calling ================" << std::endl;

    //Using copy constructor
    Vector<int> valuesCopy(values);

    //Using copy operators
    Vector<int> valuesCopy2;
    valuesCopy2 = valuesCopy;

    //Using moving constructor
    auto valuesCopy3 = func();

    //Using copy moving operator
    valuesCopy2 = std::move(values);

    //std::cout << values << std::endl;
    return 0;
}

 