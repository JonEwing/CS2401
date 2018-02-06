/**********************************************************************
     Lab9		CS2401		Spring 2017
    Jonathan Feige
    Header class for LList class
**********************************************************************/

#include<iostream>

class node{
    public:
	node(int d = 0, node* p = NULL, node* n = NULL){
	    datafield = d; previousptr=p; nextptr = n;
	    }
	int data() {return datafield;}
	node *previous() {return previousptr;}
	node *next()  {return nextptr;}
	void set_data(int d){datafield = d;}
	void set_previous(node * p){previousptr = p;}
	void set_next(node *n) {nextptr = n;}
    private:
	int datafield;
	node *nextptr;
	node *previousptr;
};

class LList{
    public:
	LList(){
	    head = tail = NULL;
	    nodecount = 0;
	}
	LList(const LList &other);
	void add_item(int item);
	void frontview()const;
	void rearview() const;
	~LList();
	int size()const {return nodecount;}
	//LList(const LList& other);
    private:
	node* head;
	node* tail;
	int nodecount;
};