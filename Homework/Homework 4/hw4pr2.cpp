//Oneal Abdulrahim
//CSCE 121-504
//Due: March 3, 2016
//hw4pr2.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//returns the number of words within "american" that have the substring "content"
int count_substring(string content) {
	int count = 0;
	
	ifstream file("american"); //AMERICAN

	if (!file) { //error handling
		cerr << "File could not be opened for reading! Does it exist?" << endl;
	}


    while (file) {
		string line;
        file >> line; //read line into string
		
		if (line.find(content) != string::npos) { //compare string line values to substring
			++count; //if it's not false (meaning it is found), add one to our count.
		}
    }
	
	return count;	
}

int main() {
	cout << "The number of cie substrings found: " << (count_substring("cie") + count_substring("Cie")) << endl;
    cout << "The number of cei substrings found: " << (count_substring("cei") + count_substring("Cei"))<< endl;
}