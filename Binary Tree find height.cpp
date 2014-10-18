
// Find height of a binary tree  --RECURSIVE and ITERATIVE

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
//count height of left and right subtrees to find height of root (recursive)
int find_height (bstnode* root)
{
	if(root==NULL)
	return -1; 			//to balance the height of leaf node i.e. h(last node)= -1+1=0
	int rightheight = find_height(root->right)+1; //to count height of parent node,we add 1 extra to height of subtree
	int leftheight = find_height(root->left)+1;
	return max(rightheight,leftheight); //return max height of left and right subtree
	
}
 // ITERATIVE WAY using queue	//
int itheight(bstnode* root){
	if(root==NULL)return 0;
	queue<bstnode*> q;
	q.push(root);
	int level=0;
	int n;
 while(1){
 	n=q.size();				//counting nodes in current level
 	if(n==0)return level-1;  //neglecting extra height
	while(n>0){
		bstnode* tmp=q.front();
		//cout<<tmp->data;
		if(tmp->left)
		q.push(tmp->left);
		if(tmp->right)
		q.push(tmp->right);
		q.pop();			//delete all nodes at current level
		n--;
	}
	level++;				//count level
  }
}

int main(void)
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

	cout<<"height of tree is: "<<find_height(root);
	cout<<"\nheight of tree(using iteration) is: "<<itheight(root);


}

