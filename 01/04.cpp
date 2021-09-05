//
// Created by Veniamin_arefev on 10.02.2021.
//
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    using namespace std;

    long double in;
    long double main_sum = 0;
    long double sum = 0;
    long double n = 0;
    while (cin >> in) {
        n++;
        main_sum += in;
        sum += in * in;
    }
    cout << setprecision(10) << fixed << main_sum / n << endl;
    cout << setprecision(10) << fixed << sqrt(sum / n - (main_sum / n) * (main_sum / n)) << endl;

}