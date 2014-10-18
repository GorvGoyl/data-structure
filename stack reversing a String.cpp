#include<iostream>
#include<string>

using namespace std;

struct node{
			char data;
			node* next;
			};

class stack
{   char x[50];
	struct node* head;
	public:
		stack() //constructor
		{head=NULL;
		}
		void print();
		void push();
};


void stack::push () //characters are storing at begining so the last element will be at first.
{
	cout<<"enter the string: ";
	gets(x);
	for(int i=0;x[i]!='\0';i++)
	{
	node* temp = new node();
	temp->data=x[i];
	temp->next=head;
	head=temp;
	}
}

void stack::print()   //just printing the default stack
{
	 node* tmp=head;
	cout<<"Reversed string is: ";
	while(tmp!=NULL)
		{
		cout<<tmp->data;
		tmp=tmp->next;
		}
	cout<<"\n";

}

int main(void)
{
stack c;
	c.push();
	cout<<"\n";
	c.print();
}

