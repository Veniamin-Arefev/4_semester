//
// Created by Veniamin_Arefev on 12.05.2021.
//

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

std::string
pop_element(std::stack<std::string> &stack)
{
    std::string str = stack.top();
    stack.pop();
    return str;
}

bool
is_variable(int in)
{
    return std::islower(in);
}

bool
is_operator(int in)
{
    return in == '+' || in == '-' || in == '*' || in == '/';
}

void
error_exit()
{
    std::cout << "WRONG INPUT";
    exit(1);
}

int
main()
{
    std::stack<std::string> main_stack;
    char input;
    while ((input = std::cin.get()) != EOF) {
        if (is_operator(input)) {
            if (main_stack.size() < 2) {
                error_exit();
            }
            std::string right_operand = pop_element(main_stack);
            std::string left_operand = pop_element(main_stack);

            std::stringstream ss;
            ss << "(" << left_operand << (char)input << right_operand << ")";

            main_stack.push(ss.str());
        } else if (is_variable(input)) {
            main_stack.push(std::string(1, input));
        } else {
            if (!isspace(input)) {
                std::cout << "WRONG INPUT";
                error_exit();
            }
        }
    }

    if (main_stack.size() != 1) {
        std::cout << "WRONG INPUT";
        error_exit();
    } else {
        std::cout << main_stack.top() << std::endl;
    }
}