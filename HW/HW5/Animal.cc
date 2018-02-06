/*************************************************************
    HW5        CS2401      Spring 2017
    Jonathan Feige
    This is the footer file for the animal class
    and all of its child classes
**************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Animal.h"

using namespace std;

dog::dog(){
name="NULL";
height=0;
width=0;
wood_type = "NULL";
}

void dog::input(istream& ins){
cout<<"What is your name?\n";
ins>> name;
cout<<"\nHow tall would you like your house?\n";
ins>> height;
cout<<"\nHow wide would you like your house?\n";
ins>> width;
cout<<"\nWhat wood would you like for your house?\n";
ins>> wood_type;
}

void dog::output(ostream& outs){
outs<<"This Dogs name is ";
outs<<name;
outs<<"\n";
outs<<"The heigth of the house is ";
outs<<height;
outs<<"\n";
outs<<"The width of the house is ";
outs<<width;
outs<<"\n";
outs<<"They would like it built from ";
outs<<wood_type;
outs<<"\n";
}

void dog::finput(std::istream& ins){
ins>> name;
ins>> height;
ins>> width;
ins>> wood_type;
}

void dog::foutput(std::ostream& outs){
outs << "D";
outs <<"\n";
outs << name;
outs <<"\n";
outs << height;
outs <<"\n";
outs << width;
outs <<"\n";
outs << wood_type;
outs <<"\n";
}

cat::cat(){
name="NULL";
height=0;
width=0;
levels = 0;
campartments = 0;
}

void cat::input(istream& ins){
std::cout<<"What is your name?\n";
ins>> name;
std::cout<<"\nHow tall would you like your house?\n";
ins>> height;
std::cout<<"\nHow wide would you like your house?\n";
ins>> width;
std::cout<<"\nHow many levels would you like for your house?\n";
ins>> levels;
std::cout<<"\nHow many campartments would you like for your house?\n";
ins>> campartments;
}

void cat::output(ostream& outs){
outs<<"This Cats name is ";
outs<<name;
outs<<"\n";
outs<<"The heigth of the house is ";
outs<<height;
outs<<"\n";
outs<<"The width of the house is ";
outs<<width;
outs<<"\n";
outs<<"They would like ";
outs <<levels;
outs<<" levels";
outs <<"\n";
outs<<"They would also like ";
outs <<campartments;
outs<<" capartments";
outs <<"\n";
}

void cat::finput(std::istream& ins){
ins>> name;
ins>> height;
ins>> width;
ins>> levels;
ins>> campartments;
}

void cat::foutput(std::ostream& outs){
outs << "C";
outs <<"\n";
outs << name;
outs <<"\n";
outs << height;
outs <<"\n";
outs << width;
outs <<"\n";
outs << levels;
outs <<"\n";
outs << campartments;
outs <<"\n";
}


honey_badger::honey_badger(){
name="NULL";
height=0;
width=0;
depth = 0;
leaf_type = "NULL";
}

void honey_badger::input(std::istream& ins){
std::cout<<"What is your name?\n";
ins>> name;
std::cout<<"\nHow tall would you like your house?\n";
ins>> height;
std::cout<<"\nHow wide would you like your house?\n";
ins>> width;
std::cout<<"\nHow deep would you like the house?\n";
ins>> depth;
std::cout<<"\nWhat type of leaf would you like for your floor?\n";
cin>> leaf_type;
}

void honey_badger::finput(std::istream& ins){
ins>> name;
ins>> height;
ins>> width;
ins>> depth;
ins>> leaf_type;
}

void honey_badger::foutput(std::ostream& outs){
outs << "H";
outs <<"\n";
outs << name;
outs <<"\n";
outs << height;
outs <<"\n";
outs << width;
outs <<"\n";
outs <<depth;
outs <<"\n";
outs <<leaf_type;
outs <<"\n";
}

void honey_badger::output(std::ostream& outs){
outs<<"This Honey Badger name is ";
outs<<name;
outs<<"\n";
outs<<"The heigth of the house is ";
outs<<height;
outs<<"\n";
outs<<"The width of the house is ";
outs<<width;
outs<<"\n";
outs<<"The depth of the house ";
outs << depth;
outs<<"\n";
outs<<"The type of leaf padding ";
outs<< leaf_type;
outs<<"\n";
}


shark::shark(){
name="NULL";
glass_color = "NULL";
height=0;
width=0;
rocks = 0;

}

void shark::input(std::istream& ins){
std::cout<<"What is your name?\n";
ins>> name;
std::cout<<"\nHow tall would you like your tank?\n";
ins>> height;
std::cout<<"\nHow wide would you like your tank?\n";
ins>> width;
std::cout<<"\nWhat color glass would you like for your tank?\n";
ins>> glass_color;
std::cout<<"\nHow many rocks would you like?\n";
ins>> rocks;
}

void shark::output(std::ostream& outs){
outs<<"This Sharks name is ";
outs<<name;
outs<<"\n";
outs<<"The heigth of the tank is ";
outs<<height;
outs<<"\n";
outs<<"The width of the tank is ";
outs<<width;
outs<<"\n";
outs<<"The color of the glass is ";
outs<<glass_color;
outs<<"\n";
outs<<"The amount of rocks are ";
outs<< rocks;
outs<<"\n";
}

void shark::finput(std::istream& ins){
ins>> name;
ins>> height;
ins>> width;
ins>> glass_color;
ins>> rocks;
}

void shark::foutput(std::ostream& outs){
outs << "S";
outs <<"\n";
outs << name;
outs <<"\n";
outs << height;
outs <<"\n";
outs << width;
outs <<"\n";
outs << glass_color;
outs <<"\n";
outs << rocks;
outs <<"\n";
}

goat::goat(){
name="NULL";
height=0;
width=0;
straw = 0;
bed = false;
bed_color = "NULL";
}

void goat::input(std::istream& ins){
std::cout<<"What is your name?\n";
ins>> name;
std::cout<<"\nHow tall would you like your house?\n";
ins>> height;
std::cout<<"\nHow wide would you like your house?\n";
ins>> width;
std::cout<<"\nHow much straw would you like for your house? (in ibs)\n";
ins>> straw;
std::cout<<"\nWould you like a bed? (Yes|No)\n";
ins>> bed_color;
if(bed_color == "Yes"|| bed_color == "yes"){
    bed = true;
std::cout<<"\nWhat color would you like your bed?\n";
ins>> bed_color;
}
}

void goat::output(std::ostream& outs){
outs<<"This Goats name is ";
outs<<name;
outs<<"\n";
outs<<"The heigth of the house is ";
outs<<height;
outs<<"\n";
outs<<"The width of the house is ";
outs<<width;
outs<<"\n";
outs<<"The amount of straw is ";
outs<<straw;
outs<<"\n";
if(bed){
outs<<"The color of the bed is ";
outs<<bed_color;
outs<<"\n";
}
}

void goat::finput(std::istream& ins){
ins>> name;
ins>> height;
ins>> width;
ins>> straw;
ins>> bed;
ins>> bed_color;
}

void goat::foutput(std::ostream& outs){
outs << "G";
outs <<"\n";
outs << name;
outs <<"\n";
outs << height;
outs <<"\n";
outs << width;
outs <<"\n";
outs << straw;
outs <<"\n";
outs << bed;
outs <<"\n";
outs << bed_color;
outs <<"\n";
}


ostream& operator << (ostream& outs, animal& c){
        c.output(outs);
        return outs;
    }

istream& operator >> (istream& ins, animal& c){
       c.input(ins);
       return ins;
}