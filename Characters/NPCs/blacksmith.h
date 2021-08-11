#pragma once
#include "NPC.h"
#include "game_progress.h"
#include "shield.h"
class blacksmith :
	public NPC
{public:
	blacksmith();
	int converse(player& p);
	~blacksmith();
	string get_type() const;
	void gift_sword(player& p);
	void gift_shield(player& p);
};

