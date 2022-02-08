#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> values{ 0, 1, 2, 3, 4};
    std::for_each(values.begin(), values.end(), [](const int& n) { std::cout << n << " "; });
}

