#pragma once
#include "area.h"
//#include "character.h"
//#include "NPC.h"
#include <vector>
#include "player.h"
#include "blacksmith.h"
#include "locksmith.h"
#include "librarian.h"
#include "dog_lady.h"
#include "dairy_farmer.h"
#include "alchemist.h"
#include "shaman.h"
class village :public area
{public:
	village();
	~village();
	string get_menu_info() const;
	string get_neighbouring_rooms() const;
	NPC & getNPC(int i, const area& a) const;
	int get_number_of_NPCs();
	string get_type()const;
	string get_description()const;
	int get_number_of_exit_options();
	int get_number_of_room_options();
	void apply_room_changes(){}
	void available_interactions_for_area(int i, area &a, character &p);	
};

