//Oneal Abdulrahim
//CSCE 121-504
//Due: February 8, 2016
//hw2pr1.cpp

#include "std_lib_facilities_4.h"
#include <iostream>
#include <vector>
using namespace std;

//returns a vector loaded with percentages
//plan[0] corresponds to 10% of income
//plan[1] corresponds to 80% of income
vector<double> get_plan(double income) {
	vector<double> plan = {};

	plan.push_back(income * 0.1); //10%
	plan.push_back(income * 0.8); //80%

	return plan;
}

//prints out suggested financial plan, using get_plan() function
void print_plan(vector<double> plan) {
	cout << "You should give away about $" << fixed << setprecision(2) << plan[0]
		 << ", save about $" << fixed << setprecision(2) << plan[0]
		 << ", and live on about $" << fixed << setprecision(2) << plan[1];
}

int main() {

	double income = 0;

	cout << "Income in dollars? ";
	try {
		while (cin >> income) { //user input income
			print_plan(get_plan(income));
			cout << "\nIncome in dollars? ";
		}
		return 0;
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
