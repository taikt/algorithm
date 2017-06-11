#include <stdio.h>
// https://www.youtube.com/watch?v=COZK7NATh4k
// https://www.youtube.com/watch?v=hWokyBoo0aI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=29
// binary search tree
typedef struct bin_tree {
    int data;
    struct bin_tree *right, *left;
} node;

node* createNode(int val) {
    node *temp = NULL;
    temp = (node*) malloc(sizeof(node));
    // temp->left = temp->right = NULL; // similar as below
    (*temp).left = (*temp).right = NULL;
    //temp->data = val;
    (*temp).data = val;

    return temp; //ok to return value of local variable, not its address
}

void insert(node **tree, int val) { //*tree la pointer chi den root

    node *temp = NULL;
    if (*tree == NULL) {
#if 0
        temp = (node*) malloc(sizeof(node));
        // temp->left = temp->right = NULL; // similar as below
        (*temp).left = (*temp).right = NULL;
        //temp->data = val;
        (*temp).data = val;
        *tree = temp;
#endif
        *tree = createNode(val);
        return;
    }
    if (val < ((**tree).data)) // (val < (*tree)->data)
        insert(&((**tree).left),val); // insert(&((*tree)->left),val)
    else insert(&((**tree).right),val);
}


void print_preoder(node* tree) {
    if (tree)
    {
        printf("%d\n",(*tree).data);
        print_preoder((*tree).left);
        print_preoder((*tree).right);
    }
}

void delete_tree(node* tree) {
    if (tree!= NULL)
    {
        delete_tree((*tree).left);
        delete_tree((*tree).right);
        free(tree);
    }
}

int main()
{
    node* root = NULL;

    insert(&root,9);
    insert(&root,4);
    insert(&root,15);

    print_preoder(root);
    delete_tree(root);

    return 0;
}
