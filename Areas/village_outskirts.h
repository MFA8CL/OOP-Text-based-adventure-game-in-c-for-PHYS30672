#pragma once
#include "area.h"
#include "player.h"
#include <vector>
#include "game_progress.h"
class village_outskirts:public area
{private:
	int grating_found{ 0 };
	int grating_unlocked{ 0 };
public:
	village_outskirts();
	~village_outskirts();
	string get_menu_info() const;
	string get_neighbouring_rooms() const;
	NPC & getNPC(int i, const area& a) const;
	int get_number_of_NPCs();
	string get_type()const;
	string get_description()const;
	void apply_room_changes(){}
	void available_interactions_for_area(int i, area& a, character& p);
	int player_has_key();
	int get_number_of_room_options();
	int get_number_of_exit_options();
};

