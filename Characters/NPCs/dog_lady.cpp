#include "dog_lady.h"
#include "NPC.h"
dog_lady::dog_lady() {
	type = "dog lady";
	health = 100;
}
int dog_lady::converse(player& p) {
	int options = 2;
	bool still_talking(true);
	//if dog is not yet found
	if (!game_progress::dog_has_been_given) {
		cout << "Doreen: '*Sniffle*...Please Sir, can you help me find my dog??'\n" << endl;
		cout << '1' << "= " << "No, sorry" << endl;
		cout << '2' << "= " << "What's happened??" << endl;
		if (game_progress::player_has_dog) {
			options = 3;
			cout << '3' << "= " << "Hey, is this your dog? I found him in the forest" << endl;
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
				cout << "Doreen: 'Oh.... okay.. *sniffle*... have a good day..'\n" << endl;
				break;
			case 2:
				cout << "Doreen: 'Snu...*sobs*...Snuggles...\nHe was the love of the town, such a cute dog...\nI don't know where he went but if he went in the forest he's probably dead, it's too dangerous for him..'" << endl;
				break;
			case 3:
				cout << "Doreen: 'Oh my god!!!! Snuggles!! You found him!! Thank you so much!!!\nThis experience has made me realise how little material goods mean to me...\n Please, take this monetary reward of 700 gold!'\n" << endl;
				p.add_gold(700);
				cout << "700 gold added to inventory\nPress any key to continue..." << endl;
				_getch();
				cout << "\nDoreen: 'Thanks again sir, I'm going to go to the library and find every piece of Marxist literature I can!!!!!!!'\n" << endl;
				game_progress::dog_has_been_given = 1;
				still_talking = false;
				break;
			default:
				cout << "Please choose one of the numbered options" << endl;
			}
		} while (still_talking);
		return 0;
	}
	//Dog quest completed
	else { 
		cout << "Doreen: Hello hero!! ;) I'm halfway through the communist manifesto!!!!\nCan't wait to get onto Das Capital!!:)))))))\nPress any key to return to the village\n" << endl; _getch; 
		return 0; 
	}
}
dog_lady::~dog_lady() {};
string dog_lady::get_type() const { return type; };
