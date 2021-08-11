#pragma once
#include "NPC.h"
#include "game_progress.h"
#include<conio.h>
class shaman :
	public NPC
{public:
	shaman();
	int converse(player& p);
	~shaman();
	string get_type() const;	
};

