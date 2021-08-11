#include "item.h"
item::item(string type, string name) { 
	item_type = type; 
	item_name = name;
	health = 0;
	damage = 0;
}
string item::get_item_type() {
	return item_type;
}
string item::get_item_name() {
	return item_name;
}
int item::get_health() { return health; }
int item::get_damage() {return damage;}