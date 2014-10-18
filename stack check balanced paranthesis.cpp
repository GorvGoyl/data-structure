#include<iostream>
using namespace std;

struct node{
			char data;
			node* next;
			};

class stack
{
	struct node* head;
	public:
		stack() //constructor
		{head=NULL;
		}

		void pop();
		void push(char);
		char top();
		bool isempty();
		
};


void stack::push (char ch)
{   if(ch=='d') return;
	node* temp = new node();
	temp->data=ch;
	temp->next=head;
	head=temp;

}



char stack::top(){
	if(head==NULL){
		return 0;
	}
	return head->data;
}

bool stack::isempty(){
	if(head==NULL)
	return true;
	else return false;
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

char ch,tp;
stack c;
int flag=0;
cout<<"enter a paranthesis expression, enter 'd' for done\n";
while(ch!='d')
	{
	
	cin>>ch;
	if(ch=='(' || ch=='{' || ch=='[')
	c.push(ch);
	tp=c.top();
	
	if(ch==')'||ch=='}'||ch==']')
		if( (ch==')' && tp=='(') || (ch=='}' && tp=='{') || (ch==']' && tp=='[') )	{
		c.pop();
		}
		else {
		flag=1;break; }
	
	}
		if(c.isempty()!=true || flag==1)
		cout<<"paranthesis didn't 'match!";
		else cout<<"Parenthesis matched";
	
	
	}





