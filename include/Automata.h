#pragma once
#include <iostream>
#include <string>
#include <vector>

enum STATES {
    OFF,
    ON,
    SELECTED,
    WAITING,
    COOKING,
    FINISH
};
class Automata {
private:
    int cash;
    std::vector <std::string> menu;
    std::vector <int> prices;
    STATES state;
public:
    Automata();
    void on();
    void off();
    void coin(int sum);
    std::vector<std::string> getMenu();
    void getState();
    void choice(int index);
    bool check(int index);
    void cook();
    void finish();
    void cancel();
};
