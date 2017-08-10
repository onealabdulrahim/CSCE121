// Oneal Abdulrahim
// Section: 121-504
// Due: 11:59 P.M. Tuesday, February 16, 2016
// hw3pr3.cpp

#include <iostream>
#include "hw2pr4.cpp"

using namespace std;

//A more accurate cube root! This formula was provided for us.
double my_cbrt_4(double n) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return -my_cbrt_4(-n);
    }

    double x = my_cbrt_2(n);
    int k = 0; //counter for how many iterations we need to complete task accurately
    for (int i = 0; i < 10; ++i) {

        if (x == (2.0 / 3.0) * x + (n / (3 * x * x))) { //if the new x being set is equal to the old one,
            cout << "It only took " << k << " iterations! The cbrt(" << n << "): "; //stop the loop
            return x;
        }
        else {
        x = (2.0 / 3.0) * x + (n / (3 * x * x)); //otherwise, continue looping and
        ++k; //increment counter by 1
        }

    }
    cout << "It took all " << k << " iterations! The cbrt(" << n << "): "; //if this statement is reached, looped 10 times
    return x;
}

int main() {
    double n = 0;

    cout << "enter a double: ";
    while (cin >> n) {
        cout << my_cbrt_4(n) << endl;
        cout << "\nenter a double: ";
    }
}