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
            vector<vector<int>> res(1); // res = {{},}, create empty element
            sort(S.begin(), S.end());
            for (int i=0; i<S.size(); i++) {
                int size = res.size();
                //printf("i=%d, size=%d\n",i,size);
                //printf("before insert\n");
                //logout(res);
                for (int j=0; j<size; j++) {
                    res.push_back(res[j]); // create new element which value = res[j]
                    res.back().push_back(S[i]); // new element = res[j] + S[i]
                    //printf("\n-- j=%d\n",j);
                    //printf("after insert\n");
                    //logout(res);
                }
            }
            return res;
        }
};

int main() {
    vector<int> S={1,2,3};
    Solution anw;
    vector<vector<int>> out = anw.subsets(S);
    anw.logout(out);
    //debug
#if 0
    vector<vector<int>> res; //res[0] = {}
    vector<int> aa;
    aa.push_back(2);
    aa.push_back(4);
    printf("%d %d %d\n",aa[0], aa[1], aa[2]); // aa={2,4,0}
    res.push_back(aa); // res={{2,4},}
    printf("res[0][0]=%d\n",res[0][0]); // 2
    printf("size=%d\n", res.size()); // 1
    res.push_back(res[0]); // new element = res[1] = {2,4}
    res.back().push_back(1); //new element = rest[1] + 1 = {2,4,1}, res.back() return last element of res (res[1]), res.front return first element
    res.front().push_back(3);
    printf("res[0,0]=%d, res[0,1]=%d res[0,2]=%d res[1,0]=%d res[1,1]=%d, res[1,2]=%d\n", res[0][0], res[0][1], res[0][2], res[1][0], res[1][1], res[1][2]);
#endif
    return 0;
}
