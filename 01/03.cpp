//
// Created by Veniamin_arefev on 10.02.2021.
//
#include <iostream>
#include <cstdio>

int main() {
    using namespace std;
    int in_char;
    bool isNumber = false;
    bool isNotOnlyZero = false;
    while (true) {
        in_char = getchar();
        if (in_char == EOF) {
            break;
        }
        if (in_char >= '0' && in_char <= '9') {
            isNumber = true;
            if (in_char != '0') {
                isNotOnlyZero = true;
                printf("%c", in_char);
            } else {
                if (isNotOnlyZero) {
                    printf("%c", in_char);
                }
            }
        } else {
            if (isNumber && !isNotOnlyZero) {
                printf("0");
            }
            isNumber = false;
            isNotOnlyZero = false;
            printf("%c", in_char);
        }
    }

    if (isNumber && !isNotOnlyZero) {
        cout << '0';
    }
}