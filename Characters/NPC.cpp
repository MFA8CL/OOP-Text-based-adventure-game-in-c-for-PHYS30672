#include "NPC.h"

NPC::NPC() {
	type = "NPC";
}
NPC::~NPC() {}
string NPC::get_type()const {
	return type;
}


