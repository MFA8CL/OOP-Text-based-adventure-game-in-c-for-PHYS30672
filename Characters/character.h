#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "item.h"
using namespace std;
class character
{protected:
	int health;
	int gold;
	int base_damage;
	string type;
	//Protected as we do not want to create characters directly
	character() {};
	virtual ~character() {};
public:
	//Virtual functions which will need inheriting for character classes to interact with one another
	virtual string get_type() const =0;
	virtual void set_health(int health){ return; }
};

