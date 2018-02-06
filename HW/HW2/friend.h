/*************************************************************
    Project 2		CS2401		Spring 2017
	Jonathan Feige
	Friend header defines what a friend is.
**************************************************************/

#include<iostream>
#include<string>
#include "date.h"
#ifndef FRIEND_H
#define FRIEND_H


class Friend{
    public:
	Friend(Date d = Date(1,1,1900), std::string p = "VOID");
	
	std::string get_name()const {return name;}
	Date get_bday()const {return bday;}
	
	bool operator == (const Friend& other)const;
	bool operator != (const Friend& other)const;
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
   
   private:
	std::string name;
	Date bday;
};

std::istream& operator >>(std::istream& ins,Friend& f);
std::ostream& operator <<(std::ostream& outs,const Friend& f);

#endif

