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

// method 2
#if 0

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            levelorder(root,0,res);
            return res;
        }

        void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
            if (!node) return;
            if (res.size() == level) res.push_back({}); // init two-dimentional vector, check debug test part below
            res[level].push_back(node->val);
            if (node->left) levelorder(node->left, level+1, res);
            if (node->right) levelorder(node->right, level+1, res);
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
#if 0
    //debug: testing init two-dimentional vector
    vector<vector<int>> res;
    res.push_back({});
    res[0].push_back(1);
    res[0].push_back(2);
    // {{1,2}}
    res.push_back({}); // core dumped if not initialization this
    res[1].push_back(3);
    res[1].push_back(2);
    // {{1,2}, {3,2}}
    printf("%d %d\n",res[0][0], res[0][1]);
    printf("%d %d\n",res[1][0], res[1][1]);
#endif
    return 0;
}

#endif // 0
