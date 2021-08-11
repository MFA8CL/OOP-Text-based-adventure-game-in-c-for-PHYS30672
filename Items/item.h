#pragma once
#include <string>
using namespace std;
class item
{protected:
	string item_type;
	string item_name;
	int damage;
	int health;
public:
	item() {};
	item(string type, string name);
	~item() {};
	string get_item_type();
	string get_item_name();
	int get_health();
	int get_damage();
};

