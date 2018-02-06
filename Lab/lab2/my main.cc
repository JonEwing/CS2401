//*******************************************
// Jonathan Feige	
// 9/7/17
// CS2401
// Lab 2
//*******************************************
#include "numlist.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	NumList data;
	
	ifstream ins;
	ofstream outs;
	
	string file;
	cout << "What is the name of your file?\n";
	cin >> file;
	
	ins.open(file.c_str());
	
	data.load_from_file(ins);
	data.b_sort();
	data.see_all();
	
return 0;
}
