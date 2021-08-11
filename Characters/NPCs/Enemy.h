#pragma once
#include "NPC.h"
class enemy :
	public NPC
{public:
	virtual int attacked(player& p, int base_damage) = 0;
	virtual int attacking(player& p) = 0;
	virtual int add_health(int health_added) = 0;
	virtual int get_health() = 0;
	virtual int is_dead(player& p)=0;
};

