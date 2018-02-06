/*************************************************************
    Lab8		CS2401		Spring 2017
    Jonathan Feige
    class for template array
**************************************************************/

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include "node.h"


template<class T>
class node_iterator;
template<class T>
class dlist{
    public:
	dlist();
    dlist(const dlist &other);
    void operator =(dlist& other);
    ~dlist();
	friend class node_iterator<T>;
	void front_insert(T& c);
	void rear_insert(T& c);
    void show();
    void reverse_show();
    void front_remove();
    void rear_remove();
    size_t size(){return count;}

		typedef node_iterator<T> iterator;
    	iterator begin(){return iterator(head);}
    	iterator end(){return iterator(NULL);}
    	iterator r_begin(){return iterator(tail);}
    	iterator r_end(){return iterator (NULL);}

    	void remove(iterator it);
    	void insert_before(iterator it, T item);
    	void insert_after(iterator it, T item);
    private:
    size_t count = 0;
	node<T>* head = NULL;
	node<T>* tail = NULL;
};


template<class T>
class node_iterator{
public:
	node_iterator(node<T>*init=NULL){current=init;}
	T operator *(){return current -> data();}
    node<T> *get_current(){return current;}
	bool operator !=(const node_iterator& other){return current != other.current;}
	bool operator ==(const node_iterator& other){return current == other.current;}
	node_iterator operator ++(){current=current->link_next(); return current;}
    node_iterator operator ++(int){node<T> * hold = current; current = current->next(); return hold;}
	node_iterator operator --(){current=current->link_back(); return current;}
    node_iterator operator --(int){node<T> * hold = current; current = current->pre(); return hold;}
private:
	node<T> * current;
	friend class dlist<T>;
};


// This is how we hook this to the implementation file for templates:
#include "dlist.template"
