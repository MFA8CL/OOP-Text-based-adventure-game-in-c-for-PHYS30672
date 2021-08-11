#pragma once
#include "character.h"
#include <algorithm>
#include "item.h"
#include "sword.h"
#include "key.h"
#include "book.h"
#include "player.h"
class NPC :public character
{public:
	NPC();
	virtual int converse(player &p) = 0;
	~NPC();
	string get_type() const;
};

