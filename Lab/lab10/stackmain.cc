/**********************************************************************
 Lab10    CS2401    Spring 2017
    Jonathan Feige
    main for lab 10
**********************************************************************/
#include<cstdlib>
#include<iostream>
#include<string>
#include "calc_useful.h"
using namespace std;


int main(){
    char c;
    char tmp;
    int onenum, twonum;
    int count;
    bool continu = true;
    stack<int> nums;
    do
	{
	cout<<"Please enter your expression:\n";
    c = cin.get(); // priming read for the sentinel loop.

    while(c != '\n')
    {
 		if(isdigit(c))
 		{
	    cin.putback(c);
	    cin>>onenum;
	    cout << onenum << endl;
	    nums.push(onenum);
	// stack operation here.
		}

	else if(isop(c)){
		if(!nums.empty())
		{
			onenum=nums.top();
			nums.pop();
			if(!nums.empty())
			{
				twonum = nums.top();
				nums.pop();
				int tmp;
				if(c=='+' || c=='*')
				{
					tmp=evaluate(onenum,twonum,c);
					cout << tmp << endl;
				}
				else if(c=='-' || c=='/')
				{
					tmp=evaluate(twonum,onenum,c);
					cout << tmp <<endl;
				}
				nums.push(tmp);
				onenum=nums.top();
			}
			else
			{
        			cout<<"Error. Insufficient operators for operands.\n";
        			return -1;
			}

		}
	// if the stack is empty here you have an error.
		if(nums.empty())
		{
			cout << "Error. Stack is empty.\n";
			return -1;
		}
	// here is where you have to pop a couple of numbers,
        // apply the operator to the numbers
        // and then push the result back into the stack
	}
	c = cin.get(); // reading at the bottom of the sentinel loop
    }
	// this is where you get your final answer off the stack
	// it should be the only number left on the stack at this point
    if(nums.empty())
    {
	cout<<"Error. Insufficient operators for operands.\n";
	return -1;
    }
 	nums.pop();
 	if(!nums.empty())
 	{
 		cout <<"Too Many values left in the String";
 		return -1;
 	}
    cout<<"The answer is: "<< onenum<<endl;
    cout << "Enter another equation?(y or n)";
    cin>> tmp;
    if(tmp=='y' || tmp=='Y')
    {
    	c = 0;
	continu=true;
	}
    else
	continu=false;
	}
	while(continu == true);
	return 0;
}
