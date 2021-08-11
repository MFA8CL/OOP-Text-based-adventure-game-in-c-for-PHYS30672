#include "combat_handler.h"
combat_handler::combat_handler(){}
combat_handler::~combat_handler(){}
int combat_handler::fight(enemy &e, player& p) {
	int potion_counter{ 0 };
	int weapon_counter{ 0 };
	int extra_damage{ 0 };
	int weapon_damage{ 0 };
	int potion_damage{ 0 };
	int player_attack_damage{ 0 };
	int damage_option{ 0 };
	int health_option{ 0 };
	int shield_option{ 0 };
	int sword_option{ 0 };
	int longsword_option{ 0 };
	int demon_slayer_option{ 0 };
	int shield_defense{ 0 };
	if (p.check_for_item_name("shield"))
		shield_defense = p.get_item_by_name("shield").get_damage();
	bool still_fighting = true;
	do {
		cout << "\nPlayer health = " << p.get_health() << "\n" << endl;
		cout <<e.get_type()<< " health = " << e.get_health() << "\n" << endl;
		cout << "Press any key to continue\n"<<endl;
		_getch();
		//do u want to use a potion?? available potions = list
		p.view_items_by_type("potion");
		if (p.check_for_item_name("health potion")) {
			potion_counter++;
			health_option = potion_counter;
			cout << "Press " << potion_counter << " to use health potion" << endl;
		}
		if (p.check_for_item_name("shield potion")) {
			potion_counter++;
			shield_option = potion_counter;
			cout << "Press " << potion_counter << " to use shield potion" << endl;
		}
		if (p.check_for_item_name("damage potion")) {
			potion_counter++;
			damage_option = potion_counter;
			cout << "Press " << potion_counter << " to use damage potion" << endl;
		}
		cout << "Press 0 to skip potions\n";
		int potion_choice;
		while ((cin >> potion_choice).fail() || cin.peek() != '\n' || potion_choice > potion_counter || potion_choice < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter one of the given options" << endl;
		}
		if (potion_choice == 0) {}
		else if (potion_choice == health_option) {
			p.add_health(p.get_item_by_name("health potion").get_health());
			p.remove_1_item_by_name("health potion");
		}else if (potion_choice == shield_option) {
			p.add_health_boost(p.get_item_by_name("shield potion").get_health());
			p.remove_1_item_by_name("shield potion");
		 }else if (potion_choice == damage_option) {
			potion_damage = p.get_item_by_name("damage potion").get_damage();
			p.remove_1_item_by_name("damage potion");
		  }
		//choose your weapon
		cout << "\n";
		p.view_items_by_type("weapon");
		if (p.check_for_item_name("sword")) {
			weapon_counter++;
			sword_option = weapon_counter;
			cout << "Press " << weapon_counter << " to use sword" << endl;
		}
		if (p.check_for_item_name("longsword")) {
			weapon_counter++;
			longsword_option = weapon_counter;
			cout << "Press " << weapon_counter << " to use longsword" << endl;
		}
		if (p.check_for_item_name("demon slayer")) {
			weapon_counter++;
			demon_slayer_option = weapon_counter;
			cout << "Press " << weapon_counter << " to use Demon Slaying dagger" << endl;
		}
		cout << "Press 0 to attack with your bare hands\n";
		int weapon_choice;
		while ((cin >> weapon_choice).fail() || cin.peek() != '\n' || weapon_choice > weapon_counter || weapon_choice < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter one of the given options" << endl;
		}
		if (weapon_choice == 0) {}
		else if (weapon_choice == sword_option) 
			weapon_damage = p.get_item_by_name("sword").get_damage();
		else if (weapon_choice == longsword_option)
			weapon_damage = p.get_item_by_name("longsword").get_damage();
		else if (weapon_choice == demon_slayer_option)
		weapon_damage = p.get_item_by_name("demon slayer").get_damage();
		//player attacks	
		player_attack_damage = p.get_base_damage() + weapon_damage + potion_damage;
		e.attacked(p, player_attack_damage);
		cout << "Press any key to continue\n" << endl;
		_getch();
		//check if NPC dead, if so break loop
		if (e.get_health() == 0) {
			cout << "You have killed the "<<e.get_type()<<".\n" << endl;
			//win condition depends on the NPC
			e.is_dead(p);
			still_fighting = false;
			return 0;
		}else {
			//NPC attacks player
			e.attacking(p);
		 }
		//check player still alive, if so repeat this loop
		if (p.get_health() == 0) {
			cout << "You have been killed by the "<<e.get_type()<<"\n" << endl;
			still_fighting = false;
			return 0;
		}
		//reset values for a new round
		potion_counter = 0;
		weapon_counter = 0;
		extra_damage = 0;
		weapon_damage = 0;
		potion_damage = 0;
		player_attack_damage = 0;
		damage_option = 0;
		health_option = 0;
		shield_option = 0;
		sword_option = 0;
		longsword_option = 0;
		demon_slayer_option = 0;
	} while (still_fighting);
	return 0;
}