#include <iostream>
using namespace std;

//Returns sum of two doubles
double add(double num1, double num2) {
	return num1 + num2;
}

//Returns difference of larger num and smaller num
double subtract(double num1, double num2) {
	if (num1 > num2) {
		return num1 - num2;
	}
	
	return num2 - num1;
}

//Returns product of two doubles
double multiply(double num1, double num2) {
	return num1 * num2;
}

//Returns quotient of two doubles
//Checks included to avoid 0 dividend
double divide(double num1, double num2) {
	if (num1 == 0 && num2 == 0) {
		return 0;
	}
	
	if (num1 > num2) {
		if (num2 == 0) {
			cerr << "Error! Divide       Error!\n"
				 << "Error!        by    Error!\n" 
				 << "Error!            0 Error!\n";
			return -1;
		}
		return num1 / num2;
	}
	
	if (num1 == 0) {
			cerr << "Error! Divide       Error!\n"
				 << "Error!        by    Error!\n" 
				 << "Error!            0 Error!\n";
			return -1;
		}
	return num2 / num1;
}

int main() {
	double num1 = 0;
	char operand = ' ';
	double num2 = 0;
	
	cout << "Please enter two numbers with an operator (x + y): ";
	cin >> num1;
	cin >> operand;
	cin >> num2;
	
	switch (operand) {
		case '+':
			cout << "The sum of " << num1 << " and " << num2 << " is " << add(num1, num2);
			break;
		case '-':
			cout << "The difference of " << num1 << " and " << num2 << " is " << subtract(num1, num2);
			break;
		case '*':
			cout << "The product of " << num1 << " and " << num2 << " is " << multiply(num1, num2);
			break;
		case '/':
			cout << "The quotient of " << num1 << " and " << num2 << " is " << divide(num1, num2);
			break;
		default:
			cout << "Incorrect input!";
			break;
	}
}