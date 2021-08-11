#pragma once
#include "player.h"
#include "area.h"
#include "village.h"
#include "village_outskirts.h"
#include "skeleton_room.h"
#include "vampire_room.h"
#include "boss_room.h"
#include "NPC.h"
#include "forest.h"
#include <limits>
class inputoutputhandler
{private:
	vector <shared_ptr<area>> vector_of_areas;
	forest the_forest;
public:
	inputoutputhandler();
	~inputoutputhandler();
	int interact_with_area(player& p);
	int area_purgatory(player& p, inputoutputhandler& ioh);
	void interact_with_NPC(int choice, player& p, NPC& n);
	area &get_area(int i);
};

