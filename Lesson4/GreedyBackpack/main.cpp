#include <iostream>
#include <algorithm>
#include <set>
#include "Object.h"

int main()
{
    std::multiset <Object> objects; 
    double backpackCapacity = 12.5;   //backpack Capacity
        
    objects.insert(Object(1.1, 1.1));
    objects.insert(Object(2.2, 2.4));
    objects.insert(Object(4.4, 4.1));
    objects.insert(Object(3.3, 3.7));
    objects.insert(Object(2.2, 2.4));
    objects.insert(Object(5.5, 6.6));

    //Print objects list
    std::cout << "== Object list sort by value ==" << std::endl;
    for (auto n : objects)
    {
        n.print();
    }

    //Put objects in backpack and print them
    std::cout << "\n====  Objects in backpack  ====" << std::endl;
    for (auto n : objects) 
    {
        if (n.getWeight() <= backpackCapacity)
        {
            backpackCapacity -= n.getWeight();
            n.print();
        }
    }
}
