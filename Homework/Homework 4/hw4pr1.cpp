//Oneal Abdulrahim
//CSCE 121-504
//Due: March 3, 2016
//hw4pr1.cpp

#include <iostream>
#include <cmath>
#include "Element.cpp"
using namespace std;

extern vector<Element> elements;

//Using the vector declared above, this method finds the atomic number of
//an element whose symbol was given.
int find_atomic_number(string symbol) {

    for (int i = 0; i < elements.size(); ++i) {
        if (elements[i].get_symbol() == symbol) {
            return i;
        }
    }
}

//Finds the amount of moles per given grams of element.
double find_mols(double mass, Element e) {
    return mass / e.get_mass();
}

//Verifies if the order of elements needs swap when finding mass ratios;
//this is relevant to order of user input.
bool is_reverse(double mol1, double mol2) {
    if (mol1 > mol2) {
        return true;
    }
    if (mol2 > mol1) {
        return false;
    }
}

//Finds the ratio of moles of each of the two elements given within 1% error
//Prints out predicted final formula.
void find_ratio(Element e1, double m1, Element e2, double m2) {
    double mol_e1 = find_mols(m1, e1);
    double mol_e2 = find_mols(m2, e2);

    //finds mass ratio, also determines if the element with more moles was entered first or last
    double mass_ratio = ((is_reverse(mol_e1, mol_e2)) ? (mol_e2 / mol_e1) : (mol_e1 / mol_e2));

    double error = 1.1;

    //checking every fraction until we can narrow the absolute value of error down to 1%
    for (double i = 1.0; error > 1; ++i) {
        for (double j = 1.0; error > 1; ++j) {

            error = (abs(mass_ratio - (i / j)) / (mass_ratio)) * 100;

            if (error < 1) {
                if (is_reverse(mol_e1, mol_e2)) { //if the elements were needed to be swapped due to order of input,
                                                  //account for this by swapping them back into correct order
                    cout << "the ratio is " << i << " to " << j << endl;

                    if (i != 1 && j != 1) {
                        cout << "Chemical formula: " << e2.get_symbol() << i << e1.get_symbol() << j << endl;
                    }
                    else if (i == 1 && j != 1) {
                        cout << "Chemical formula: " << e2.get_symbol() << e1.get_symbol() << j << endl;
                    }
                    else if (i != 1 && j == 1) {
                        cout << "Chemical formula: " << e2.get_symbol() << i << e1.get_symbol() << endl;
                    }
                    else if (i == 1 && j == 1) {
                        cout << "Chemical formula: " << e2.get_symbol() << e1.get_symbol() << endl;
                    }
                }
                else {
                    cout << "the ratio is " << i << " to " << j << endl;

                    if (i != 1 && j != 1) {
                        cout << "Chemical formula: " << e1.get_symbol() << i << e2.get_symbol() << j << endl;
                    }
                    else if (i == 1 && j != 1) {
                        cout << "Chemical formula: " << e1.get_symbol() << e2.get_symbol() << j << endl;
                    }
                    else if (i != 1 && j == 1) {
                        cout << "Chemical formula: " << e1.get_symbol() << i << e2.get_symbol() << endl;
                    }
                    else if (i == 1 && j == 1) {
                        cout << "Chemical formula: " << e1.get_symbol() << e2.get_symbol() << endl;
                    }
                }
            }
        }
    }

    //prints number of moles of each element found in the compound
    cout << "mol " << e1.get_symbol() << ": " << mol_e1 << endl;
    cout << "mol " << e2.get_symbol() << ": " << mol_e2 << endl;

}

int main() {
    string s1, s2;
    double m1, m2;
    Element e1, e2;

    //verifies integrity of user input
    try {
        cout << "What is the name of your first atom? ";
        cin >> s1;

        cout << "What is the mass of " << s1 << "? ";
        cin >> m1;

        cout << "What is the name of your second atom? ";
        cin >> s2;

        cout << "What is the mass of " << s2 << "? ";
        cin >> m2;


        e1 = elements[find_atomic_number(s1)];
        e2 = elements[find_atomic_number(s2)];
    }
    //general error for bad input (will occur with bad element symbol, capitalization issue, or bad input for double
    catch (...) {
        cerr << "Check your input!" << endl;
    }

    find_ratio(e1, m1, e2, m2);
}