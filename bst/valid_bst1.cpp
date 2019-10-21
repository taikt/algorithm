/*  https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 *  create a binary tree
 *  Note: binary tree (node has two children) differ with binary search tree (left node < node < right node)
 *
 *  A binary tree node has data,  
 *   pointer to left child and  
 *   a pointer to right child 
 *
 */

#include <bits/stdc++.h> 
#include <iostream> 
using namespace std; 
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
      
    /* Constructor that allocates  
    a new node with the given data 
    and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
}; 
  
int isBSTUtil(node* node, int min, int max);  
  
/* Returns true if the given  
tree is a binary search tree  
(efficient version). */
int isBST(node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  
  
  
/* Driver code*/
int main()  
{  
    node *root = new node(4);  
    root->left = new node(2);  
    root->right = new node(5);  
    root->left->left = new node(1);  
    root->left->right = new node(3);  
      
    if(isBST(root))  
        cout<<"Is BST\n";  
    else
        cout<<"Not a BST\n";  
          
    return 0;  
}  

