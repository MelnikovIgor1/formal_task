#ifndef MACHINE_TESTS
#define MACHINE_TESTS

#include <gtest/gtest.h>
#include "machine.h"


class TestMachine: public ::testing::Test {
protected:
    CMachine machine;

    void testAdd() {
//        machine.SetMachine('a', 10);
//
//        machine.add('b');
//
//        CInfo expected(11);
//        expected[0] = {true, false};
//
//        EXPECT_EQ(machine.stack.back(), expected);
//
//        machine.add('a');
//
//        CInfo expected2(11);
//        expected2[1] = {true, true};
//        EXPECT_EQ(machine.stack.back(), expected2);
    }

    void PutToStack() {
//        CInfo x1(11);
//        x1[1] = {true, true};
//        x1[2] = {true, false};
//
//        CInfo x2(11);
//        x2[2] = {true, true};
//        x2[4] = {true, false};
//
//        machine.stack.push_back(x1);
//        machine.stack.push_back(x2);
    }

    void MakePoint() {
//        machine.SetMachine('a', 10);
//
//        PutToStack();
//
//        machine.make('.');
//
//        CInfo expected(11);
//        expected[2] = {true, false};
//        expected[3] = {true, true};
//        expected[5] = {true, false};
//        EXPECT_EQ(machine.stack.back(), expected);
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
//        MakePoint();
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