//Oneal Abdulrahim
//CSCE 121-504
//Due: March 23, 2016
//hw5pr3.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

void draw_board(int x, int y) {
	Simple_window window(Point(200,200), x, y,"HW5PR3: Checkerboard");
	
	//checkerboard is reliant on window size,
	//will do its best to fit largest possible squares (must fit to window dimensions)
	//if dimensions are not 1x1, it will morph squares into rectangles
	int width = x / 8; //width of each rectangle
	int height = y / 8; //height of each rectangle
	
	const Color moss_green(0xADDFAD00); //HEX for both of the requested colors
	const Color cherry_blossom_pink(0xFFB7C500);
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {

			Rectangle *square = new Rectangle(Point(width * i, height * j), width, height);

			if ((i + j) % 2 == 1) {
				
				square->set_fill_color(moss_green); //on odd blocks, make it green
				square->set_color(moss_green);

				window.attach(*square);
				 
				if (j <= 2) { //if on rows 1, 2, 3, fill in the red pieces
					Circle *red_piece = new Circle(Point(width * i + (width / 2), height * j + (height / 2)), width / 4);
					Circle *shadow = new Circle(Point(width * i + (width / 2), height * j + (height / 2) + width / 32), width / 3.8);
					red_piece -> set_color(Color::black);
					red_piece -> set_fill_color(0xC4023300);
					shadow -> set_fill_color(0x34343400);

					window.attach(*shadow);
					window.attach(*red_piece);
				}
				else if (j >= 5) { //if on rows 6, 7, 8, fill in the white pieces
					Circle *white_piece = new Circle(Point(width * i + (width / 2), height * j + (height / 2)), width / 4);
					Circle *shadow = new Circle(Point(width * i + (width / 2), height * j + (height / 2) + width / 32), width / 3.8);
					white_piece -> set_color(Color::black);
					white_piece -> set_fill_color(Color::white);
					shadow -> set_fill_color(0x34343400);

					window.attach(*shadow);
					window.attach(*white_piece);
				}
			}
			else {
				square->set_fill_color(cherry_blossom_pink); //on even ones, make it pink
				square->set_color(cherry_blossom_pink);

				window.attach(*square);
			}
		}
    }
	window.wait_for_button();
}

int main()
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);

  draw_board(1000, 1000);

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