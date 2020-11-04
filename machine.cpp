#include "machine.h"

void make_edge(CVertex* a, CVertex* b, const std::string& word) {
    if (a->edges.find(word) == a->edges.end()) {
        a->edges.insert({word, {b}});
    } else {
        a->edges.find(word)->second.insert(b);
    }
}

std::unordered_set<CVertex*> find_all(const std::unordered_set<CVertex*>& set_) {
    std::queue<CVertex*> queue;
    std::unordered_set<CVertex*> used;

    for (auto& item: set_) {
        queue.push(item);
        used.insert(item);
    }

    while (!queue.empty()) {
        CVertex* current = queue.front();
        queue.pop();

        if (current->edges.find("") != current->edges.end()) {
            for (auto item: current->edges[""]) {
                if (used.find(item) == used.end()) {
                    used.insert(item);
                    queue.push(item);
                }
            }
        }
    }

    return used;
}

void CMachine::add(const std::string& letter) {
    auto* item1 = order();
    auto* item2 = order();
    item2->final = true;

    make_edge(item1, item2, (letter));

    stack.push_back({item1, {item2}});
}

CVertex* CMachine::order() {
    auto* item = new CVertex();
    vector.push_back(item);

    return item;
}

void CMachine::point() {
    auto item2 = stack.back();
    stack.pop_back();
    auto item1 = stack.back();
    stack.pop_back();

    for (auto& item: item1.final) {
        make_edge(item, item2.vertex, "");
    }

    stack.push_back({item1.vertex, item2.final});
}

void CMachine::star() {
    auto item = stack.back();
    stack.pop_back();

    auto* new_v = order();
    make_edge(new_v, item.vertex, "");
    for (auto& vertex: item.final) {
        make_edge(vertex, new_v, "");
    }

    stack.push_back({new_v, {new_v}});
}

void CMachine::plus() {
    auto item2 = stack.back();
    stack.pop_back();
    auto item1 = stack.back();
    stack.pop_back();

    auto* new_v = order();
    make_edge(new_v, item1.vertex, "");
    make_edge(new_v, item2.vertex, "");

    auto set_ = item1.final;
    set_.insert(item2.final.begin(), item2.final.end());

    stack.push_back({new_v, set_});
}

void CMachine::step(char letter) {
    switch (letter) {
        case '.':
            point();
            break;
        case '*':
            star();
            break;
        case '+':
            plus();
            break;
        default:
            std::string p = "";
            p += letter;
            add(p);
            break;
    }
}

CMachine::~CMachine() {
    for (auto& item: vector) {
        delete item;
    }
}

std::unordered_set<CVertex*> CMachine::apply(std::unordered_set<CVertex*>& set_, const std::string& letter) {
    std::unordered_set<CVertex*> answer;
    std::unordered_set<CVertex*> last = find_all(set_);

    for (auto item: last) {
        if (item->edges.find(letter) != item->edges.end())
            for (auto x: item->edges[letter]) {
                answer.insert(x);
            }
    }

    return find_all(answer);
}

void CMachine::load(const std::string& string) {
    for (auto letter: string) {
        machine.step(letter);
    }
}

bool CMachine::result(int k, char x) {
    std::unordered_set<CVertex*> start = {machine.stack.back().vertex};

    for (int i = 0; i < k; ++i) {
        std::string str_;
        str_ += x;
        start = machine.apply(start, str_);
    }

    return !start.empty();
}