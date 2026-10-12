#include <iostream>

int main() {
    // integer overflow
    int largeNumber = 2147483645;
    std::cout << "largeNumber + 0 = " << largeNumber + 0 << std::endl;
    std::cout << "largeNumber + 1 = " << largeNumber + 1 << std::endl;
    std::cout << "largeNumber + 2 = " << largeNumber + 2 << std::endl;
    std::cout << "largeNumber + 3 = " << largeNumber + 3 << std::endl;
    std::cout << "largeNumber + 4 = " << largeNumber + 4 << std::endl;
    std::cout << "largeNumber + 5 = " << largeNumber + 5 << std::endl;
    std::cout << "largeNumber + 6 = " << largeNumber + 6 << std::endl;
    std::cout << std::endl;

    // integer underflow
    int smallNumber = -2147483648;
    std::cout << "smallNumber - 0 = " << smallNumber - 0 << std::endl;
    std::cout << "smallNumber - 1 = " << smallNumber - 1 << std::endl;
    std::cout << "smallNumber - 2 = " << smallNumber - 2 << std::endl;
    std::cout << "smallNumber - 3 = " << smallNumber - 3 << std::endl;
    std::cout << std::endl;

    // unsigned
    unsigned int unsignedNumber = 4294967293;
    std::cout << "unsignedNumber + 0 = " << unsignedNumber + 0 << std::endl;
    std::cout << "unsignedNumber + 1 = " << unsignedNumber + 1 << std::endl;
    std::cout << "unsignedNumber + 2 = " << unsignedNumber + 2 << std::endl;
    std::cout << "unsignedNumber + 3 = " << unsignedNumber + 3 << std::endl;
    std::cout << "unsignedNumber + 4 = " << unsignedNumber + 4 << std::endl;
    std::cout << "unsignedNumber + 5 = " << unsignedNumber + 5 << std::endl;
    std::cout << "unsignedNumber + 6 = " << unsignedNumber + 6 << std::endl;
    std::cout << std::endl;

    unsignedNumber = 2;
    std::cout << "unsignedNumber - 0 = " << unsignedNumber - 0 << std::endl;
    std::cout << "unsignedNumber - 1 = " << unsignedNumber - 1 << std::endl;
    std::cout << "unsignedNumber - 2 = " << unsignedNumber - 2 << std::endl;
    std::cout << "unsignedNumber - 3 = " << unsignedNumber - 3 << std::endl;
    std::cout << "unsignedNumber - 4 = " << unsignedNumber - 4 << std::endl;
    std::cout << "unsignedNumber - 5 = " << unsignedNumber - 5 << std::endl;
    std::cout << "unsignedNumber - 6 = " << unsignedNumber - 6 << std::endl;
    std::cout << std::endl;

    unsigned int test = -2;
    std::cout << "unsigned int test = -2 = " << test << std::endl;

    return 0;
}
