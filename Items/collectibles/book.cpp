#include "book.h"
demon_book::demon_book(){
	title = "The Mythology of Demons and the supernatural in the Shedim region";

}
void demon_book::read() {
	cout << "\nPage 57: 'As it became clear the rule of the Demon King and the other supernatural beings was inevitable,\nit would be up to Arwyn, the leader, to restore peace and balance to the Shedim village.\nThose still remaining in the village who are descended from fortune tellers claim this story has a factual basis \nin History, and that it is prophecised that when order between these realms is lost, \na saviour shall arrive unexpectedly..'\n" << endl;
}
physics_book::physics_book() {
	title = "University Physics with modern Physics";
};
void physics_book::read() {
	cout << "Looks way too boring" << endl;
}
wildlife_book::wildlife_book() {
	title = "How to make your garden exciting in 2020";
};
void wildlife_book::read() {
	cout << "Looks pretty useless" << endl;
}
boat_book::boat_book() {
	title = "Boat racing for beginners";
};
void boat_book::read() {
	cout << "Can't see why this is here since this is a village with no water but doesn't look useful anyway" << endl;
}
of_mice_and_men::of_mice_and_men() {
	title = "Of Mice and Men";
}
void of_mice_and_men::read() {
	cout << "There is a piece of graffiti written at the front of the book in ink that says: 'Lenny dies'." << endl;
}