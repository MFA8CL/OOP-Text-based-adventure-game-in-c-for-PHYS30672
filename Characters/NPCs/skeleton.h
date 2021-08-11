#pragma once
#include "Enemy.h"
#include <conio.h>
#include "longsword.h"
#include <random>
#include "game_progress.h"
#include "combat_handler.h"
class skeleton :
	public enemy
{private:
	int health;
public:
	skeleton();
	int converse(player& p);
	~skeleton();
	string get_type() const;
	int attacked(player & p, int base_damage);
	int attacking(player& p);
	int is_dead(player &p);
	int get_health();
	int add_health(int health_added);
};
