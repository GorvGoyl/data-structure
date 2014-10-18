// C++ program to find predecessor and successor in a BST both Iterative and recursive
#include <iostream>
using namespace std;
 
// BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}
 

  //	Iterative Fuction	//
 void precsuc(Node* root,int key){
 	Node* pre = NULL, *suc = NULL;
 	while(root){
 		if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        break;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        root=root->left;
    }
    else // go to right subtree
    {
        pre = root ;
        root=root->right;
 		
 	}
 }
 cout << "\nPredecessor (iterative) is: ";
 if (pre != NULL)
      cout<< pre->key;
    else
      cout << "No Predecessor";
 cout << "\nSuccessor (iterative) is: ";
    if (suc != NULL)
      cout<< suc->key<<"\n";
    else
      cout << "No Successor\n";
}
 
 // A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
 
// Driver program to test above function
int main()
{
    int key;    //Key to be searched in BST
 
   /* Let us create following BST
              20
           /     \
          8      22
         /  \    
       4    12
	   		/ \
	   	  10  14	*/
	   	  
    Node *root = NULL;
    root = insert(root,20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);
 
 
    Node* pre = NULL, *suc = NULL;
 cout<<"enter the key to find its predecessor and successor\n";
 cin>>key;
    findPreSuc(root, pre, suc, key);
 cout << "\nPredecessor is: ";
 if (pre != NULL)
      cout<< pre->key;
    else
      cout << "No Predecessor";
      
 cout << "\nSuccessor is: ";
    if (suc != NULL)
      cout<< suc->key<<"\n";
    else
      cout << "No Successor\n";
      
	precsuc(root,key);
    return 0;
}
