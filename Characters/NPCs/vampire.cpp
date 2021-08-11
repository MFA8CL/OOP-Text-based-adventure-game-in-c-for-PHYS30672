#include "vampire.h"
vampire::vampire() {
	type = "vampire";
	health = 200;
	base_damage = 100;
}
int vampire::converse(player& p) {
	string weapons_or_not;
	combat_handler battle_between;
	if (game_progress::vampire_is_dead) {
		cout << "Vampire is dead\n" << endl;
		return 0;
	}
	int options = 2;
	bool still_talking(true);
	//if milk is not yet given
	cout << "You are in what seems like a room of a beautifully built stone castle.\nIt's almost pitch black, except for a few candles on a wooden table.\nPress any key to continue\n" << endl;
	_getch();
	cout << "You see a magnificent wooden coffin at the rear of the room, blocking the path to a large, exquisite hand carved door.\nAs you approach the coffin begins to open.\nPress any key to continue\n";
	_getch();
	if (!game_progress::vampire_has_sunscreen) {
		cout << "\nVampire: I am a vampire who is a personal assistant to the demon king, you will have to defeat me to pass\n'" << endl;
		cout << '1' << "= " << "Try and reason with the vampire" << endl;
		cout << '2' << "= " << "Fight the vampire" << endl;
		if (game_progress::player_has_sunscreen) {
			options = 3;
			cout << '3' << "= " << "Hey dude, looks like you've not been outside in a while... Do you need any sunscreen??" << endl;
		}
		cout << '0' << "= " << "End conversation" << endl;
		do {
			int answer;
			while ((cin >> answer).fail() || cin.peek() != '\n' || answer > options || answer < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Please enter one of the given options" << endl;
			}
			switch (answer) {
			case 0:
				still_talking = false;
				break;
			case 1:
				cout << "Vampire: 'To be honest with you mate, I just wanna go back to sleep in my coffin\nIf you're here to harm the boss though I'm gonna have to eat your remains, as much as I can't be asked'\n" << endl;
				break;
			case 2:
				battle_between.fight(*this, p);
				if (p.get_health() == 0 || game_progress::vampire_is_dead) { still_talking = false; }
				break;
			case 3:
				cout << "Vampire: 'Well normally us vampires burn up in the sun, but it doesn't help I can't get any damn factor 50 \ndown here in hell.";
				cout<<" You know what mate, you've helped me out here\n" << endl;
				cout << "Sunscreen given to vampire\n" << endl;
				game_progress::vampire_has_sunscreen = 1;
				cout << "Press any key to continue...\n" << endl;
				_getch();
				cout << "Vampire: 'One more thing... If you're seeing the demon king, I'd advise getting rid of your weapons.\n" << endl;
				p.remove_items_by_name("sunscreen");				
				cout << "Press 1 to get rid of weapons\nEnter any other key to continue\n" << endl;
				cin >> weapons_or_not;
				if (weapons_or_not == "1") {//get rid of weapons here}
					p.remove_item_by_type("weapon");
					p.view_inventory();
					still_talking = false;
				}
				else { 
					cout << "Well good luck then\n" << endl;	
					still_talking = false;
				}
				break;
			default:
				cout << "Please choose one of the numbered options" << endl;
			}


		} while (still_talking);

		return 0;
	}else { cout << "Vampire: 'If it goes well I'll see you on the beach mate'\n" << endl; return 0; }
}
vampire::~vampire() {};
string vampire::get_type() const { return type; };
int vampire::add_health(int health_added) {

	int new_health = health + health_added;

	if (new_health < 0)
		health = 0;
	else
		health = new_health;
	return 0;
}
int vampire::get_health() {
	return health;
}
int vampire::attacking(player& p) { 	
	int attacks = rand() % 5 + 1;
	int shield_defense{ 0 };
	if (p.check_for_item_name("shield"))
		shield_defense = p.get_item_by_name("shield").get_damage();
	switch (attacks) {
	case 1:
		p.add_health(-base_damage+shield_defense);
		cout << "Vampire attacked you with a critical hit for " << base_damage << " damage\n" << endl;
		if (p.check_for_item_name("shield"))
			cout << shield_defense << " damage absorbed by shield\n" << endl;
		break;
	case 2:
		p.add_health(-base_damage+30+shield_defense);
		cout << "The vampire grazed you with his sword for " << base_damage-30 << " damage\n" << endl;
		if (p.check_for_item_name("shield"))
			cout << shield_defense << " damage absorbed by shield\n" << endl;
		break;
	case 3:
		cout << "You were just able to dodge the vampire's attack and took no damage\n" << endl;
		break;
	case 4:
		p.add_health(-base_damage);
		if (p.check_for_item_name("shield"))
			cout << "Vampire managed to attack past your shield\n";
		cout << "Vampire attacked you with a critical hit for " << base_damage << " damage\n" << endl;	
		break;
	case 5:
		p.add_health(-base_damage + 30);
		if (p.check_for_item_name("shield"))
			cout << "Vampire managed to attack past your shield\n";
		cout << "The vampire grazed you with his sword for " << base_damage - 30 << " damage\n" << endl;
		break;
	}
	return 0;
};
int vampire::attacked(player& p, int base_damage) {
	int attacks = rand() % 3 + 1;
	switch (attacks) {
	case 1:
		this->add_health(-3 * (base_damage));
		cout << "You stabbed the vampire in the heart for " << 3*base_damage << " damage\n" << endl;
		break;
	case 2:
		this->add_health(-base_damage);
		cout << "You hit the vampire with a body shot for " << base_damage << " damage\n" << endl;
		break;
	case 3:
		cout << "The Vampire dodged your attack and took no damage\n" << endl;
		break;
	}
	return 0;
}
int vampire::is_dead(player &p) {
	//give demon killing blade
	shared_ptr<demon_slayer> demon_slayer_for_the_player = { make_shared<demon_slayer>() };
	cout << "Vampire dropped a dagger with the words 'Demon Slayer' engraved into it\n" << endl;
	p.add_to_inventory(demon_slayer_for_the_player);
	p.view_inventory();
	game_progress::vampire_is_dead = 1;
	return 0;
};
