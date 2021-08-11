#pragma once
#include "item.h"
class potion :
	public item
{public:
	potion();
	potion(string type, int damage_boost, int health_boost);
	~potion();
	int get_health();
	int get_damage();
};

