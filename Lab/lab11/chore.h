/**********************************************************************
 Lab11    CS2401    Spring 2017
    Jonathan Feige
    chore header
**********************************************************************/
#include <queue>
#include <iostream>
#include <cstdlib>
class chore{
public:
	chore();
	chore(std::string a, int b);
	void set();
	void output();
	bool operator<(const chore& a) const;

private:
	std::string task;
	int priority;
};
