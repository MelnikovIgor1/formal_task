#include "machine.h"

int main() {
    std::string str;
    char x = 0;
    int k = 0;

    std::cin >> str >> x >> k;

    CMachine machine;

    machine.load(str);


    if (!machine.result(k, x)) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
