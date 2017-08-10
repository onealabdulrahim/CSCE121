/*
courses.cse.tamu.edu/daugher/misc/PPP/homeworks/regex_test2.cpp
Check the input file data for either a Social Security Number or a UIN.  
 
The pattern should be 3 digits followed by a hyphen followed by 2 digits
followed by a hyphen followed by 3 digits.  Place the 2-digit field in 
parentheses to make it a submatch.  If it is "00" print "That looks like
a UIN"; otherwise print "That looks like a Social Security Number."

regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"}; 
 
Hint: First get the program to run with a zip code file, then modify it
to run with a file of Social Security Numbers and UIN's.
 
P.S. This program uses a "raw string" which does not require \\ to get
a \ in the string.

*/

#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

void read_regex(regex pattern) {
	ifstream file_in{"file.txt"};		// input file
	if (!file_in) cerr << "no file\n";
    
//	cout << "pattern: " << pattern << '\n';
	int lineno = 0;
	
	for (string line; getline(file_in,line); ) { // read input line into input buffer
		++lineno;
		smatch matches;	// matched strings go here
		if (regex_search(line, matches, pattern)) {
			cout << lineno << ": " << matches[0] << '\n';	// whole match
			if (1 < matches.size() && matches[1].matched) {
				if (matches[1] == "00") {
					cout  << "\t: " << matches[1] << " ~UIN.\n";	// sub-match
				}
				else {
					cout << "\t: " << matches[1] << " ~SSN.\n";
				}
			}
		}
	}
}

int main() {
	regex pattern {R"(\d{3}-(\d{2})-\d{3})"};     // SSN or UIN pattern
	read_regex(pattern);
}
