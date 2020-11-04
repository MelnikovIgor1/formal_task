#ifndef MACHINE
#define MACHINE

#include <iostream>
#include <vector>
#include <deque>

struct CInfo {
    CInfo(int k):
        K(k),
        info(k, {false, false}) {

    }
    int K;

    std::pair<bool, bool>& operator [](size_t i);
    std::vector<std::pair<bool, bool>> info;

    bool operator==(const CInfo& other) const;
};

CInfo point(const CInfo& x1, const CInfo& x2);

CInfo star(const CInfo& x1);

CInfo plus(const CInfo& x1);

struct Machine {
    Machine(char letter, int k);

    Machine();

    void SetMachine(char letter, int K);

    std::deque<CInfo> stack;
    char x;
    int k;

    void make(char operation);
    void add(char letter);
    void step(char letter);
};

#endif