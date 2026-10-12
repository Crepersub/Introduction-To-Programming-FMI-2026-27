#include <iostream>

int main() {
    int number;
    std::cout << number << std::endl;

    int divideByZero = 5 / 0;

    // program crashes before this point
    std::cout << divideByZero << std::endl;

    return 0;
}
