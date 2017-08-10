// reads in from the file to get the scores
// TODO: sort the scores

Text* score1 = new Text(Point(0, 0), "");
Text* score2 = new Text(Point(0, 0), "");
Text* score3 = new Text(Point(0, 0), "");
Text* score4 = new Text(Point(0, 0), "");
Text* score5 = new Text(Point(0, 0), ""); 

vector<Score> Game_window::get_scores() {
	vector<Score> list = {};
	string name;
	int score;
	ifstream file("scores.txt");

	if (!file) { //error handling
		cerr << "File could not be opened for reading! Does it exist?" << endl;
	}
	

    	while(file>>name>>score)
	{
		list.push_back(Score(name, score));
	}
    
    	sort(list.begin(), list.end());

	if (list.size() == 1) { //error handling for empty list
		cerr << "The list is empty! Check the file contents." << endl;
	}

	return list;
}

// clears the window, removing all objects, then attaches the high scores area items
void Game_window::attach_scores() {
	detach(home);
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