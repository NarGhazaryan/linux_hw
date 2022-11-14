#include <iostream>
#include <string>

void do_magic();

int main() {
    do_magic();

    std::string man;
    std::getline(std::cin, man);

    std::cout << man;

    return 0;
}