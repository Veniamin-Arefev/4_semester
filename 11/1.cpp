#include <iostream>
#include <string>

int main()
{
    bool flag_len = true, flag_S_right = false, flag_e_right = false, flag_auto = true,
            flag_r = false, flag_l = false, flag_reg = true, flag_no_term = false;
    std::string str, str2;
    while (std::cin >> str) {
        std::cin >> str2;

        int count_term = 0, count_no_term = 0;
        for (int i = 0; i < (int) str2.length(); i++) {
            if (str2[i] == 'S') {
                flag_S_right = true;
            }
            if (str2[i] < 'A' || str2[i] > 'Z') {
                count_term++;
            }
            if (str2[i] >= 'A' && str2[i] <= 'Z') {
                count_no_term++;
            }
        }
        if (str2[0] == '_') {
            flag_e_right = true;
            if (str[0] != 'S') {
                flag_len = false;
                flag_auto = false;
            }
        } else if (count_term == 0 && count_no_term == 1 && flag_no_term == false) {
            flag_no_term = true;
        } else if (count_term != 1) {
            flag_auto = false;
        }

        if (!(count_no_term == 0 || (count_no_term == 1 && count_term == 0))) {
            if (count_no_term == 1 && str2[0] >= 'A' && str2[0] <= 'Z' && flag_r == false){
                flag_l = true;
            } else if (count_no_term == 1 && str2[str2.length() - 1] >= 'A' && str2[str2.length() - 1] <= 'Z'
                       && flag_l == false) {
                flag_r = true;
            } else {
                flag_reg = false;
            }
        }
    }

    if (flag_e_right && flag_S_right) {
        flag_len = false;
    }
    if (flag_S_right && flag_no_term) {
        flag_auto = false;
    }
    if (flag_reg) {
        if (flag_auto) {
            if (flag_r) {
                std::cout << 321;
            } else {
                std::cout  << 311;
            }
        } else {
            if (flag_r) {
                std::cout << 32;
            } else {
                std::cout  << 31;
            }
        }
    } else {
        if (flag_len) {
            std::cout << 21;
        } else {
            std::cout << 2;
        }
    }
    return 0;
}
