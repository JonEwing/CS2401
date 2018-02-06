/**********************************************************************
 Lab13    CS2401    Spring 2017
    Jonathan Feige
	&& 
    Babacar Ndoye
    main for lab 13
**********************************************************************/
#include <queue>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

int counting(int n);
std::string reversing(std::string& s,int start, int end);

using namespace std;

int main(){
	int x;
	for(int j=0; j<3; ++j){ // loop to do three test runs in 1 run                                             
	cout<<"Enter a number: ";
     	cin>>x;
	cout<<"The even numbers counting to there:\n";
	counting(x);
	}
     //main for Part Two will go here
	string s;
   	 int start, end;
   	 cout<<"Enter a string:"<<endl;
	cin.ignore();
   	 getline(cin,s);
   	 cout<<"Now enter two numbers that are within the bounds of the string.";
   	 cin>>start>>end;
   	 cout<<"This is how your words look now:\n";
   	 reversing(s,start,end);
   	 cout<<s<<endl;
	return 0;
}

int counting(int n){
if(n%2 != 0){
n = n-1;}

if(n>-2){/*if the number is greater than 0*/  
	n=n-2; // ex. 28 now its 26 0
        counting(n); // call the function for 26 and doing it infinitely until 0 then the else
	cout<<"n: "<<n+2<<endl;
    } 
else{

return n;
}      
}


std::string reversing(string& s,int start, int end){ //start/end is the numbers we want to switch

if(start < end)
{
	swap(s[start], s[end]);
	++start;
	--end;
	reversing(s,start,end);
	
return s;
}
else
{
	return s;
}

}




















