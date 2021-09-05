//
// Created by Veniamin_Arefev on 26.04.2021.
//
#include <iostream>

enum states {
    FIRST_ZERO_READING,
    FIRST_ONE_READING,
    ZERO_READING,
    ONE_READING,
    NORMAL_EXIT,
    ERROR_EXIT
};

int input;

void gc() {
    input = std::cin.get();
}

void skip_spaces() {
    while (isspace(input)) {
        gc();
    }
}

void skip_not_spaces() {
    while (!isspace(input) && input != EOF) {
        gc();
    }
}

inline bool end_of_word() {
    return isspace(input) || input == EOF;
}


int main() {
    int current_state;
    int max_zero_count;
    int max_one_count;
    int zero_count;
    int one_count;

    gc();
    while (input != EOF) {
        current_state = FIRST_ZERO_READING;
        max_zero_count = 0;
        max_one_count = 0;
        zero_count = 0;
        one_count = 0;

        skip_spaces();
        while (current_state != NORMAL_EXIT && current_state != ERROR_EXIT) {
            switch (current_state) {
                case FIRST_ZERO_READING:
                    if (input == '0') {
                        gc();
                        ++max_zero_count;
                    } else if (input == '1' && max_zero_count > 0) {
                        gc();
                        max_one_count = 1;
                        current_state = FIRST_ONE_READING;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case FIRST_ONE_READING:
                    if (input == '1') {
                        gc();
                        ++max_one_count;
                    } else if (input == '0') {
                        gc();
                        zero_count = 1;
                        current_state = ZERO_READING;
                    } else if (end_of_word()) {
                        current_state = NORMAL_EXIT;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case ZERO_READING:
                    if (input == '0') {
                        gc();
                        ++zero_count;
                    } else if (input == '1') {
                        if (zero_count != max_zero_count) {
                            current_state = ERROR_EXIT;
                        } else {
                            gc();
                            one_count = 1;
                            current_state = ONE_READING;
                        }
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case ONE_READING:
                    if (input == '1') {
                        gc();
                        ++one_count;
                    } else if (input == '0') {
                        if (one_count != max_one_count) {
                            current_state = ERROR_EXIT;
                        } else {
                            gc();
                            zero_count = 1;
                            current_state = ZERO_READING;
                        }
                    } else if (end_of_word() && one_count == max_one_count) {
                        current_state = NORMAL_EXIT;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
            }
        }
        std::cout << (current_state == NORMAL_EXIT ? 1 : 0) << std::endl;

        skip_not_spaces();
        gc();
    }
}
