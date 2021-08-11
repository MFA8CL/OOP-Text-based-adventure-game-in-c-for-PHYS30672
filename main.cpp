#include<vector>
#include<iostream>
#include<string>
#include "game.h"
#include "area.h"
#include "character.h"
#include "NPC.h"
#include "player.h"
#include "village.h"
using namespace std;
int main(){
	game newgame;
	newgame.start_game();
	newgame.finish_game();
}