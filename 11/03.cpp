//
// Created by Veniamin_Arefev on 11.05.2021.
//

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

bool
contains(std::vector<std::string> &vec, std::string &string_to_find)
{
    return std::find(vec.begin(), vec.end(), string_to_find) != std::end(vec);
}

int
main()
{
    std::map<std::pair<std::string, char>, std::string> gram_rules;
    std::vector<std::string> end_states;

    std::string cur_state, new_state; // names from the task condition
    char char_in_rule;

    std::cin >> cur_state; // reading all gram rules
    while (cur_state != "END") {
        std::cin >> char_in_rule >> new_state;
        gram_rules[std::make_pair(cur_state, char_in_rule)] = new_state;

        std::cin >> cur_state;
    }

    std::cin >> cur_state; // reading all end states
    while (cur_state != "END") {
        end_states.push_back(cur_state);
        std::cin >> cur_state;
    }

    std::cin >> cur_state; //read start state and start loop

    unsigned long long read_char = 0; // already read
    bool done_without_errors = true;
    while (std::cin >> char_in_rule) {

        auto new_state_iter = gram_rules.find(std::make_pair(cur_state, char_in_rule));
        if (new_state_iter == gram_rules.end()) {
            done_without_errors = false;
            break;
        } else {
            cur_state = new_state_iter->second;
            ++read_char;
        }
    }
    std::cout << (done_without_errors && contains(end_states, cur_state) ? 1 : 0) << std::endl;
    std::cout << read_char << std::endl << cur_state;
}
