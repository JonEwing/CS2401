/*************************************************************
    Project 2		CS2401		Spring 2017
	Jonathan Feige
	FBFriend header makes a collection of friends
**************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include "friend.h"
#ifndef FBFRIENDS_H
#define FBFRIENDS_H

class FBFriends{
    public:
	FBFriends();

	//The functions known as the Big 3
	~FBFriends();
	FBFriends(const FBFriends& other);
	void operator = (const FBFriends& other);

	// Functions for the internal iterator
	
	void start(){current_index=0;}
	void advance(){current_index++;};
	bool is_item(){return current_index < used;}
	Friend current(){return data[current_index];}
	void remove_current();
	void insert(const Friend& f);
	void attach(const Friend& f);
	void show_all(std::ostream& outs)const;
	void bday_sort();
	
	Friend find_friend(const std::string& name)const;
	bool is_friend(const Friend& f) const;
	void load(std::ifstream& ins);
	void save(std::ostream& outs);
	
    private:
	void resize(); // increases the capacity of the container by 5
	Friend *data;
	Friend *tmpd;
	int used;
	int capacity;
	int current_index;
};

#endif



