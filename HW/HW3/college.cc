/******************************************************
	This is the main for Project 3, which asks you to 
    build a container that holds a list of college courses.
    The courses are always kept in order, so they never need
    to be sorted since they are always inserted in the order 
    where they go. You will also need the files:
	course.h
	course.cc
	node.h
    in order to do this project. You will be writing both the .h
    and the .cc file for the container.
	John Dolan			Spring 2015
**********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

using namespace std;

		College::College()
		{
			name = "none";
			head = NULL;
		}

		College::College(std::string a)
		{
			name = a;
			head = NULL;
		}

		College::College(const College& other)
		{
			if(other.head==NULL)
			{
				head==NULL;
			}
			else
			{
				head=new node;
				head->set_data(other.head->data());
				head->set_link(NULL);
				node * sptr = other.head->link();
				node * dptr = head;
				while(sptr != NULL)
				{
					dptr-> set_link(new node(sptr->data()));
					sptr = sptr->link();
					dptr = dptr->link();
				}
			}
		}

		College::~College()
		{	
				node* current = head;
   				while (current != NULL)
    			{
        		node* saveFirst = head;
    			head = head->link();
    			delete current;
        		current = head;
    			}
    			head = NULL;
		}

		void College::operator =(College &other)
		{
			node* current = head;
   			while (current != NULL)
    			{
        		node* saveFirst = head;
    			head = head->link();
    			delete current;
        		current = head;
    			}
    			head = NULL;

    		if(other.head==NULL)
			{
				head==NULL;
			}
			else
			{
				head=new node;
				head->set_data(other.head->data());
				head->set_link(NULL);
				node * sptr = other.head->link();
				node * dptr = head;
				while(sptr != NULL)
				{
					dptr-> set_link(new node(sptr->data()));
					sptr = sptr->link();
					dptr = dptr->link();
				}
			}
		}

    	void College::load(std::istream& ins)
		{
			course tmpc;
			ins >> tmpc;
			while(!ins.eof())
			{
				add(tmpc);
				ins >> tmpc;
			}
			add(tmpc);
		}
		
    	void College::add(course& c)
		{
			node * tmp;
			node * f;
    		if(head == NULL)
    			{
        			head = new node;
        			head -> set_data(c);
        			head -> set_link(NULL);
    			}
    		else
    			{	
    				course tmpc;
        			tmp = head;
        			f = head;

					while(tmp -> link() != NULL)
						{
							tmpc = tmp->data();

							if (c.get_course_number() < tmpc.get_course_number() && tmp == head)
								{
									node *blankN;
        							blankN = new node;
        							blankN ->set_link(NULL);
       								blankN ->set_data(c);
        							blankN ->set_link(head);
        							head = blankN;
        							return;
								}

							if (c.get_course_number() > tmpc.get_course_number())
								{
									tmp = tmp -> link();
									tmpc = tmp->data();
								}

							if (c.get_course_number() <= tmpc.get_course_number())
								{
									f -> set_link(new node);
        							f = f->link();
        							f->set_data(c);
        							f-> set_link(tmp);
									return;
								}
								f = f -> link();
						}

					if (tmp->link() == NULL)
						{
							tmp -> set_link(new node);
        					tmp = tmp->link();
        					tmp-> set_data(c);
        					tmp-> set_link(NULL);
							return;
						}
    			} 
		}
		
		
    	void College::display(std::ostream& outs)
		{	
			node *tmp;
			for(tmp = head; tmp != NULL; tmp = tmp->link())
			{
        	outs<<tmp->data();
	      	outs<<"\n";
	     	}
            	
		}
		
    	void College::remove(std::string a)
		{
					node * tmp=head;
					node * f=head;
					course tmpc;

					while(tmp -> link() != NULL)
						{
							tmpc = tmp->data();

							if (a == tmpc.get_course_number() && tmp == head )
								{
									head= head->link();
									delete f;
									return;
								}

							if (a != tmpc.get_course_number())
								{
									tmp = tmp -> link();
									tmpc = tmp->data();
								}

							if (a == tmpc.get_course_number() && tmp->link()==NULL)
								{
									f->set_link(NULL);
									delete tmp;
									return;
								}

							if (a == tmpc.get_course_number())
								{
									node * hold;
									tmp = hold;
									tmp = tmp -> link();
									f-> set_link(tmp);
									delete hold;
									return;
								}

								f = f -> link();
						}
    	} 
		
    	double College::hours()
		{
			course tmps;
			double hour = 0;
			for(node *tmp = head; tmp != NULL; tmp = tmp->link())
			{
				tmps = tmp->data();
				hour = hour + tmps.get_hours();
			}
			return hour; 
		}
		
    	double College::gpa()
		{
			course tmps;
			double gpa = 0;
			int i = 0;
			for(node *tmp = head; tmp != NULL; tmp = tmp->link())
			{
				tmps = tmp->data();
				gpa = gpa + tmps.get_number_grade();
				i++;
			}
			gpa = gpa/i;
			return gpa;
		}
		
    	void College::save(std::ostream& outs)
		{
			for(node *tmp = head; tmp != NULL; tmp = tmp->link())
			{
        	outs<<tmp->data();
        	}
        	return;
        }