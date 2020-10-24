#include <stdio.h>
// https://www.youtube.com/watch?v=COZK7NATh4k
// https://www.youtube.com/watch?v=hWokyBoo0aI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=29
// binary search tree
typedef struct bin_tree {
    int data;
    struct bin_tree *right, *left;
} node;

node* insert(node *tree, int val) { //*tree la pointer chi den root

    node *temp = NULL;
    if (tree == NULL) {
        temp = (node*) malloc(sizeof(node));
        // temp->left = temp->right = NULL;
        (*temp).left = (*temp).right = NULL;
        //temp->data = val;
        (*temp).data = val;
        tree = temp;
        return tree;
    }
    if (val < ((*tree).data)) // (val < (*tree)->data)
        (*tree).left = insert((*tree).left,val); // insert(&((*tree)->left),val)
    else (*tree).right = insert((*tree).right,val);
}


void print_preoder(node* tree) {
    if (tree)
    {
        printf("%d\n",(*tree).data);
        print_preoder((*tree).left);
        print_preoder((*tree).right);
    }
}

int main()
{
    node* root = NULL;

    printf("second bst\n");
    root = insert(root,9);
    root = insert(root,4);
    root = insert(root,15);

    print_preoder(root);

    return 0;
}

