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
  
  
/* Driver code*/
int main()  
{  
    node *root = new node(4);  
    root->left = new node(2);  
    root->right = new node(5);  
    root->left->left = new node(1);  
    root->left->right = new node(3);  
      
          
    return 0;  
}  

