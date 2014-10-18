

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


class binarytree{
	bstnode* root;
	public:
		binarytree(){
			root=NULL;
		}
		
		
		void insert(int);
		void preorder();
		void postorder();
		void inorder();

		void preorder(bstnode*); 		//fuction overloading
		void postorder(bstnode*);
		void inorder(bstnode*);
};


void binarytree::insert(int d){			//iterative way to insert new no.
			bstnode *abc=new bstnode();
			abc->data=d;
			abc->left=abc->right=NULL;
			if(root==NULL){
				root=abc;return;
			}
			bstnode* tmp=root;
			while(1){
				if(d<tmp->data){
					if(tmp->left!=NULL)
					tmp=tmp->left;
					else{
						tmp->left=abc;return;
					}
				}
				else 
					if(tmp->right!=NULL)
					tmp=tmp->right;
					else{
						tmp->right=abc;return;	
			}
			
		}
		}
/*		//Recursive way
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
*/
void binarytree::preorder(){      					//fuction overloading
		preorder(root);
		}
void binarytree::postorder(){
		postorder(root);
		}
void binarytree::inorder(){
		inorder(root);
		}
void binarytree::preorder(bstnode* root)
{	
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
	
}

void binarytree::inorder(bstnode* root) //sorting of tree
{	
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
	
}

void binarytree::postorder(bstnode* root)
{	
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	
}

main()
{
binarytree b;
/*Code to test the logic*/
	b.insert(15);
	b.insert(10);
	b.insert(20);
	b.insert(25);
	b.insert(8);
	b.insert(2);
	b.insert(45);
	b.insert(9);
	b.insert(12);
	b.insert(24);
	b.insert(23);
cout<<"\ninorder:= ";
b.inorder();
cout<<"\nPreorder:= ";
b.preorder();
cout<<"\nPostorder:= ";
b.postorder();
}

