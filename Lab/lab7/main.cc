/*********************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Spring 2014
*********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
     int data;
     node * link;
};


// These are the three I have written for you
void build_list(node* & head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);
void ll_bubblesort(struct node*& head);
//These are the two that you are to write, as described in the 
//instructions page.
void remove_repeats(node*& head);
void split_list(node* original, node*& lesser, node*& greater,int split_value);

int main(){
    int start, stop;
    int split;
    node* head = NULL;
    node * lesser;
    node * greater;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout<<"Time to build list = "<<stop - start <<"seconds.\n";
    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout<<"Time to print list = "<<stop - start<<"seconds.\n";
    cout<<"Size of the list = "<<size(head)<<endl;

	ll_bubblesort(head);

    remove_repeats(head);
    cout <<"\n";

    show_list(head);
     cout<<"Size of the list = "<<size(head)<<endl;

    cout<<"where would you like to split the list?";
    cin >> split;
    split_list(head, lesser, greater, split);

    show_list(lesser);
    show_list(greater);


return 0;
}

// builds a linked list of 2000 random integers, all in the 1 to 500 range
void build_list(node*& head){
     node* cursor;
     head = new node;
     head->data = rand()%500 + 1;
     cursor = head;
     for(int i = 0; i < 2000; ++i){
	cursor->link = new node;
        cursor = cursor->link;
        cursor->data = rand()%500 + 1;
     }
     cursor->link = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
      const node * cursor = head;
      while(cursor !=  NULL){
   	cout<<cursor->data<<"  ";
	cursor = cursor->link;
      }
     cout<<endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor->link;
	}
	return count;
}

void remove_repeats(node*& head)
{
	node * current;
	node * run;
	node * tmp;
	node * del;
	bool done = false;
	int hold;

	 while(!done)
	 { done =true;
	 	for(current = head; current->link != NULL; current = current -> link)
	 		{
	 			hold = current-> data;
	 			for(run = current; run->link != NULL; run = run -> link)
	 				{
	 					tmp = run;
	 					tmp = tmp->link;
	 	 				if(tmp -> data == hold && tmp->link != NULL)
	 	 					{
	 	 						done = false;
	 	 						del = tmp;
	 	 						tmp = tmp->link;
	 	 						run->link = tmp;
	 	 						delete del;
       							cout <<endl<<hold;
	 	 					}
	 					if((tmp -> data == hold && tmp->link == NULL))
	 	 					{
	 	 						run->link=NULL;
	 	 						delete tmp;
	 	 					}
					}
			}
	}
}

void split_list(node* original, node*& lesser, node*& greater,int split_value)
{
	node * tmp;
	node * f;

	f= original;
	tmp = original;
	lesser = original;
	for(tmp = original; tmp->link != NULL; tmp = tmp -> link)
	{
		if(tmp->data != split_value)
			{
				f = f->link;
				cout<<f->data;
			}
		if(tmp->data += split_value)
			{
				greater = tmp;
				f->link = NULL;
				return;
			}
		if(tmp->data != split_value && tmp->link != NULL)
			{
				cout<<"No value, pick another.\n";
				cin>> split_value;
				tmp = original;
			}
	}
	
}

void ll_bubblesort(struct node*& head)
{
    struct node *p = head;
    head = nullptr;

    while (p)
    {
        node **lhs = &p;
        node **rhs = &p->link;
        bool swapped = false;
        while (*rhs)
        {
            if ((*rhs)->data < (*lhs)->data)
            {
                std::swap(*lhs, *rhs);
                std::swap((*lhs)->link, (*rhs)->link);
                lhs = &(*lhs)->link;
                swapped = true;
            }
            else
            {  
                lhs = rhs;
                rhs = &(*rhs)->link;
            }
        }
        *rhs = head;
        if (swapped)
        {
            head = *lhs;
            *lhs = nullptr;
        }

        else
        { 
            head = p;
            break;
        }
    }
}
