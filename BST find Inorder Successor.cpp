//Inorder Successor in a binary search tree

//https://www.youtube.com/watch?v=5cPbNCrdotA&index=37&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P
#include<iostream>
#include<queue>
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
		root=new bstnode();// root is only storing address of new node "tmp"
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else if(data<=root->data)			// < and = 
	root->left = insert(root->left,data); //newly created node will be saved at root->left location
	else 
	root->right = insert(root->right,data);//newly created node will be saved at root->right location
	
	return root; //everytime "root" will return the same top root node address to main()
}


void inorder(bstnode* root) //sorting of tree
{	
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
	
}
bstnode*  find_node(bstnode* root,int data)
{
	if(root==NULL)
	return NULL;
	while(root->data!=data)
	{
		if(data< root->data)
		root=root->left;
		else
		root=root->right;
	}
	return root;
}

bstnode* find_min(bstnode* root)
{	if(root==NULL)
	return NULL;
	while(root->left!=NULL)
	root=root->left;
	return root;
}

bstnode* getsuccessor(bstnode*root,int data)
{
	bstnode* current=find_node(root,data);
	if(current==NULL)
	return NULL;
	//case 1. node has right subtree -O(h)
	if(current->right!=NULL)
	return find_min(current->right);//return leftmost element(which is min.) of its right subtree
	else // case 2. no right subtree -O(h)
	{	//to find the nearest greater "parent node" of current
		bstnode* successor = NULL;
		bstnode* ancestor= root;//starting from the root to current
		while(current!=ancestor) 
		{
			if(current->data< ancestor->data)
			{
				successor=ancestor; // sets when parent node is greater then current
				ancestor=ancestor->left;
			}
			else
			ancestor=ancestor->right;
		}
	return successor;	//returning the nearest greater parent node
		
	}
	
	
}


int main(void)
{
root = NULL; // creating empty tree with tope root node  = NULL
/*Code to test the logic*/
	root = insert(root,15);	//storing the address of top root node in "root"
	 root = insert(root,10);// no need to store address again bcuz everytime "root" will return the same top root node address
	 insert(root,20);
	 insert(root,25);
	 insert(root,8);
	 insert(root,2);
	 insert(root,45);
	 insert(root,9);
	insert(root,12);
	insert(root,24);
	insert(root,23);
bstnode* current;
int a;
while(true)
{
cout<<"\ninorder:=";
inorder(root);
cout<<"\nenter a node to print its inorder successor";
cin>>a;
current=getsuccessor(root,a);
if(current!=NULL)
cout<<"\nsuccessor is: "<<current->data;
}
}

