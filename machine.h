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

struct СMachine {
    std::vector<CVertex*> vector;
    std::deque<Automat> stack;

    void add(const std::string& letter);

    CVertex* order();

    void point();

    void star();
    void plus();
    void step(char letter);
    ~СMachine();

    std::unordered_set<CVertex*> apply(std::unordered_set<CVertex*>& set_, const std::string& letter);

//    void print() {
//        for (auto item: stack.back().final) {
//            printf("%p ", item);
//        }
//        printf("\n");
//        printf("%p\n", stack.back().vertex);
//        for (auto item: vector) {
//            printf("%p\n   ", item);
//            for (const auto& edge: item->edges) {
//                for (auto word: edge.second) {
//                    std::cout << "[" << edge.first;
//                    printf(", %p]", word);
//                }
//
//            }
//            std::cout << "\n";
//        }
//    }
};


#endif