#pragma once
#include "Enemy.h"
#include "player.h"
#include <conio.h>
class combat_handler
{public:
	combat_handler();
	~combat_handler();
	int fight(enemy &e, player &p);
};

