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

    std::pair<bool, bool>& operator [](size_t i);// {
//        return info[i];
//    }

    std::vector<std::pair<bool, bool>> info;

    bool operator==(const CInfo& other) const {
        return info == other.info;
    }
};

CInfo point(const CInfo& x1, const CInfo& x2);

CInfo star(const CInfo& x1);

CInfo plus(const CInfo& x1);

struct Machine {
    Machine(char letter, int k) :
        stack(),
        x(letter),
        k(k){

    }

    Machine() :
        stack(),
        x(),
        k(){

    }

    void SetMachine(char letter, int K) {
        x = letter;
        k = K;
    }

    std::deque<CInfo> stack;
    char x;
    int k;

    void make(char operation) {
        if (operation == '.') {
            auto x2 = stack.back();
            stack.pop_back();
            auto x1 = stack.back();
            stack.pop_back();

            stack.push_back(point(x1, x2));
        }
        if (operation == '*') {
            auto x1 = stack.back();
            stack.pop_back();

            stack.push_back(star(x1));
        }
        if (operation == '+') {
            auto x1 = stack.back();
            stack.pop_back();

            stack.push_back(plus(x1));
        }
    }

    void add(char letter) {
        CInfo item(k + 1);
        if (letter == x) {
            item.info[1] = {true, true};
        } else {
            item.info[0] = {true, false};
        }
        stack.push_back(item);
    }

    void step(char letter) {
        switch (letter) {
            case '.':
            case '*':
            case '+':
                make(letter);
                break;
            default:
                add(letter);
                break;
        }
    }
};

#endif