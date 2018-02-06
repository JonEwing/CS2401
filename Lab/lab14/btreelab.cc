/**********************************************************************
 Lab14    CS2401    Spring 2017
    Jonathan Feige
	&& 
    Babacar Ndoye
    main and node for lab 14
**********************************************************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Bnode{
	string data;
	Bnode * left;
	Bnode * right;
};

void inorder(Bnode* root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

void search(Bnode* root, int& count , string& item){
	if(root != NULL){
		search(root->left, count, item);
		if(root->data == item)
		{
		count++;
		cout<<root->data<<" "<< count << endl;
		}
		search(root->right, count, item);
	}
}

void bigger(Bnode* root, int& count , string& item){
	if(root != NULL){
		bigger(root->left, count, item);
		if(root->data > item)
		{
		count++;
		}
		bigger(root->right, count, item);
	}
}

void add(Bnode *& root, string item){
	if(root == NULL){
		root=new Bnode;
		root->data = item;
		root->left=root->right=NULL;
	}
	else if (item <= root->data)
		add(root->left,item);
	else
		add(root->right,item);
}

int size(Bnode * root){
	if(root == NULL) return 0;
	else
	return size(root->left) + size(root->right) + 1;
}


int main(){
	Bnode * root = NULL;
	string name,item;
	int count = 0;
	ifstream fin;
	ofstream fout;

        fin.open("names");
	while(!fin.eof())
		{
		fin>>name;
		add(root,name);
		}

	inorder(root);
	cout<<"\nEnter the name you are looking for\n";
	cin>>item;
	cout<<"\n";
	search(root,count,item);
	cout<<"\nYour search "<<item<<" appers "<<count<<" times\n";
	count = 0;
	bigger(root,count,item);
	cout<<"There are "<<count<<" names higher than "<<item<<"\n";
return 0;
}























