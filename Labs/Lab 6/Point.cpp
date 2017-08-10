#include <iostream>
using namespace std; //terrible

class Point {
	int x;
	int y;
	
	public:
	    Point() {
	        x = 0;
	        y = 0;
	    }

		Point(int X, int Y) {
			x = X;
			y = Y;
		}

		int get_x() const {
			return x;
		}
		
		int get_y() const {
			return y;
		}
};
ostream& operator<<(ostream& os, const Point& p) {
	return os << p.get_x() << " " << p.get_y();
}

istream& operator>>(istream& is, Point& pp) {
	int x, y;
	char space;
	
	is >> x >> y;
	
	if (!is) return is;	// we didn't get our values, so just leave

	pp = Point{x, y};	// update pp
	return is;			// and leave with is in the good() state
}