


// Find min and max element in a binary search tree

#include<iostream>
using namespace std;


struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;
};
bstnode* root; //to store only address of root node

bstnode* getnewnode(int data)
{
	bstnode* tmp= new bstnode();
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}


bstnode* insert(bstnode* root,int data) //1st argument=address of root node
{
	if(root==NULL)
	{
		root=getnewnode(data);// root is only storing address of new node "tmp"
	}
	else if(data<=root->data)			// < and = 
	root->left = insert(root->left,data); //newly created node will be saved at root->left location
	else 
	root->right = insert(root->right,data);//newly created node will be saved at root->right location
	
	return root; //everytime "root" will return the same top root node address to main()
}




// recursive way to find minimum
void minimum(bstnode* root)
{	if(root==NULL) // empty tree, avoiding error
	return;
	if(root->left==NULL)
	{
		cout<<root->data;
		return;
	}
	minimum(root->left);
}
/*
void minimum(bstnode* root)
{	if(root==NULL) // empty tree, avoiding error
	return;
	while(root->left!=NULL)
	{
		root=root->left; //root is local so it won't change the main's root value
	}
	cout<<root->data;
}*/
// iterative way t o find maximum
void maximum(bstnode* root)
{	if(root==NULL) // empty tree, avoiding error
	return;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	cout<<root->data;
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
	insert(root,12);

	cout<<"min. no is: ";
	minimum(root);
		cout<<"\n max. no is: ";
	maximum(root);




}

