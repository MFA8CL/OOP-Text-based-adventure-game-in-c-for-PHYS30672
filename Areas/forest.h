#pragma once
#include "area.h"
#include "game_progress.h"
#include "NPC.h"
#include "player.h"
class forest :
	public area
{public:
	forest();
	~forest();
	string get_menu_info() const;
	string get_neighbouring_rooms() const;
	NPC& getNPC(int i, const area& a) const;
	int get_number_of_NPCs();
	string get_type()const;
	string get_description()const;
	int get_number_of_room_options();
	int get_number_of_exit_options();
	void apply_room_changes(){}
	void available_interactions_for_area(int i, area& a, character& p);
	void different_stages_of_forest(int direction, int movement, character& p);
};

