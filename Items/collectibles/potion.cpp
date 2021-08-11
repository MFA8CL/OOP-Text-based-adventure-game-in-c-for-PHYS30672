#include "potion.h"
potion::potion(){
	item_type = "potion";
	item_name = "generic potion";
	damage = 0;
	health = 0;
}
potion::potion(string name, int damage_boost, int health_boost) {
	item_type = "potion";
	item_name = name;
	damage = damage_boost;
	health = health_boost;
}
potion::~potion() {}
int potion::get_health() {
	return health;
}
int potion::get_damage() { 
	return damage; 
}
