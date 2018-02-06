/**********************************************************************
 Lab11    CS2401    Spring 2017
    Jonathan Feige
    Chore footer
**********************************************************************/
#include<cstdlib>
#include<iostream>
#include<string>
#include "chore.h"
using namespace std;

chore::chore(){
    task = "NONE";
    priority = 0;
}

chore::chore(std::string a, int b){
    task = a;
    priority = b;
}

    void chore::set(){
        cout<<"What is the chore you need to do?\n";
        while(cin.peek()=='\n' || cin.peek()=='\r'){
            cin.ignore();
        }
        getline(cin,task);
        cout<<"\nWhat is the priority of ths chore?\n";
        cin>> priority;
    }

    void chore::output(){
        cout<<task<<"\n"<<priority<<"\n";
    }

bool chore::operator<(const chore& a) const{
    return(priority < a.priority);
}