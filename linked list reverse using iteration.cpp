#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
struct node* head;

void insert (int x)
{
	node* temp = new node();
	temp->data=x;
	temp->next=head;
	head=temp;

}

void print()
{
 node* tmp=head;
	cout<<"linked list is: ";
	while(tmp!=NULL)
	{cout<<tmp->data<<"  ";
	tmp=tmp->next;
	}
	cout<<"\n";

}
void pos(int e,int p)
{   node* insrt =new node();
	insrt->data=e;
	insrt->next=NULL;
	node* tmp=head;
	if(p==1)
	{
		insrt->next=tmp;
		head=insrt;
		return;
	}
	for(int i=1;i<p-1;i++)
	{
	tmp=tmp->next;
	}
	insrt->next=tmp->next;
	tmp->next=insrt;
}


void reverse()
{
	node *tmp,*prev,*nex;
	tmp=head;
	prev=NULL;
	while(tmp!=NULL)
	{
	nex=tmp->next;
	tmp->next=prev;
	prev=tmp;
	tmp=nex;
	
	}
	head=prev;
	
}


int main(void)
{
std::ios_base::sync_with_stdio(0);
//std::cin.tie(0); //use this only when no std::cout statement used
int n,x;
cout<<"how many no. you want to add";
cin>>n;
while(n--){
	cout<<"enter the no. to insert";
	cin>>x;
	insert(x);
	cout<<"\n";
	print();

}

/*cout<<"enter element to insert at nth position";
int p,e;
cin>>e>>p;
pos(e,p);
print();
*/
cout<<"\n reverse linked list is: ";
reverse();
print();

}





