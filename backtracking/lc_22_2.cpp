#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(0, 0, "", res, n);
        return res;
    }
    // left: open bracket (
    // right: right bracket )
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res, int max) {
        if (out.length() == 2*max) {res.push_back(out); return;}
        if (left < max)
            generateParenthesisDFS(left + 1, right, out + '(',res,max);
        if (right < left) // if right < max => create invalid cases: ))()((
            generateParenthesisDFS(left, right+1, out + ')', res,max);
    }
};


int main() {
    freopen("lc_22.inp","r",stdin);
    freopen("lc_22.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    Solution su;
    vector<string> out = su.generateParenthesis(n);
    for (auto a:out)
        cout<<a<<"\n";

    return 0;
}
