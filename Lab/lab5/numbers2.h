/*************************************************************
    Lab5		CS2401		Spring 2017
    Jonathan Feige
    class for simple and Numbers2
**************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;
/* This class is so simple that it is really a lot like an old-fashioned C strut
   with the two data members being public and directly accessible by everything
*/

class simple{
    public:
        unsigned long num;
	unsigned long *sq;
};

class Numbers2{
    public:
    Numbers2();
	~Numbers2();
	void insert(unsigned long item);
	void display();
	void operator = (const Numbers2& other);
	
    private:
	void resize();
	simple *data;
	size_t used, capacity;
};

Numbers2::Numbers2(){
	used = 0;
	capacity = 10;
	data = new simple[capacity];
}

void Numbers2::resize(){
	simple* tmp;
	capacity += 5;
	tmp = new simple[capacity];
	for(int i = 0; i < used; i++)
	{
		tmp[i] = data[i];
		*(data[i].sq) = *(data[i].sq);
	}
	delete [] data;	
	data = tmp;
	
}

void Numbers2::insert(unsigned long item){
	if(used == capacity)
	   resize();
	data[used].num = item;
	data[used].sq = new unsigned long;
	*(data[used].sq) = item*item;
 	used++;
}

void Numbers2::display(){
	for(size_t i = 0; i < used; i++)
	     cout<<"( "<<data[i].num<<","<<*(data[i].sq)<<" ) ";
	cout<<endl;
}


void Numbers2::operator = (const Numbers2& other){
      if(this == &other){
		return;
	  }
	if ( capacity != other.capacity){
		delete [] data;
		capacity = other.capacity;
		data = new simple [capacity];
		}
	used = other.used;
	copy(other.data, other.data + used, data);

Numbers2::~Numbers2(){
	for(int i = 0; i < used; i++){
		delete data[i].sq;
	}
	delete [] data;
	cout<<"I'm melting!!!\n";
}

