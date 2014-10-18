#include<iostream>
using namespace std;
struct node{
			int data;
			node* next;
			};
			struct node* head;

void push (int x)
{
	node* temp = new node();
	temp->data=x;
	temp->next=head;
	head=temp;

}

void print()
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


void pop()
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


while(ch!=3)
	{
	cout<<" 1. to push an element\n 2. to pop the element\n 3. to exit\n";
	cin>>ch;
	if(ch==1)
	{
	cout<<"enter the no. to insert";
	cin>>x;
	push(x);
	cout<<"\n";
	print();
	}
	
	else if(ch==2)
	{
	pop();
	print();
	}
	else break;
	}


}





