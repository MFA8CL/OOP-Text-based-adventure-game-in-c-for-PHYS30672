#pragma once
#include "NPC.h"
#include <conio.h>
#include "game_progress.h"
class dog_lady :
	public NPC
{public:
	dog_lady();
	int converse(player& p);
	~dog_lady();
	string get_type() const;
};

