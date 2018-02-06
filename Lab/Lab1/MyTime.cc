// Jonathan Feige
// CS2401
// Lab 1 Footer
// 08/31/17

#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructors
MyTime::MyTime(){
	hours = 0;
	minutes = 0;
}

MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::simplify(){
       	hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime :: operator + (const MyTime& t2)const{
	MyTime tmp;
        tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime :: operator - (const MyTime& t2)const{
	MyTime tmp;
	tmp.minutes = abs((hours*60+minutes) - 
					(t2.hours*60+t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime :: operator / (int num)const{
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime :: operator * (int num)const{
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

const bool MyTime :: operator == (const MyTime& t2){
	return hours == t2.hours && minutes == t2.minutes;
}

const bool MyTime :: operator < (const MyTime& t2){
	return (hours*60 + minutes) < (t2.hours*60 + t2.minutes);
}

const bool MyTime :: operator <=(const MyTime& t2){
	return (hours*60 + minutes) <= (t2.hours*60 + t2.minutes);
}

	void MyTime::input(istream&ins){
	char junk;
	ins>>hours;
  	ins.get(junk);
	ins>>minutes;
	simplify();
	
}

       // Here you are to copy the implementation code from the >> operator shown below
	// remember to that variables will be local here - so no referene to t1
       //Then you can have the >> operator call this function.
      // In the .h file remove the word friend for the operator and move its prototype to a spot
      // under the class declaration

	void MyTime::output(ostream& outs){
	 outs<<hours<<':'<<setw(2)<<setfill('0')<<minutes;

}


ostream& operator <<(ostream& outs, const MyTime& t1){
        outs<<t1.hours<<':'<<setw(2)<<setfill('0')<<t1.minutes;
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	char junk;
	ins>>t1.hours;
  	ins.get(junk);
	ins>>t1.minutes;
	t1.simplify();
	return ins;
}

