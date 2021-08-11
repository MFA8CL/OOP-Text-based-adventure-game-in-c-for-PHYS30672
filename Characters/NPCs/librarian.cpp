#include "librarian.h"
librarian::librarian() {
	shared_ptr<physics_book> youngandfreedman = { make_shared<physics_book>() };
	shared_ptr<wildlife_book> wildlife = { make_shared<wildlife_book>() };
	bookshelf.push_back(youngandfreedman);
	bookshelf.push_back(wildlife);
	shared_ptr<demon_book> demons = { make_shared<demon_book>() };
	shared_ptr<boat_book> boatracing = { make_shared<boat_book>() };
	shared_ptr<of_mice_and_men> OMAM = { make_shared<of_mice_and_men>() };
	members_bookshelf.push_back(demons);
	members_bookshelf.push_back(boatracing);
	members_bookshelf.push_back(OMAM);
	type = "librarian";
}
librarian::~librarian() {
}
string librarian::get_type()const {
	return type;
}
void librarian::view_titles(){
	cout << "\nTITLES: \n" << endl;
	for (unsigned int i{ 0 }; i < bookshelf.size(); ++i) {

		cout << bookshelf[i]->get_title() << " (press " << i + 1 << " to read)" <<endl;
	}
}
void librarian::view_member_titles() {
	cout << "\nTITLES: \n" << endl;
	for (unsigned int i{ 0 }; i < members_bookshelf.size(); ++i) {

		cout << members_bookshelf[i]->get_title() << " (press " << i + 1 << " to read)" << endl;
	}
}
int librarian::check_membership(player& p) {

	if (game_progress::player_is_library_member == 0) {
		cout << "It costs 10 gold to purchase a members card. Press 1 to purchase or press 0 to go back" << endl;
		int choice;
		while ((cin >> choice).fail() || cin.peek() != '\n' || choice > 1 || choice < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter one of the given options" << endl;
			}
		switch (choice) {
		case 0:
			break;
		case 1:
			if (p.get_gold() < 10) {
				cout << "Insufficient funds!" << endl;
				return 0;
			}
			else { p.add_gold(-10); game_progress::player_is_library_member=1;  }
			break;
		}		
	}
	else { return 0; }
	return 0;
};
int librarian::in_public_section(player&p) {	
	this->view_titles();
	cout << "Press 0 to leave the public section of the library" << endl;
	bool still_in_public_section = true;
	do {		
		int book_to_read;
		while ((cin >> book_to_read).fail() || cin.peek() != '\n' || book_to_read > 3 || book_to_read < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please select one of the given titles" << endl;
		}
		if (book_to_read == 0) { still_in_public_section = false; }
		else { read_a_public_book(book_to_read);}		
	} while (still_in_public_section);
	return 0;
}

int librarian::in_members_section(player& p) {	
	if (game_progress::player_is_library_member == 0) { return 0; }
	else {
		bool still_in_member_section = true;
		do {
			this->view_member_titles();
			cout << "Press 0 to leave the members section of the library\n" << endl;
			int book_to_read;
			while ((cin >> book_to_read).fail() || cin.peek() != '\n' || book_to_read > 3 || book_to_read < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please select one of the given titles" << endl;
			}
			if (book_to_read == 0) {
				still_in_member_section = false; 
			}
			else if (book_to_read == 1 && game_progress::player_has_bookmark == 0) {
				cout << "Inside the book you find a bookmark, with the name ARWYN scrawled in what looks like blood.\n" << endl;
				shared_ptr<bookmark> bookmark_clue = { make_shared<bookmark>() };
				p.add_to_inventory(bookmark_clue);
				game_progress::player_has_bookmark = 1;
				p.view_inventory();
				cout << "Press any key to continue and read the page the bookmark was in\n";
				_getch();
				read_a_member_book(book_to_read);
				cout << "\nPress any key to return to the members section of the library\n" << endl;
				_getch();			
			}
			else {
				read_a_member_book(book_to_read);
				cout << "\nPress any key to return to the members section of the library\n" << endl;
				_getch();
			}
		} while (still_in_member_section);
	}
	return 0;
}

int librarian::converse(player& p) {
	bool still_talking(true);	
	do {
		cout << "\nLibrarian: " << "Hi and welcome to the library, how can I help today?\n" << endl;
		cout << '1' << "= " << "Borrow a book from the public shelf" << endl;
		cout << '2' << "= " << "Visit the members room" << endl;
		cout << '0' << "= " << "Leave" << endl;
		int answer;
		while ((cin >> answer).fail() || cin.peek() != '\n' || answer > 2 || answer < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please select one of the given options" << endl;
		}
		switch (answer) {
		case 1:
			this->in_public_section(p);
			break;
		case 2:
			this->check_membership(p);
			this->in_members_section(p);
			break;
		case 0:
			still_talking = false;
			break;
		}
	} while (still_talking);
	return 0;
};
void librarian::read_a_public_book(int i) {
	bookshelf[i-1]->read();
}
void librarian::read_a_member_book(int i) {
	members_bookshelf[i-1]->read();
}




