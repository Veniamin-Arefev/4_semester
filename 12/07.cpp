//
// Created by Veniamin_Arefev on 17.05.2021.
//

#include <iostream>

char input;

void gc() {
    std::cin >> input;
    if (!std::cin.good()) {
        input = 0;
    }
}

void B() {
    if (input == 'b') {
        gc();
        B();
    } else if (input == 'd') {
        gc();
    } else if (!std::cin.good()) {
        input = 0;
        //dont do anything because end of reading
    } else {
        throw input;
    }
}

void A() {
    if (input == 'c') {
        gc();
        A();
        if (input == 'd') {
            gc();
        } else {
            throw input;
        }
    } else if (input == 'e') {
        gc();
    } else {
        throw input;
    }
}

void S() {
    if (input == 'a') {
        gc();
        A();
        if (input == 'b') {
            gc();
        } else {
            throw input;
        }
    } else if (input == 'c') {
        gc();
        B();
    } else {
        throw input;
    }
}

int main() {
    try {
        gc();
        S();
        if (!std::cin.good()) {
            std::cout << 1 << std::endl;
        }
    } catch (char error) {
        std::cout << 0 << std::endl;
    }

}