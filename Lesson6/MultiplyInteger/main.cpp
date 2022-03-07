#include <iostream>
#include <stdexcept>

int multiplyInteger(const int a, const int b)
{
    if ((a < 0 && b < 0) || (0 < a && 0 < b)) {
        if ((INT_MAX / a) / b < 1) {
                throw std::overflow_error("Overflow error! The resulting value exceeds the hihg border for the Iteger type...");
        }
    }
    
    if ((a < 0 && 0 < b) || ( 0 < a && b < 0))
    {
        if ((INT_MAX / a) / b > -1) {
                    throw std::overflow_error("Overflow error! The resulting value exceeds the low border for the Iteger type...");
        }
    }
    
    return a * b;
}

int main()
{
    int a = 10000;
    int b = 100000;
    int c = -100000;

    std::cout << "Integer  A = " << a << "\nInteger  B = " << b << "\nInteger  C = " << c << std::endl;

    //Check for positive values
    try {
        std::cout << "Result of multiply A x B = ";
        std::cout << multiplyInteger(a, b) << std::endl;
    }
    catch (std::overflow_error& error) {
        std::cout << error.what() << std::endl;
    }

    //Check for negative values
    try {
        std::cout << "Result of multiply A x C = ";
        std::cout << multiplyInteger(a, c) << std::endl;
    }
    catch (std::overflow_error& error) {
        std::cout << error.what() << std::endl;
    }

    //Check for zero values
    try {
        std::cout << "Result of multiply A x 0 = ";
        std::cout << multiplyInteger(a, 0) << std::endl;
    }
    catch (std::overflow_error& error) {
        std::cout << error.what() << std::endl;
    }

    //Check overflow in high border 
    try {
        std::cout << "Result of multiply B x B = ";
        std::cout << multiplyInteger(b, b) << std::endl;
    }
    catch (std::overflow_error& error) {
        std::cout << error.what() << std::endl;
    }

    //Check overflow in low border 
    try {
        std::cout << "Result of multiply B x C = ";
        std::cout << multiplyInteger(b, c) << std::endl;
    }
    catch (std::overflow_error& error) {
        std::cout << error.what() << std::endl;
    }
}

