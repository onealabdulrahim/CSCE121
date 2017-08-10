#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;

struct Bulb_window : Graph_lib::Window {
    Bulb_window(Point xy, int w, int h, const string& title );
	Rectangle backdrop;
    Circle bulb;
	bool light_on;
private:
    Button switch_button;        // add (next_x,next_y) to lines
    Button quit_button;
	Text header;

    static void cb_flip(Address, Address); // callback for switch_button
    void flip(); 
    static void cb_quit(Address, Address); // callback for quit_button
    void quit(); 
};

Bulb_window::Bulb_window(Point xy, int w, int h, const string& title)
    :Graph_lib::Window(xy, w, h, title),
    switch_button(Point(x_max() / 2 - 35, 0), 70, 20, "ON / OFF", cb_flip),
    quit_button(Point(x_max()-70, 0), 70, 20, "QUIT", cb_quit),
	backdrop(Point(0, 20), x_max(), y_max()),
	bulb(Point(x_max() / 2, y_max() / 2), 150),
	header(Point(5, 13), "A simple light bulb window by Oneal Abdulrahim")
{
	light_on = false;
	bulb.set_color(0x523F4500);
	bulb.set_fill_color(0x523F4500);
	backdrop.set_fill_color(0x34282C00);
	
	attach(backdrop);
    attach(switch_button);
    attach(quit_button);
    attach(bulb);
	attach(header);
}

void Bulb_window::cb_quit(Address, Address pw)    // "the usual"
{  
       reference_to<Bulb_window>(pw).quit();
} 

void Bulb_window::quit()
{
    hide();        // curious FLTK idiom for delete window
}

void Bulb_window::cb_flip(Address, Address pw)     // "the usual"
{  
    reference_to<Bulb_window>(pw).flip();
} 

void Bulb_window::flip()
{
	light_on = !light_on;
    if (light_on) {
		bulb.set_fill_color(Color::white);
		bulb.set_color(Color::white);
		backdrop.set_fill_color(0xFFEDD100);
	}
	else {
		bulb.set_color(0x523F4500);
		bulb.set_fill_color(0x523F4500);
		backdrop.set_fill_color(0x34282C00);
	}
    redraw();
}

int main()
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
	Bulb_window win(Point(0, 0), 800, 600,"Light bulb"); 
	return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
