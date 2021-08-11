#include "shaman.h"
shaman::shaman() {
	type = "shaman";
}
shaman::~shaman() {}
string shaman::get_type() const {
	return type;
}
int shaman::converse(player& p) {
	int options = 2;
	bool still_talking(true);
	//if dog is not yet found
	if (!game_progress::shaman_has_spoken) {
		cout << "Shaman: 'Muhm..Blah.. hhg..\n'" << endl;
		cout << '1' << "= " << "You alright?" << endl;
		cout << '2' << "= " << "Hey, I hear you're the shaman of the village, I've arrived here and I don't know why, can you help?" << endl;
		if (game_progress::player_has_bookmark) {
			options = 3;
			cout << '3' << "= " << "Does the name Arwyn mean anything to you?" << endl;
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
				cout << "The Shaman continues mumbling nonsense and beckons for you to leave\n";
				break;
			case 2:
				cout << "Shaman: 'hnnng... uhh.. If you want any help, try and find out why you might be here, \nbut I'm not wasting my time with fakers'" << endl;
				break;
			case 3:
				cout << "Shaman: 'Ah, so it is you.'\nPress any key to continue..." << endl;
				_getch();
				cout << "Shaman: '2000 years ago, the supernatural beings of this world were in a position to take over this village.\nWe thought they would, but then a martyr named Arwyn was bestowed upon our village.\n" << endl;
				_getch();
				cout << "'He was a natural diplomat, with enough power that the demons, vampires and whatever other creatures existed at the time bowed before him.'\n" << endl;
				_getch();
				cout<< "He made the Demon king sign a contract that meant they could never occupy our village in 2000 years.\nPress any key to continue...\n" << endl;
				_getch();
				cout << "'Problem is, that contract has just run out, and the demons have elected a right wing leader who wishes for nothing more than to occupy this land.'\n" << endl;
				_getch();
				cout << "Although Arwyn predicted this would happen, and so without telling the demons cast a spell on the contract so that when that time eventually came, a descendant of his would be pulled from history who has the capabilities to restore balance and order.\nThis must be you.'\nPress any key to continue...\n" << endl;
				_getch();
				cout << "'There is only one person who can get you into Hell to negotiate with the Demon King, and that is the locksmith.\n";
				cout << "Tell him I have sent you on a code red emergency.\n";
				_getch();
				cout << "I imagine this is the type of protocol - oriented language they will use in the future for emergencies'\nPress any key to continue...\n" << endl;
				_getch();
				cout << "'One more thing... I hear even the most fearsome of monsters can be bribed with what you least expect.. That might make your quest easier...'\nPress any key to leave and return to the village\n";
				_getch();
				game_progress::shaman_has_spoken = 1;
				still_talking = false;
				break;
			default:
				cout << "Please choose one of the numbered options" << endl;
			}
		} while (still_talking);
		return 0;
	}
	//Shaman quest completed
	else { cout << "Shaman: 'I give you my blessing Sir, hopefully you are the one to save us as prophecised'\n" << endl; return 0; }
}