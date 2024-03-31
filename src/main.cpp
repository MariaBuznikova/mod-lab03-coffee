#include "Automata.h"
//#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    Automata coffee;
    coffee.on();
    coffee.getState();
    coffee.getMenu();
    coffee.coin(50);
    coffee.choice(3);
    coffee.cancel();
    coffee.coin(150);
    coffee.choice(2);
    coffee.check(2);
    coffee.cook();
    coffee.finish();
    coffee.off();

}