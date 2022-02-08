#include <iostream>
#include <vector>
#include <algorithm>

//Function for vector filling
void fillVector(std::vector<int> &values)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 10; i++)
    {
        values.push_back(rand() % 100);
    }
}

//Method for vector printing
void printVector(const std::vector<int>& values) {
    for (auto n : values)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> values;
    fillVector(values);
    int count = 0;

    std::cout << "Unsorted vector : ";
    printVector(values);

    std::sort(values.begin(), values.end(), [&count](int a, int b)->bool { 
                                                                            if (a < b) 
                                                                            { 
                                                                                count++; 
                                                                            } 
                                                                            return a < b; 
                                                                          }
    );

    std::cout << "Sorted vector : ";
    printVector(values);

    std::cout << "Count of shifts : " << count << std::endl;
}

