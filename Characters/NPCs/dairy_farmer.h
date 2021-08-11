#pragma once
#include "NPC.h"
#include "item.h"
#include "game_progress.h"
class dairy_farmer :
	public NPC
{public:
	dairy_farmer();
	int converse(player& p);
	~dairy_farmer();
	string get_type() const;
	void gift_item(player& p, string type, int cost);
};

