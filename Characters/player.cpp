#include "player.h"
player::player() {
	health = 0;
	gold = 0;
};
player::player(area &current) {
	health = 100;
	base_damage = 10;
	gold = 1000;
	current_area = &current;	
}
player::~player() {	}
void player::set_player_health(int i){
	health = i;	
}
int player::get_gold() {
	return gold;
}
void player::add_gold(int gold_added){
	int new_gold = this->get_gold() + gold_added;
	if (new_gold < 0) 
		gold = 0; 
	else 
		gold = new_gold;
}
int player::add_health(int health_added) {
	int new_health = health + health_added;
	if (new_health < 0)
		health = 0;
	else if (new_health > 100)
		health = 100;
	else
		health = new_health;
	return 0;
	cout << "Player health = " << health << endl;
}
void player::add_health_boost(int health_added) {
	int new_health = health + health_added;
		health = new_health;
		cout << "Player health = " << health << endl;
}
//Area related functions i.e moving the player to different locations and allocating them to memory
void player::set_current_area(area &a) {
	current_area = &a; 
}
area &player::get_current_area() {
	return *current_area;
}
string player::get_current_area_string() {
	area& a = *current_area;
	return a.get_type();
}
void player::move_area(area& a, player &p) {
	current_area = &a;
}
//inventory functions
void player::add_to_inventory(shared_ptr<item> it) {
	inventory.push_back(it);
	cout << it->get_item_name() <<" added to inventory\n" <<endl;
}
void player::view_inventory() {
	
	cout << "INVENTORY:" << endl;

	for (unsigned int i{ 0 }; i < inventory.size(); ++i) 
	cout << inventory[i]->get_item_name() << "\n";	

	cout << "\n";
}
void player::remove_item_by_type(string item_type) {	
		inventory.erase(
		std::remove_if(
			inventory.begin(),
			inventory.end(),
			[item_type](shared_ptr<item> desired_item) { return desired_item->get_item_type() == item_type; }),
		inventory.end());
}
void player::remove_items_by_name(string item_name) {
	inventory.erase(
		std::remove_if(
			inventory.begin(),
			inventory.end(),
			[item_name](shared_ptr<item> desired_item ){ return desired_item->get_item_name() == item_name; }),
		inventory.end());
}
void player::remove_1_item_by_name(string item_name) {
	auto the_item = std::find_if(inventory.begin(), inventory.end(),
		[item_name](shared_ptr<item> desired_item) { return desired_item->get_item_name() == item_name; });
	if (the_item != inventory.end()) {
		inventory.erase(the_item);
	}
}
item& player::get_item_by_name(string item_name) {
	auto the_item = std::find_if(inventory.begin(), inventory.end(),
		[item_name](shared_ptr<item> desired_item) { return desired_item->get_item_name() == item_name; });
	int index = std::distance(inventory.begin(), the_item);
	if (the_item != inventory.end()) {
		return *inventory[index];
	}
}
void player::view_items_by_type(string item_type){
	cout << item_type << "s:\n" << endl;
	int number_of_type{ 0 };
	for (unsigned int i{ 0 }; i < inventory.size(); ++i) {
		if (inventory[i]->get_item_type() == item_type) {
			cout << inventory[i]->get_item_name() << "\n";
			number_of_type++;
		}
	}	
	if(number_of_type==0)
		cout <<"No "<< item_type << "s found\n" << endl;
	cout << "\n";
}
int player::check_for_item_name(string item_name) {
	auto the_item = std::find_if(inventory.begin(), inventory.end(),
		[item_name](shared_ptr<item> desired_item) { return desired_item->get_item_name() == item_name; });
	if (the_item != inventory.end()) 
		return 1;	
	else
		return 0;
}
int player::check_for_item_type(string item_type) {
	auto the_item = std::find_if(inventory.begin(), inventory.end(),
		[item_type](shared_ptr<item> desired_item) { return desired_item->get_item_type() == item_type; });
	if (the_item != inventory.end())
		return 1;
	else
		return 0;
}
//health and damage accessors
int player::get_health() { return health; }
int player::get_base_damage() { return base_damage; }
void player::set_health(int new_health) { health = new_health; }
string player::get_type() const { return "null"; };