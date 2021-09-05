//
// Created by Veniamin_Arefev on 15.03.2021.
//

#include <iostream>
#include <vector>

void
apply_destruction_to_current_cell(int &my_int, int damage)
{
    my_int = my_int - damage > 0 ? my_int - damage : 0;
}

void
apply_destruction(std::vector<std::vector<int>> &mas, int x, int y, int damage)
{
    if (x > 0) {
        if (y > 0) {
            apply_destruction_to_current_cell(mas[x - 1][y - 1], damage / 4);
        }
        if (mas[x - 1].size() > (unsigned int) y) {
            apply_destruction_to_current_cell(mas[x - 1][y], damage / 2);
        }

        if (mas[x - 1].size() > (unsigned int) y + 1) {
            apply_destruction_to_current_cell(mas[x - 1][y + 1], damage / 4);
        }
    }
    if (y > 0) {
        apply_destruction_to_current_cell(mas[x][y - 1], damage / 2);
    }
    apply_destruction_to_current_cell(mas[x][y], damage);
    if (mas[x].size() > (unsigned int) y + 1) {
        apply_destruction_to_current_cell(mas[x][y + 1], damage / 2);
    }
    if (mas.size() > (unsigned int) x + 1) {
        if (y > 0) {
            apply_destruction_to_current_cell(mas[x + 1][y - 1], damage / 4);
        }
        if (mas[x + 1].size() > (unsigned int) y) {
            apply_destruction_to_current_cell(mas[x + 1][y], damage / 2);
        }

        if (mas[x + 1].size() > (unsigned int) y + 1) {
            apply_destruction_to_current_cell(mas[x + 1][y + 1], damage / 4);
        }
    }
}

int
main()
{
    std::vector<std::vector<int>> mas;
    if (1) {
        auto temp_vec = std::vector<int>();
        mas.push_back(temp_vec);
    }
    bool was_new_line = true;
    int temp = 0;
    while (true) {
        int input_char = std::cin.get();
        if (was_new_line && input_char == '\n') {
            break;
        }
        if (input_char == '\n' || input_char == ' ') {
            if (input_char == '\n') {
                mas[mas.size() - 1].push_back(temp);
                auto temp_vec = std::vector<int>();
                mas.push_back(temp_vec);
                was_new_line = true;
            } else { // input_char == ' '
                mas[mas.size() - 1].push_back(temp);
                was_new_line = false;
            }
            temp = 0;
        } else {
            was_new_line = false;
            temp = temp * 10 + (input_char - '0');
        }
    }
    mas.pop_back();

    while (std::cin >> temp) {
        unsigned int x = 0;
        unsigned int y = 0;
        int max = mas[0][0];

        for (unsigned int i = 0; i < mas.size(); ++i) {
            for (unsigned int j = 0; j < mas[i].size(); ++j) {
                if (mas[i][j] > max) {
                    x = i;
                    y = j;
                    max = mas[i][j];
                }
            }
        }
        apply_destruction(mas, x, y, temp);
    }
    for (auto const &vec: mas) {
        for (auto const &my_int: vec) {
            std::cout << my_int << " ";
        }
        std::cout << std::endl;
    }
}
