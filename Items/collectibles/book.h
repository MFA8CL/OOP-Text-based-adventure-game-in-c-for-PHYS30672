#pragma once
#include "item.h"
#include <iostream>
class book :
	public item
{protected:
	string title;
	string book_info;
	book() {};
	virtual ~book() {};
public:
	string get_title() { return title; };
	virtual void read()=0;
};
class demon_book: 
	public book
{public:
	demon_book();
	~demon_book() {};
	void read();
};
class wildlife_book :
	public book
{public:
	wildlife_book();
	~wildlife_book() {};
	void read();
};
class physics_book :
	public book
{public:
	physics_book();
	~physics_book() {};
	void read();
};
class boat_book :
	public book
{
public:
	boat_book();
	~boat_book() {};
	void read();
};
class of_mice_and_men :
	public book
{
public:
	of_mice_and_men();
	~of_mice_and_men() {};
	void read();
};