/*
 * validate BST
 * https://leetcode.com/problems/validate-binary-search-tree/solution/
 * https://github.com/grandyang/leetcode/issues/98
 *
 */

#include <iostream>
#include <climits>
#include <vector>
#include <stack>
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
            stack<TreeNode*> s;
            TreeNode *p = root, *pre = NULL;
            while (p || !s.empty()) {
                while(p) {
                    s.push(p);
                    p = p->left;
                }
                p = s.top(); s.pop();
                if (pre && p->val <= pre->val) return false;
                pre = p;
                p = p->right;
            }

            return true;
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
