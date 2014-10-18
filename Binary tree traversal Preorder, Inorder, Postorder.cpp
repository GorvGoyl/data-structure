
//Binary tree traversal: Preorder, Inorder, Postorder
//T = O(n) all cases
//S = O(n) worst && O(logn) best/avg case i.e.skew tree
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
	{bstnode* tmp= new bstnode();
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	root=tmp;		//root becomes temp
	}
	else if(data<=root->data)			// < and = 
	root->left = insert(root->left,data); //newly created node will be saved at root->left location
	else 
	root->right = insert(root->right,data);//newly created node will be saved at root->right location
	
	return root; //everytime "root" will return the same top root node address to main()
}

void preorder(bstnode* root)
{	
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
	
}

void inorder(bstnode* root) //sorting of tree
{	
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
	
}

void postorder(bstnode* root)
{	
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	
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
cout<<"Preorder:=";
preorder(root);
cout<<"\ninorder:=";
inorder(root);
cout<<"\nPostorder:=";
postorder(root);
}

