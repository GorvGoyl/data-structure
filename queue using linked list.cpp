//Queue using Linked List :-Gourav Goyal
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class queue
{

	node *rear; //for storing the last node  (for Insertion)
	node *front;  //fro storing the first node (for deletion)
public:
    queue()
    {
        
        front=rear=NULL; 
    }
    void insert(int data)
    {
        node *p=new node();
        p->data=data;
        p->next=NULL;    
        if(front==NULL)
        {
            front=rear=p; //inserting node in empty linked list
        }
        else
        {
        	
            rear->next=p;  //rear is the last node and now pointing to the new node
            rear=p;			//rear becomes the new node[last]
        }
    }
    void del()
    {
        if(front==NULL)  //for empty linked list
            cout<<"UNDERFLOW";
        else
        {
            node *t=front;
            cout<<"The element to be deleted is"<<front->data;
            if(front==rear) 	//in case of only node in linked list
                front=rear=NULL;
            else
			front=front->next; //moving to the very next node
            delete t;
        }
    }
    void display()
    {
        node* tmp=front;  //front is the first node i.e..head node
        if(front==NULL){
        	cout<<"Queue's empty";return;
        }
        
        while(tmp!=rear)  //print upto rear-1
        {cout<<tmp->data<<" ";tmp=tmp->next;
        }
        cout<<" "<<tmp->data; //printing last element at  rear
        
    }
};

main()
{
    
    queue q;
    int data,option;
    while(1)
    {
        cout<<"\n 1.Insert \n 2.Delete \n 3.Display\n 4.Exit\n Enter your Option";
        cin>>option;
        switch(option)
        {
            case 1:
                    cout<<"\nEnter the element to be inserted";
                    cin>>data;
                    q.insert(data);
                    break;
            case 2:
                    q.del();
                    break;
            case 3:
                    q.display();
                    break;
            case 4:
                    exit(0);
        }
    }
}


