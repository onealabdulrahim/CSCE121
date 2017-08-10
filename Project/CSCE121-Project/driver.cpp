#include "Simple_window.h"
#include "GUI.h"
#include "Graph.h"
#include "Window.h"
#include "Game_window.cpp"
#include <FL/Fl.H>

using namespace Graph_lib;

int main()
try {
	if (H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		H112);
	Game_window game(Point(50, 50), 1050, 700, "FLARE! Group 23");
	return gui_main();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
