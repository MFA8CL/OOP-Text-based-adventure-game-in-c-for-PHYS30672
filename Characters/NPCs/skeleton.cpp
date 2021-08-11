#include "skeleton.h"
skeleton::skeleton() {
	type = "skeleton";
	health = 100;
	base_damage = 60;
}
int skeleton::converse(player& p) {
	if (game_progress::skeleton_is_dead) {
		cout<<"Skeleton is dead\n"<<endl;
		return 0;
	}
	combat_handler battle_between;
	int options = 2;
	bool still_talking(true);
	//if milk is not yet given
	if (!game_progress::skeleton_has_milk) {
		cout << "The room around is dimly lit with fire lamps attached to the walls.\n"; cout << "You see an assortment of bones and remains on a floor of stained dirt and gravel, and in front of a door at the back of the room is a full sized skeleton.\nPress any key to continue\n";
		_getch();
		cout << "\nThe skeleton starts moving and begins to approach you\nPress any key to continue\n" << endl;
		_getch();
		cout << "\nSkeleton: I am the skeleton guard of this region, you will have to defeat me to pass\n'" << endl;
		cout << '1' << "= " << "Try and reason with the skeleton" << endl;
		cout << '2' << "= " << "Fight the skeleton" << endl;
		if (game_progress::player_has_milk) {
			options = 3;
			cout << '3' << "= " << "Hey man, your bones are looking kinda brittle... Do you need any milk??" << endl;
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
				cout << "Skeleton: 'Try and talk me down if you wish but you're getting sliced up fam'\n" << endl;
				break;
			case 2:
				//fight(p);				
				battle_between.fight(*this, p);
				if (p.get_health() == 0||game_progress::skeleton_is_dead) { still_talking = false; }
				break;
			case 3:
				cout << "Skeleton: 'Uhh... yeah to be fair mate my bones have been super brittle recently, I'd love that'\n" << endl;
				cout << "Milk given to skeleton\n" << endl;
				p.remove_items_by_name("milk");
				game_progress::skeleton_has_milk = 1;
				cout << "Press any key to continue\n" << endl;
				_getch();
				return 0;
				break;
			default:
				cout << "Please choose one of the numbered options" << endl;
			}
		} while (still_talking);
		return 0;
	}
	else { cout << "Ay seriously thanks for the milk man, it's long hours down here in hell and it's not a great climate for the old bones ya know\nGood luck on your journey!!!!\n" << endl; return 0; }
}
skeleton::~skeleton() {};
string skeleton::get_type() const { return type; };
int skeleton::add_health(int health_added) {

	int new_health = health + health_added;

	if (new_health < 0)
		health = 0;
	else
		health = new_health;
	return 0;
}
int skeleton::get_health() {
	return health;
}
int skeleton::attacked(player& p, int base_damage) {
	add_health(-base_damage);
	cout << "You attacked the skeleton for " << base_damage << " damage\n" << endl;
	return 0;
};
int skeleton::attacking(player& p) {
	int attacks = rand() % 3 + 1;
	int shield_defense{ 0 };
	if (p.check_for_item_name("shield"))
		shield_defense = p.get_item_by_name("shield").get_damage();
	switch (attacks) {
	case 1:
		p.add_health(-base_damage);
		cout << "Skeleton attacked you for " << base_damage << " damage\n" << endl;
		if (p.check_for_item_name("shield"))
			shield_defense = p.get_item_by_name("shield").get_damage();
		cout << shield_defense << " damage absorbed by shield\n" << endl;
		break;
	case 2:
		cout << "You managed to evade the Skeleton's attack and take no damage\n" << endl;
		break;	
	case 3:
		p.add_health(-base_damage);
		if (p.check_for_item_name("shield"))
			cout << "Skeleton managed to attack past your shield\n";
		cout << "Skeleton attacked you for " << base_damage << " damage\n" << endl;		
		break;
	}
	return 0;
};
int skeleton::is_dead(player& p) {
	shared_ptr<longsword> longsword_for_player = { make_shared<longsword>() };
	cout << "Skeleton dropped a longsword\n" << endl;
	p.add_to_inventory(longsword_for_player);
	p.view_inventory();
	game_progress::skeleton_is_dead = 1;
	return 0;
};

