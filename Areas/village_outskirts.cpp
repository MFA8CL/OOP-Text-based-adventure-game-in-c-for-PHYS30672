#include "village_outskirts.h"
village_outskirts::village_outskirts() {
	type = "village outskirts";
	grating_found = 0;
	number_of_room_options = 2;
	number_of_exits = 2;
	area_description = "CURRENT AREA: VILLAGE OUTSKIRTS";
	area_menu = "\nPress 1 to investigate\nPress 2 to look west\nPress 0 to leave the village outskirts";
	neighbouring_rooms = "Press 1 to go west and return to the village\nPress 2 to explore east into the forest\nPress 0 to remain in the village outskirts\n";
}
village_outskirts::~village_outskirts() {

}
string village_outskirts::get_menu_info() const {
	return area_menu;
}
NPC &village_outskirts::getNPC(int i, const area& a) const {
	return *vector_of_NPCs[i];
}
int village_outskirts::get_number_of_NPCs() { return vector_of_NPCs.size();}
string village_outskirts::get_neighbouring_rooms() const {

	return neighbouring_rooms;
}
string village_outskirts::get_type()const {
	return type;
}
string village_outskirts::get_description()const {
	return area_description;
}
int village_outskirts::player_has_key() {
	neighbouring_rooms = "Press 1 to go west and return to the village\nPress 2 to explore east into the forest\nPress 3 to enter the unlocked grating\nPress 0 to remain in the village outskirts\n";
	number_of_exits = 3;
	return 0;
}
int village_outskirts::get_number_of_exit_options() { return number_of_exits; }
void village_outskirts::available_interactions_for_area(int i, area& a, character& p){
	cout << "\n" << endl;
	if (game_progress::player_has_key) {
		player_has_key();
	}
	switch (i) {
	case 1:	
		if (!game_progress::player_has_found_grating) {
			cout << "Under a pile of leaves you see a metal grating\n" << endl;
			game_progress::player_has_found_grating = 1;
		}else if(game_progress::player_has_found_grating&&( !game_progress::player_has_key)){
			cout << "The grating is locked\n" << endl;

		 }else if (game_progress::player_has_found_grating && game_progress::player_has_key) {
			cout << "The grating is unlocked. Leave the outskirts to reveal secret entrance\n" << endl;
		  }
		break;
	case 2:
		cout << "You see to your west a forest which extends further than you can see.\n" << endl;
		break;
	default:
		break;
	}
}
int village_outskirts::get_number_of_room_options() {
	return number_of_room_options;
}