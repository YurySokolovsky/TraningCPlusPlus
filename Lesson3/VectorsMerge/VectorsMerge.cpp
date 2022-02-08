#include <iostream>
#include <vector>
#include <algorithm>

//Function for vector merging
template <class T, class V>
std::vector<V> mergeVector(std::vector<T>& vector1, std::vector<V>& vector2){

    std::vector<V> newVector;

    for (unsigned int i = 0; i < std::max(vector1.size(), vector2.size()); i++)
    {
        if (i < std::min(vector1.size(), vector2.size()))
        {
            newVector.push_back(vector1[i] + vector2[i]);
        }
        else
        {
            (vector1.size() < vector2.size()) ? newVector.push_back(vector2[i]): newVector.push_back(vector1[i]);
        }
        
    }
    return newVector;
}

//Function for vector printing 
template <class T>
void printVector(std::vector<T> vector)
{
    for (auto n : vector)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> values1{ 1, 2, 3 };
    std::vector<double> values2{ 1.1, 3.3, 4.4, 5.5 };

    std::cout << "First vector: ";
    printVector(values1);

    std::cout << "Second vector: ";
    printVector(values2);

    auto newValues = mergeVector(values1, values2);

    std::cout << "Resulting vector: ";
    printVector(newValues);
}
