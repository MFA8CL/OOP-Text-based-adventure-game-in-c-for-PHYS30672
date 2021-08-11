#include "alchemist.h"
alchemist::alchemist() {

	type = "alchemist";

	health = 100;
}
int alchemist::converse(player& p) {
	bool still_talking(true);
	cout << "\n" << "Alchemist: 'Alright? I'm the alchemist, got an assortment of funky fresh potions here'\n" << endl;
	cout << '1' << " = " << "Purchase a health potion (50 gold)" << endl;
	cout << '2' << " = " << "Purchase a shield potion (100 gold)" << endl;
	cout << '3' << " = " << "Purchase a damage potion (50 gold)" << endl;
	cout << '4' << " = " << "View potion descriptions" << endl;
	cout << '0' << " = " << "End conversation" << endl;
	do {
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > 4 || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter one of the given options" << endl;
		}
		switch (answer) {
		case 0:
			still_talking = false;
		case 1:
			if (p.get_gold() < 50) {
				cout << "Insufficient funds!" << endl;
			}
			else {
				cout << "here u go" << endl;
				gift_item(p, "health potion", 50);
				cout << '1' << " = " << "Purchase a health potion (50 gold)" << endl;
				cout << '2' << " = " << "Purchase a shield potion (100 gold)" << endl;
				cout << '3' << " = " << "Purchase a damage potion (50 gold)" << endl;
				cout << '4' << " = " << "View potion descriptions" << endl;
				cout << '0' << " = " << "End conversation" << endl;
			}
			break;
		case 2:
			if (p.get_gold() < 100) {
				cout << "Insufficient funds!" << endl;
			}
			else {
				gift_item(p, "shield potion", 100);
				cout << '1' << " = " << "Purchase a health potion (50 gold)" << endl;
				cout << '2' << " = " << "Purchase a shield potion (100 gold)" << endl;
				cout << '3' << " = " << "Purchase a damage potion (50 gold)" << endl;
				cout << '4' << " = " << "View potion descriptions" << endl;
				cout << '0' << " = " << "End conversation" << endl;
			}
			break;
		case 3:
			if (p.get_gold() < 50) {
				cout << "Insufficient funds!" << endl;
			}
			else {
				gift_item(p, "damage potion", 50);
				cout << '1' << " = " << "Purchase a health potion (50 gold)" << endl;
				cout << '2' << " = " << "Purchase a shield potion (100 gold)" << endl;
				cout << '3' << " = " << "Purchase a damage potion (50 gold)" << endl;
				cout << '4' << " = " << "View potion descriptions" << endl;
				cout << '0' << " = " << "End conversation" << endl;
			}
			break;
		case 4:
			cout << "\nHealth potion: Restores health to 100 but no higher\n";
			cout<< "Shield potion: Adds 50 health onto any health value with no upper limit\n";
			cout << "Damage potion: Adds 50 damage to any strike against an enemy on a one time basis\n";
			cout << "Disclaimer: All potions have temporary effects and thus can only be used in the heat of battle, so choose wisely\n";
			break;
		default:
			cout << "Please choose one of the numbered options" << endl;
		}
	} while (still_talking);
	return 0;
}
alchemist::~alchemist() {};
string alchemist::get_type() const { return type; };
void alchemist::gift_item(player& p, string type, int cost) {
	if (type =="shield potion"){
		shared_ptr<potion> newshield = { make_shared<potion>("shield potion", 0 , 50) };
		p.add_to_inventory(newshield);
		p.add_gold(-cost);
		p.view_inventory();
		cout << "PLAYER GOLD = " << p.get_gold() << endl;
	}else if (type == "health potion") {
		shared_ptr<potion> newhealth = { make_shared<potion>("health potion", 0 , 100) };
		
		p.add_to_inventory(newhealth);
		p.add_gold(-cost);
		p.view_inventory();
		cout << "PLAYER GOLD = " << p.get_gold() << endl;
	 }else if (type == "damage potion") {
		shared_ptr<potion> newdmg = { make_shared<potion>("damage potion", 50 , 0) };
		p.add_to_inventory(newdmg);
		p.add_gold(-cost);
		p.view_inventory();
		cout << "PLAYER GOLD = " << p.get_gold() << endl;
	  }
}
