//Check if a binary tree is binary search tree or not
//https://www.youtube.com/watch?v=yEwSGhSsT0U&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=35
#include<iostream>
#include<queue>
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
	else if(data<= root->data)			// < and = 
	root->left = insert(root->left,data); //newly created node will be saved at root->left location
	else 
	root->right = insert(root->right,data);//newly created node will be saved at root->right location
	
	return root; //everytime "root" will return the same top root node address to main()
}

//1st approach  T=O(n)
bool is_inorder(bstnode* root) //sorting of tree by inorder and then check current data with previous
{	static bstnode* prev= NULL; //using STATIC to store 'prev' value after each recursion and not NULL
	if(root!=NULL) // traverse the tree in inorder fashion and keep track of prev node
	{
	if(!is_inorder(root->left))
	return false; //only return when left subtree is NULL
	if(prev!=NULL && prev->data> root->data)
	return false;
	prev=root;
	return is_inorder(root->right); //always return after traversing right subtree
	}
	return true;
}

//2nd approach T = O(n)
bool is_bst(bstnode* root,int min_val,int max_val) //default(for first run) min_val=min possible value & max_val=max possible value
{
	if(root==NULL) //base condition
	return true;
	if(root->data>=min_val && root->data<max_val //if root> left subtree && root< right subtree
	 && is_bst(root->left,min_val,root->data) //going to leftsubtree & max_val becomes parent root data
	 && is_bst(root->right,root->data,max_val)) //going to rightsubtree & min_val becomes parent root data
	 return true; //if all 4 conditions true recursively
	 else
	 return false;
	
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



}

