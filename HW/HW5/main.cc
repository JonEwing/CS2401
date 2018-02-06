/*************************************************************
    HW5        CS2401      Spring 2017
    Jonathan Feige
    This is the main for HW5
**************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Animal.h"

using namespace std;

// This function displays the menu and returns the user's choice
int main(){
    int choice = 1;
    list<animal*> house;
    list<animal*>::iterator it;
    char code;
    animal * tmp;
    std::string filename = "test";

    ifstream fin;
    ofstream fout;

 	cout<<"Welcome to Animal House Construction inc.\n\n";
        filename = filename + ".txt";
        fin.open(filename.c_str());
        	if(!fin.fail()){
			while(!fin.eof())
			{
				fin>> code;
				if(code == 'D')
				{
				tmp = new dog;
				tmp ->finput(fin);
				house.push_back(tmp);
				}
				if(code == 'C')
				{
				tmp = new cat;
				tmp ->finput(fin);
				house.push_back(tmp);
				}
				if(code == 'S')
				{
				tmp = new shark;
				tmp ->finput(fin);
				house.push_back(tmp);
				}
				if(code == 'H')
				{
				tmp = new honey_badger;
				tmp ->finput(fin);
				house.push_back(tmp);
				}
				if(code == 'G')
				{
				tmp = new goat;
				tmp ->finput(fin);
				house.push_back(tmp);
				}
			} 

		house.pop_back();
	}
        fin.close();

	while(choice != 0){
	
	cout<<"\nChoose from the following options:\n";
    cout<<"1) I am a Dog.\n";
    cout<<"2) I am a Cat.\n";
    cout<<"3) I am a Shark.\n";
    cout<<"4) I am a Honey Badger.\n";
    cout<<"5) I am a Goat\n";
    cout<<"6) Show All houses\n";
    cout<<"0) Quit - saving all changes.\n";

    cin>> choice;
	    if(choice == 1)
	    {
	    	tmp = new dog;
			tmp ->input(cin);
			house.push_back(tmp);
	    }

	     if(choice == 2)
	    {
	    	tmp = new cat;
			tmp ->input(cin);
			house.push_back(tmp);
	    }

		if(choice == 3)
	    {
	    	tmp = new shark;
			tmp ->input(cin);
			house.push_back(tmp);
	    }
	    if(choice == 4)
	    {
	    	tmp = new honey_badger;
			tmp ->input(cin);
			house.push_back(tmp);
	    }
	     if(choice == 5)
	    {
	    	tmp = new goat;
			tmp ->input(cin);
			house.push_back(tmp);
	    }

	    if(choice == 6)
	    {
	    	for (it=house.begin(); it!=house.end(); ++it){
   			(*it)->output(cout);
   			cout<<"\n";
   			}
	    }

		if(choice == 0)

	    {	fout.open(filename.c_str());

	    	cout<<"Thank you for using Animal House Construction inc.\n";
	    	for (it=house.begin(); it!=house.end(); ++it){
        	(*it)->foutput(fout);
        	}

        	fout.close();
        	return -1;
	    }
	    
		if(choice<0 || choice>6)
		{
		cout<<"Not an option.\n";
	    }  
	}

return 0;
}

