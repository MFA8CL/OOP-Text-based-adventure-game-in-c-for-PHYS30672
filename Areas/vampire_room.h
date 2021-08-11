#pragma once
#include "area.h"
#include "vampire.h"
#include "game_progress.h"
class vampire_room :
	public area
{public:
	vampire_room();
	~vampire_room();
	string get_menu_info() const;
	string get_neighbouring_rooms() const;
	NPC& getNPC(int i, const area& a) const;
	int get_number_of_NPCs();
	string get_type()const;
	string get_description()const;
	int get_number_of_exit_options();
	int get_number_of_room_options();
	void available_interactions_for_area(int i, area& a, character& p);
	void apply_room_changes();
	void vampire_obstacle_completed();
};

