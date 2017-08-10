// Oneal Abdulrahim
// Section: 121-504
// Due: 11:59 P.M. Tuesday, February 16, 2016
// hw3pr2.cpp

#include <iostream>
#include <cmath>
#include "hw2pr4.cpp"
using namespace std;

//A more accurate cube root! This formula was provided for us.
double my_cbrt_3(double n) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return -my_cbrt_3(-n);
    }

    double x = my_cbrt_2(n);

    for (int i = 0; i < 10; ++i) {
        x = (2.0 / 3.0) * x + (n / (3 * x * x));
    }

    return x;
}

//cleans up main, includes all output statements using given double
//prints parameter n, new n, and formulas from above methods
void driver(double n) {
	cout << "The double operated on (original n): " << n << endl;
	cout << "n\t" << setw(20) << "cbrt(n)\t" << setw(20)
			 << "my_cbrt_3(n)" << setw(20) << "error %" << endl;

    cout << "**************************************************************************" << endl;

    double relative_error_per_cent = 100 * (my_cbrt_3(n) - cbrt(n)) / (cbrt(n));

    cout << n << fixed << setw(20)
         << cbrt(n) << fixed << setw(20)
         << my_cbrt_3(n) << fixed << setw(20)
         << relative_error_per_cent << fixed << endl;
}

int main() {
    double n = 0;

    cout << "\nEnter a double: ";
    while (cin >> n) {
        driver(n);
        cout << "\nEnter a double: ";
    }
}