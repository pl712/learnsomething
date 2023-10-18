#include <pybind11/pybind11.h>
#include <iostream>
#include <vector>
#include <cmath>

namespace py = pybind11;

void get_prime_factors() {

    for (int n = 2; n < 2500; n++){
        int num = n;
        std::vector<int> prime_factors;

        while (num % 2 == 0) {
            prime_factors.push_back(2);
            num /= 2;
        }
        for (int i = 3; i <= sqrt(num); i += 2) {
            while (num % i == 0) {
                prime_factors.push_back(i);
                num /= i;
            }
        }
        if (num > 2) {
            prime_factors.push_back(num);
        }
    }
}

PYBIND11_MODULE(cppCalc, m) {
    m.def("disasterCode", &get_prime_factors, "A function to calculate prime");
}
