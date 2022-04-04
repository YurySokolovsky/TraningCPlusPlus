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


int bubbleSortVectorGetCount(std::vector<int> vector)
{
    int count = 0;

    for (int i = 0; i < vector.size(); i++) {
        for (int j = vector.size() - 1; j >= i + 1; j--) {
            if (vector[j] < vector[j - 1])
            {
                std::swap(vector[j], vector[j - 1]);
                count++;
            }
        }
    }

    return count;
}

//Using Bubble sort 
void bubbleSortVectorGetTime(std::vector<int> vector)
{
    int count = bubbleSortVectorGetCount(vector);

    auto startTime = std::chrono::steady_clock::now();;

    for (int i = 0; i < vector.size(); i++) {
        for (int j = vector.size() - 1; j >= i + 1; j--) {
            if (vector[j] < vector[j - 1])
            {
                std::swap(vector[j], vector[j - 1]);
            }
        }
    }

    auto endTime = std::chrono::steady_clock::now();
    auto timeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "\n\nBubble sort algorithm time: " << timeNanoseconds.count() << " nanoseconds\nBubble sort algorithm operation count: " << count ;
    std::cout << "\nSorted vector values:  ";
    printVector(vector);
}

int sortVectorGetCount(std::vector<int> vector)
{
    int count = 0;
    std::sort(vector.begin(), vector.end(), [&count](int a, int b)->bool {if (a > b) count++; return a < b; });
    return count;
}

//Using STL library sorting function
void sortVector(std::vector<int> vector)
{
    int count = sortVectorGetCount(vector);
    auto startTime = std::chrono::steady_clock::now();
    std::sort(vector.begin(), vector.end(), [&count](int a, int b)->bool {if (a > b) count++; return a < b; });
    auto endTime = std::chrono::steady_clock::now();
    auto timeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "\n\nSTL sort algorithm time: " << timeNanoseconds.count() << " nanoseconds\nSTL sort algorithm operation count: " << count;
    std::cout << "\nSorted vector values:  ";
    printVector(vector);
}

int main()
{
    std::vector<int> values;
    fillVector(values);
    std::cout << "\nUnsorted vector values:  ";
    printVector(values);
    bubbleSortVectorGetTime(values);
    sortVector(values);
    return 0;
}
