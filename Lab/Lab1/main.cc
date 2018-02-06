// Jonathan Feige
// CS2401
// Lab 1 main
// 08/31/17

#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

MyTime t1, t2, tmp;
int m;

cout << "Enter a time, hours, then minutes\n";
cin >> t1;
cout << "Enter a second time, hours, then minutes\n";
cin >> t2;

cout << "\nAddidtion of times\n";
tmp = t1 + t2;
cout << tmp;

cout << "\nSubtraction of times\n";
tmp = t1 - t2;
cout << tmp;

cout << "\nDivision of times\n";
cout << "\nWhat integer do you want to devide by?\n";
cin >> m;
tmp = t1 / m;
cout << tmp;

cout << "\nMultiplication of times\n";
cout << "\nWhat integer do you want to multiply by?\n";
cin >> m;
tmp = t1 * m;
cout << tmp;

if (t1 == t2){
cout << "\nTimes are equal.\n";
}
else
cout << "\ntimes are not equal.\n";

return 0;
}
