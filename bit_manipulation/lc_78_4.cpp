/* 
 * https://leetcode.com/problems/subsets/
 * https://www.cnblogs.com/TenosDoIt/p/3451902.html
 * https://github.com/grandyang/leetcode/issues/78
 *
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
            vector<vector<int>> res(1); // res={{},}
            sort(S.begin(), S.end());
            vector<int> temp;
            
            int len = S.size(), max = 1<<len;
            for (int i=1; i<max; i++) {
                temp.clear();
                int current = i;
                for (int j=0; j<S.size(); j++) {
                    if (current & 1) temp.push_back(S[j]);
                    current = current >> 1; //current >>= 1;
                }
                res.push_back(temp);
            } 


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
