#ifndef MACHINE
#define MACHINE

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct CVertex {
    std::unordered_map<std::string, std::unordered_set<CVertex*>> edges;
    bool final = false;
};

void make_edge(CVertex* a, CVertex* b, const std::string& word);

struct Automat {
    CVertex* vertex;
    std::unordered_set<CVertex*> final;
};

std::unordered_set<CVertex*> find_all(const std::unordered_set<CVertex*>& set_);

struct CMachine {
    std::vector<CVertex*> vector;
    std::deque<Automat> stack;

    void add(const std::string& letter);

    CVertex* order();

    void point();

    void star();
    void plus();
    void step(char letter);

    void load(const std::string& string);
    bool result(int k, char x);

    void clear() {
        vector.clear();
        stack.clear();
    }

    ~CMachine();

    std::unordered_set<CVertex*> apply(const std::unordered_set<CVertex*>& set_, const std::string& letter);
};


#endif