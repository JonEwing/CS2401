/***********************************************************************
    HW 1 header header
	This program is desgined to help write a single check
	Jonathan Feige			
	September 2017
	
************************************************************************/

#ifndef CHEESEY
#define CHEESEY

#include<iostream>
#include<string>
#include "date.h"

class Check{
    public:
	Check(Date d = Date(1,1,1900), std::string p = "VOID", 
		int num = 1, double amt = 0);
    // Input and output functions
	void write_check(std::istream& ins);
	void output(std::ostream& outs)const;
    // Accessor functions
	double get_amount()const {return amount;}	 
        Date get_date()const {return date;}
	std::string get_payto()const {return payto;}
	int get_num()const {return checknum;}
	
    private:
	int checknum;
	double amount;
	Date date;
	std::string payto;
};

std::ostream& operator << (std::ostream& outs, const Check& c);

std::istream& operator >> (std::istream& ins, Check& c);


#endif
