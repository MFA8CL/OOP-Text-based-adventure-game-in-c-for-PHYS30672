#include "forest.h"
forest::forest() {
	type = "forest";
	number_of_exits = 0;
	area_description = "You are in the forest, a dark, all encompassing, and dangerous part of this region. Many travellers have been told the \nforest is impossible to leave once you enter.\n\nCURRENT AREA: FOREST\n";
}
forest::~forest(){}
string forest::get_menu_info() const { return "empty function"; };
string forest::get_neighbouring_rooms() const { return "empty function"; }
NPC& forest::getNPC(int i, const area& a) const { //NPC test; 
	return *vector_of_NPCs[i]; }
int forest::get_number_of_NPCs() { return vector_of_NPCs.size(); };
string forest::get_type()const { return type; }
string forest::get_description()const { return area_description; };
int forest::get_number_of_room_options() {
	return number_of_room_options;
};
int forest::get_number_of_exit_options() {
	return number_of_exits;
};
void forest::available_interactions_for_area(int i, area& a, character & p) {
	cout << get_description() <<"\n"<<endl;
	string option_1;
	string option_2;
	if(i==1){
	//for travelling east ->>
		option_1 = "east";
		option_2 = "west";
	}
	//for travelling west
	else if(i==0){
		option_1 = "west";
		option_2 = "east";	
	}	
	//counter of total movements in forest
	int movement_counter{ 0 };
	//counter of correct moves to escape
	int how_far_to_end{ 0 };
	//Print available options
	cout << "You are in the forest. You remember the way you came in but somehow have no sense of where you are\n" << endl << "Press 0 to continue "<< option_1 <<" or 1 to go "<< option_2 <<"\n" << endl;
	//Loop for each stage of the forest
	bool still_in_area(true);
	do {
		//If player makes too many moves the forest kills them
		if (movement_counter == 8) { p.set_health(0); cout << "You died from starvation after being incapable of escaping the forest\n" << endl; return; }
		//5 moves in the correct direction (the way the player came to begin with) get the player out of the  forest
		if(how_far_to_end == 5){ still_in_area = false; }
		//Validate user choice	
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > 1 || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter one of the given options" << endl;
		}
		switch (answer) {
		case 0:			
			//+1 move
			++movement_counter;		
			//Specific output for the new part of the forest
			different_stages_of_forest(i, how_far_to_end, p);
			//Player continues in forward direction, gets closer to exit
			++how_far_to_end;
			break;
		case 1:
			//If player tries to retrace steps the counter for available moves resets to 0
			how_far_to_end = 0;
			++movement_counter;
			cout << "All you can see is trees for miles around you, \nand the forest itself is deathly silent.\n" << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
			break;
		}
	} while (still_in_area);
	return;
}
void forest::different_stages_of_forest(int direction, int movement_counter, character& p) {	
	//Strings for allowing the output to change directions in output string whether player has come into the forest from the east or west
	string option_1;
	string option_2;
	//For the case we are travelling west into the forest from the village
	if (direction == 0) {
		option_1 = "west";
		option_2 = "east";
	}
	//For the case we are travelling east into the forest from the outskirts
	else if(direction == 1) {
		option_1 = "east";
		option_2 = "west";
	}	
	//Different output depending on the movement counter of how far the player is into the forest, with 5 leaving the forest before this whole function is called
	switch (movement_counter) {
	case 0:
		cout << "You have been walking for a few miles. All you can see is trees for miles around you, and the forest itself is deathly silent.\n" << endl<< "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
		break;
	case 1:
		cout << "After walking a few more miles, all you can see is trees for miles around you, and the forest itself is deathly silent.\n" << endl << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
		break;
	case 2:
		//If the player has not yet found the dog in the forest
		if (game_progress::player_has_dog == 0) {
			cout << "After walking a few more miles, you hear faint scuttling in the direction you are walking.\n" << endl << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
		}else { 
			cout << "After walking a few more miles, all you can see is trees for miles around you, and the forest itself is deathly silent.\n" << endl << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
		 }
		break;
	case 3:
		//If player has not yet found the dog in the forest
		if (!game_progress::player_has_dog) {
			cout << "As you come through a clearing, you see a a tired, weathered dog on the ground.\nPress 1 to pick up the dog or 0 to ignore\n" << endl;
			int answer;
			while ((cin >> answer).fail() || cin.peek() != '\n' || answer > 1 || answer < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Please enter one of the given options" << endl;
			}
			switch (answer) {
			case 0:
				cout << "The creator of the game thinks you're a terrible person\n" << endl;
				cout << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
				break;
			case 1:
			//Player picks up dog
				game_progress::player_has_dog = 1;
				cout << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
				break;
			}
			break;
		}
		else{}
	case 4:
		//For emerging into the village from a start at the outskirts
		if (direction == 1) {
			cout << "As you continue on, the density of trees is beginning to sharply decrease and you can hear what sounds like a large group of people.\n" << endl;
		}
		//For emerging into the outskirts from a start at the village
		else if (direction == 0){
			cout << "As you continue on, the density of trees is beginning to sharply decrease and you begin to emerge into a clearing.\n" << endl;
		}
		cout << "Press 0 to continue " << option_1 << " or 1 to go " << option_2 << "\n" << endl;
		break;
	}
}