#include "skeleton_room.h"
skeleton_room::skeleton_room() {
	type = "skeleton room";
	area_description = "CURRENT AREA: FIRST ROOM OF HELL";
	area_menu = "\nPress 1 to inspect the room\nPress 0 to leave room and continue";
	neighbouring_rooms = "Cannot leave the room. Press 0 to remain in the room\n";
	number_of_exits = 0;
	number_of_room_options = 1;
	shared_ptr<skeleton> samskeleton = { make_shared<skeleton>() };
	//skeleton* samskeleton = new skeleton;
	vector_of_NPCs.push_back(samskeleton);
}
skeleton_room::~skeleton_room() {}
string skeleton_room::get_menu_info() const {
	return area_menu;
}
string skeleton_room::get_neighbouring_rooms() const {
	return neighbouring_rooms;
}
NPC& skeleton_room::getNPC(int i, const area& a) const { 
	return *vector_of_NPCs[i]; 
}
int skeleton_room::get_number_of_NPCs() { return vector_of_NPCs.size(); };
string skeleton_room::get_type()const { 
	return type; 
}
string skeleton_room::get_description()const { 
	return area_description; 
}
int skeleton_room::get_number_of_exit_options() {
	return number_of_exits;
}
int skeleton_room::get_number_of_room_options() {
	return number_of_room_options;
}
void skeleton_room::available_interactions_for_area(int player_choice, area& a, character& p) {
	switch (player_choice) {
	case 1:

		if (!game_progress::skeleton_is_dead) {
			if (game_progress::skeleton_is_dead || game_progress::skeleton_has_milk)
				skeleton_obstacle_completed();
		}else{
			cout << "The skeleton is dead, you can see a tunnel to exit at the back of the room\n" << endl;
		
		 }
		break;			
	}
	return;
}
void skeleton_room::apply_room_changes() {
	if (game_progress::skeleton_is_dead || game_progress::skeleton_has_milk)
		skeleton_obstacle_completed();
}
void skeleton_room::skeleton_obstacle_completed() {
	neighbouring_rooms = "Press 1 to move west into the next room\nPress 0 to remain in the current room\n";
	number_of_exits = 1;
}
