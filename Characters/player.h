#pragma once
#include "character.h"
#include "area.h"
#include "sword.h"
#include "potion.h"
#include <algorithm>
class player :
	public character
{private:
	area *current_area;
	vector<shared_ptr<item>> inventory;
public:
	player();
	player(area& current);
	~player();
	void move_area(area& a, player& p);
	void set_current_area(area& a);
	area &get_current_area();
	string get_type() const;
	string get_current_area_string();
	void set_player_health(int i);
	void set_health(int new_health);
	int add_health(int health_added);
	void add_health_boost(int health_added);
	int get_health();
	int get_base_damage();
	void add_to_inventory(shared_ptr<item> it);
	void remove_item_by_type(string item_type);
	void remove_items_by_name(string item_name);
	item & get_item_by_name(string item_name);
	void remove_1_item_by_name(string item_name);
	void view_inventory();
	void view_items_by_type(string item_type);
	int check_for_item_name(string item_name);
	int check_for_item_type(string item_type);
	int get_gold();
	void add_gold(int gold_added);
};




