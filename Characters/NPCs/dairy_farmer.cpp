#include "dairy_farmer.h"
dairy_farmer::dairy_farmer() {

	type = "dairy farmer";
}
dairy_farmer::~dairy_farmer() {

}
string dairy_farmer::get_type()const {
	return type;
}
int dairy_farmer::converse(player& p) {
	bool still_talking(true);
	cout << "\n" << "Dairy farmer: 'Hello there! Welcome to the dairy farm, we got a selection of dairy products and suncream, \nit's hot out here on the farm!'\n" << endl;
	cout << '0' << " = " << "Purchase a bottle of milk (5 gold)" << endl;
	cout << '1' << " = " << "Purchase a sunscreen bottle (10 gold)" << endl;
	cout << '2' << " = " << "Purchase a milkshake (7 gold)" << endl;
	cout << '3' << " = " << "End conversation" << endl;
	do {
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > 3 || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter one of the given options" << endl;
		}
		switch (answer) {
		case 0:
			if (p.get_gold() < 5) {
				cout << "Insufficient funds!" << endl;
			}
			else {
				gift_item(p, "milk", 5);
				game_progress::player_has_milk = 1;		
				cout << "\n"<<"0" << " = " << "Purchase a bottle of milk (5 gold)" << endl;
				cout << '1' << " = " << "Purchase a sunscreen bottle (10 gold)" << endl;
				cout << '2' << " = " << "Purchase a milkshake (7 gold)" << endl;
				cout << '3' << " = " << "End conversation" << endl;
			}
			break;
		case 1:
			if (p.get_gold() < 10) {
				cout << "Insufficient funds!" << endl;
			}
			else {
					gift_item(p, "sunscreen", 10);
					game_progress::player_has_sunscreen = 1;
					cout << "\n" << "0" << " = " << "Purchase a bottle of milk (5 gold)" << endl;
					cout << '1' << " = " << "Purchase a sunscreen bottle (10 gold)" << endl;
					cout << '2' << " = " << "Purchase a milkshake (7 gold)" << endl;
					cout << '3' << " = " << "End conversation" << endl;
				}
			break;
		case 2:
			if (p.get_gold() < 7) {
				cout << "Insufficient funds!" << endl;
			}
			else {
				gift_item(p, "milkshake", 7);
				cout << "\n"<<"0" << " = " << "Purchase a bottle of milk (5 gold)" << endl;
				cout << '1' << " = " << "Purchase a sunscreen bottle (10 gold)" << endl;
				cout << '2' << " = " << "Purchase a milkshake (7 gold)" << endl;
				cout << '3' << " = " << "End conversation" << endl;

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
void dairy_farmer::gift_item(player& p, string type, int cost) {
	shared_ptr<item> dairyitem = { make_shared<item>("accessory", type) };
	p.add_to_inventory(dairyitem);
	p.add_gold(-cost);
	p.view_inventory();
	cout << "PLAYER GOLD = " << p.get_gold() << endl;
}



