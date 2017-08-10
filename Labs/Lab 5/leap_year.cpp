#include "std_lib_facilities_4.h"
#include "Chrono.cpp"

int main() {
	int year;
	cout << "Enter a year: ";
	
	while(cin >> year) {
	
	cout << year << " is ";
		
	if (!(Chrono::leapyear(year))) cout << "NOT ";
		
	cout << "a leapyear!\n";
		
	cout << "Enter a year: ";
	}
}

