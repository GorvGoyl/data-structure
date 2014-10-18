#include<iostream>

using namespace std;

#define MAX 5
int a[MAX];
int front=-1;
int rear=-1;
void enqueue(int e) //to insert at rear
{
if ((rear+1)%MAX==front) //(rear+1)%MAX always produce no. within 0 to MAX-1
{
cout<<"*Queue OVERFLOW*"<<"\n";
return;
}
if (rear== -1) //for NULL queue, set index at 0
front=rear= 0;
else
rear = (rear+1)%MAX; //increasing rear only before insertion!!

a[rear]=e;

}
void dequeue()  //to delete from front
{
	if(front==-1)
	{cout<<"*Queue UNDERFLOW*"<<"\n";
	return;
	}
	if (front==rear) //for only element in queue,set front, rear = -1
	front=rear=-1;
	else
	front=(front+1)%MAX; // increasing front and (front+1)%MAX always generate no b/w 0 to MAX-1
}

void print() //printing the circular queue
{   cout<<"circular queue is: ";
	if(front==-1)
	{
		cout<<"NULL\n";
		return;
	}
	for(int i=front;;i++)
	{
		if(i==MAX)
		i=0;
		cout<<a[i]<<" ";
		if(i==rear) // condition has to be check after cout statement otherwise loop will fail ex- when rear+1=front
		break;
	}
	cout<<"\n";
	
}

void firstelement( ) //printing the front element of queue
{   if(front==-1)
	{cout<<"*no element in queue*\n";
	return;
	}
	cout<<"front element is: "<<a[front]<<"\n";
}

int main(void)
{
int e,n;
n=0;

while(n!=5)
{
cout<<"\nenter 1. to insert at rear \n 2. to delete from front\n 3. to print the circular queue\n 4. to print the front element\n 5. to exit\n";
cin>>n;
if(n==1)
{
	cout<<"enter an element\n";
	cin>>e;
	enqueue(e);
}
if(n==2)
dequeue();
if(n==3)
print();
if(n==4)
firstelement();

print();
}

}

