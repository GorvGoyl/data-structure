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
		{
		cout<<tmp->data<<"  ";
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


void del(int d)
{

	node* tmp=head;
	node* abc=head;
	if(tmp->data==d)  //1st element is 'd'
	{
		head=tmp->next;
		//tmp->next=NULL;
		delete tmp;
		return;
	}
	
	// "METHOD 1"
	
	while((tmp->next)->data!=d && (tmp->next)->next!=NULL)
{
tmp=tmp->next;
}

abc=tmp->next;
tmp->next=tmp->next->next;
delete abc;
	
	/* OR "METHOD 2"
	tmp=abc->next;
	while(tmp->next!=NULL && tmp->data!=d)
	{
	abc=abc->next;
	tmp=abc->next;
	}
	abc->next=tmp->next;
 delete tmp;   */
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
cout<<"enter an element to delete";
int d;
cin>>d;
del(d);
print();

}





