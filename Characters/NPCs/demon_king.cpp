#include "demon_king.h"
#include "vampire.h"

demon_king::demon_king() {
	type = "demon king";

	health = 400;
	base_damage = 120;
}

int demon_king::converse(player& p) {
	string weapons_or_not;
	combat_handler battle_between;
	if (game_progress::boss_is_dead) {
		cout << "The Demon King is dead\n" << endl;
		return 0;
	}
	else if (game_progress::player_has_won) {
		cout << "Demon King: HahaAhaAAh lovely to meet a descendant of such a great man haHAA PLEASE SPARE ME\n" << endl;
		return 0;
	}
	int options = 1;
	bool still_talking(true);
	//if milk is not yet given
	if (!p.check_for_item_type("weapon")) {
		cout << "\nDemon King: Hello Sir, have you come to negotiate political matters?\n'" << endl;
		cout << '1' << "= " << "I'd like to renew the contract of Shedim for another 2000 years please" << endl;
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
				cout << "\nDemon King: 'What makes you think I'm going to help you??'\n" << endl;
				break;
			default:
				cout << "Please choose one of the numbered options" << endl;
			}
			cout << '1' << " = " << "I'm a descendant of the late spellcaster Arwyn" << endl;
			cout << '0' << " = " << "End conversation" << endl;
			int answer2;
			while ((cin >> answer2).fail() || cin.peek() != '\n' || answer2 > 1 || answer2 < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Please enter one of the given options" << endl;
			}
				switch (answer2) {
				case 0:
					still_talking = false;
					break;
				case 1:
					cout << "Demon King: 'WELL THAT'S ALL YOU HAD TO SAY OKAY NICE PLEASE DON'T KILL ME'\n" << endl;
					cout << "The Demon King has signed the contract.\n" << endl;
					_getch();
					game_progress::player_has_won = 1;
					return 0;
					break;
				default:
					cout << "Please choose one of the numbered options" << endl;
				}

			} while (still_talking);

		return 0;
	}else { 
			cout << "\nDemon King: 'You are armed. Prepare to die'.\n";
			battle_between.fight(*this, p);
			if (health == 0)
				game_progress::boss_is_dead;
	 }
}
demon_king::~demon_king() {};
string demon_king::get_type() const { return type; };
int demon_king::add_health(int health_added) {
	int new_health = health + health_added;
	if (new_health < 0)
		health = 0;
	else if (new_health > 400)
		health = 400;
	else
		health = new_health;
	return 0;
}
int demon_king::get_health() {
	return health;
}
int demon_king::attacked(player& p, int base_damage) { 
	int attacks = rand() % 3 + 1;
	switch (attacks) {
	case 1:
		this->add_health(-3*(base_damage));
		cout << "You stabbed the demon king in the heart for " << 3*base_damage << " damage\n" << endl;
		break;
	case 2:
		this->add_health(-base_damage);
		cout << "You hit the demon king with a body shot for " << base_damage << " damage\n" << endl;
		break;
	case 3:
		cout << "The Demon King deflected your attack and took no damage\n" << endl;
		break;
	}
	return 0; 
};
int demon_king::attacking(player & p) { 
	//3 random attack choices
	int attacks{ 0 };
	int shield_defense{ 0 };
	if (p.check_for_item_name("shield"))
		shield_defense = p.get_item_by_name("shield").get_damage();
	if (health < 400) {
		attacks = rand() % 4 + 1;
		switch (attacks) {
		case 1:
			cout << "Demon King has replenished 50 health\n" << endl;
			this->add_health(50);
			break;
		case 2:
			p.add_health(-base_damage + shield_defense);
			cout << "Demon King attacked you for " << base_damage << " damage\n" << endl;
			if (p.check_for_item_name("shield"))
				cout << shield_defense << " damage absorbed by shield\n" << endl;
			break;
		case 3:
			cout << "Demon King: 'I'll go easy on you this round and give you a break'\n" << endl;
			break;		
		case 4:
			if (p.check_for_item_name("shield"))
				cout<<"The Demon King managed to attack past your shield\n";
			p.add_health(-base_damage);
			cout << "Demon King attacked you for " << base_damage << " damage\n" << endl;
			break;
		}
	}else{//if Demon King at full health
		attacks = rand() % 3 + 1;
		switch (attacks) {
		case 1:
			if (p.check_for_item_name("shield"))
				cout << "The Demon King managed to attack past your shield\n";
			p.add_health(-base_damage);
			cout << "Demon King attacked you for " << base_damage << " damage\n" << endl;
			break;
		case 2:
			cout << "Demon King: 'I'll go easy on you this round and give you a break'\n" << endl;
			break;
		case 3:
			p.add_health(-base_damage + shield_defense);
			cout << "Demon King attacked you for " << base_damage << " damage\n" << endl;
			if (p.check_for_item_name("shield"))
				cout << shield_defense << " damage absorbed by shield\n" << endl;
			break;
		}
	 }
	return 0; 
};
int demon_king::is_dead(player &p) {
	game_progress::player_has_won = 1;
	return true;
};

