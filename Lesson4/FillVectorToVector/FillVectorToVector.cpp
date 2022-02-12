#include <iostream>
#include <vector>
#include <algorithm>

//Function for print vector
void printVector(const std::vector<int>& values)
{
    for (int n : values)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2;
    
    //v2.assign(v1.begin() + v1.size()/2, v1.end());
    //copy(v1.begin() + v1.size()/2, v1.end(), back_inserter(v2));
    for_each(v1.begin() + v1.size()/2, v1.end(), [&v2](const int n) {v2.push_back(n); });

    std::cout << "First vector values: ";
    printVector(v1);

    std::cout << "Second vector values: ";
    printVector(v2);
        
    return 0;
}

