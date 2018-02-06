//*******************************************
// Jonathan Feige	
// 9/7/17
// CS2401
// Lab 3 main part 2

//*******************************************
#include<iostream>

using namespace std;
		
	int main()
	{
		
		int w;
		
		int *ptr;
		ptr = new int;
		cout << ptr << endl;
		cout << &ptr;
		*ptr = 2401; 
		
		for (int i=0; i < 1000000; i++){
			--(ptr);   
			cout << *ptr << "is stored at " <<ptr<<endl;
		}
		cin >> w;
		return 0;
	}