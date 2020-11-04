#include "machine.h"

std::pair<bool, bool>& CInfo::operator [](size_t i) {
    return info[i];
}

bool CInfo::operator==(const CInfo& other) const {
    return info == other.info;
}

Machine::Machine(char letter, int k) :
    stack(),
    x(letter),
    k(k){

}

Machine::Machine() :
    stack(),
    x(),
    k(){

}

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