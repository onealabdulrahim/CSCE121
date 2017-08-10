//Oneal Abdulrahim
//CSCE 121-504
//hw2pr4.cpp

#include "std_lib_facilities_4.h"
#define _USE_MATH_DEFINES

//first method using given approximation
double my_cbrt_1(double n) {
    return -0.411665 * n * n + 1.03455 * n + 0.377113;
}

//second method given more accurate pseudocode
double my_cbrt_2(double n) {
    double result = 1.0;

    if (n > 1) {
        while (n > 1) {
            result *= 2.0;
            n /= 8.0;
        }
    }
    if (n < (1 / 8)) {
        while (n < (1 / 8)) {
            result /= 2.0;
            n *= 8.0;
        }
    }

    return result * my_cbrt_1(n);
}


