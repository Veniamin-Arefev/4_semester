//
// Created by Veniamin_Arefev on 20.02.2021.
//
#include <iostream>

void print(char last_char, long long count_last_char){
    if (count_last_char > 4 || last_char == '#') {
        std::cout << '#' << last_char << std::hex << count_last_char << '#';
    } else {
        for (int i = 0; i < count_last_char; i++) {
            std::cout << last_char;
        }
    }
}

int main() {
    char current_char;
    char last_char;
    long long count_last_char = 0;
    current_char = std::cin.get();
    if (!std::cin.fail()) {
        last_char = current_char;
        count_last_char++;
        current_char = std::cin.get();
        while (!std::cin.fail()) {
            if (current_char == last_char) {
                count_last_char++;
            } else {
                print(last_char, count_last_char);
                last_char = current_char;
                count_last_char = 1;
            }
            current_char = std::cin.get();
        }
        print(last_char, count_last_char);
    }
}