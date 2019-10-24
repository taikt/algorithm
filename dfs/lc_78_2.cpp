/* https://github.com/grandyang/leetcode/issues/78
 * https://leetcode.com/problems/subsets/
 * https://www.cnblogs.com/TenosDoIt/p/3451902.html
 */


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void logout(vector<vector<int>> &out) {
            printf("[debug] start---------\n");
            for (int i=0; i<out.size(); i++) {
                for (int j=0; j<out[i].size(); j++)
                printf("%d ",out[i][j]);
                printf("\n");    
            }
            printf("[debug] end---------\n\n");
        }

        vector<vector<int>> subsets(vector<int> &S) {
            vector<vector<int>> res;
            sort(S.begin(), S.end());
            vector<int> temp;
            dfs(res,S,temp,0);

            return res;
        }

        void dfs(vector<vector<int>> &res, vector<int>& S, vector<int>& temp, int pos) {
            res.push_back(temp);
            for (int i=pos; i<S.size(); i++) {
                temp.push_back(S[i]);
                dfs(res,S,temp,i+1);
                temp.pop_back();
            }
        }


};

int main() {
    vector<int> S={1,2,3};
    Solution anw;
    vector<vector<int>> out = anw.subsets(S);
    anw.logout(out);
    
    return 0;
}
