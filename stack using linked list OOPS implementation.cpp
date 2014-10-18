#include<iostream>
using namespace std;

struct node{
			int data;
			node* next;
			};

class stack
{
	struct node* head;
	public:
		stack() //constructor
		{head=NULL;
		}
		void print();
		void pop();
		void push();
};


void stack::push ()
{   int x;
	cout<<"enter the no. to insert";
	cin>>x;
	node* temp = new node();
	temp->data=x;
	temp->next=head;
	head=temp;

}

void stack::print()
{
	 node* tmp=head;
	cout<<"Stack is: ";
	while(tmp!=NULL)
		{
		cout<<tmp->data<<"  ";
		tmp=tmp->next;
		}
	cout<<"\n";

}


void stack::pop()
{

	node* tmp=head;
	if(tmp==NULL)
	{
	 cout<<"underflow\n";
	 return;
	}
		head=tmp->next;
		delete tmp;
}

int main(void)
{
std::ios_base::sync_with_stdio(0);
//std::cin.tie(0); //use this only when no std::cout statement used
int x,ch;
stack c;

while(ch!=3)
	{
	cout<<" 1. to push an element\n 2. to pop the element\n 3. to exit\n";
	cin>>ch;
	if(ch==1)
	{
	c.push();
	cout<<"\n";
	c.print();
	}

	else if(ch==2)
	{
	c.pop();
	c.print();
	}
	else break;
	}


}

