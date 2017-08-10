#include <vector>
#include <fstream>
#include "Point.cpp"
using namespace std;

vector<Point> get_coords() {
	vector<Point> result;
	//Bjarne wants seven pairs
	for (int i = 1; i <= 7; ++i) {
		int x, y;
		cout << "Point: " << i << ".\tx: ";
			cin >> x;
		cout << "Point: " << i << ".\ty: ";
			cin >> y;
		result.push_back(Point(x, y));
	}
	return result;
}

void print_vector(vector<Point> p) {
	for (int i = 0; i < p.size(); ++i) {
		cout << p[i] << endl;
	}
}

void write_file(vector<Point> p) {
	ofstream file("mydata.txt");
	
	if (!file) { //error handling
		cerr << "File could not be opened for writing! Does it exist?" << endl;
	}
	
	for (int i = 0; i < p.size(); ++i) {
		file << p[i] << endl;
	}
}


vector<Point> read_vector() {
	vector<Point> list = {};
	
	ifstream file("mydata.txt");

	if (!file) { //error handling
		cerr << "File could not be opened for reading! Does it exist?" << endl;
	}


    while (file) {
        int x, y;
        file >> x >> y;
        list.push_back(Point(x, y));
    }

	if (list.size() == 1) { //error handling for empty list
		cerr << "The list is empty! Check the file contents." << endl;
	}

	return list;	
}


int main() {
	vector<Point> original_points = get_coords();
	print_vector(original_points);

	write_file(original_points);

	cout << "\n\nNew read: " << endl;
	print_vector(read_vector());
}