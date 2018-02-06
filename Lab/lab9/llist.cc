/************************************************************************
     Lab9		CS2401		Spring 2017
    Jonathan Feige
   Corrected footer for LList.h
************************************************************************/
#include<iostream>
#include "llist.h"
using namespace std;

void LList::frontview()const{
   node *tmp;
	for(tmp = head; tmp != NULL; tmp = tmp->next())
	{
       cout<<tmp->data();
	   cout<<"\n";
	}
}

// The student is required to write the implementation of this function
void LList::rearview()const{
	node *tmp;
	for(tmp = tail; tmp != NULL; tmp = tmp->previous())
	{
       cout<<tmp->data();
	   cout<<"\n";
	}

}

void LList::add_item(int item){
    if(head == NULL){
	head=tail=new node(item);
	nodecount++;
	head -> set_previous(NULL);
	head -> set_next(NULL);
    }
    else if(item%5 == 0 && nodecount > 3){
	int i = 0;
	node* cursor=head;
	while(i < nodecount/2){
	    cursor = cursor->next();
	    i++;
	}
	node * n;
	node * p;
	n = cursor;
	p = cursor;
	n = n->next();
	cursor->set_next(new node());
	cursor = cursor->next();
	cursor -> set_data(item);
	cursor -> set_next(n);
	cursor -> set_previous(p);
	n -> set_previous(cursor);
	nodecount++;
    }
    else{
	tail->set_next(new node(item, tail));
	tail = tail->next();
	tail->set_next(NULL);
	nodecount++;
    }
}

LList::~LList(){
   node* rmptr;
   while(head != NULL){
	rmptr=head;
	head = head->next();
	delete rmptr;
   }
}

LList::LList(const LList &other)
{
	node * h;
	if(other.head==NULL)
			{
				head==NULL;
			}
			else
			{
				head=new node;
				head->set_data(other.head->data());
				head->set_next(NULL);
				head->set_previous(NULL);
				node * sptr = other.head->next();
				node * dptr = head;
				while(sptr != NULL)
				{
					h = dptr;
					dptr-> set_next(new node(sptr->data()));
					sptr = sptr->next();
					dptr = dptr->next();
					dptr-> set_previous(h);
				}
			}
}