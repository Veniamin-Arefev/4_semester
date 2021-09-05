//
// Created by Veniamin_Arefev on 11.05.2021.
//

#include <iostream>

enum states {
    START,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    M,
    N,
    P,
    NORMAL_EXIT,
    ERROR_EXIT
};

int input;

void
gc()
{
    input = std::cin.get();
}

void
skip_spaces()
{
    while (isspace(input)) {
        gc();
    }
}

void
skip_not_spaces()
{
    while (!isspace(input) && input != EOF) {
        gc();
    }
}

inline
bool
end_of_word()
{
    return isspace(input) || input == EOF;
}


int main()
{
    int current_state;

    gc();

    bool was_word = false;

    while (input != EOF) {
        skip_spaces();
        current_state = START;

        while (current_state != NORMAL_EXIT && current_state != ERROR_EXIT) {
            if (input != EOF && !isspace(input)) {
                was_word = true;
            }
            switch (current_state) {
                case START:
                    if (input == '0') {
                        current_state = A;
                    } else if (input == '1') {
                        current_state = B;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case A:
                    if (input == '0') {
                        current_state = C;
                    } else if (input == '1') {
                        current_state = F;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case C:
                    if (input == '0') {
                        current_state = D;
                    } else if (input == '1') {
                        current_state = E;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case F:
                    if (input == '0') {
                        current_state = G;
                    } else if (input == '1') {
                        current_state = H;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case B:
                    if (input == '0') {
                        current_state = I;
                    } else if (input == '1') {
                        current_state = M;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case I:
                    if (input == '0') {
                        current_state = J;
                    } else if (input == '1') {
                        current_state = K;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case M:
                    if (input == '0') {
                        current_state = N;
                    } else if (input == '1') {
                        current_state = P;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case D:
                    if (input == '0') {
                        current_state = D;
                    } else if (input == '1') {
                        current_state = E;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case E:
                    if (input == '0') {
                        current_state = G;
                    } else if (input == '1') {
                        current_state = H;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case G:
                    if (input == '0') {
                        current_state = J;
                    } else if (input == '1') {
                        current_state = K;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case H:
                    if (input == '0') {
                        current_state = N;
                    } else if (input == '1') {
                        current_state = P;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case J:
                    if (input == '0') {
                        current_state = D;
                    } else if (input == '1') {
                        current_state = E;
                    } else if (end_of_word()) {
                        current_state = NORMAL_EXIT;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case K:
                    if (input == '0') {
                        current_state = G;
                    } else if (input == '1') {
                        current_state = H;
                    } else if (end_of_word()) {
                        current_state = NORMAL_EXIT;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case N:
                    if (input == '0') {
                        current_state = J;
                    } else if (input == '1') {
                        current_state = K;
                    } else if (end_of_word()) {
                        current_state = NORMAL_EXIT;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
                case P:
                    if (input == '0') {
                        current_state = N;
                    } else if (input == '1') {
                        current_state = P;
                    } else if (end_of_word()) {
                        current_state = NORMAL_EXIT;
                    } else {
                        current_state = ERROR_EXIT;
                    }
                    break;
            }
            if (!(current_state == ERROR_EXIT || current_state == NORMAL_EXIT)) {
                gc();
            }
        }
        if (was_word) {
            std::cout << (current_state == NORMAL_EXIT ? 1 : 0) << std::endl;
            was_word = false;
        }
        skip_not_spaces();
    }
}
