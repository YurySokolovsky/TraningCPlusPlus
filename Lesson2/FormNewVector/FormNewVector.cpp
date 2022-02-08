#include <iostream>
#include <vector>
#include <algorithm>

//Method for vector printing
void printVector(const std::vector<int>& vector)
{
    for (auto n : vector)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int k;
    std::vector<int> values{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << "Insert number of elements k <=10, k = ";
    std::cin >> k;

    if (std::cin.fail() || k < 0 || k >10)  //Check k value
    {
        std::cout << "Incorrect value of k!" << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    else                                  //If k value is valid
    {
        //Print old vector
        std::cout << "Vector : ";
        printVector(values);

        //Lambda expression calculate value for new vector
        auto returnNewValue{ [values](int number)->int
            {
                if (number < values.size())
                {
                    return values[number];
                }
                else
                {
                    return values.back() + number - values.size() + 1;
                }
            }
        };

        //Create new vector
        std::vector<int> newValues;

        //Add values to new vector
        for (int i = k; i < values.size() + k; i++)
        {
            newValues.push_back(returnNewValue(i));
        }

        //Print new vector
        std::cout << "New vector :";
        printVector(newValues);
    }
}
