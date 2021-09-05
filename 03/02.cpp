//
// Created by Veniamin_Arefev on 01.03.2021.
//
//#include "01.cpp"
#include <cstdio>

namespace numbers {
    class complex_stack {
        complex *array;
        size_t stack_size = 0;
    public:

        complex_stack() {
        }

        complex_stack(const complex_stack &init_stack) {
            stack_size = init_stack.stack_size;
            if (stack_size != 0) {
                array = new complex[stack_size];
            }
            for (size_t i = 0; i < init_stack.stack_size; i++) {
                array[i] = init_stack.array[i];
            }
        }

        ~complex_stack() {
            if (stack_size != 0) {
                delete[] array;
                stack_size = 0;
            }
        }

        friend complex_stack operator<<(const complex_stack &stack, complex comp) {
            complex_stack new_stack;
            new_stack.stack_size = stack.stack_size + 1;
            new_stack.array = new complex[new_stack.stack_size];
            for (size_t i = 0; i < stack.stack_size; i++) {
                new_stack.array[i] = stack.array[i];
            }
            new_stack.array[new_stack.stack_size - 1] = comp;
            return new_stack;
        }

        numbers::complex operator[](const int i) const {
            return array[i];
        }

        numbers::complex operator+() const {
            return array[stack_size - 1];
        }

        friend const complex_stack operator~(const complex_stack &stack) {
            complex_stack new_stack;
            new_stack.stack_size = stack.stack_size - 1;
            new_stack.array = new complex[new_stack.stack_size];
            for (size_t i = 0; i < new_stack.stack_size; i++) {
                new_stack.array[i] = stack.array[i];
            }
            return new_stack;
        }

        complex_stack &operator=(const complex_stack &stack) {
            if (&stack == this) {
                return *this;
            }
            if (stack_size != 0) {
                delete[] array;
            }
            stack_size = stack.stack_size;
            if (stack_size != 0) {
                array = new complex[stack_size];
            }
            for (size_t i = 0; i < stack.stack_size; i++) {
                array[i] = stack.array[i];
            }
            return *this;
        }

        size_t size() const {
            return stack_size;
        }

    };
}


//int main() {
//    using namespace numbers;
//    const complex_stack st1;
//    complex c1 = complex(1, 2);
//    complex c2 = complex(4, 8);
//    const complex_stack st2 = st1;
//    std::cout << st2[0].to_string();
//    std::cout << st2.size();
//    complex_stack st3 = st2 << c1 << c2 << c1 << c2;
//    const complex_stack st4 = st3 << c1 << c2 << c1 << c2;
//    std::cout << st4[0].to_string();
//    std::cout << st4[1].to_string();
//    std::cout << st4[2].to_string();
//    std::cout << st4[3].to_string();
//    const complex_stack st5 = ~~~~st4;
//    std::cout << st5.size();
//    std::cout << st4.size();
//    std::cout << st3.size();
//    std::cout << (+st5).to_string();
//}

