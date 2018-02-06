/*************************************************************
    Lab8    CS2401    Spring 2017
    Jonathan Feige
    main for lab 8
**************************************************************/

#include<iostream>
#include<cstdlib>
#include "tarray.h"
using namespace std;

int main(){
    Tarray <int> nums;
    Tarray<string> words;

    nums.add(rand());
    nums.add(rand());
    nums.add(rand());
    nums.add(rand());
 
   for(nums.start(); nums.is_item(); nums.advance())
	cout<<nums.current()<<endl;

    words.add("CS");
    words.add("is");
    words.add("the");
    words.add("bestest");
    words.add("major");
    words.add("at");
    words.add("Ohio");
    words.add("University");

   words.start();
   while(words.is_item() && words.current() != "major")
   	words.advance();

    words.remove_current();
   for(words.start(); words.is_item(); words.advance())
	cout<<words.current()<<' ';

int q;
cin>>q;
return 0;
}

