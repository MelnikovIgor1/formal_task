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
        EXPECT_EQ(machine.stack.back().vertex->edges[""].size(), 2);
        EXPECT_EQ(machine.stack.back().final.size(), 2);
    }

    void MakeStar() {
//        machine.SetMachine('a', 10);
//
//        CInfo x1(11);
//        x1[1] = {true, false};
//        x1[2] = {true, true};
//
//        machine.stack.push_back(x1);
//
//        machine.make('*');
//
//        CInfo expected(11);
//        expected[0] = {true, true};
//        expected[1] = {true, false};
//
//        for (int i = 2; i < 11; i += 2) {
//            expected[i] = {true, true};
//        }
//
//        EXPECT_EQ(machine.stack.back(), expected);
    }

    void MakePlus() {
//        machine.SetMachine('a', 10);
//
//        CInfo x1(11);
//        x1[1] = {true, false};
//        x1[2] = {true, true};
//
//        machine.stack.push_back(x1);
//
//        machine.make('+');
//
//        CInfo expected(11);
//        expected[1] = {true, false};
//
//        for (int i = 2; i < 11; i += 2) {
//            expected[i] = {true, true};
//        }
//
//        EXPECT_EQ(machine.stack.back(), expected);
    }

    void testMake() {
        MakePoint();
//        MakeStar();
//        MakePlus();
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