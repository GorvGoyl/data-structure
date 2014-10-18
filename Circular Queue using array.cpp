  /* Circular Queues */
	  #include<iostream>
using namespace std;	  

	  const int MAX = 5;
	  class cqueue
	  {
		   int a[MAX],front,rear;
		public :
		   cqueue()
		   {
			 front=rear=-1;
		   }
		   void insert(int );
		   int deletion();
		   void display();
	  };

	  void cqueue :: insert(int val)
	  {
		 if((front==0 && rear==MAX-1) || (rear+1==front))
			  cout<<" Circular Queue is Full";
		 else
		 {
		   if(rear==MAX-1)
			  rear=0;
		   else
			 rear++;
		   a[rear]=val;
		 }
		 if(front==-1)
		   front=0;
	  }
	  int cqueue :: deletion()
	  {
		 int k;
		 if(front==-1)
			cout<<"Circular Queue is Empty";
		 else
		 {
			k=a[front];
			if(front==rear)
			   front=rear=-1;
			else
			{
			   if(front==MAX-1)
				  front=0;
			   else
				  front++;
			}
		 }
		 return k;
	  }
	  void cqueue :: display()
	  {
		  int i;
		  if(front==-1)
			 cout<<"Circular Queue is Empty";
		  else
		  {
			 if(rear < front)
			 {
				for(i=front;i<=MAX-1;i++)
				   cout<<a[i]<<"   ";
				for(i=0;i<=rear;i++)
				   cout<<a[i]<<"   ";
			 }
			 else
			 {
				for(i=front;i<=rear;i++)
				   cout<<a[i]<<"   ";
				cout<<endl;
			 }
		  }
	  }

	  main()
	  {
		 cqueue c1;

		 int ch,val;
		 char op;
		 do
		 {
		   
		 cout<<"1.Insertion 2.Deletion 3.Display 4.Exit";
		   cout<<"Enter Your Choice <1..4> ?";
		   cin>>ch;
		   switch(ch)
		   {
			   case 1 : cout<<"Enter Element to Insert ?";
						cin>>val;
						c1.insert(val);
						break;
			   case 2 : val=c1.deletion();
						cout<<"Deleted Element :"<<val<<endl;
						break;
			   case 3 : c1.display();
						break;
			}
			cout<<"Do you want to continue<Y/N> ?";
			cin>>op;
		  }while(op=='Y' || op=='y');
		   
		}

