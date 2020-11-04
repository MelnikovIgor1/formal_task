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

CInfo point(const CInfo& x1, const CInfo& x2) {
    CInfo item(x1.K);

    for (int i = 0; i < x1.K; ++i) {
        for (int j = 0; j < x2.K; ++j) {
            if (i + j < x1.K && x1.info[i].first && x2.info[j].first) {
                if (x1.info[i].second) {
                    item.info[i + j] = {true, x1.info[i].second && x2.info[j].second};
                } else {
                    item.info[i] = {true, false};
                }
            }
        }
    }

    return item;
}

CInfo star(const CInfo& x1) {
    CInfo item(x1.K);
    item.info = x1.info;
    item.info[0] = {true, true};

    for (int i = 1; i < x1.K; ++i) {
        if (x1.info[i].first && x1.info[i].second) {
            int h = i;
            while (h < x1.K) {
                item.info[h] = {true, true};
                h += i;
            }
        }
    }

    return item;
}

CInfo plus(const CInfo& x1) {
    CInfo item(x1.K);
    item.info = x1.info;

    for (int i = 1; i < x1.K; ++i) {
        if (x1.info[i].first && x1.info[i].second) {
            int h = i;
            while (h < x1.K) {
                item.info[h] = {true, true};
                h += i;
            }
        }
    }

    return item;
}

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