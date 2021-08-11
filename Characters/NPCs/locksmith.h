#pragma once
#include "NPC.h"
#include "game_progress.h"
#include <conio.h>
class locksmith :
	public NPC
{private:
	int dialogue_options;
public:
	locksmith();
	int converse(player& p);
	~locksmith();
	string get_type() const;
	void gift_item(player& p);
};



