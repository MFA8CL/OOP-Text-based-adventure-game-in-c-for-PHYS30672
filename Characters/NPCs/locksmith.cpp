#include "locksmith.h"
#include "NPC.h"
locksmith::locksmith() {;
	dialogue_options = 1;
	type = "locksmith";
}
locksmith::~locksmith() {

}
string locksmith::get_type()const {
	return type;
}
int locksmith::converse(player& p) {

	bool still_talking(true);
	cout << "\n" << "Hi im the locksmith, how can I help?\n" << endl;
	cout << '1' << " = " << "What's your business here?" << endl;
	if (game_progress::player_has_found_grating){
		dialogue_options = 2;
		if (!game_progress::shaman_has_spoken) {
			cout << '2' << " = " << "Do you have a key for the metal grating outside the village?" << endl;
		}else {
			cout << '2' << " = " << "I'm here on a code red summons from the Shaman. Do you have a key for the metal grating outside the village??" << endl;
		 }
	}
	cout << '0' << "= " << "End conversation" << endl;
	do {
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > dialogue_options || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter one of the given options" << endl;
		}
		switch (answer) {
		case 1:
			cout << "Locksmith: 'If you're buying a property or need a key for anything come to me and I'll see what I can do for you'" << endl;
			break;
		case 2:
			if (!game_progress::shaman_has_spoken) {
				cout << "I know of no such key" << endl;				
			}else {
				if (!game_progress::locksmith_has_given_key) {
					cout << "\nLocksmith: 'I hope you know what you're getting into here.' \nPress any key to continue...\n"<<endl;
					_getch();
					gift_item(p);
					game_progress::locksmith_has_given_key = 1;
					cout << "\n" << "Hi im the locksmith, how can I help?\n" << endl;
					cout << '1' << "= " << "What's your business here?" << endl;
					if (game_progress::player_has_found_grating) {
						dialogue_options = 2;
						if (!game_progress::shaman_has_spoken) {
							cout << '2' << "= " << "Do you have a key for the metal grating outside the village?" << endl;
						}else {
							cout << '2' << "= " << "I'm here on a code red summons from the Shaman. Do you have a key for the metal grating outside the village??" << endl;
						 }
					}
					cout << '0' << "= " << "End conversation" << endl;					
				 }else {
					cout << "Alright I've given you the key now, get outta here\n" << endl;
				  }
			}
			break;
		case 0:
			still_talking = false;
			break;
		default:
			cout << "Please choose one of the numbered options" << endl;
		}
	} while (still_talking);
	return 0;
};
void locksmith::gift_item(player& p) {
	shared_ptr<key> key_for_player = { make_shared<key>() };
	p.add_to_inventory(key_for_player);
	game_progress::player_has_key = 1;
	p.view_inventory();
}
