/***********************************************************************
	HW 1 footer check
	This program is desgined to help write a single check
	Jonathan Feige			
	September 2017
	
*************************************************************************/
#include "check.h"
#include<iostream>
#include<fstream>
using namespace std;

    Check::Check(Date d, string p, int num,double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
	}
    // Input and output functions
    void Check::write_check(std::istream& ins){
		if(&ins == &cin){
		cout<<"Enter Check number\n";
		ins >> checknum;
		cout<<"\nEnter Check date\n";
		ins >> date;
		cout<<"\nEnter Check payto\n";
		while(ins.peek()=='\n' || ins.peek()=='\r'){
			ins.ignore();
		}
		getline(ins, payto);
		cout<<"\nEnter Check amount\n";
		ins>> amount;
		cout<<"\n";
		}
	
		else{
		ins >> checknum;
		ins >> date;
		while(ins.peek()=='\n' || ins.peek()=='\r'){
			ins.ignore();
		}
		getline(ins, payto);
		ins>> amount;
		cout<<"\n";
		}
	
    	} 
    void Check::output(std::ostream& outs)const{
	if (&outs == &cout){
	outs << checknum<< amount << date << payto << endl;
		}
		else{
			cout << "The check number is " << checknum << "\n";
			cout << "The amount payed is" << amount << "\n";
			cout << "The date is " << date << "\n";
			cout << "The check was payed to, "<< payto << "\n";
		}
	}
			

ostream& operator << (ostream& outs, const Check& c){
        c.output(outs);
        return outs;
}

istream& operator >> (istream& ins, Check& c){
        c.write_check(ins);
        return ins;
}


