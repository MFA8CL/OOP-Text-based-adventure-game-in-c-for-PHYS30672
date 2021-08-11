#pragma once
#include "NPC.h"
#include "bookmark.h"
#include "game_progress.h"
#include <conio.h>
class librarian :
	public NPC
{private:
	vector<shared_ptr<book>> bookshelf;
	vector<shared_ptr<book>> members_bookshelf;
	int player_has_bookmark{0};
public:
	librarian();
	void view_titles();
	void read_a_public_book(int i);
	void read_a_member_book(int i);
	int in_public_section(player& p);
	int in_members_section(player& p);
	int check_membership(player& p);
	void view_member_titles();
	int converse(player& p);
	~librarian();
	string get_type() const;
};

