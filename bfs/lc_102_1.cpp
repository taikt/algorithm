/*
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 * https://github.com/grandyang/leetcode/issues/102
 * g++ binary_tree_level_order_travel.cpp --std=c++11
 */

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            int t=0;
            if (!root) return {};
            vector<vector<int>> res;
            queue<TreeNode*> q{{root}};
            while (!q.empty()) {
                vector<int> onelevel;
                for (int i=q.size(); i>0; i--)  { //just print 0-> current size of queue, not all upcomming elements
                    TreeNode* node = q.front(); q.pop();
                    onelevel.push_back(node->val);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                res.push_back(onelevel);
                //debug
                printf("\n[debug] level[%d] ",++t);
                for (int i=0; i<onelevel.size(); i++) {
                    printf("%d ",onelevel[i]);
                } 
            }
            return res;
        }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution anw;
    vector<vector<int>> levelOrder = anw.levelOrder(root);
    for (int i=0; i<levelOrder.size(); i++) {
        for (int j=0; j<levelOrder[i].size(); j++) {
            printf("%d ",levelOrder[i][j]);
        }
        printf("\n");
    }

    return 0;
}
