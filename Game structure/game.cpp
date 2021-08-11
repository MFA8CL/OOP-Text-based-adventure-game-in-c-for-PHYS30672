#include "game.h"
#include "village.h"
#include <iostream>
#include <conio.h>
#include <limits>
game::game(){
	first_paragraph_of_game = "You wake up on the side of a wooden carriage in a pile of hay.\nYou can hear shouting and the mechanical turn of wooden carriage wheels.\nYou are in what seems to be a medieval village of some sort that you have never seen or visited before.\nAs you slowly become more awake a few areas in the village become clearer.\nPress any key to continue\n";
}
int game::start_game() {
	cout << "Welcome to the game. Press any key to continue\n" << endl;
	//load the map and initialise a new player using a test village
	inputoutputhandler the_handler;	
	village test;
	player *p= new player(test);
	_getch();
	cout << "This game was created by Max Allen for the OOP in c++ course\n" <<"Press any key to start.\n"<< endl;
	_getch();
	//game starts
	cout << "Press 0 to wake up or any other key to sleep in\n" << endl;
	//validate input
	int wake_up;
		while ((cin >> wake_up).fail() || cin.peek() != '\n' || wake_up != 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou sleep in, unaware of what you will see when you wake up." << endl;
			cout << "Press 0 to wake up or any other key to sleep in\n" << endl;
		}
	cout <<"\n"<< first_paragraph_of_game << endl;
	_getch();
	//Move the player to the village as contained in the inputoutput_handler
	p->set_current_area(the_handler.get_area(1));
	the_handler.interact_with_area(*p);	
	the_handler.area_purgatory(*p, the_handler);
	delete p;
	return 0;
};
int game::finish_game() {	
	if (game_progress::player_has_won) { cout << "You have won the game! Congratulations" << endl; }
	else{ cout << "GAME OVER" << endl; }
	cout << "Press any key to exit\n";
	_getch();
	exit(0);
	return 0;
}