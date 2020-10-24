/*
 * validate BST
 * https://leetcode.com/problems/validate-binary-search-tree/solution/
 * https://www.cnblogs.com/grandyang/p/4298435.html
 *
 */

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        Solution(TreeNode* root): root(root) {}
        bool isValidBST() {
            return isValidBST(root);
        }

    private:
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, LONG_MIN, LONG_MAX);
        }

        bool isValidBST(TreeNode* root, long min, long max) {
            if (!root) return true;
            if (root->val <= min || root->val >= max) return false;
            return isValidBST(root->left, min, root->val) && 
                isValidBST(root->right, root->val, max);
        }


    private:
        TreeNode* root;
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    Solution aws(root);

    if(aws.isValidBST())
        cout<<"Is BST\n";
    else
        cout<<"Not a BST\n";

    return 0;
}
