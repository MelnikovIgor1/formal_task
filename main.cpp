#include "machine.h"

int main() {
    std::string str;
    char x = 0;
    int k = 0;

    std::cin >> str >> x >> k;

    СMachine machine;

    for (auto letter: str) {
        machine.step(letter);
    }

    std::unordered_set<CVertex*> start = {machine.stack.back().vertex};

    for (int i = 0; i < k; ++i) {
        std::string str_;
        str_ += x;
        start = machine.apply(start, str_);
    }
    if (start.empty()) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
