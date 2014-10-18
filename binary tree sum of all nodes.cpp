//BINARY TREE SUM OF ALL NODES -- RECURSIVE AND ITERATIVE
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
	{bstnode* tmp= new bstnode();
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

		// RECURSIVE WAY  //
int totalsum(bstnode* root){
	if (root==NULL)return 0;
	
	return( root->data + totalsum(root->left) + totalsum(root->right));
}

		//	ITERATIVE WAYY	//
int itsum(bstnode* root){
	queue<bstnode*> q;	
	if(root==NULL)return 0;
	int sum=0;
	
	q.push(root);
	while(!q.empty()){
		bstnode* tmp=q.front();
		sum=sum+tmp->data;

		if(tmp->left)
		q.push(tmp->left);
		if(tmp->right)
		q.push(tmp->right);
		q.pop();
		
	}
	
	return sum;
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

cout<<"total sum(by recursion) of all nodes: "<<totalsum(root);

cout<<"\ntotal sum(iterative) of all nodes: "<<itsum(root);

}

