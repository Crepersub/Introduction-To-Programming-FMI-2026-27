#include <iostream>

int main() {
    double input;
    std::cin >> input;

    bool isWholeNumber = input == (int)input;

    std::cout << std::boolalpha << isWholeNumber << std::endl;

    return 0;
}
