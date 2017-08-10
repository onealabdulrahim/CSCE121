#include "Score.cpp"
#include "Game_window.h"
#include <random>
#include <unistd.h>

// constructor for Game_window
Game_window::Game_window(Point xy, int w, int h, const string& title)
	:Graph_lib::Window(xy, w, h, title),
	// Text for welcome screen, will be recycled
	welcome(Point(x_max() / 2 - 65, y_max() / 4), "Welcome to FLARE!"),
	
	// Three buttons to be displayed on home screen
	// They are dynamic to the window size
	play_button(Point(x_max() / 2 - 90, y_max() / 2), 180, 60, "Play Now!", cb_play),
	scores_button(Point(x_max() / 2 - 90, y_max() / 2 + 60), 180, 60, "High Scores", cb_scores),
	quit_button(Point(x_max() / 2 - 90, y_max() / 2 + 120), 180, 60, "Quit", cb_quit),
	
	// Large, full screen buttons that will move you to next screen
	instructions_button(Point(0, 0), x_max(), y_max(), " ", cb_instr),
	home_button(Point(0, 0), x_max(), y_max(), " ", cb_home),
	
	// Graphical images to be used throughout the program
	// Sizes are fixed
	splash(Point(0, 0), "splash.jpeg"),
	instructions(Point(0, 0), "instructions.jpeg"),
	home(Point(25, 25), "homeT.gif"),
	earth_map(Point(0, 50), "earth_image.jpeg"),
	
	// Next button and difficulty box allows for user input of difficulty level
	// The next button calls to the continue which will load the game area
	next_button(Point(x_max() / 2 - 90, y_max() / 2 + 60), 180, 60, "Continue...", cb_next),
	diff_box(Point(x_max() / 2, y_max() / 2), 80, 20, "Satellite count (2 through 8)"),
	
	// Directional buttons for the satellites
	up_button(Point(x_max() - 100, y_max() - 100), 50, 50, "UP", cb_up),
	down_button(Point(x_max() - 100, y_max()- 50), 50, 50, "DOWN", cb_down),
	left_button(Point(x_max() - 150, y_max()- 50), 50, 50, "LEFT", cb_left),
	right_button(Point(x_max() - 50, y_max()- 50), 50, 50, "RIGHT", cb_right),
	
	moves(0),
	current_sat(0),
	
	hint_button(Point(x_max()-300 , 650), 100, 50, "HINT", cb_hint),
	
	quit_game_button(Point(0, 650), 100, 50, "<-- Home", cb_quit_game),
	stop_game_button(Point(100, 650), 100, 50, "Finished!", cb_stop_game)
{
	attach_splash();
}

static int difficulty = 2;

// attaches initial splash graphical image, with button underlay to continue
void Game_window::attach_splash() {
	attach(splash);
	attach(instructions_button);
}

// callback for go home button
void Game_window::cb_home(Address, Address gw) {
	reference_to<Game_window>(gw).attach_home();
}

// attaches all object parameters (home screen buttons and images)
void Game_window::attach_home() {
	detach(instructions);
	clear();
	attach(play_button);
	attach(scores_button);
	attach(quit_button);
	attach(home);
	
	attach(welcome);
	
	redraw();
}

// callback for high scores button
void Game_window::cb_scores(Address, Address gw) {
	reference_to<Game_window>(gw).attach_scores();
}

// callback for instructions button
void Game_window::cb_instr(Address, Address gw) {
	reference_to<Game_window>(gw).attach_instructions();
}

// attaches instructional graphical image, with button underlay to continue
void Game_window::attach_instructions() {
	detach(splash);
	clear();
	attach(instructions);
	attach(home_button);
	
	redraw();
}

// callback for quit button
void Game_window::cb_quit(Address, Address gw) {
	reference_to<Game_window>(gw).quit();
}

// quits the game
void Game_window::quit() {
	hide();
}
	
// callback for play button
void Game_window::cb_play(Address, Address gw) {
	reference_to<Game_window>(gw).play();
}

// plays the game
void Game_window::play() {
	set_difficulty();
}

//SCORE AREA-----------------------------------------------------------------------------------

vector<Score> Game_window::get_scores() {
	vector<Score> list = {};
	string name;
	int score;
	ifstream file("scores.txt");

	if (!file) { //error handling
		cerr << "File could not be opened for reading! Does it exist?" << endl;
	}

    	while(file >> name >> score)
	{
		list.push_back(Score(name, score));
	}

    	sort(list.begin(), list.end());

	if (list.size() == 1) { //error handling for empty list
		cerr << "The list is empty! Check the file contents." << endl;
	}

	return list;
}

// writes the given score to the file
void Game_window::write_score(Score high_score) {
	ofstream file;
	file.open("scores.txt", std::ios_base::app);
	file << '\n' << high_score;
}

// clears the window, removing all objects, then attaches the high scores area items
void Game_window::attach_scores() {
	detach(welcome);
	clear();
	
	Button* back_button = new Button(Point(0, 0), 100, 20, "Back...", cb_back);
	vector<Score> score_list = get_scores();
	
	string output;
	output = score_list[score_list.size()-1].x + "\t" + to_string(score_list[score_list.size()-1].y);
	score1 = new Text(Point(x_max() / 2 - 25, y_max() / 2.75 + 25 + 0),  output);
	attach(*score1);
	output = score_list[score_list.size()-2].x + "\t" + to_string(score_list[score_list.size()-2].y);
	score2 = new Text(Point(x_max() / 2 - 25, y_max() / 2.75 + 25 + 25), output);
	attach(*score2);
	output = score_list[score_list.size()-3].x + "\t" + to_string(score_list[score_list.size()-3].y);
	score3 = new Text(Point(x_max() / 2 - 25, y_max() / 2.75 + 25 + 50), output);
	attach(*score3);
	output = score_list[score_list.size()-4].x + "\t" + to_string(score_list[score_list.size()-4].y);
	score4 = new Text(Point(x_max() / 2 - 25, y_max() / 2.75 + 25 + 75), output);
	attach(*score4);
	output = score_list[score_list.size()-5].x + "\t" + to_string(score_list[score_list.size()-5].y);
	score5 = new Text(Point(x_max() / 2 - 25, y_max() / 2.75 + 25 + 100), output);
	attach(*score5);
	
	attach(*back_button);
	redraw();
}

// callback for back button
void Game_window::cb_back(Address, Address pw)
{
	reference_to<Game_window>(pw).back();
}

// goes back to home screen after clearing onscreen contents
void Game_window::back()
{
	detach(*score1);
	detach(*score2);
	detach(*score3);
	detach(*score4);
	detach(*score5);

	clear();
	
	attach(play_button);
	attach(scores_button);
	attach(quit_button);
	attach(home);
	attach(welcome);
	
	redraw();
}

//DIFFICULTY AREA-----------------------------------------------------------------------------------

// sets the difficulty level by detaching and attaching appropriate buttons
void Game_window::set_difficulty() {
	detach(play_button);
	detach(scores_button);
	detach(quit_button);
	detach(welcome);
	
	attach(home);
	attach(diff_box);
	attach(next_button);
	
	redraw();
}

// callback for next button
void Game_window::cb_next(Address, Address gw) {
	reference_to<Game_window>(gw).next();
}

// reads user typed difficulty
void Game_window::next() {
	difficulty = diff_box.get_int();
	
	if (difficulty < 2 || difficulty > 8) {
		difficulty = 8; //if not in range, set to 8, because they deserve it
	}
	attach(home);
	clear();
	redraw();
	
	load_vectors();
	enter();
}

//GAMEPLAY AREA-----------------------------------------------------------------------------------

void Game_window::load_vectors() {
	//loads each vector with appropriate amount of items BASED ON DIFFICULTY
	for (int i = 1; i <= difficulty; ++i) {
		int x = rand() % 950 + 25; // x is between 25 and 950
		int y = rand() % 414 + 50; // y is between 50 and 550 (due to buttons)
		
		
		// ensures EACH BUTTON HAS CORRESPONDING SATELLITE CALLBACK (random placement)
		switch(i) {
			case 1: {
				Image* aqua_satellite = new Image(Point(x, y), "aqua_satellite.gif");
				satellites.push_back(aqua_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback1);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 2: {
				Image* black_satellite = new Image(Point(x, y), "black_satellite.gif");
				satellites.push_back(black_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback2);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 3:{
				Image* blue_satellite = new Image(Point(x, y), "blue_satellite.gif");
				satellites.push_back(blue_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback3);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 4:{
				Image* green_satellite = new Image(Point(x, y), "green_satellite.gif");
				satellites.push_back(green_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback4);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 5: {
				Image* navy_satellite = new Image(Point(x, y), "navy_satellite.gif");
				satellites.push_back(navy_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback5);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 6: {
				Image* red_satellite = new Image(Point(x, y), "red_satellite.gif");
				satellites.push_back(red_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback6);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 7: {
				Image* yellow_satellite = new Image(Point(x, y), "yellow_satellite.gif");
				satellites.push_back(yellow_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback7);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
			case 8: {
				Image* purple_satellite = new Image(Point(x, y), "purple_satellite.gif");
				satellites.push_back(purple_satellite);
				Button* current_button = new Button(Point(x+35, y+35), 35, 35, " ", sb_callback8);
				sat_pickers.push_back(current_button);
				longitudes.push_back(x);
				latitudes.push_back(y);
				break;
			}
		}
	}
}

//calculating score
double Game_window::distance(int la1, int lo1, int la2, int lo2){
	//Satellite 1 coordinates
	double lat1;
	double long1;
	double lat2;
	double long2;
	
	if(la1 >= 525 && lo1 <= 325){
		lat1 = (la1 - 525) / 2.77;
		long1 = (325.0 - lo1) / 2.77;
		
	}
	else if(la1 <= 525 && lo1 <= 325){
		lat1 = (la1 - 525) / 2.77;
		long1 = (325.0 - lo1) / 2.77;
	}
	else if(la1 <= 525 && lo1 >= 325){
		lat1 = (la1 - 525) / 2.77;
		long1 = (325.0 - lo1) / 2.77;
	}
	else if(la1 >= 525 && lo1 >= 325){
		lat1 = (la1-525) / 2.77;
		long1 = (325.0 - lo1) / 2.77;
	}
	
	//Satellite 2 coordinates
	if(la2 >= 525 && lo2 <= 325){
		lat2 = (la2 - 525) / 2.77;
		long2 = (325.0 - lo2) / 2.77;
		
	}
	else if(la2 <= 525 && lo2 <= 325){
		lat2 = (la2 - 525) / 2.77;
		long2 = (325.0 - lo2) / 2.77;
	}
	else if(la2 <= 525 && lo2 >= 325){
		lat2 = (la2 - 525) / 2.77;
		long2 = (325.0 - lo2) / 2.77;
	}
	else if(la2 >= 525 && lo2 >= 325){
		lat2 = (la2 - 525) / 2.77;
		long2 = (325.0 - lo2) / 2.77;
	}
	double r = 4000;
	double phi_1 = (M_PI/180.0) * (lat1);
	double phi_2 = (M_PI/180.0) * (lat2);
	double delta_phi = (M_PI/180.0) * (lat2 - lat1);
	double delta_lambda = (M_PI/180.0) * (long2 - long1);
	double a = sin(delta_phi/2) * sin(delta_phi/2) + cos(phi_1) * cos(phi_2) * sin(delta_lambda/2) * sin(delta_lambda/2); 
	double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
	double distance = r * c;
	return distance * difficulty;
}

//Hint button
void Game_window::cb_hint(Address, Address gw) {
	reference_to<Game_window>(gw).hint();
}
void Game_window::hint() {
	int game_score = 10000000;
	int low_long1;
	int low_lat1;
	int low_long2;
	int low_lat2;
	
	for(int i = 0; i < difficulty; i += 1){
		for(int j = 0; j < difficulty; j +=1){
			if(game_score > distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]) && distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]) != 0){
				game_score = distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]);
				low_long1 = longitudes[i];
				low_lat1 = latitudes[i];
				low_long2 = longitudes[j];
				low_lat2 = latitudes[j];
			}
		}
	}
	hint1_cirlce = new Circle(Point(low_long1+50, low_lat1+50), 55);
	hint2_circle = new Circle(Point(low_long2+50, low_lat2+50), 55);
	hint1_cirlce->set_color(Color::red);
	hint2_circle->set_color(Color::red);
	attach(*hint1_cirlce);
	attach(*hint2_circle);
	redraw();
}

// enters the gamespace, attaches all object necessary (as dictated by difficulty)
void Game_window::enter() {	
	//ensure move count is visible
	clear();
	move_count = new Text(Point(20, 20), "Moves: " + to_string(moves));
	game_score = 10000000;
	for(int i = 0; i < difficulty; i += 1)
		for(int j = 0; j < difficulty; j +=1){
			if(game_score > distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j])){
				game_score = distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]);
			}
		}
	current_score = new Text(Point(x_max()-150, 20), "Score: " + to_string(game_score));
	
	detach(home);
	attach(earth_map);
	attach(quit_game_button);
	attach(stop_game_button);
	attach(*move_count);
	attach(*current_score);
	attach(up_button);
	attach(down_button);
	attach(hint_button);
	attach(left_button);
	attach(right_button);
	
	for (int i = 0; i < satellites.size(); ++i) {
		attach(*satellites[i]);
		attach(*sat_pickers[i]);
	}
	redraw();
}

// UP button moves current satellite based on move count
void Game_window::up() {
	detach(*move_count);
	detach(*current_score);
	detach(*hint1_cirlce);
	detach(*hint2_circle);
	
	if(moves > 49) {
		game_over();
		return;
	}
	
	delete move_count;
	++moves;
	move_count = new Text(Point(20, 20), "Moves: " + to_string(moves));
	game_score = 1000000;
	for(int i = 0; i < difficulty; i += 1)
		for(int j = 0; j < difficulty; j +=1){
			if(game_score>distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]) && i != j){
				game_score = distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]);
			}
		}
	current_score = new Text(Point(x_max()-150, 20), "Score: " + to_string(game_score));
	attach(*move_count);
	attach(*current_score);
	
	if (moves > 0 && moves <= 10) {	
		if (!(satellites[current_sat]->center().y <= 50)) {
			satellites[current_sat]->move(0, -55);  //move count is 1-10
			sat_pickers[current_sat]->move(0, -55); //move by 20 pixels (degrees)
			latitudes[current_sat] -= 55;
		}
	}
	else if (moves >= 11 && moves <= 20) {
		if (!(satellites[current_sat]->center().y <= 50)) {
			satellites[current_sat]->move(0, -42);  //move count is 11-20
			sat_pickers[current_sat]->move(0, -42); //move by 15 pixels (degrees)
			latitudes[current_sat] -= 42;
		}
	}
	else if (moves >= 21 && moves <= 30) {
		if (!(satellites[current_sat]->center().y <= 50)) {
			satellites[current_sat]->move(0, -28);  //move count is 21-30
			sat_pickers[current_sat]->move(0, -28); //move by 10 pixels (degrees)
			latitudes[current_sat] -= 28;
		}
	}
	else if (moves >= 31 && moves <= 40) {
		if (!(satellites[current_sat]->center().y <= 50)) {
			satellites[current_sat]->move(0, -14);   //move count is 31-40
			sat_pickers[current_sat]->move(0, -14);  //move by 5 pixels (degrees)
			latitudes[current_sat] -= 14;
		}
	}
	else if (moves >= 41 && moves <= 50) {
		if (!(satellites[current_sat]->center().y <= 50)) {
			satellites[current_sat]->move(0, -3);   //move count is 41-50
			sat_pickers[current_sat]->move(0, -3);  //move by 1 pixel (degree)
			latitudes[current_sat] -= 3;
		}
	}
	
	attach(*satellites[current_sat]);
	redraw();
}

// DOWN BUTTON
void Game_window::down() {
	detach(*move_count);
	detach(*current_score);
	detach(*hint1_cirlce);
	detach(*hint2_circle);
	
	if(moves > 49) {
		game_over();
		return;
	}
	
	delete move_count;
	++moves;
	move_count = new Text(Point(20, 20), "Moves: " + to_string(moves));
	game_score = 1000000;
	for(int i = 0; i < difficulty; i += 1)
		for(int j = 0; j < difficulty; j +=1){
			if(game_score>distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]) && i != j){
				game_score = distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]);
			}
		}
	current_score = new Text(Point(x_max()-150, 20), "Score: " + to_string(game_score));
	attach(*move_count);
	attach(*current_score);
	
	if (moves > 0 && moves <= 10) {	
		if (!(satellites[current_sat]->center().y >= 464)) {
			satellites[current_sat]->move(0, 55);  //move count is 1-10
			sat_pickers[current_sat]->move(0, 55); //move by 20 pixels (degrees)
			latitudes[current_sat] += 55;

		}
	}
	else if (moves >= 11 && moves <= 20) {
		if (!(satellites[current_sat]->center().y >= 464)) {
			satellites[current_sat]->move(0, 42);  //move count is 11-20
			sat_pickers[current_sat]->move(0, 42); //move by 15 pixels (degrees)
			latitudes[current_sat] += 42;

		}
	}
	else if (moves >= 21 && moves <= 30) {
		if (!(satellites[current_sat]->center().y >= 464)) {
			satellites[current_sat]->move(0, 28);  //move count is 21-30
			sat_pickers[current_sat]->move(0, 28); //move by 10 pixels (degrees)
			latitudes[current_sat] += 28;

		}
	}
	else if (moves >= 31 && moves <= 40) {
		if (!(satellites[current_sat]->center().y >= 464)) {
			satellites[current_sat]->move(0, 14);   //move count is 31-40
			sat_pickers[current_sat]->move(0, 14);  //move by 5 pixels (degrees)
			latitudes[current_sat] += 14;

		}
	}
	else if (moves >= 41 && moves <= 50) {
		if (!(satellites[current_sat]->center().y >= 464)) {
			satellites[current_sat]->move(0, 3);   //move count is 41-50
			sat_pickers[current_sat]->move(0, 3);  //move by 1 pixel (degree)
			latitudes[current_sat] += 3;
		}
	}
	
	attach(*satellites[current_sat]);
	redraw();
}

// RIGHT BUTTON
void Game_window::right() {
	detach(*move_count);
	detach(*current_score);
	detach(*hint1_cirlce);
	detach(*hint2_circle);
	
	if(moves > 49) {
		game_over();
		return;
	}
	
	delete move_count;
	++moves;
	move_count = new Text(Point(20, 20), "Moves: " + to_string(moves));
	game_score = 1000000;
	for(int i = 0; i < difficulty; i += 1)
		for(int j = 0; j < difficulty; j +=1){
			if(game_score > distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]) && i != j){
				game_score = distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]);
			}
		}
	current_score = new Text(Point(x_max()-150, 20), "Score: " + to_string(game_score));
	attach(*move_count);
	attach(*current_score);
	
	if (moves > 0 && moves <= 10) {
		if (!(satellites[current_sat]->center().x >= 925)) {
			satellites[current_sat]->move(55, 0);    //move count is 1-10
			sat_pickers[current_sat]->move(55, 0);   //move by 20 pixels (degrees)
			longitudes[current_sat] += 55;
		}
		else {
			satellites[current_sat]->move(-940, 0);  //wraparound
			sat_pickers[current_sat]->move(-940, 0);
			longitudes[current_sat] -= 940;
		}
	}                                            
	else if (moves >= 11 && moves <= 20) {       
		if (!(satellites[current_sat]->center().x >= 925)) {
			satellites[current_sat]->move(42, 0);    //move count is 11-20
			sat_pickers[current_sat]->move(42, 0);   //move by 15 pixels (degrees)
			longitudes[current_sat] += 42;

		}
		else {
			satellites[current_sat]->move(-955, 0); //wraparound
			sat_pickers[current_sat]->move(-955, 0);
			longitudes[current_sat] -= 955;

		}
	}                                            
	else if (moves >= 21 && moves <= 30) {       
		if (!(satellites[current_sat]->center().x >= 925)) {
			satellites[current_sat]->move(28, 0);    //move count is 21-30
			sat_pickers[current_sat]->move(28, 0);   //move by 10 pixels (degrees)
			longitudes[current_sat] += 28;

		}
		else {
			satellites[current_sat]->move(-970, 0); //wraparound
			sat_pickers[current_sat]->move(-970, 0);
			longitudes[current_sat] -= 970;

		}
	}                                            
	else if (moves >= 31 && moves <= 40) {    
		if (!(satellites[current_sat]->center().x >= 925)) {
			satellites[current_sat]->move(14, 0);    //move count is 31-40
			sat_pickers[current_sat]->move(14, 0);   //move by 5 pixels (degrees)
			longitudes[current_sat] += 14;

		}
		else {
			satellites[current_sat]->move(-985, 0); //wraparound
			sat_pickers[current_sat]->move(-985, 0);
			longitudes[current_sat] -= 985;

		}
	}                                            
	else if (moves >= 41 && moves <= 50) {          
		if (!(satellites[current_sat]->center().x >= 925)) {
			satellites[current_sat]->move(3, 0);    //move count is 41-50
			sat_pickers[current_sat]->move(3, 0);   //move by 1 pixel (degree)
			longitudes[current_sat] += 3;

		}
		else {
			satellites[current_sat]->move(-996, 0); //wraparound
			sat_pickers[current_sat]->move(-996, 0);
			longitudes[current_sat] -= 996;

		}
	}
	
	attach(*satellites[current_sat]);
	redraw();
}

// LEFT BUTTON
void Game_window::left() {
	detach(*move_count);
	detach(*current_score);
	detach(*hint1_cirlce);
	detach(*hint2_circle);
	
	if(moves > 49) {
		game_over();
		return;
	}
	
	delete move_count;
	++moves;
	move_count = new Text(Point(20, 20), "Moves: " + to_string(moves));
	game_score = 1000000;
	for(int i = 0; i < difficulty; i += 1)
		for(int j = 0; j < difficulty; j +=1){
			if(game_score > distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]) && i != j){
				game_score = distance(longitudes[i], latitudes[i], longitudes[j], latitudes[j]);
			}
		}
	current_score = new Text(Point(x_max()-150, 20), "Score: " + to_string(game_score));
	attach(*move_count);
	attach(*current_score);
	
	if (moves > 0 && moves <= 10) {
		if (!(satellites[current_sat]->center().x <= 25)) {
			satellites[current_sat]->move(-55, 0);    //move count is 1-10
			sat_pickers[current_sat]->move(-55, 0);   //move by 20 pixels (degrees)
			longitudes[current_sat] -= 55;

		}
		else {
			satellites[current_sat]->move(940, 0);  //wraparound
			sat_pickers[current_sat]->move(940, 0);
			longitudes[current_sat] += 940;

		}
	}                                            
	else if (moves >= 11 && moves <= 20) {       
		if (!(satellites[current_sat]->center().x <= 25)) {
			satellites[current_sat]->move(-42, 0);    //move count is 11-20
			sat_pickers[current_sat]->move(-42, 0);   //move by 15 pixels (degrees)
			longitudes[current_sat] -= 42;

		}
		else {
			satellites[current_sat]->move(955, 0); //wraparound
			sat_pickers[current_sat]->move(955, 0);
			longitudes[current_sat] += 955;

		}
	}                                            
	else if (moves >= 21 && moves <= 30) {       
		if (!(satellites[current_sat]->center().x <= 25)) {
			satellites[current_sat]->move(-28, 0);    //move count is 21-30
			sat_pickers[current_sat]->move(-28, 0);   //move by 10 pixels (degrees)
			longitudes[current_sat] -= 28;

		}
		else {
			satellites[current_sat]->move(970, 0); //wraparound
			sat_pickers[current_sat]->move(970, 0);
			longitudes[current_sat] += 970;

		}
	}                                            
	else if (moves >= 31 && moves <= 40) {    
		if (!(satellites[current_sat]->center().x <= 25)) {
			satellites[current_sat]->move(-14, 0);    //move count is 31-40
			sat_pickers[current_sat]->move(-14, 0);   //move by 5 pixels (degrees)
			longitudes[current_sat] -= 14;

		}
		else {
			satellites[current_sat]->move(985, 0); //wraparound
			sat_pickers[current_sat]->move(985, 0);
			longitudes[current_sat] += 985;

		}
	}                                            
	else if (moves >= 41 && moves <= 50) {          
		if (!(satellites[current_sat]->center().x <= 25)) {
			satellites[current_sat]->move(-3, 0);    //move count is 41-50
			sat_pickers[current_sat]->move(-3, 0);   //move by 1 pixel (degree)
			longitudes[current_sat] -= 3;

		}
		else {
			satellites[current_sat]->move(996, 0); //wraparound
			sat_pickers[current_sat]->move(996, 0);
			longitudes[current_sat] += 996;

		}
	}
	
	attach(*satellites[current_sat]);
	redraw();
}

// callbacks for directional button presses
void Game_window::cb_up(Address, Address gw) {
	reference_to<Game_window>(gw).up();
}

void Game_window::cb_down(Address, Address gw) {
	reference_to<Game_window>(gw).down();
}

void Game_window::cb_right(Address, Address gw) {
	reference_to<Game_window>(gw).right();
}

void Game_window::cb_left(Address, Address gw) {
	reference_to<Game_window>(gw).left();
}

// callbacks for buttons for each satellite, called as needed
// current_sat is range [0, 7] due to max size = 8
void Game_window::sb_callback1(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button1();
}
void Game_window::sat_button1() {
	current_sat = 0;
}

void Game_window::sb_callback2(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button2();
}
void Game_window::sat_button2() {
	current_sat = 1;
}

void Game_window::sb_callback3(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button3();
}
void Game_window::sat_button3() {
	current_sat = 2;
}

void Game_window::sb_callback4(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button4();
}
void Game_window::sat_button4() {
	current_sat = 3;
}

void Game_window::sb_callback5(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button5();
}
void Game_window::sat_button5() {
	current_sat = 4;
}

void Game_window::sb_callback6(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button6();
}
void Game_window::sat_button6() {
	current_sat = 5;
}

void Game_window::sb_callback7(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button7();
}
void Game_window::sat_button7() {
	current_sat = 6;
}

void Game_window::sb_callback8(Address, Address gw) {
	reference_to<Game_window>(gw).sat_button8();
}
void Game_window::sat_button8() {
	current_sat = 7;
}

// buttons on the play screen for QUIT, STOP
void Game_window::cb_quit_game(Address, Address gw) {
	reference_to<Game_window>(gw).quit_game();
}

//resets EVERYTHING! moves, difficulty, etc.
void Game_window::quit_game() {
	for (int i = 0; i < difficulty; ++i) { //iterates through and detaches objects
		detach(*satellites[i]);
		detach(*sat_pickers[i]);
	}
	moves = 0;
	current_sat = 0;
	satellites.erase(satellites.begin(), satellites.end()); // erases contents of each vector
	sat_pickers.erase(sat_pickers.begin(), sat_pickers.end());
	latitudes.erase(latitudes.begin(), latitudes.end());
	longitudes.erase(longitudes.begin(), longitudes.end());
	detach(*move_count);
	detach(*current_score);
	detach(*hint1_cirlce);
	detach(*hint2_circle);
	detach(earth_map);
	clear();
	
	attach(play_button);
	attach(scores_button);
	attach(quit_button);
	attach(home);
	attach(welcome);
	
	redraw();
}
// Stop game button callback
void Game_window::cb_stop_game(Address, Address gw) {
	reference_to<Game_window>(gw).stop_game();
}

// stops the game, allows user to add score
void Game_window::stop_game() {
	game_over(); // go to end of game processes
}

// callback for play again button
void Game_window::cb_play_again(Address, Address gw) {
	reference_to<Game_window>(gw).play_again();
}

// adds score to file, quits game
void Game_window::play_again() {
	string initials = name_box -> get_string();
	Score high_score(initials, game_score);
	write_score(high_score);
	
	detach(*name_box);
	detach(*quit_final_button);
	detach(*play_again_button);
	
	attach(home);
	attach(diff_box);
	attach(next_button);
	
	redraw();
	
}

// callback for quit button (on final display)
void Game_window::cb_quit_final(Address, Address gw) {
	reference_to<Game_window>(gw).quit_final();
}

// adds score to file, quits game
void Game_window::quit_final() {
	string initials = name_box -> get_string();
	Score high_score(initials, game_score);
	write_score(high_score);
	hide();
}

//called when 50 moves is reached
void Game_window::game_over() {
	for (int i = 0; i < difficulty; ++i) { //iterates through and detaches objects
		detach(*satellites[i]);
		detach(*sat_pickers[i]);
	}
	moves = 0;
	current_sat = 0;
	satellites.erase(satellites.begin(), satellites.end()); // erases contents of each vector
	sat_pickers.erase(sat_pickers.begin(), sat_pickers.end());
	latitudes.erase(latitudes.begin(), latitudes.end());
	longitudes.erase(longitudes.begin(), longitudes.end());
	detach(*move_count);
	detach(*current_score);
	detach(*hint1_cirlce);
	detach(*hint2_circle);
	detach(earth_map);
	clear();
	
	name_box = new In_box(Point(x_max() / 2, y_max() / 2), 80, 20, "Enter initials!");
	quit_final_button = new Button(Point(x_max() / 2 , y_max() / 2 + 20), 100, 40, "Quit Game", cb_quit_final);
	play_again_button = new Button(Point(x_max() / 2 - 100, y_max() / 2 + 20), 100, 40, "Play again!", cb_play_again);
	
	attach(home);
	attach(*name_box);
	attach(*quit_final_button);
	attach(*play_again_button);
	
	redraw();
}




