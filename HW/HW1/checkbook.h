/***********************************************************************
	HW 1 header Checkbook
	This program is desgined to keep track of your checks that are enterd
	Jonathan Feige			
	September 2017
	
*************************************************************************/


#include <iostream>
#include<fstream>
#include <ctype.h>
#include "check.h"

#ifndef SOMETHING
#define SOMETHING

#endif

class Checkbook{
	public :
	
	static const size_t CAPACITY = 200;
	
	double get_bal()const {return bal;}
	size_t gey_used()const {return USED;}
	std::string get_name()const {return name;}
	size_t gey_capacity()const {return CAPACITY;}
	
	Checkbook(std::string p);
	void load_from_file(std::ifstream& ins);
	void deposit(double a);
	void write_check(std::istream& cin);
	double get_balance();
	void show_all(std::ostream& cout);
	void remove(int);
	void number_sort();
	void payto_sort();
	void date_sort();
	void show(std::string);
	double average();
	void save(std::ofstream& ofs);
	
	private:
	std::string name;
	double bal = 0;
	Check checkbook[CAPACITY];
	size_t USED = 0;
	
	
};