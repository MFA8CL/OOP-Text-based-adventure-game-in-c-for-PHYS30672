#pragma once
#include "Enemy.h"
#include "game_progress.h"
#include "combat_handler.h"
#include <random>
#include <conio.h>
#include "demon_slayer.h"
class vampire :
	public enemy
{public:
	vampire();
	int converse(player& p);
	~vampire();
	string get_type() const;
	int attacking(player& p);
	int attacked(player& p, int base_damage);
	int is_dead(player& p);
	int get_health();
	int add_health(int health_added);
};

