#include "Automata.h"
#include <iostream>

Automata::Automata() {
    int cash = 0;
    menu = { "��� ������", "��� �������", "���������", "�����", "�����", "������� �������", "���������" };
    prices = { 50, 50, 150, 120, 160, 150, 150 };
    state = OFF;
}

void Automata::on() {
    if (state == STATES::OFF) state = STATES::ON;
}

void  Automata::off() {
    if (state == STATES::ON) state = STATES::OFF;
}

void  Automata::coin(int sum) {
    if (state == STATES::ON) cash += sum;
}

std::vector<std::string> Automata::getMenu() {
    std::vector <std::string> mp;
    for (int i = 0; i < menu.size(); i++) {
        mp.push_back(menu[i] + " - "
            + std::to_string(prices[i]) + "���.");
    }
    for (int i = 0; i < mp.size(); i++)
    {
        std::cout << mp[i] << std::endl;
    }
    return mp;
}

void  Automata::getState() {
    std::cout << "������� ���������: ";
    switch (state) {
    case STATES::OFF:
        std::cout << "��������" << std::endl;
        break;
    case STATES::ON:
        std::cout << "�������" << std::endl;
        break;
    case STATES::SELECTED:
        std::cout << "������ �������" << std::endl;
        break;
    case STATES::WAITING:
        std::cout << "�������� ������" << std::endl;
        break;
    case STATES::COOKING:
        std::cout << "������������� �������" << std::endl;
        break;
    }
}

void  Automata::choice(int index) {
    if (state == STATES::ON) {
        if (index >= 0 && index < 7) {
            state = STATES::SELECTED;
        }
    }
}
bool  Automata::check(int index) {
    if (cash >= prices[index]) {
        state = STATES::WAITING;
        return true;
    }
    else {
        std::cout << "������������ �������" << std::endl;
        return false;
    }
}

void  Automata::cook() {
    if (state == WAITING) {
        state = COOKING;
        // ������� ������������� �������
    }
}

void  Automata::finish() {
    if (state == COOKING) {
        state = FINISH;
        std::cout << "���������� ������";
        // ���������� ������������
    }
}

void  Automata::cancel() {
    if (state == SELECTED || state == WAITING || state == COOKING) {
        state = ON;
        // ������ ������ ������
    }
}