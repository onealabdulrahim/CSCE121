//Oneal Abdulrahim
//CSCE 121-504
//Due: March 23, 2016
//hw5pr2.cpp

// SOURCES:
// http://homepages.inf.ed.ac.uk/rbf/HIPR2/geomops.htm
// https://upload.wikimedia.org/wikipedia/commons/f/f7/Flag_of_Texas.svg
// ^^^^ This SVG was reverse-engineered for the star solution ^^^^

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

//This method draws the Texas flag, to as close of dimensions
//possible using the given window size
void draw_flag(int x, int y) {
	Simple_window window(Point(200, 200), x, y,"HW5PR2: The Texas Flag");

	//The white area goes underneath, to draw the red and blue atop
	Rectangle white_area(Point(0, 0), x, y); //the entirety of the window
	white_area.set_color(Color::white);
	white_area.set_fill_color(Color::white);

	//The red area drawn atop the white
	Rectangle red_area(Point(0, y / 2), x, y / 2); //half of the window
	red_area.set_color(0xBF0A3000); //HEX for TEXAS FLAG RED (#BF0A30)
	red_area.set_fill_color(0xBF0A3000);

	//The blue area is 1/3 the width
	Rectangle blue_area(Point(0, 0), x / 3, y);
	blue_area.set_color(0x00286800); //HEX for TEXAS FLAG BLUE (#002868)
	blue_area.set_fill_color(0x00286800);
	
	//attach rectangles to window
	window.attach(white_area);
	window.attach(red_area);
	window.attach(blue_area);
	
	
	
	//the following block of code creates the star in a rather fancy way
	//it's complicated but it was a fun challenge
	//***Please see the attached diagram for a better explanation of how this is constructed!!!
	for (int i = 0; i < 5; ++i) {
		double radians = (72 * i) * M_PI / 180;
		
		//create the slightly rotated triangles
		//rotation formula =
		// x2 = cos(theta) * (x1 - x0) - sin(theta) * (y1 - y0) + x0
		// y2 = sin(theta) * (x1 - x0) + cos(theta) * (y1 - y0) + x0
		
		Polygon* triangle = new Polygon();
		triangle -> add(Point(blue_area.width() / 2,
							  blue_area.height() / 2 - 3 * y / 16));
		triangle -> add(Point(cos(0.099 * M_PI) * (blue_area.width() / 2
							  - triangle -> point(0).x)
							  - sin(0.099 * M_PI) * (blue_area.height() / 2
							  - triangle -> point(0).y) + triangle -> point(0).x,
							  
							  sin(0.099 * M_PI) * (blue_area.width() / 2
							  - triangle -> point(0).x)
							  + cos(0.099 * M_PI) * (blue_area.height() / 2
							  - triangle -> point(0).y) + triangle -> point(0).y));
							  
		triangle -> add(Point(cos(0.099 * M_PI) * (blue_area.width() / 2 + x / 16
							 - triangle -> point(0).x)
							 - sin(0.099 * M_PI) * (blue_area.height() / 2
							 - triangle -> point(0).y) + triangle -> point(0).x,
							 
							  sin(0.099 * M_PI) * (blue_area.width() / 2 + x / 16
							 - triangle -> point(0).x)
							 + cos(0.099 * M_PI) * (blue_area.height() / 2
							 - triangle -> point(0).y) + triangle -> point(0).y));
							  
		//rotate five of these triangles about the center of the blue rectangle
		Polygon* result = new Polygon();
		for (int i = 0; i < triangle -> number_of_points(); ++i) {
			result -> add(Point(cos(radians) * (triangle -> point(i).x - blue_area.width() / 2)
											   - sin(radians)
											   * (triangle -> point(i).y - blue_area.height() / 2)
											   + blue_area.width() / 2,
											   
								sin(radians) * (triangle -> point(i).x - blue_area.width() / 2)
											   + cos(radians)
											   * (triangle -> point(i).y - blue_area.height() / 2)
											   + blue_area.height() / 2));
	    }
		
		result -> set_color(Color::white);
		result -> set_fill_color(Color::white);
		window.attach(*result);
		
		//creates sister flipped triangle which combine to form vertices of star
		//flip across an axis, in this case the abscissa of each triangle's first point
		//the reflection formula is =
		// x2 = -x1 + 2 * x0
		// y2 = y1
		Polygon* flipped = new Polygon();
		for (int i = 0; i < result -> number_of_points(); ++i) {
			flipped -> add(Point(-(result -> point(i).x) + 2 * (blue_area.width() / 2), result -> point(i).y));
	    }
		
		flipped -> set_color(Color::white);
		flipped -> set_fill_color(Color::white);
		window.attach(*flipped); 
	}
	
	window.wait_for_button();
}

int main()
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);

  draw_flag(1200, 800);

  return 0;
}
catch(exception& e) { 
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
