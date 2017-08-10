class Game_window : Graph_lib::Window {
	
	Text welcome; //welcome text
	
	Button play_button; //menu: play button
	Button scores_button; //menu: high scores button
	Button quit_button; //menu: quit button
	Button instructions_button; //moves to instructions button
	Button home_button; //moves to menu button
	
	Image splash; //first screen image
	Image instructions; //instructions image (second screen)
	Image home; //menu screen image
	Image earth_map;//map of earth during gamemode
	
	Text* score1;
	Text* score2;
	Text* score3;
	Text* score4;
	Text* score5;
	
	In_box diff_box; //input box for user input of difficulty (could be changed to buttons for user to pick)
	Button next_button; //continue button for score screen
	
	void attach_splash(); // attaches 1st screen
	
	static void cb_home(Address, Address);
	void attach_home(); // removes instrctions, attaches the home screen items
	
	static void cb_instr(Address, Address);
	void attach_instructions(); //removes splash, attaches instructions
	
	static void cb_scores(Address, Address);
	vector<Score> get_scores(); //reads from text file the scores as a string
	void write_score(Score); // writes given score to file
	void attach_scores(); //callback for scores button on Game_window
	
	static void cb_quit(Address, Address);
	void quit(); //quits the program
	
	static void cb_back(Address, Address); //callback to go to home screen
	void back(); //goes to home screen from high scores screen
		
	static void cb_play(Address, Address);
	void play(); //call to the play area
	
	void set_difficulty(); //attaches the difficulty level screen
	
	static void cb_next(Address, Address); // continue button after setting difficulty
	void next();
	
	// GAMEMODE --------------------------------------------------------
	
	// keeps track of what sat we are moving
	int current_sat;
	
	// vector of circles holds satellites, buttons holds selectors
	vector<Image*> satellites;
	vector<Button*> sat_pickers;
	
	// for each possible satellite, a callback and method for its button
	static void sb_callback1(Address, Address);
	static void sb_callback2(Address, Address);
	static void sb_callback3(Address, Address);
	static void sb_callback4(Address, Address);
	static void sb_callback5(Address, Address);
	static void sb_callback6(Address, Address);
	static void sb_callback7(Address, Address);
	static void sb_callback8(Address, Address);
	void sat_button1();
	void sat_button2();
	void sat_button3();
	void sat_button4();
	void sat_button5();
	void sat_button6();
	void sat_button7();
	void sat_button8();
	
	// loads the vectors above based on difficulty level
	void load_vectors();
	void enter(); //enters the gamemode
	
	// directional buttons for movement
	Button up_button;
	Button down_button;
	Button left_button;
	Button right_button;
	
	// tracks number of moves
	int moves;
	Text* move_count;
	
	//score display and calculation
	double distance(int, int, int, int);
	int game_score;
	Vector<double> latitudes;
	Vector<double> longitudes;
	Text* current_score;
	
	// movement area, buttons perform corresponding tasks
	static void cb_up(Address, Address);
	void up();
	static void cb_down(Address, Address);
	void down();
	static void cb_left(Address, Address);
	void left();
	static void cb_right(Address, Address);
	void right();
	
	//hint button 
	Button hint_button;
	static void cb_hint(Address, Address);
	void hint();
	Circle* hint1_cirlce;
	Circle* hint2_circle;
	
	//Game over called when game final screen is called
	void game_over();
	
	//quit, stop, and back to home buttons
	Button quit_game_button;
	Button stop_game_button;
	
	// callbacks for quit, stop, gohome
	static void cb_quit_game(Address, Address);
	void quit_game();
	static void cb_stop_game(Address, Address);
	void stop_game();
	
	In_box* name_box; //input box for user initials
	Button* quit_final_button;
	Button* play_again_button;
	
	// callbacks for play again and quit buttons for final screen
	static void cb_play_again(Address, Address gw);
	void play_again();
	static void cb_quit_final(Address, Address);
	void quit_final();
	
	public:
		Game_window(Point xy, int w, int h, const string& title); //constructor
};
