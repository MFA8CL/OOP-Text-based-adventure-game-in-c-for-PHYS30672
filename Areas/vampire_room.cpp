#include "vampire_room.h"
vampire_room::vampire_room() {
	type = "vampire room";
	area_description = "CURRENT AREA: SECOND ROOM OF HELL";
	area_menu = "\nPress 1 to explore the room\nPress 0 to leave room and continue";
	neighbouring_rooms = "Cannot leave the room. Press 0 to remain in the room\n";
	number_of_exits = 0;
	number_of_room_options = 1;
	//vampire* vladvampire = new vampire;
	shared_ptr<vampire> vladvampire = { make_shared<vampire>() };
	vector_of_NPCs.push_back(vladvampire);
}
vampire_room::~vampire_room() {}
string vampire_room::get_menu_info() const {
	return area_menu;
}
string vampire_room::get_neighbouring_rooms() const {
	return neighbouring_rooms;
}
NPC& vampire_room::getNPC(int i, const area& a) const {
	return *vector_of_NPCs[i];
}
int vampire_room::get_number_of_NPCs() { return vector_of_NPCs.size(); };
string vampire_room::get_type()const {
	return type;
}
string vampire_room::get_description()const {
	return area_description;
}
int vampire_room::get_number_of_exit_options() {
	return number_of_exits;
}
int vampire_room::get_number_of_room_options() {
	return number_of_room_options;
}
void vampire_room::available_interactions_for_area(int player_choice, area& a, character& p) {
	switch (player_choice) {
	case 1:
		if (!game_progress::vampire_is_dead) {
			if (game_progress::vampire_is_dead || game_progress::vampire_has_sunscreen)
				vampire_obstacle_completed();
		}else {
			cout << "The vampire is dead, you can see a maginficent hand carved wooden door at the back of the room\n" << endl;
		 }
		break;
	}
	return;
}
void vampire_room::apply_room_changes() {
	if (game_progress::vampire_is_dead || game_progress::vampire_has_sunscreen)
		vampire_obstacle_completed();
}
void vampire_room::vampire_obstacle_completed() {
	neighbouring_rooms = "Press 1 to enter through the door\nPress 0 to remain in the current room\n";
	number_of_exits = 1;
}
