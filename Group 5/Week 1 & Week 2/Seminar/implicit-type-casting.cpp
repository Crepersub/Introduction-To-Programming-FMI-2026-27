#include <iostream>

int main() {
    char letter = '(';
    int number = letter;
    float fractional = number;

    std::cout << letter << std::endl;
    std::cout << number << std::endl;
    std::cout << fractional << std::endl;
    std::cout << std::endl;

    //

    float floatToInt = 3.14;
    int fromFloat = floatToInt;

    std::cout << floatToInt << std::endl;
    std::cout << fromFloat << std::endl;
    std::cout << std::endl;

    //

    double numWrong = 5 / 2;
    std::cout << numWrong << std::endl;

    double numCorrect = 5.0 / 2;
    std::cout << numCorrect << std::endl;

    return 0;
}
