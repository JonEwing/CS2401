/*************************************************************
    Project 2		CS2401		Spring 2017
	Jonathan Feige
	Friend footer
**************************************************************/

    

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "friend.h"
#include "fbfriends.h"
#include "date.h"
using namespace std;

	Friend :: Friend(Date d, string n){
	bday = d;
	name = n;
	}
	
	bool Friend :: operator == (const Friend& other)const{
		if (name == other.name && bday == other.bday)
		{return true;
	}
	else {
		return false;
	}
	
	}
	
	bool Friend :: operator != (const Friend& other)const{
				if (name == other.name && bday == other.bday)
		{return false;
	}
	else {
		return true;
	}
	}
	
	void Friend :: input(std::istream& ins){
		if(&ins == &cin){
		cout<<"\nEnter Name\n";
		while(ins.peek()=='\n' || ins.peek()=='\r'){
			ins.ignore();
		}
		getline(ins, name);
		cout<<"\nEnter Birthday\n";
		ins >> bday;
		cout<<"\n";
		}
	
		else{
		while(ins.peek()=='\n' || ins.peek()=='\r'){
			ins.ignore();
		}
		getline(ins, name);
		ins>> bday;
		}
	}
	
	void Friend :: output(std::ostream& outs)const{
		outs << name;
		cout <<"\n";
		outs << bday;
	}
	
	ostream& operator << (ostream& outs, const Friend& c){
        c.output(outs);
        return outs;
	}

	istream& operator >> (istream& ins, Friend& c){
       c.input(ins);
       return ins;
	}
   