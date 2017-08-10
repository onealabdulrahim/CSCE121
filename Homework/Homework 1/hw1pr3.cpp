//Oneal Abdulrahim
//CSCE 121-504
//Due: February 1, 2016
//hw1pr3.cpp

#include <iostream>
using namespace std;

//Returns minimum tiles needed to achieve amount of rice
int tile_count(int amount) {
	int total = 1; //running total of rice grains (start at 1)
	int tile = 1; //the tile number we start on (start at 1st)
	while (total < amount) {
		total *= 2; //double sum of rice grains each tile
		++tile; //move to the next tile
	}
	return tile;
}

int main() {
    int rice1 = 1000; //initialize all rice possibilities
    int rice2 = 1000000;
	int rice3 = 1000000000;
    
	cout << "The inventor needs " << tile_count(rice1) << " squares to fulfill "
		 << rice1 << " grains of rice." << endl;
    cout << "The inventor needs " << tile_count(rice2) << " squares to fulfill "
         << rice2 << " grains of rice." << endl;
    cout << "The inventor needs " << tile_count(rice3) << " squares to fulfill "
         << rice3 << " grains of rice." << endl;
	return 0;
}