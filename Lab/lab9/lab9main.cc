/******************************************************************
     Lab9		CS2401		Spring 2017
    Jonathan Feige
    Main for LList class
********************************************************************/

#include<iostream>
#include<cstdlib>
#include "llist.h"
using namespace std;

int main(){

    int n;
    LList somenums;
    for(int i = 0; i <35; ++i)
    {	n = rand()%700 + 1;
	somenums.add_item(n);
    }
// Once you have written the rear-view this should let you
// see the list frontwards and backwards.
      somenums.frontview();
      cout<<"\n";
      somenums.rearview();
      cout<<"\n";
// This part will be uncommented once you have written the copy constructor
{
    LList numcopy(somenums);  // call to the copy constructor
    numcopy.frontview();
    cout<<"\n";
    numcopy.rearview();
    cout<<"\n";
}   // Line 34 - What happens here?

// Checking the original list
   somenums.frontview();
   cout<<"\n";
   somenums.rearview();
return 0;
}
	

