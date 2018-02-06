/*************************************************************
    Lab5		CS2401		Spring 2017
    Jonathan Feige
    Main.cc to lab 5
**************************************************************/

#include<iostream>
#include<fstream>
#include "numbers2.h"
using namespace std;

int main(){
    Numbers2 longlife;
    unsigned long tmp;
    ifstream ifs;
     string filename;
     cout<<"Please enter the name of your number file.\n";
     cin>>filename;
     ifs.open(filename.c_str());
     if(ifs.fail()){
        cout<<"Input file failed to open.\n";
        return -1;
     }
	{ // The scope of shortlife starts here
	Numbers2 shortlife;
	ifs>>tmp;
	while(!ifs.eof()){
	     shortlife.insert(tmp);
	     ifs>>tmp;
	}
	ifs.close();
	longlife = shortlife;
	} // the scope of shortlife ends here
	longlife.display();
	cout<<endl;
	
return 0;
}
