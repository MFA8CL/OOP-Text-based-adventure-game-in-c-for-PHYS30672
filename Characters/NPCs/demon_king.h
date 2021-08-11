#pragma once
#include "Enemy.h"
#include <random>
#include "combat_handler.h"
class demon_king :
	public enemy
{public:
	demon_king();
	int converse(player& p);
	~demon_king();
	string get_type() const;
	int attacked(player& p, int base_damage);
	int attacking(player& p);
	int get_health();
	int is_dead(player &p);
	int add_health(int health_added);
};

