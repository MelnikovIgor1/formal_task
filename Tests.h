#ifndef MACHINE_TESTS
#define MACHINE_TESTS

#include <gtest/gtest.h>
#include "machine.h"


class TestMachine: public ::testing::Test {
protected:
    CMachine machine;

    void testAdd() {
        machine.clear();
        machine.add("a");
        EXPECT_EQ(machine.vector.size(), 2);
        EXPECT_EQ(machine.stack.back().vertex->edges.size(), 1);
        EXPECT_EQ(machine.stack.back().vertex->edges["a"].size(), 1);
    }

    void PutToStack() {

    }

    void MakePoint() {
        auto* v1 = machine.order();
        auto* v2 = machine.order();

        auto* v3 = machine.order();
        auto* v4 = machine.order();

        machine.stack.push_back({v1, {v2}});
        machine.stack.push_back({v3, {v4}});

        machine.point();

        EXPECT_EQ(machine.stack.size(), 1);
        EXPECT_EQ(v2->edges[""], std::unordered_set<CVertex*>({v3}));
        EXPECT_EQ(machine.stack.back().final, std::unordered_set<CVertex*>({v4}));
        EXPECT_EQ(machine.stack.back().vertex, v1);
    }

    void MakeStar() {
        auto* v1 = machine.order();
        auto* v2 = machine.order();

        machine.stack.push_back({v1, {v2}});

        machine.star();

        EXPECT_EQ(machine.stack.size(), 1);
        EXPECT_EQ(v2->edges[""], std::unordered_set<CVertex*>({machine.stack.back().vertex}));
        EXPECT_EQ(machine.stack.back().final, std::unordered_set<CVertex*>({machine.stack.back().vertex}));
    }

    void MakePlus() {
        auto* v1 = machine.order();
        auto* v2 = machine.order();

        auto* v3 = machine.order();
        auto* v4 = machine.order();

        machine.stack.push_back({v1, {v2}});
        machine.stack.push_back({v3, {v4}});

        machine.plus();

        EXPECT_EQ(machine.stack.size(), 1);
        EXPECT_EQ(machine.stack.back().vertex->edges[""].size(), 2);
        EXPECT_EQ(machine.stack.back().final.size(), 2);
        EXPECT_EQ(machine.stack.back().vertex->edges[""], std::unordered_set<CVertex*>({v1, v3}));
        EXPECT_EQ(machine.stack.back().final, std::unordered_set<CVertex*>({v2, v4}));
    }

    void testMake() {
        machine.clear();
        MakePoint();
        machine.clear();
        MakeStar();
        machine.clear();
        MakePlus();
    }

    void testFindAll() {
        machine.clear();
        auto* v1 = machine.order();
        auto* v2 = machine.order();

        auto* v3 = machine.order();
        auto* v4 = machine.order();
        make_edge(v1, v2, "");
        make_edge(v2, v3, "");
        make_edge(v3, v4, "");

        EXPECT_EQ(find_all({v1}), std::unordered_set<CVertex*>({v1, v2, v3, v4}));
    }

    void testApply() {
        machine.clear();
        auto* v1 = machine.order();
        auto* v2 = machine.order();

        auto* v3 = machine.order();
        auto* v4 = machine.order();
        make_edge(v1, v2, "");
        make_edge(v2, v3, "a");
        make_edge(v3, v4, "");

        EXPECT_EQ(machine.apply({v1}, "a"), std::unordered_set<CVertex*>({v3, v4}));
    }

    void testBasic() {
        machine.clear();
        machine.load("ab+c.aba.*.bac.+.+*");
        EXPECT_EQ(machine.result(2, 'a'), true);
        machine.clear();
        machine.load("acb..bab.c.*.ab.ba.+.+*a.");
        EXPECT_EQ(machine.result(3, 'b'), false);
    }

};

#endif