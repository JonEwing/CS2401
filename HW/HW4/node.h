/*************************************************************
    Lab8		CS2401		Spring 2017
    Jonathan Feige
    class for template array
**************************************************************/

#include<iostream>
#ifndef NODE_D
#define NODE_D

template<class T>
class node{
    public:
    	typedef T value_type;
	node(value_type d = value_type(), node *n = NULL, node *p = NULL)
		{data_field = d;  next = n; pre = p;}
       
        // Mutator functions
	void set_data(T d)
		{data_field = d;}
	void set_next(node *l)
		{next = l;}
	void set_pre(node *l)
		{pre = l;}

        // Accessor functions
        value_type data() const 
		{return data_field;}
        node* link_next() 
		{return next;}
		node* link_back() 
		{return pre;}

    private:
	T data_field;
	node* next;
	node* pre;
};

#endif