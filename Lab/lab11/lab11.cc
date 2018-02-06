/**********************************************************************
 Lab11    CS2401    Spring 2017
    Jonathan Feige
    main for lab 11
**********************************************************************/
#include <queue>
#include <iostream>
#include <cstdlib>
#include "chore.h"
using namespace std;

int main(){
	chore tmp;
    queue<chore> q;
    char hold;
    bool exit = false;

    while(exit != true)
{
	tmp.set();
    cout<<"\n Enter a new chore?\n(Y or N)\n";
    cin>> hold;
    q.push(tmp);
    if(hold == 'N'|| hold == 'n')
    {
    	exit = true;
    }
}
cout<<"\n";
while(!q.empty()){
q.front().output();
q.pop();
}
	return 0;
}
