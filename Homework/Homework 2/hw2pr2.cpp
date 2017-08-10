//Oneal Abdulrahim
//CSCE 121-504
//Due: February 8, 2016
//hw2pr2.cpp

#include "std_lib_facilities_4.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

//returns estimated cube root of n
double my_cbrt_1(double n) {
	return ((-0.411665 * pow(n, 2)) + (1.03455 * n) + 0.377113);
}

//cleans up main, includes all output statements using given double
//prints parameter n, new n, and formulas from above methods
void driver(double n) {
	cout << "The double operated on (original n): " << n << endl;
	cout << "n\t" << setw(20) << "cbrt(n)\t" << setw(20) 
			 << "my_cbrt_1(n)" << endl;
			 
		cout << "**************************************************************************" << endl;

		for(auto k : {-100, -10, -1, 0, 1, 10, 100}) {
			n = M_PI * pow(10.0, k);
			double relative_error_per_cent = 100 * (my_cbrt_1(n) - cbrt(n)) / cbrt(n);
			cout << n << scientific << setw(20)
				 << cbrt(n) << scientific << setw(20) 
				 << my_cbrt_1(n) << scientific << endl;
		}
}

int main() {
	try {
		driver(27);
	}
	catch (exception& e) {
		cerr << e.what() << "\n";
		return -1;
	}
	catch (...) {
		cerr << "Oops! Unknown exception\n";
		return -2;
	}
}
