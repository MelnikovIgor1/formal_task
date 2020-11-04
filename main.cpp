#include "machine.h"

int main() {
    std::string str;
    char x = 0;
    int k = 0;

    std::cin >> str >> x >> k;

    Machine machine(x, k);

    for (auto letter: str) {
        machine.step(letter);
    }

    std::cout << machine.stack.front().info[k].first;

    return 0;
}
