#pragma once
#include "NPC.h"
#include "potion.h"
class alchemist :
	public NPC
{public:
	alchemist();
	int converse(player& p);
	~alchemist();
	string get_type() const;
	void gift_item(player& p, string type, int cost);
};

