#include <iostream>
#include "std_lib_facilities_4.h"
using namespace std;

int main() {
	string friend_name = "";
	string other_friend = "";
	char friend_sex;
	int age;
	cout << "Enter friend's name: ";
	cin >> friend_name;
	cout << "\nEnter name of another friend: ";
	cin >> other_friend;
	cout << "\nGender of friend? (m or f): ";
	cin >> friend_sex;
	cout << "\nAge of recipient?: ";
	cin >> age;

	cout << "\nDear " << friend_name << ",\n\tHow are you? I am fine. I miss you! Have you talked with " << other_friend << " lately? If you see " << other_friend << " have ";
	if (friend_sex == 'm') {
		cout << "him ";
	}
	else {
		cout << "her ";
	}
	cout << "give me a call! Where has time gone?";

	if (age < 0 || age > 110) {
		simple_error("you're kidding!");
	}
	else if (age == 12) {
		cout << " Next year you will be " << age + 1 << "!!\n";
	}
	else if (age == 17) {
		cout << " Next year you'll be able to vote!\n";
	}
	else if (age == 70) {
		cout << " I hope you are enjoying retirement.\n";
	}

	cout << "\nYours sincerely, \n\nOneal Abdulrahim";
}
