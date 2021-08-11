#include "boss_room.h"

boss_room::boss_room() {
	type = "boss room";
	area_description = "CURRENT ROOM: BOSS ROOM";
	area_menu = "\nPress 1 to inspect the room\nPress 0 to leave room and continue";
	neighbouring_rooms = "Cannot leave the room. Press 0 to remain in the room\n";
	shared_ptr<demon_king> bossman = { make_shared<demon_king>() };
	vector_of_NPCs.push_back(bossman);
	number_of_exits = 0;
	number_of_room_options = 1;
}
boss_room::~boss_room() {
}
string boss_room::get_menu_info() const {
	return area_menu;
}
string boss_room::get_neighbouring_rooms() const {
	return neighbouring_rooms;
}
NPC& boss_room::getNPC(int i, const area& a) const {
	return *vector_of_NPCs[i];
}
int boss_room::get_number_of_NPCs(){
	return vector_of_NPCs.size();
}
string boss_room::get_type()const {
	return type;
}
string boss_room::get_description()const {
	return area_description;
}
int boss_room::get_number_of_exit_options() {
	return number_of_exits;
}
int boss_room::get_number_of_room_options() {
	return number_of_room_options;
}
void boss_room::available_interactions_for_area(int player_choice, area& a, character& p) {
	switch (player_choice) {
	case 1:

		if (!game_progress::player_has_won) {
			if (game_progress::skeleton_is_dead || game_progress::skeleton_has_milk)
				boss_obstacle_completed();
		}else {
			cout << "The boss is dead, you can see a tunnel to exit at the back of the room\n" << endl;
		 }
		break;
	}
	return;
}
void boss_room::boss_obstacle_completed() {
	neighbouring_rooms = "Press 1 to exit through portal\nPress 0 to remain in the current room\n";
	number_of_exits = 1;
}
void boss_room::apply_room_changes(){
	if (game_progress::player_has_won)
		boss_obstacle_completed();
}