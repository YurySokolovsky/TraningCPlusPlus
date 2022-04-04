#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

//Print vector
void printVector(std::vector<int>& vector)
{
    for (auto v : vector)
    {
        std::cout << v << " ";
    }
}

//Fill data to vector
void fillVector(std::vector<int> &vector)
{
    srand(time(NULL));

    for (auto i = 0; i < 100; i++)
    {
        vector.push_back(rand() % 100);
    }
}

//Using Bubble sort 
void bubbleSortVector(std::vector<int> vector)
{
    auto startTime = std::chrono::steady_clock::now();;

    for (int i = 0; i < vector.size(); i++) {
        for (int j = vector.size()-1; j >= i + 1; j--) {
            if (vector[j] < vector[j - 1])
                std::swap(vector[j], vector[j - 1]);
        }
    }

    auto endTime = std::chrono::steady_clock::now();
    auto timeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "\n\nBubble sort algorithm time: " << timeNanoseconds.count() << " nanoseconds";
    std::cout << "\nSorted vector values:  ";
    printVector(vector);
}

//Using STL library sorting function
void sortVector(std::vector<int> vector)
{
    auto startTime = std::chrono::steady_clock::now();;
    std::sort(vector.begin(), vector.end());
    auto endTime = std::chrono::steady_clock::now();
    auto timeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "\n\nSTL sort algorithm time: " << timeNanoseconds.count() << " nanoseconds";
    std::cout << "\nSorted vector values:  ";
    printVector(vector);
}

int main()
{
    std::vector<int> values;
    fillVector(values);
    std::cout << "\nUnsorted vector values:  ";
    printVector(values);
    bubbleSortVector(values);
    sortVector(values);
    return 0;
}
