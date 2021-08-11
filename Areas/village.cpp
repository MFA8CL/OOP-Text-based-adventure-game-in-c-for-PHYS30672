#include "village.h"

village::village(){
	number_of_exits = 2;
	number_of_room_options = 7;
	type = "village";
	//loading in relevant NPCs for the main area
	shared_ptr<blacksmith> billyblacksmith = { make_shared<blacksmith>() };
	shared_ptr<locksmith> larrylocksmith = { make_shared<locksmith>() };
	shared_ptr<librarian> lucylibrarian = { make_shared<librarian>() };
	shared_ptr<dog_lady> doreendoglady = { make_shared<dog_lady>() };
	shared_ptr<dairy_farmer> diondairyfarmer = { make_shared<dairy_farmer>() };
	shared_ptr<alchemist> andyalchemist = { make_shared<alchemist>() };
	shared_ptr<shaman> sullyshaman = { make_shared<shaman>() };
	//push onto private vector
	vector_of_NPCs.push_back(billyblacksmith);
	vector_of_NPCs.push_back(larrylocksmith);
	vector_of_NPCs.push_back(lucylibrarian);
	vector_of_NPCs.push_back(doreendoglady);
	vector_of_NPCs.push_back(diondairyfarmer);
	vector_of_NPCs.push_back(andyalchemist);
	vector_of_NPCs.push_back(sullyshaman);
	area_description = "CURRENT AREA: VILLAGE";
	area_menu = "\nPress 1 to talk to Blacksmith\nPress 2 to talk to Locksmith\nPress 3 to visit the village library\nPress 4 to talk to Rug Salesman\nPress 5 to visit the dairy farm\nPress 6 to visit the Alchemist\nPress 7 to visit the village Shaman\nPress 0 to leave the village";
	neighbouring_rooms = "Press 1 to explore west into the forest\nPress 2 to move east to the village outskirts\nPress 0 to remain in the village\n";
}
village::~village(){}
string village::get_menu_info() const {
	return area_menu;
}
NPC &village::getNPC(int i, const area& a) const{
	return *vector_of_NPCs[i];
}
int village::get_number_of_NPCs() { 
	return vector_of_NPCs.size(); 
};
string village::get_neighbouring_rooms() const {	
	return neighbouring_rooms;
}
string village::get_type()const {
	return type;
}
string village::get_description()const {
	return area_description;
}
int village::get_number_of_exit_options() { return number_of_exits; }
int village::get_number_of_room_options(){ return number_of_room_options; }
void village::available_interactions_for_area(int i, area& a, character& p) {}