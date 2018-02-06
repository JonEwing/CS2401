/***********************************************************************
	HW 1 footer Checkbook
	This program is desgined to keep track of your checks that are enterd
	Jonathan Feige			
	September 2017
	
*************************************************************************/

#include "checkbook.h"
#include<iostream>
#include<fstream>

using namespace std;

Checkbook :: Checkbook (string p){
name = p;
}


void Checkbook::load_from_file(ifstream& ifs){
		ifs >> bal;
		ifs >> checkbook[USED];
		while(!ifs.eof()){
			USED++;
			ifs >> checkbook[USED];
		}
}


void Checkbook :: deposit(double a){
	bal = bal + a;
}

void Checkbook :: write_check(std::istream& ins){
	Check tmp;
	if ( USED <= CAPACITY - 1)
	{
	tmp.write_check(ins);
	}
	else {
		cout<< "No more room for checks\n";
		}
	checkbook[USED+1] = tmp;
	bal = bal - tmp.get_amount();
	cout <<endl;
	USED++;
		for(int i =0; i<USED;i++){
		if (checkbook[i].get_num() == tmp.get_num()){
			cout<<"Not a valid check\n";
			USED--;
	}
}
}

double Checkbook :: get_balance(){
	return bal;
}

void Checkbook :: show_all(std::ostream& cout){
	for(int i = 0; i <= USED ; i++)
	{
		cout << endl;
		cout << checkbook[i].get_num();
		cout << endl;
		cout << checkbook[i].get_amount();
		cout << endl;
		cout << checkbook[i].get_date();
		cout << endl;
		cout << checkbook[i].get_payto();
		cout << endl;
	}
}

void Checkbook :: remove(int pos){
	if (pos >= USED)
	{
	cout<< "Not a valid number";
	}
	else {
		bal = checkbook[pos].get_amount()+bal;
		checkbook[pos] = checkbook[USED];
		USED--;
		}
	
}

void Checkbook :: number_sort(){
	bool done = false;
	size_t i;
	size_t a=0;
	Check tmp[2];
	while(!done)
	{
		done = true;
		for (i=0; i <USED ; ++i)
		{	if(checkbook[i].get_num() > checkbook[i+1].get_num())
			{	tmp[a] = checkbook[i];
				checkbook[i] = checkbook[i+1];
				checkbook[i+1] = tmp[a];
				done = false;
			}
		}
	}
}
			

void Checkbook :: payto_sort(){
	bool done = false;
	size_t i;
	size_t a=0;
	Check tmp[2];
	while(!done)
	{
		done = true;
		for (i=0; i <USED ; ++i)
		{	if(checkbook[i].get_payto() > checkbook[i+1].get_payto())
			{	tmp[a] = checkbook[i];
				checkbook[i] = checkbook[i+1];
				checkbook[i+1] = tmp[a];
				done = false;
			}
		}
	}
}

void Checkbook :: date_sort(){
	bool done = false;
	size_t i;
	size_t a=0;
	Check tmp[2];
	while(!done)
	{
		done = true;
		for (i=0; i <USED  ; ++i)
		{	if(checkbook[i].get_date() > checkbook[i+1].get_date())
			{	tmp[a] = checkbook[i];
				checkbook[i] = checkbook[i+1];
				checkbook[i+1] = tmp[a];
				done = false;
			}
		}
	}
}

void Checkbook :: show(std::string a){
	size_t i =0;
	std::string payto;
	cin>> payto;
		while (i < USED){
		{	if(checkbook[i].get_payto() == payto)
			cout << endl;
			cout << checkbook[i].get_num();
			cout << endl;
			cout << checkbook[i].get_amount();
			cout << endl;
			cout << checkbook[i].get_date();
			cout << endl;
			cout << checkbook[i].get_payto();
			cout << endl;
		}
		i++;
		}
}

double Checkbook :: average(){
	bool done = false;
	size_t i;
	double tmp, total = 0;
		for (i=0; i <=USED ; ++i)
		{	
			tmp = checkbook[i].get_amount();
			total = tmp+ total;
		}
		total = total / i;
		cout.precision(2);
		cout << "The average check value is "<<fixed;
		return total;
}

void Checkbook :: save(std::ofstream& ofs){
	ofs << bal;
	for (size_t i = 0;i <= USED ;i++){
			ofs << endl;
			ofs << checkbook[i].get_num();
			ofs << endl;
			ofs << checkbook[i].get_date();
			ofs << endl;
			ofs << checkbook[i].get_payto();
			ofs << endl;
			ofs << checkbook[i].get_amount();
	}
}