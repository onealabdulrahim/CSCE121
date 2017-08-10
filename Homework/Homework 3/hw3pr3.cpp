// Oneal Abdulrahim
// Section: 121-504
// Due: 11:59 P.M. Tuesday, February 16, 2016
// hw3pr3.cpp

#include <iostream>
#include <vector>
using namespace std;

//Finds the fibonacci number for the x-th term in the sequence, starting with 0
// Sequence: 0, 1, 1, 2, 3, 5, 8, 13...
// Term    : 1, 2, 3, 4, 5, 6, 7, 8...
//
//Since the Fibonacci sequence is recursive by definition, we may compute its
//terms recursively.
int fibonacci(int x) {
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    else
        return fibonacci(x - 1) + fibonacci(x - 2);
}

//Returns a vector of doubles with the fibonacci sequence from the start to end terms
//The difference of start and end is the size of the vector
vector<double> fib_to_list(int start, int end) {
    vector<double> list = {};

    for (int i = start; i <= end; ++i) { //loads vector of the "snippet" of the sequence
        list.push_back(fibonacci(i));
    }
    return list;
}

//Calculates the ratio of the last two terms of the fibonacci sequence.
//The section of the fibonacci sequence are between the terms start and end
double golden_ratio(int start, int end) {
    vector<double> list = fib_to_list(start, end);
    return list[list.size() - 1] / list[list.size() - 2];
}

int main() {
    int start = 0;
    int end = 0;
	
	//We do not need the user to give us the first two numbers to start with,
	//because fibonacci() takes care of finding any number given the term
    cout << "Start term: "; //user input for first term in sequence
    cin >> start;
    cout << "End term  : "; //user input for end term in sequence
    cin >> end;

    cout << "Ratio of last two: " << fixed << golden_ratio(start, end) << endl;
}