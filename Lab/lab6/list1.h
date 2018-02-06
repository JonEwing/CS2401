/*************************************************************
    Lab6		CS2401		Spring 2017
    Jonathan Feige
    class for node lists and a node struct
**************************************************************/

#include<iostream>
#include<string>

struct Node{
    std::string data;
    Node *link;
};

class Lilist{
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string name);
		void move_front_to_back();

    private:
        Node *head;
};

void Lilist::add(std::string item)
{
    Node * tmp;
    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> link = NULL;
    }
    else
    {
        for(tmp = head; tmp->link != NULL; tmp = tmp -> link)
            ;
        tmp ->link = new Node;
        tmp = tmp->link;
        tmp->data = item;
        tmp->link = NULL;
    }
}

void Lilist::show()
{
    for(Node *tmp = head; tmp != NULL; tmp = tmp->link)
        std::cout<<tmp->data<<"  ";
	       std::cout<<"\n";
}

 Node* Lilist::search(std::string name)
 {
	Node* cursor;
 	cursor = head;
    while(cursor != NULL && cursor -> data != name)
    {
        cursor = cursor -> link;
    }
    return cursor;
}

 void Lilist::move_front_to_back()
 {	
  Node *cursor;
  Node *tmp;
  tmp = new Node;
  cursor = head;

  while (cursor-> link != NULL)
  {
    cursor = cursor->link;
  }

  cursor -> link = head;
  tmp -> link = head -> link;
  head -> link = NULL;
  head = tmp -> link;
}
