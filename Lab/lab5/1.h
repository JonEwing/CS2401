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
//	~Numbers();
	void insert(unsigned long item);
	void display();
//	void operator = (const Numbers& other);
	
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
	// copying is going to be more complicated this time because 
	// for each array element you will have to allocate the 
	//unsigned long which will hold its square

	// deleting the hold array will also be more complicated
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

/*
void Numbers2::operator = (const Numbers& other){
      // This is left up to the student
}
*/

/*
Numbers2::~Numbers2(){
	// This is left up to the student
//	cout<<"I'm melting!!!\n";
}
*/
