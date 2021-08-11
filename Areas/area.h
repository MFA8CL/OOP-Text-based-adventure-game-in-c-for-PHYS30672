#pragma once
#include "character.h"
#include <string>
//Forward declaration of NPC class
class NPC;
class area
{protected:
	vector<shared_ptr<NPC>> vector_of_NPCs;
	int number_of_room_options;
	string area_menu;
	string area_description;
	string type;
	string neighbouring_rooms;
	int number_of_exits;
	area() : number_of_room_options{ 0 }, number_of_exits{0}, area_menu{ "generic menu" }, area_description{ "generic description" }{}
public:
	virtual ~area() = default;
	virtual string get_menu_info() const=0;
	virtual string get_neighbouring_rooms() const =0;
	virtual string get_type()const = 0;
	virtual void set_description() {};
	virtual NPC &getNPC(int i, const area& a) const = 0;
	virtual string get_description()const = 0;
	virtual int get_number_of_room_options() = 0;
	virtual int get_number_of_NPCs() = 0;
	virtual int get_number_of_exit_options() = 0;
	virtual void available_interactions_for_area(int i, area& a, character& p) = 0;
	virtual void apply_room_changes() = 0;
};

