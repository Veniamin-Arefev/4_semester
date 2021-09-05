//
// Created by Veniamin_Arefev on 26.04.2021.
//
#include <iostream>

int main() {
    int input;
    bool belongs = true;
    bool was_word = false;
    bool was_second_letter = false;

    while ((input = std::cin.get()) != EOF) {
        if (isspace(input)) {
            if (was_word) {
                std::cout << belongs<<std::endl;
                belongs = true;
                was_second_letter = false;
                was_word = false;
            }
        } else if (!was_second_letter) {
            was_word = true;
            if (input == '1' || input == '2') {
                was_second_letter = true;
            } else if (input != '3' && input != '4') {
                belongs = false;
            }
        } else {
            if (input != '1' && input != '2') {
                belongs = false;
            }
        }
    }
    if (was_word) {
        std::cout << belongs<<std::endl;
    }
}
