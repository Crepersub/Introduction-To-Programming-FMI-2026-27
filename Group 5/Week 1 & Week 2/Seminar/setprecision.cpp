#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::setprecision(2) << 0.12345 << std::endl;

    std::cout << std::setprecision(20) << (0.1 + 0.2) << std::endl;
    std::cout << std::setprecision(20) << (0.3) << std::endl;

    return 0;
}
