//Oneal Abdulrahim
//CSCE 121-504
//Due: February 1, 2016
//hw1pr4.cpp

#include <iostream>
using namespace std;

//Returns count of grains of rice given a max number of tiles
unsigned long long int rice_count(int tiles) {
	unsigned long long int total = 1; //start with 1 grain of rice
	for (int i = 2; i <= tiles; i++) { //iterate through each tile, starting at 2
		total *= 2; //each tile doubles previous amount
	}
	return total;
}

int main() {
	int tile_count = 64;
	cout << "For " << tile_count << " tiles, there are: "
		 << rice_count(tile_count) << " rice grains." << endl; 
		//total is 2^63, since we start with 2^0 and not 2^1.
	return 0;
}