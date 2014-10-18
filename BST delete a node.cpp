//Delete a node from Binary Search Tree

//https://www.youtube.com/watch?v=gcULXE7ViZw&index=36&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P
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
bstnode* min_of(bstnode* root)
{	root=root->right;
	while(root->left!=NULL)
	root=root->left;
	return root;
}
bstnode* max_of(bstnode* root)
{	root=root->left;
	while(root->right!=NULL)
	root=root->right;
	return root;
}
bstnode* _delete(bstnode* root,int data)
{	
	if(root==NULL)
	return root;
	
	if(data<root->data)
		root->left= _delete(root->left,data);
	else if(data>root->data)
		root->right= _delete(root->right,data);
else
{
		
	//case 1: no child ..leaf node
	if(root->left==NULL && root->right==NULL)
	{
	delete root;
	root=NULL;
	}
	//case 2: node with 1 child
	else if(root->left==NULL)
	{
		bstnode* tmp=root;
		root=root->right;
		delete tmp;
	}
	else if(root->right==NULL)
	{
		bstnode* tmp=root;
		root=root->left;
		delete tmp;
	}
	//case 3: node with 2 children
	else{	
	bstnode* tmp=min_of(root); //tmp storing the node just greater then root i.e.. addr of minimum node of right subtree...new root will be > node
	// bstnode* tmp=max_of(root); // works also.. in this case new root will be < node
	root->data=tmp->data; // root(assumed for deleting) now storing the min. value of right subtree
	root->right = _delete(root->right,tmp->data); //using the same fuction for deleting min. node
	}											//and storing 'NULL' in root->right after return from _delete()
}
return root; //returns NULL when recursion ends

}

void ittraversal(bstnode* root){
queue<bstnode*> q;
if(root==NULL)return;

q.push(root);
while(!q.empty())
{
	
	cout<<q.front()->data<<" ";
	if(q.front()->left!=NULL)
	q.push(q.front()->left);
	if(q.front()->right!=NULL)
	q.push(q.front()->right);
	q.pop();
	
}
}

int main(void)
{
root = NULL; // creating empty tree with tope root node  = NULL
/*Code to test the logic*/
	root = insert(root,15);	//storing the address of top root node in "root"
	 insert(root,10);
	 insert(root,20);
	 insert(root,25);
	 insert(root,8);
	 insert(root,2);
	 insert(root,45);
	 insert(root,9);
	insert(root,12);
	insert(root,24);
	insert(root,23);
int a;
while(true)
{
cout<<"\ninorder:=";
inorder(root);
cout<<"\nlevel order: ";
ittraversal(root);
cout<<"\nenter a node to delete";
cin>>a;
root=_delete(root,a);

}
}

