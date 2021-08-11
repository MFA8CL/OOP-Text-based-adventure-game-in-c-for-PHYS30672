#include "shield.h"
shield::shield() {
	item_type = "weapon";
	item_name = "shield";
	damage = 40;
}
shield::~shield() {}
int shield::get_damage() {
	return damage;
}
