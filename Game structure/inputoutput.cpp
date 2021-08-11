#include "inputoutput.h"

inputoutputhandler::inputoutputhandler() {

	//create the map by dynamically allocating memory for the rooms of the game
	shared_ptr<village> new_village(make_shared<village>());
	shared_ptr<village_outskirts> new_outskirts(make_shared<village_outskirts>());
	shared_ptr<skeleton_room> skel_room(make_shared<skeleton_room>());
	shared_ptr<vampire_room> vamp_room(make_shared<vampire_room>());
	shared_ptr<boss_room> the_boss_room(make_shared<boss_room>());

	//push onto private vector	
	vector_of_areas.push_back(new_outskirts);//element [0] = village outskirts
	vector_of_areas.push_back(new_village);//element [1] = village
	vector_of_areas.push_back(skel_room);//element [2] = skeleton room
	vector_of_areas.push_back(vamp_room);//element [3] = vampire room
	vector_of_areas.push_back(the_boss_room);//element [4] = boss room

}

void inputoutputhandler::interact_with_NPC(int choice, player& p, NPC& n) {
	n.converse(p);
}

inputoutputhandler::~inputoutputhandler() {}

area &inputoutputhandler::get_area(int i) {
	//returns a given output
	return *vector_of_areas[i];
}

int inputoutputhandler::interact_with_area(player& p) {
		//set area using pointer to player's current area 
	area &area_right_now = p.get_current_area();
	//Print a description for the current area
	cout <<"\n"<< area_right_now.get_description() << endl;
	//Get the number of NPCs in the area
	int NPCs = area_right_now.get_number_of_NPCs();
	//While still in the current area
	bool still_in_area{ true };
	do {
		//Print a numbered list of options for interacting with the room
		cout << area_right_now.get_menu_info() << endl;
		//Get number of options for interacting with the room
		int b = area_right_now.get_number_of_room_options();
		//Get and validate player's choice
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > b || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter one of the given options" << endl;
		}			
			if (answer == 0) { //this answer leaves the current area, exiting the while-loop and ending this function
				still_in_area = false; 
			}else if (NPCs > 0) {//if there are NPCs in the room, talk to them
				interact_with_NPC(answer, p, area_right_now.getNPC(answer - 1, area_right_now));
				area_right_now.apply_room_changes();//if anything has been changed from the player interaction
				if (p.get_health() == 0) { still_in_area = false; }//check player is not dead and break if so
			 }else {//else the area has different environmental responses specific to the number of the player choice				
				area_right_now.available_interactions_for_area(answer, area_right_now, p);
				}		
	} while (still_in_area);
	return 0;
}
int inputoutputhandler::area_purgatory(player& p, inputoutputhandler &ioh) {
	//we start in the village, corresponding to element 1 of the areas vector
	int room_count{ 1 };
	bool still_in_purgatory(true);
	do {
		if (p.get_health() == 0) { return 0; }
		//Get area from player current area pointer
		area &a = p.get_current_area();
		//Get number of possible exits and string of available areas to move to
		int options = a.get_number_of_exit_options();
		cout << "\nAvailable options"<<"("<<options<<")" << endl <<"\n"<< a.get_neighbouring_rooms();		
		//Taking valid player input for chosen new area
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > options||answer<0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter one of the given options" << endl;
		}	
		switch (answer) {
		case 1:	
			//Special case: player going west from the village into the forest -->
			if (p.get_current_area_string() == "village") {
				//int for the forest function to specify whether the player has gone west [0] or east [1]
				int east_or_west{ 0 };
				//player goes to the forest
				p.move_area(the_forest, p);
				the_forest.available_interactions_for_area(east_or_west, the_forest, p);
				//end game if player died in forest
				if (p.get_health() == 0) {
					still_in_purgatory = false;
				}
				//else player gets taken back to village
				else {
					cout << "Somehow you have emerged in the village outskirts\n" << endl;
					p.move_area(get_area(0), p);
					room_count = 0;
					ioh.interact_with_area(p);
				}
			}else if (p.get_current_area_string() == "boss room") {//if we are leaving the boss room the game ends
				return 0;
			 }else {//or we just move along by one room				
				p.move_area(get_area(room_count + 1), p);//moves player along by one horizontal vector element (to the village)
				room_count++;
				ioh.interact_with_area(p);
			  }
			break;
		case 2:
			//player enters area to the east
			if (p.get_current_area_string() == "village outskirts") {
				//]integer to specify whether the player has gone west {0} or east {1}
				int east_or_west{ 1 };
				//player goes to forest
				p.move_area(the_forest, p);
				the_forest.available_interactions_for_area(east_or_west, the_forest, p);
				//end game if player died in forest
				if (p.get_health() == 0) 	
					still_in_purgatory = false;				
				//else player gets taken back to village
				else 
					cout << "Somehow you have emerged in the village\n" << endl;
					p.move_area(get_area(1), p);
					room_count = 1;
					ioh.interact_with_area(p);
			}
			//Going east from any other room that has a legal option to its east
			else {
				//need the maths for movement here
				p.move_area(get_area(room_count - 1), p);//moves player along by one horizontal vector element
				room_count--;
				ioh.interact_with_area(p);
			}
			break;
		case 0:
			//stay where you are;
			ioh.interact_with_area(p);
			break;
		case 3:
			//Player enters skeleton room
			p.move_area(get_area(2), p);
			room_count = 2;
			ioh.interact_with_area(p);
			break;
		}		
	} while (still_in_purgatory);
	return 0;
}