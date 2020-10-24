/*
 * validate BST
 * https://leetcode.com/problems/validate-binary-search-tree/solution/
 * https://www.cnblogs.com/grandyang/p/4298435.html
 *
 */

#include <iostream>
#include <climits>
#include <vector>
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
            if (!root) return true;
            vector<int> vals;
            inorder(root, vals);

            for (int i=0; i < vals.size() -1; i++) {
                if (vals[i] >= vals[i+1]) return false;
            }

            return true;
        }

        void inorder(TreeNode* root, vector<int>& vals) {
            if (!root) return;
            inorder(root->left, vals);
            vals.push_back(root->val);
            inorder(root->right, vals);
        }

    private:
        TreeNode* root;
};

//method 2
class Solution {
    public:
        Solution(TreeNode* root): root(root) {}
        bool isValidBST() {
            return isValidBST(root);
        }

    private:
        bool isValidBST(TreeNode* root) {
            TreeNode *pre = NULL;
            return inorder(root,pre);
        }

        bool inorder(TreeNode* node, TreeNode* pre) {
            if (!node) return true;
            bool res = inorder(node->left, pre);
            if (!res) return false;
            if (pre) {
                if (node->val <= pre->val) return false;
            }
            pre = node;
            return inorder(node->right, pre);

        }

    private:
        TreeNode* root;
};

//method 3
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
