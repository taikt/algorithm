/*
 *  https://leetcode.com/problems/symmetric-tree/
 *  https://github.com/grandyang/leetcode/issues/101
 *  g++ symmetric_tree.cpp --std=c++11
 */
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        TreeNode* root;

    public:
        Solution(TreeNode* root): root(root) {}
        bool isSymmetric(TreeNode* root) {
            if (!root) return true;

            queue<TreeNode*> q1,q2;
            if ((!root->left && root->right) || (!root->right && root->left)) return false;
            if (!root->left && !root->right) return true;
            q1.push(root->left);
            q2.push(root->right);

            while (!q1.empty() && !q2.empty()) {
                TreeNode* node1 = q1.front();q1.pop();
                TreeNode* node2 = q2.front();q2.pop();
                if (!node1 && !node2) continue; // both node is null
                if ((!node1 && node2) || (!node2 && node1)) return false;
                if (node1->val != node2->val) return false;
                q1.push(node1->left);
                q2.push(node2->right);
                q1.push(node1->right);
                q2.push(node2->left); 
            }

            return true;
        }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);    
    root->right = new TreeNode(2);    
    root->left->left = new TreeNode(3);    
    root->left->right = new TreeNode(4);    
    root->right->left = new TreeNode(5);    
    root->right->right = new TreeNode(3);    
    Solution ans(root);
    if (ans.isSymmetric(root)) printf("tree is symmetric\n");
    else printf("tree is not symmetric\n");

    return 0;
}
