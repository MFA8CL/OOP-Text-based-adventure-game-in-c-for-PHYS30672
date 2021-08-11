#pragma once
#include "area.h"
#include "character.h"
#include "player.h"
#include "NPC.h"
#include "village.h"
#include "village_outskirts.h"
#include "inputoutput.h"
#include "game_progress.h"
class game
{private:
	string first_paragraph_of_game;
public:
	game();
	int start_game();
	int finish_game();
};

