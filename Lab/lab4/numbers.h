/*************************************************************
    Lab4		CS2401		Spring 2017
	Jonathan Feige
	Numbers header & footer
**************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>


class Numbers{
	public:
	Numbers();
	~Numbers();
	Numbers(const Numbers& other);
	void operator = (const Numbers& other);
	
	void resize();
	void display(std::ostream& outs);
	void remove_last();
	void add(unsigned long i);
	
	private:
	unsigned long * data;
	unsigned long * tmpd;
	std::size_t used;
	std::size_t capacity;
};

using namespace std;


Numbers :: Numbers(){
		capacity = 5;
		used = 0;
		data = new unsigned long[capacity];
}

Numbers :: ~Numbers(){
		delete []data;
		cout << "I'm melting";
	}
	
	Numbers :: Numbers(const Numbers& other){
		used = other.used;
		capacity = other.capacity;
		data = new unsigned long[capacity];
		copy(other.data, other.data+used, data);
	}
	
	void Numbers :: operator = (const Numbers& other){
		if(this == &other){
		return;
		}
	}

void Numbers :: resize(){
		tmpd = new unsigned long[capacity+5];
		copy(data, data+used, tmpd);
		delete []data;
		data = tmpd;
	}
	
void Numbers :: display(std::ostream& outs){
		for(int i = 0; i <= used ; i++){
		cout << endl;
		cout << data[i];
		cout << endl;
	}
}

void Numbers :: remove_last(){
	used--;
	return;
}

void Numbers :: add(unsigned long i){
	resize();
	data[used+1] = i;
	++used;
}