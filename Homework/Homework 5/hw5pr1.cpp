//Oneal Abdulrahim
//CSCE 121-504
//Due: March 23, 2016
//hw5pr1.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

//Draws house, roof, and chimney
//Lots of little shapes, very messy, but I tried to be zany with the colors
//This method is dynamic given the size of the window, meaning it will
//stretch or scale the house depending on the given parameters
void draw_house(int width, int height) {
    Simple_window window(Point(200, 200), width, height,"HW5PR1: A House");

    int x = width / 25;
    int y = height / 20;

	Rectangle sky(Point(0, 0), width , height); //backdrop (sky color)
	sky.set_color(0xDBF6FF00);
	sky.set_fill_color(0xDBF6FF00);
	
	Rectangle grass(Point(0, 16 * y), width, 4 * y); //grass
	grass.set_color(0xB4E8A200);
	grass.set_fill_color(0xB4E8A200);
	
    Rectangle house(Point(7 * x, 8 * y), 9 * x, 8 * y); //house itself
    house.set_color(Color::black);
    house.set_fill_color(0x964B0000);

    Rectangle garage(Point(16 * x, 11 * y), 6 * x, 5 * y); //garage
    garage.set_color(Color::black);
    garage.set_fill_color(0xF5F5DC00);

	Rectangle chimney(Point(16 * x, 4 * y), 1.5 * x, 7 * y); //chimney (rectangle drawn under)
	chimney.set_color(0x841F2700);
	chimney.set_fill_color(0x841F2700);

    Closed_polyline roof; //roof is Lines object
    roof.add(Point(6 * x, 9 * y));
    roof.add(Point(13 * x, 2 * y));
	roof.add(Point(23 * x, 12 * y));
	roof.add(Point(22 * x, 11 * y));
	roof.add(Point(16 * x, 11 * y));
	roof.add(Point(16 * x, 8 * y));
	roof.add(Point(7 * x, 8 * y));
    roof.set_style(Line_style(Line_style::solid, 2));
    roof.set_color(0x841F2700);
	roof.set_fill_color(0x841F2700);

    Circle vent1(Point(13 * x, 4 * y), x / 2); //air vents
    vent1.set_style(Line_style(Line_style::solid, 2));
    vent1.set_color(0xFFFFE000);

    Circle vent2(Point(19 * x, 9 * y), x / 3);
    vent2.set_style(Line_style(Line_style::solid, 2));
    vent2.set_color(0xFFFFE000);

    Rectangle window1(Point(8 * x, 10 * y), 2 * x, 2 * y); //windows
    window1.set_color(Color::black);
    window1.set_fill_color(0xD3D3D300);
	
    Rectangle window2(Point(13 * x, 10 * y), 2 * x, 2 * y);
    window2.set_color(Color::black);
    window2.set_fill_color(0xD3D3D300);
	
	Lines window_lines;
	window_lines.add(Point(9 * x, 10 * y), Point(9 * x, 12 * y));
	window_lines.add(Point(8 * x, 11 * y), Point(10 * x, 11 * y));
	
	Lines window2_lines;
	window_lines.add(Point(14 * x, 10 * y), Point(14 * x, 12 * y));
	window_lines.add(Point(13 * x, 11 * y), Point(15 * x, 11 * y));
	
	Rectangle door(Point(10 * x, 13 * y), 3 * x, 3 * y); //door
	door.set_color(Color::black);
	door.set_fill_color(0xD3D3D300);
	
	//order matters when attaching!
	window.attach(sky);
	window.attach(grass);
	window.attach(roof);
	window.attach(chimney);
    window.attach(house);
    window.attach(garage);
    window.attach(vent1);
    window.attach(vent2);
    window.attach(window1);
    window.attach(window2);
	window.attach(window_lines);
	window.attach(window2_lines);
	window.attach(door);

    window.wait_for_button();
}

int main()
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);

  draw_house(500, 400);

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
