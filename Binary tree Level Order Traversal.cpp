
//Binary tree: Level Order Traversal
//T = O(n) all cases
//S = O(n) worst/avg & O(1) best case i.e.skew tree
#include<iostream>
#include<queue>
using namespace std;


struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;
};
bstnode* root; 

bstnode* insert(bstnode* root,int data)
{
	if(root==NULL)
	{	bstnode* tmp= new bstnode();
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
		root=tmp;
	}
	else if(data<=root->data)
	root->left = insert(root->left,data);
	else 
	root->right = insert(root->right,data);
	
	return root; 
}
//	ITERATIVE WAY (by using a queue)
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

int main()
{
root = NULL;
	root = insert(root,15);
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
ittraversal(root);


}

