/*************************************************************
    Project 2		CS2401		Spring 2017
	Jonathan Feige
	FBFriend footer
**************************************************************/
    

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "friend.h"
#include "fbfriends.h"
using namespace std;

	FBFriends :: FBFriends(){
		capacity = 5;
		used = 0;
		data = new Friend[capacity];
	}
	
	FBFriends :: ~FBFriends(){
		delete []data;
	}
	
	FBFriends :: FBFriends(const FBFriends& other){
		used = other.used;
		capacity = other.capacity;
		data = new Friend[capacity];
		copy(other.data, other.data+used, data);
	}
	
	void FBFriends :: operator = (const FBFriends& other){
		if(this == &other){
		return;
		}
		
	if(capacity != other.capacity){
		delete []data;
		capacity = other.capacity;
		data = new Friend[capacity];
	}
	used = other.used;
	copy(other.data, other.data+used, data);
	}

	// Functions for the internal iterator
	 
	void FBFriends :: remove_current(){
		data[current_index] = data[used];
		used--;
		}
	
	void FBFriends :: insert(const Friend& f){
		for(int i = 0; i <= used ; i++){
			if(data[i].get_name() == f.get_name() && data[i].get_bday() == f.get_bday() ){
				cout << "Name already used\n";
				return;
			}
		}
		
		if(!is_friend(f))
		{
			used++;
			if (used == capacity-1){
			resize();
			}
			data[used]=f;
		}
		int tmp = used;
			for(int i = used; i > current_index; --i)
				{ data[i] = data[i-1];
				}
				data[current_index]=f;
		}
		
	void FBFriends :: attach(const Friend& f){
		for(int i = 0; i <= used ; i++){
		if(data[i].get_name() == f.get_name() && data[i].get_bday() == f.get_bday() ){
				cout << "Name already used\n";
				return;
			}
		}
		if(!is_friend(f))
		{
			used++;
			if (used == capacity-1)
			{
			resize();
			}
			data[used]=f;
		}
		if (used+1 == capacity){
		resize();
		}
		else{
			for(int i = used; i > current_index + 1; --i)
				{ data[i] = data[i-1];
				}
				data[++ current_index] = f;
		}
	}
	
	void FBFriends :: show_all(std::ostream& outs)const{
		for(int i = 0; i <= used ; i++)
	{
		if(data[i].get_name() != "VOID")
		{
		cout << endl;
		cout << data[i].get_name();
		cout << endl;
		cout << data[i].get_bday();
		cout << endl;
		}
		else{
			cout << " ";
		}
	}
	}
	
	void FBFriends :: bday_sort(){
	bool done = false;
	size_t i;
	size_t a=0;
	Friend tmp[2];
	while(!done)
	{
		done = true;
		for (i=0; i <=used-1  ; ++i)
		{	if(data[i].get_bday() > data[i+1].get_bday())
			{	tmp[a] = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp[a];
				done = false;
			}
		}
	}
	}
	
	Friend FBFriends :: find_friend(const std::string& name)const{
		int i;
		for( i = 0; i<= used; ++i)
		{
			if( name == data[i].get_name())
			{
				return data[i];
			}
			if(i = used){
				cout << "No Friend\n";
				return data[used + 2];
			}
		}
		
	}
	
	bool FBFriends ::  is_friend(const Friend& f) const{
		for (int i=0; i <used; ++i){	
		if(data[i].get_name() == f.get_name() && data[i].get_bday() == f.get_bday()){
		return true;
		}
		
		else{
		return false;
		}
		}
	}
	
	void FBFriends ::  load(std::ifstream& ins){
	
	ins >> data[used];
	while(!ins.eof()){
	if (used == capacity-1){
	resize();
	}
	++used;
	ins >> data[used];
	}
	}
	
	
	
	void FBFriends :: save(std::ostream& outs){
		for (size_t i = 0;i <= used ;i++){
			outs << data[i].get_name();
			outs << endl;
			outs << data[i].get_bday();
			outs << endl;
		}
	}
	
    void FBFriends :: resize(){
		Friend *tmpd;
		capacity = capacity + 5;
		tmpd = new Friend[capacity];
		copy(data, data+used+1, tmpd);
		delete []data;
		data = tmpd;
	}
	