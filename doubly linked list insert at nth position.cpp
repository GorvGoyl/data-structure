#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
node* head;

void insertbeg(int d)
{
	node* tmp=new node();
	if(head==NULL)
	{
	
	tmp->data=d;
	head=tmp;
	tmp->next=NULL;
	tmp->prev=NULL;
	return;
	}

	tmp->next=head;
	head=tmp;
	tmp->data=d;
	tmp->prev=NULL;
}

void pos(int d,int p)
{   if(p==1)
	{
		insertbeg(d);
		return;

	}
	node* insrt =new node();
	insrt->data=d;
	insrt->next=NULL;
	node* tmp=head;
	
	for(int i=1;i<p-1;i++)
	{
	tmp=tmp->next;
	}
	insrt->next=tmp->next;
	tmp->next=insrt;
	
	
}

void print()
{
	node* tmp;
	tmp=head;
	cout<<"doubly linked list is: ";
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<"\n";
}

int main(void)
{
std::ios_base::sync_with_stdio(0);
//std::cin.tie(0); //use this only when no std::cout statement used
cout<<"how many element you want to insert?"<<"\n";
int t,n;
cin>>t;
while(t--)
{

cout<<"enter an element at beginning"<<"\n";
cin>>n;
insertbeg(n);
print();

}
cout<<"enter an element for nth position"<<"\n";
cin>>t;
cout<<"enter nth position for insert"<<"\n";
cin>>n;
pos(t,n);
print();
}

