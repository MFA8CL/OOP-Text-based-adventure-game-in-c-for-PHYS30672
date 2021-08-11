#include "blacksmith.h"
#include "NPC.h"
blacksmith::blacksmith() {

	type = "blacksmith";
}
blacksmith::~blacksmith() {

}
string blacksmith::get_type()const {
	return type;
}
int blacksmith::converse(player& p) {
	bool still_talking(true);
	cout << "\n" << "Blacksmith: 'ello ello im the blacksmith and i got a wide range of weapons for u to look at today'\n" << endl;
	cout << '1' << "= " << "Purchase a shield (100 gold)" << endl;
	cout << '2' << "= " << "Purchase a sword (100 gold)" << endl;
	cout << '3' << "= " << "End conversation" << endl;
	do {
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > 3 || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter one of the given options" << endl;
		}
		switch (answer) {
		case 1:
			if (p.get_gold() < 100) {
				cout << "Blacksmith: 'I only give shields out to people who can afford em mate'" << endl;
			}
			else {
				if (!game_progress::player_has_shield) {
					cout << "Blacksmith: 'Have a shield if u want mate'" << endl;
					gift_shield(p);
					game_progress::player_has_shield = 1;
				}
				else {
					cout << "Blacksmith: 'What you gonna use 2 shields for mate?? Get going with the first one for now'\n" << endl;
				}
			}
			break;
		case 2:
			if (p.get_gold()< 100) { 
				cout << "Blacksmith: 'I only give swords out to people who can afford em mate'" << endl; 
			}
			else {
				if (!game_progress::player_has_sword) {
					cout << "Blacksmith: 'Have a sword if u want mate'" << endl;
					gift_sword(p);
					game_progress::player_has_sword=1;
				}
				else {
					cout << "Blacksmith: 'Alright I've given u a sword now, its clearly not for an army so u dont need another one mate'\n" << endl;
				}
			}
			break;
		case 3:
			still_talking = false;
			break;
		default:
			cout << "Please choose one of the numbered options" << endl;
		}
	} while (still_talking);
	return 0;
};
void blacksmith::gift_sword(player& p) {
	shared_ptr<sword> sword_for_player = { make_shared<sword>() };
	p.add_to_inventory(sword_for_player);
	p.add_gold(-100);
	p.view_inventory();
	cout << "PLAYER GOLD = " << p.get_gold() << endl;
}
void blacksmith::gift_shield(player& p) {
	shared_ptr<shield> shield_for_player = { make_shared<shield>() };
	p.add_to_inventory(shield_for_player);
	p.add_gold(-100);
	p.view_inventory();
	cout << "PLAYER GOLD = " << p.get_gold() << endl;
}
