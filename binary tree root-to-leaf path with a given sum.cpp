//check existence of root-to-leaf path with a given sum
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


void findsum(bstnode* root,int sum){
	if (root==NULL)return;

	sum=sum-root->data;

	if(sum==0 && root->left==NULL && root->right==NULL)
	{
		cout<<"leaf node with the path equal to sum: "<<root->data;return;
	}
	findsum(root->left,sum);
	findsum(root->right,sum);
	
	return;
	
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
findsum(root,107);
//cout<<(findsum(root,107));
}

