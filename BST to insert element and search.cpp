//https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28
// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
using namespace std;


struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;
};
bstnode* root; //to store only address of root node



bstnode* insert(bstnode* root,int data) //1st argument=address of root node
{
	if(root==NULL)
	{
		root=new bstnode();// root is only storing address of new node
		root->data=data;
		root->left = root->right = NULL;
	}
	else if(data<=root->data)			// < and = 
	root->left = insert(root->left,data); //newly created node will be saved at root->left location
	else 
	root->right = insert(root->right,data);//newly created node will be saved at root->right location
	
	return root; //everytime "root" will return the same top root node address to main()
}

bool search(bstnode* root,int data) //recursive way
{
	if(root==NULL)
	return false;
	else if(root->data==data)
	return true;
	else if(data<=root->data)
	 search(root->left,data);
	else
	 search(root->right,data);
	
}
/*
bool search(bstnode* root,int data) //non-recursive way
{
	while(root)
	{
	if(root->data==data)
	return true;
	else if(data<=root->data)
	 root=root->left;
	else
	 root=root->right;
	}
	if(root==NULL)
	return false;
	
} */

int main(void)
{
root = NULL; // creating empty tree with tope root node  = NULL
/*Code to test the logic*/
	root = insert(root,15);	//storing the address of top root node in "root"
	 root = insert(root,10);// no need to store address again bcuz everytime "root" will return the same top root node address
	 insert(root,20);
	 insert(root,25);
	 insert(root,8);
	insert(root,12);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";



}

