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

    }

    void MakeStar() {
        auto* v1 = machine.order();
        auto* v2 = machine.order();

        auto* v3 = machine.order();
        auto* v4 = machine.order();

        machine.stack.push_back({v1, {v2}});
        machine.stack.push_back({v3, {v4}});

        machine.star();

        EXPECT_EQ(machine.stack.size(), 1);
        EXPECT_EQ(v2->edges[""], std::unordered_set<CVertex*>({v3}));
        EXPECT_EQ(machine.stack.back().final, std::unordered_set<CVertex*>({v4}));
        EXPECT_EQ(machine.stack.back().vertex, v1);
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
        MakePoint();
//        MakeStar();
        MakePlus();
    }

    void StepOperation() {
//        machine.SetMachine('a', 10);
//        machine.stack.clear();
//        PutToStack();
//        machine.step('.');
//        EXPECT_EQ(machine.stack.size(), 1);
    }

    void StepLetter() {
//        machine.SetMachine('a', 10);
//        machine.stack.clear();
//        machine.step('a');
//        EXPECT_EQ(machine.stack.size(), 1);
    }

    void testStep() {
//        StepOperation();
//        StepLetter();
    }

};

#endif