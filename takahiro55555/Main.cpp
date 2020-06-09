#include <iostream>

#include "Pid.hpp"

int main() {
    Pid pid = Pid(0.6, 1.0, 0.2);

    std::cout << pid.controll(200, 100) << std::endl;

    return 0;
}