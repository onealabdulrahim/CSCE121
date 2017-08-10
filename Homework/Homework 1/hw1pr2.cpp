//Oneal Abdulrahim
//CSCE 121-504
//Due: February 1, 2016
//hw1pr2.cpp

//RESOURCE: http://planetcalc.com/1421/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double PI = 3.14159; //PI is a constant

	double diameter = 14; //hardcoding the diameter
	double radius = 7; //hardcoding the radius, as needed by some calculations
	double chord = 0; //declare + initialize chord, will change with user input
    
	cout << "Pizza diameter is 14\".\nEnter chord length in inches: ";
	while (cin >> chord) {
		if (chord <= diameter && chord > 0) { //ensure that chord is possible
			double alpha = 2 * asin(chord / diameter);
                //angle btwn chord + radii
			double segment = (((radius * radius) / 2) * (alpha - sin(alpha)));
			 	//area of the segment cut off
			double circle = ((radius * radius) * PI);
                //area of the entire pizza
			double percent = ((circle - segment) / circle) * 100;
                //amount of pizza left after the cut
            
            cout << "That cut leaves " << percent << "% of the pizza.";
            cout << "\nEnter chord length in inches: ";
		}
		else { //if the chord is larger than diameter, return error!
            cout << "Chord length of " << chord << " is not possible!";
            cout << "\nEnter chord length in inches: ";
		}
	}
}
