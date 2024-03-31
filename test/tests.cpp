// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <sstream>

TEST(correct_transition, test1) {
    Automata coffee;
    coffee.on();
    STATES result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(correct_transition, test2) {
    Automata coffee;
    STATES result = coffee.getState();
    EXPECT_EQ(OFF, result);
}

TEST(correct_transition, test3) {
    Automata coffee;
    coffee.on();
    coffee.off();
    STATES result = coffee.getState();
    EXPECT_EQ(OFF, result);
}

TEST(correct_transition, test4) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    STATES result = coffee.getState();
    EXPECT_EQ(ACCEPT, result);
}

TEST(correct_transition, test5) {
    Automata coffee;
    coffee.on();
    coffee.coin(100);
    coffee.coin(50);
    STATES result = coffee.getState();
    EXPECT_EQ(ACCEPT, result);
}

TEST(correct_transition, test6) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check(1);

    EXPECT_EQ(ACCEPT, coffee.getState());
}

TEST(correct_transition, test7) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check(1);
    coffee.cook();

    EXPECT_EQ(ACCEPT, coffee.getState());
}

TEST(correct_transition, test8) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check(1);
    coffee.cook();
    coffee.finish();

    EXPECT_EQ(ACCEPT, coffee.getState());
}


TEST(correct_transition, test9) {
    Automata coffee;
    coffee.on();
    coffee.coin(100);
    coffee.cancel();
    STATES result = coffee.getState();
    EXPECT_EQ(ACCEPT, result);
}

TEST(correct_transition, test10) {
    Automata coffee;
    coffee.coin(100);
    STATES result = coffee.getState();
    EXPECT_EQ(OFF, result);
}
