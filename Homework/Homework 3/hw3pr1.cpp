// Oneal Abdulrahim
// Section: 121-504
// Due: 11:59 P.M. Tuesday, February 16, 2016
// hw3pr1.cpp

//Sources:
//file io information: http://www.learncpp.com/cpp-tutorial/136-basic-file-io/
//formulas: Texas A&M Statistics department at work, STAT211 with IRINA

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Generates a random list of doubles in range [min, max]
//Prints, line by line, to filename: "doubles.txt" in directory
void generate_list(double min, double max) {
	ofstream file("doubles.txt");
	
	if (!file) { //error handling
		cerr << "File could not be opened for writing! Does it exist?" << endl;
	}
	
	for (int i = 0; i <= 99; ++i) { //writes only 100 doubles, though this can be changed
		double random = (double)rand() / RAND_MAX;
		
		file << min + random * (max - min) << endl; //WHAT TRULY IS RANDOM?!
	}
}

//Returns a vector of doubles from filename: "doubles.txt" in directory
vector<double> read_list() {
	vector<double> list = {};
	
	ifstream file("doubles.txt");
	
	if (!file) { //error handling
		cerr << "File could not be opened for reading! Does it exist?" << endl;
	}
	
	while (file) { //read from file
		double input;
		file >> input;
		list.push_back(input);
	}
	
	if (list.size() == 1) { //error handling for empty list
		cerr << "The list is empty! Check the file contents." << endl;
	}

	return list;	
}

//Returns arithmetic mean from given list of doubles
// x_bar = sum(all elements) / number of elements
double get_mean(vector<double> list) {
	double sum = 0;
	
	for (int i = 0; i < list.size(); ++i) {
		sum += list[i];
	}

	return sum / list.size();
}

//Returns standard deviation of given list of doubles
// s = sqrt (sum of (element - mean)^2 / elements - 1)
double get_stdev(vector<double> list) {
	double mean = get_mean(list);
	double numerator = 0;
	
	for (int i = 0; i < list.size(); ++i) {
		numerator += pow((list[i] - mean), 2);
	}

	return sqrt(numerator / (list.size() - 1));
}

int main() {
	
	//How do we know that the methods work? Increase or decrease the range!
	//If range is low: mean will be closer to middle of the numbers.
	//				   stdev will also be small.
	//If range is high: the opposite.
	generate_list(0, 999);
	
	//Precision of floating points is ambiguous! Numbers may have slight error.
	vector<double> list_1 = read_list();
	cout << "The file shows this information: \nmean:  " << get_mean(list_1)
		 << "\nstdev: " << get_stdev(list_1);
}